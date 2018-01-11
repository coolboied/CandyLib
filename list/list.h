#ifndef __LIST_H__
#define __LIST_H__
#include <stdlib.h>
#include "common.h"

typedef (*ListNodeFreeFunc)(void *val);
typedef (*ListNodeMatchFunc)(void *source, void* obj);

typedef struct list_node {
  struct list_node *prev;
  struct list_node *next;
  void *val;
} list_node_t;

typedef struct {
  list_node_t *head;
  list_node_t *tail;
  UInt32     len;
  ListNodeFreeFunc free;
  ListNodeMatchFunc match;
} list_t;

list_node_t* list_node_new(void *val);
list_t * list_new(ListNodeFreeFunc freeF, ListNodeMatchFunc matchF);
void list_destroy(list_t *self);

UInt32 list_push(list_t *self, list_node_t *node);
UInt32 list_unshift(list_t *self, list_node_t *node);
list_node_t* list_pop(list_t *self);
list_node_t* list_shift(list_t *self);
list_node_t* list_find(list_t *self, void *val);
list_node_t* list_at(list_t *self, UInt32 index);
void list_remove(list_t *self, list_node_t *node);
#endif
