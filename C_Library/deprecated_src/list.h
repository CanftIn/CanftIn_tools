#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

typedef struct dlist_s List;
typedef struct dlist_iter_s ListIter;
typedef struct dlist_iter_desc_s ListDIter;

List *list_new();

bool list_destroy(List *list);
bool list_destroy_free(List *list);

bool list_splice(List *list1, List *list2);
bool list_splice_before(List *list, List *list2, int index);
bool list_splice_after(List *list, List *list2, int index);

bool list_add(List *list, void *element);
bool list_add_at(List *list, void *element, int index);
bool list_add_all(List *list1, List *list2);
bool list_add_all_at(List *list, const List *list2, int index);
bool list_add_first(List *list, void *element);
bool list_add_last(List *list, void *element);

bool list_remove(List *list, void *element);
bool list_remove_first(List *list);
bool list_remove_last(List *list);
bool list_remove_at(List *list, int index);
bool list_remove_all(List *list);

bool list_free(List *list, void *element);
bool list_free_first(List *list);
bool list_free_last(List *list);
bool list_free_at(List *list, int index);
bool list_free_all(List *list);

void *list_get(List *list, int index);
void *list_get_first(List *list);
void *list_get_last(List *list);

List *list_sublist(List *list, int from, int to);
List *list_copy_shallow(List *list);
List *list_copy_deep(List *list, void *(*cp) (void*));
void list_reverse(List *list);

bool list_replace_at(List *list, void *element, int index);

int list_contains(List *list, void *element);
int list_index_of(List *list, void *element);
void **list_to_array(List *list);

void list_sort(List *list, int (*cmp) (void*, void*));
int list_size(List *list);

ListIter *list_iter_new(List *list);
void list_iter_destroy(ListIter *iter);
bool list_iter_remove(ListIter *iter);
bool list_iter_free(ListIter *iter);
bool list_iter_add(ListIter *iter,  void *element);
bool list_iter_replace(ListIter *iter, void *element);
bool list_iter_has_next(ListIter *iter);
int list_iter_index(ListIter *iter);
void *list_iter_next(ListIter *iter);

ListDIter *list_diter_new(List *list);
void list_diter_destroy(ListDIter *iter);
bool list_diter_remove(ListDIter *iter);
bool list_diter_free(ListDIter *iter);
bool list_diter_add(ListDIter *iter, void *element);
bool list_diter_replace(ListDIter *iter, void *element);
bool list_diter_has_next(ListDIter *iter);
int list_iter_index(ListIter *iter);
void *list_diter_next(ListDIter *iter);

#endif /* LIST_H_ */