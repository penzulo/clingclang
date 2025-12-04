#ifndef MYLIB_COLLECTIONS_DLL_H
#define MYLIB_COLLECTIONS_DLL_H

#include <stddef.h>
#include <stdint.h>

typedef struct ListNode {
  void *data;
  struct ListNode *prev;
  struct ListNode *next;
} ListNode;

typedef struct {
  ListNode *head;
  ListNode *tail;
  size_t size;
} LinkedList;

/**
 * @brief Creates a new doubly linked list containing one initial element.
 *
 * Allocates a new list and a single node storing the given data.
 *
 * @param data Pointer to the initial element's data.
 * @return Pointer to the newly created LinkedList, or NULL on allocation
 * failure.
 */
LinkedList *dll_new(void *data);

/**
 * @brief Returns the data stored at the tail of the list without removing it.
 *
 * @param list The list to inspect (passed by referebce; not modified).
 * @return Pointer to the tail's data, or NULL if the list is empty.
 */
void *dll_back(LinkedList *list);

/**
 * @brief Returns the data stored at the head of the list without removing it.
 *
 * @param list The list to inspect (passed by referebce; not modified).
 * @return Pointer to the head's data, or NULL if the list is empty.
 */
void *dll_front(LinkedList *list);

/**
 * @brief Returns the number of elements currently stored in the list.
 *
 * @param list Pointer to the list to inspect.
 * @return The number of nodes in the list, or 0 if list is NULL.
 */
size_t dll_size(LinkedList *list);

/**
 * @breif Checks if the list is empty.
 *
 * @param list Pointer to the list to inspect.
 * @return 1 if empty, else 0.
 */
uint8_t dll_is_empty(LinkedList *list);

/**
 * @brief Appends a new node containing the given data to the end of the list.
 *
 * Updates the tail pointer and increases the list size.
 *
 * @param list Pointer to the list to modify.
 * @param data Pointer to the data to insert.
 * @return 0 on success, non-zero on allocation failure.
 */
uint8_t dll_push_back(LinkedList *list, void *data);

/**
 * @brief Inserts a new node containing the given data at the front of the list.
 *
 * Updates the head pointer and increases the list size.
 *
 * @param list Pointer to the list to modify.
 * @param data Pointer to the data to insert.
 * @return 0 on success, non-zero on allocation failure.
 */
uint8_t dll_push_front(LinkedList *list, void *data);

/**
 * @brief Removes the last node of the list and returns its data.
 *
 * Updates the tail pointer, decreases the list size, frees the removed node,
 * and returns the stored data.
 *
 * @param list Pointer to the list to modify.
 * @return Pointer to the removed node's data, or NULL if the list is empty.
 */
void *dll_pop_back(LinkedList *list);

/**
 * @brief Removes the first node of the list and returns its data.
 *
 * Updates the head pointer, decreases the list size, frees the removed node,
 * and returns the stored data.
 *
 * @param list Pointer to the list to modify.
 * @return Pointer to the removed node's data, or NULL if the list is empty.
 */
void *dll_pop_front(LinkedList *list);

/**
 * @brief Frees all nodes in the list, head and tail are set to NULL.
 *
 * List can still be used after this call.
 *
 * @param list Pointer to the list to clear.
 */
void dll_clear(LinkedList *list);

/**
 * @brief Frees all nodes in the list and then frees the list structure itself.
 *
 * After this call, the list pointer is no longer valid.
 *
 * @param list Pointer to the list to free.
 */
void dll_free(LinkedList *list);

#endif
