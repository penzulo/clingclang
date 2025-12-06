#ifndef MYLIB_COLLECTIONS_DLL_H
#define MYLIB_COLLECTIONS_DLL_H

#include <stddef.h>
#include <stdint.h>

typedef struct LinkedList LinkedList;
typedef struct ListNode ListNode;
typedef struct DllIterator DllIterator;

/**
 * @brief Creates a new, empty doubly linked list.
 * @return Pointer to the new LinkedList, or NULL on allocation failure.
 */
LinkedList *dll_create(void);

/**
 * @brief Frees all nodes and the list structure itself (Shallow Destroy).
 * The list's data pointers are NOT freed.
 * @param list Pointer to the list to destroy.
 */
void dll_destroy(LinkedList *list);

/**
 * @brief Returns the tail node of the list.
 * @param list Pointer to the list to inspect.
 * @return Pointer to the tail or NULL if empty.
 */
ListNode *dll_back_node(const LinkedList *list);

/**
 * @brief Returns the head node of the list.
 * @param list Pointer to the list to inspect.
 * @return Pointer to the head or NULL if empty.
 */
ListNode *dll_front_node(const LinkedList *list);

/**
 * @brief Appends a new node containing the given data to the end of the
 * list.
 * @param list Pointer to the list to modify.
 * @param data Pointer to the data to insert.
 * @return 0 on success, -1 on allocation or list failure.
 */
int dll_push_back(LinkedList *list, void *data);

/**
 * @brief Inserts a new node containing the given data at the front of the list.
 * @param list Pointer to the list to modify.
 * @param data Pointer to the data to insert.
 * @return 0 on success, -1 on allocation or list failure.
 */
int dll_push_front(LinkedList *list, void *data);

/**
 * @brief Removes the last node of the list and returns its data.
 * @param list Pointer to the list to modify.
 * @return Pointer to the removed node's data, or NULL if the list is empty.
 */
void *dll_pop_back(LinkedList *list);

/**
 * @brief Removes the first node of the list and returns its data.
 * @param list Pointer to the list to modify.
 * @return Pointer to the removed node's data, or NULL if the list is empty.
 */
void *dll_pop_front(LinkedList *list);

/**
 * @brief Removes and frees all nodes in the list. The data is NOT freed.
 * The list struct itself remains valid and empty (size 0).
 * @param list Pointer to the list to clear.
 */
void dll_clear(LinkedList *list);

/**
 * @brief Returns the number of elements currently stored in the list.
 * @param list Pointer to the list to inspect.
 * @return The number of nodes in the list, or 0 if list is NULL.
 */
size_t dll_size(const LinkedList *list);

/**
 * @brief Checks if the list is empty.
 * @param list Pointer to the list to inspect.
 * @return true if empty (or NULL), else false.
 */
int dll_is_empty(const LinkedList *list);

/**
 * @brief Creates a new iterator positioned at the head of the list.
 * @param list The list to iterate over.
 * @return A new DllIterator pointer, or NULL on failure.
 */
DllIterator *dll_iter_create(LinkedList *list);

/**
 * @brief Advances the iterator and returns the data of the current node.
 * @param iter The iterator to advance.
 * @return The data pointer of the current node, or NULL if the iteration is
 * complete.
 */
void *dll_iter_next(DllIterator *iter);

/**
 * @brief Frees the iterator structure.
 * @param iter The iterator to free.
 */
void dll_iter_destroy(DllIterator *iter);

#endif
