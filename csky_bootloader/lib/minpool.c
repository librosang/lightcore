#include <stdbool.h>
#include <minpool.h>
#include <kernel.h>

struct minpool_node {
    struct list_head block;
    struct list_head free;
    uint32_t usize;
    char data[0];
};

static inline bool
gnode_get_used(struct minpool_node *node)
{
    return node->usize & (1 << 0);
}

static inline uint32_t
gnode_get_size(struct minpool_node *node)
{
    return node->usize & ~((1 << 1) - 1);
}

static inline void
gnode_set_used(struct minpool_node *node, bool used)
{
    if (used)
        node->usize |= (1 << 0);
    else
        node->usize &= ~(1 << 0);
}

static inline void
gnode_set_size(struct minpool_node *node, uint32_t size)
{
    node->usize = (node->usize & (1 << 0)) | (size & ~((1 << 1) - 1));
}

static inline void
gnode_set(struct minpool_node *node, uint32_t size, bool used)
{
    node->usize = (size & ~((1 << 1) - 1)) | (used ? (1 << 0) : 0);
}

static struct minpool_node *
minpool_find(struct minpool_head *head, uint32_t size)
{
    struct minpool_node *node;

    list_for_each_entry(node, &head->free_list, free) {
        if (gnode_get_size(node) >= size)
            return node;
    }
    return 0;
}

static struct minpool_node *
minpool_check(void *block)
{
    struct minpool_node *node;
    node = container_of(block, struct minpool_node, data);
    if (!list_check_empty(&node->free))
        return 0;
    return node;
}

void *minpool_alloc(struct minpool_head *head, uint32_t size)
{
    struct minpool_node *node, *free;
    uint32_t fsize;

    align_high_adj(size, MINPOOL_ALIGN);

    if (size == 0)
        return 0;

    node = minpool_find(head, size);
    if (!node)
        return 0;

    fsize = gnode_get_size(node);

    if (fsize >= size + MINPOOL_BLOCK) {
        free = (void *)node + sizeof(*node) + size;

        list_add(&free->block, &node->block);
        list_add(&free->free, &node->free);
        gnode_set(free, fsize - size - sizeof(*free), false);

        head->avail -= sizeof(*free);
    } else {
        size = fsize;
    }

    head->avail -= size;
    list_del_init(&node->free);
    gnode_set_used(node, true);

    return node->data;
}

void minpool_free(struct minpool_head *head, void *block)
{
    struct minpool_node *node, *other;
    uint32_t size;

    if (!block || !(node = minpool_check(block)))
        return;

    size = gnode_get_size(node);
    head->avail += size;

    other = list_next_entry_or_null(node, &head->block_list, block);
    if (other && !gnode_get_used(other)) {
        size += sizeof(*other) + gnode_get_size(other);
        head->avail += sizeof(*other);
        list_del(&other->block);
        list_del(&other->free);
    }

    other = list_prev_entry_or_null(node, &head->block_list, block);
    if (other && !gnode_get_used(other)) {
        size += sizeof(*node) + gnode_get_size(other);
        head->avail += sizeof(*node);
        list_del(&node->block);
        node = other;
    } else {
        list_add(&node->free, &head->free_list);
    }

    gnode_set_size(node, size);
    gnode_set_used(node, false);
}

void *minpool_realloc(struct minpool_head *head, void *block, uint32_t resize)
{
    struct minpool_node *node, *expand;
    uint32_t size, esize;
    void *reblock;

    if (!resize) {
        minpool_free(head, block);
        return 0;
    }

    if (!block || !(node = minpool_check(block)))
        return minpool_alloc(head, resize);

    size = gnode_get_size(node);
    align_high_adj(resize, MINPOOL_ALIGN);
    if (size >= resize)
        return block;

    expand = list_next_entry_or_null(node, &head->block_list, block);
    if (expand && !gnode_get_used(expand)) {
        esize = gnode_get_size(expand);
        if (size + sizeof(*expand) + esize >= resize) {
            minpool_free(head, expand->data);
            node->usize &= ~(1<<0);
            return minpool_alloc(head, resize);
        }
    }

    reblock = minpool_alloc(head, resize);
    if (reblock) {
        memcpy(reblock, block, size);
        minpool_free(head, block);
        return reblock;
    }

    return 0;
}

void minpool_setup(struct minpool_head *head, void *array, uint32_t size)
{
    struct minpool_node *node = array;

    align_high_adj(size, ~MINPOOL_ALIGN);

    INIT_LIST_HEAD(&head->block_list);
    INIT_LIST_HEAD(&head->free_list);
    head->avail = size - sizeof(*node);

    list_add(&node->block, &head->block_list);
    list_add(&node->free, &head->free_list);
    gnode_set(node, head->avail, false);
}
