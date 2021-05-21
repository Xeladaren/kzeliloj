﻿/*!
 *  @file       list.h
 *  @brief      A generic doubly linked list.
 *  @author     Xeladaren
 *  @version    1.0
 *  @date       2021-03-11
 */

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/*****************************************************/
/***   Public Types                                ***/
/*****************************************************/

/*!
 *  @class      tList_t
 *  @brief      The public type for @link tList @endlink private structure.
 */
typedef struct tList     tList_t;

/*!
 *  @class      tListNode_t
 *  @brief      The public type for @link tListNode @endlink private structure.
 */
typedef struct tListNode tListNode_t;

/*****************************************************/
/***   Public methode's prototypes                 ***/
/*****************************************************/

/*!
 *  @public
 *  @brief      Init the LIST object.
 *
 *  @return     A pointer to the list object, or NULL if it is fail.
 */
tList_t *list_init();

/*!
 *  @public
 *  @brief      Purge and delete the List.
 *
 *  @param[in]  p_ptList    The list to delete.
 */
void list_delete(tList_t *p_ptList);

/*!
 *  @public
 *  @brief      Get the size of the list.
 *
 *  @param[in]  p_ptList    The list to count.
 *
 *  @return     The number of nodes in the list, or -1 if it's fail.
 */
int  list_len(tList_t *p_ptList);

/*!
 *  @public
 *  @brief      Add a new value at the front of the list (the first value).
 *
 *  @param[in]  p_ptList     The list to add the value to.
 *  @param[in]  p_pvNewValue The new value to add.
 *
 *  @return     0 if succes, -1 if it's fail.
 */
int  list_pushFront(tList_t *p_ptList, void *p_pvNewValue);

/*!
 *  @public
 *  @brief      Add a new value at the back of the list (the last value).
 *
 *  @param[in]  p_ptList     The list to add the value to.
 *  @param[in]  p_pvNewValue The new value to add.
 *
 *  @return     0 if succes, -1 if it's fail.
 */
int  list_pushBack(tList_t *p_ptList, void *p_pvNewValue);

/*!
 *  @public
 *  @brief      Get the value of the first node in the list (at the at the front).
 *              Remove the node from the list and free it.
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The first value, or NULL if it's fail.
 */
void *list_popFirst(tList_t *p_ptList);

/*!
 *  @public
 *  @brief      Get the value of the last node in the list (at the back).
 *              Remove the node from the list and free it.
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The last value, or NULL if it's fail.
 */
void *list_popLast(tList_t *p_ptList);

/*!
 *  @public
 *  @brief      get the value of the first node in the list (at the front).
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The first value, or NULL if it's fail.
 */
void *list_getFirst(tList_t *p_ptList);

/*!
 *  @public
 *  @brief      get the value of the last node in the list (at the back).
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The last value, or NULL if it's fail.
 */
void *list_getLast(tList_t *p_ptList);

/*!
 *  @public
 *  @brief      Get the first node object (at the front) in the list.
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The first node object, or NULL if the list is empty.
 */
tListNode_t *list_getFirstNode(tList_t *p_ptList);

/*!
 *  @public
 *  @brief      Get the last node object (at the back) in the list.
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The last node object, or NULL if the list is empty.
 */
tListNode_t *list_getLastNode(tList_t *p_ptList);

/*!
 *  @public
 *  @brief      Get the next note.
 *
 *  @param[in]  p_ptNode    The actual node.
 *
 *  @return     The next node, or NULL if this node is the last.
 */
tListNode_t *list_getNextNode(tListNode_t *p_ptNode);

/*!
 *  @public
 *  @brief      Get the previous note.
 *
 *  @param[in]  p_ptNode    The actual node.
 *
 *  @return     The previous node, or NULL if this node is the first.
 */
tListNode_t *list_getPrevNode(tListNode_t *p_ptNode);

/*!
 *  @public
 *  @brief      Check if the node is the first node in the list.
 *
 *  @param[in]  p_ptList    The list.
 *  @param[in]  p_ptNode    The node.
 *
 *  @return     true if the node is the first, else if it's not.
 */
bool list_isFirstNode(tList_t *p_ptList, tListNode_t *p_ptNode);

/*!
 *  @public
 *  @brief      Check if the node is the last node in the list.
 *
 *  @param[in]  p_ptList    The list.
 *  @param[in]  p_ptNode    The node.
 *
 *  @return     true if the node is the last, else if it's not.
 */
bool list_isLastNode(tList_t *p_ptList, tListNode_t *p_ptNode);

/*!
 *  @public
 *  @brief      Remove and free a node from the list, and return this value.
 *
 *  @param[in]  p_ptList    The list
 *  @param[in]  p_ptNode    The node to remove.
 *
 *  @return     the value of the node, or NULL if it's fail.
 */
void *list_popNodeInList(tList_t *p_ptList, tListNode_t *p_ptNode);

/*!
 *  @public
 *  @brief      Get the value of a node.
 *
 *  @param[in]  p_ptNode    The note to get the value.
 *
 *  @return     The value of the node, or NULL if it's fail.
 */
void *list_getNodeValue(tListNode_t *p_ptNode);

/*!
 *  @public
 *  @brief      Print the list to standard output (for debug).
 *
 *  @param[in]  p_ptList    The list to print.
 */
void list_print(tList_t *p_ptList);

#endif /* LIST_H */
