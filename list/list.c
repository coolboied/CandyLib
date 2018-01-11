#include "list.h"
#include "list_iterator.h"

list_node_t* list_node_new(void *val) 
{
    list_node_t *self = malloc(sizeof(list_node_t));
    if(self == NULL)
    {
        return NULL;
    }

    self->prev = NULL;
    self->next = NULL;
    self->val = val;
    return self;
}

list_t * list_new(ListNodeFreeFunc freeF, ListNodeMatchFunc matchF) {
    list_t *self = malloc(sizeof(list_t));
    if(self == NULL)
    {
        return NULL;
    }
    self->head = NULL;
    self->tail = NULL;
    self->free = freeF;
    self->match = matchF;
    self->len = 0;
    return self;
}

void list_destroy(list_t *self) {
    UInt32 len = self->len;
    list_node_t *next;
    list_node_t *curr = self->head;

    while (len > 0) 
    {
        len--;
        next = curr->next;
        if (self->free)
        {
            self->free(curr->val);
        }
        free(curr);
        curr = next;
    }

    free(self);
}

/*
 * Append the given node to the list
 * and return the node, NULL on failure.
 */
UInt32 list_push(list_t *self, list_node_t *node) 
{
    if(node == NULL)
    {
        return self->len;
    }

    if (self->len) 
    {
        node->prev = self->tail;
        node->next = NULL;
        self->tail->next = node;
        self->tail = node;
    }
    else 
    {
        self->head = self->tail = node;
        node->prev = node->next = NULL;
    }
    ++self->len;
    return self->len;
}

/*
 * Return / detach the last node in the list, or NULL.
 */
list_node_t * list_pop(list_t *self) 
{
    if (self->len == 0)
    {
        return NULL;
    }

    list_node_t *node = self->tail;

    if (self->len > 1) 
    {
        (self->tail = node->prev)->next = NULL;
    }
    else 
    {
        self->tail = self->head = NULL;
    }
    (self->len)--;

    node->next = node->prev = NULL;
    return node;
}

/*
 * Return / detach the first node in the list, or NULL.
 */
list_node_t * list_shift(list_t *self) 
{
    if (self->len == 0) 
    {
        return NULL;
    }

    list_node_t *node = self->head;

    if (self->len > 1) 
    {
        (self->head = node->next)->prev = NULL;
    } 
    else 
    {
        self->head = self->tail = NULL;
    }
    (self->len)--;

    node->next = node->prev = NULL;
    return node;
}

/*
 * Prepend the given node to the list
 * and return the node, NULL on failure.
 */
UInt32 list_unshift(list_t *self, list_node_t *node) 
{
    if(node == NULL)
    {
        return self->len;
    }

    if (self->len) 
    {
        node->next = self->head;
        node->prev = NULL;
        self->head->prev = node;
        self->head = node;
    }
    else
    {
        self->head = self->tail = node;
        node->prev = node->next = NULL;
    }

    (self->len)++;
    return self->len;
}

/*
 * Return the node associated to val or NULL.
 */
list_node_t * list_find(list_t *self, void *val) 
{
    list_iterator_t *it = list_iterator_new(self, LIST_HEAD);
    list_node_t *node;

    while ((node = list_iterator_next(it))) 
    {
        if (self->match) 
        {
            if (self->match(val, node->val)) 
            {
                list_iterator_destroy(it);
                return node;
            }
        } 
        else 
        {
            if (val == node->val) 
            {
                list_iterator_destroy(it);
                return node;
            }
        }
    }

    list_iterator_destroy(it);
    return NULL;
}

/*
 * Return the node at the given index or NULL.
 */
list_node_t * list_at(list_t *self, UInt32 index) 
{
    list_direction_t direction = LIST_HEAD;

    if (index < 0) 
    {
        direction = LIST_TAIL;
        index = ~index;
    }

    if ((unsigned)index < self->len) 
    {
        list_iterator_t *it = list_iterator_new(self, direction);
        list_node_t *node = list_iterator_next(it);
        while (index--)
        {
            node = list_iterator_next(it);
        }
        list_iterator_destroy(it);
        return node;
    }

    return NULL;
}

/*
 * Remove the given node from the list, freeing it and it's value.
 */
void list_remove(list_t *self, list_node_t *node)
{
    node->prev
        ? (node->prev->next = node->next)
        : (self->head = node->next);

    node->next
        ? (node->next->prev = node->prev)
        : (self->tail = node->prev);

    if (self->free)
    {
        self->free(node->val);
    }

    free(node);
    (self->len)--;
}

UInt32 list_insert(list_t *self, list_node_t* node, UInt32 index)
{
    list_node_t* preNode = list_at(self, index);
    if(preNode == NULL)
    {
        return self->len;
    }

    preNode->prev->next = node;
    node->prev = preNode->prev;
    node->next = preNode;
    preNode->prev = node;
    return self->len;
}
