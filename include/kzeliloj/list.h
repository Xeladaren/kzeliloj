/*!
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
 *  @brief      A doubly linked list object.
 */
typedef struct tList     tList_t;

/*!
 *  @class      tListNode_t
 *  @brief      A node of the doubly linked list tList_t.
 */
typedef struct tListNode tListNode_t;

/*****************************************************/
/***   Public methode's prototypes                 ***/
/*****************************************************/

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Create and init a new tList_t object.
 *
 *  @return     The new tList_t object, or NULL if it is fail.
 */
tList_t *list_new(void);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Purge and delete this tList_t.
 *
 *  @warning    The tList_t and all tListNode_t objects are freed, but not the void * pointers of the tListNode_t values.
 *
 *  @param[in]  this    The tList_t object.
 */
void list_delete(tList_t *this);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Get the size of this tList_t.
 *
 *  @param[in]  this    The tList_t object.
 *
 *  @return     The number of nodes in this tList_t, or -1 if it's fail.
 */
int  list_len(tList_t *this);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Add a new value at the front of this tList_t (the first value).
 *
 *  @param[in]  this         The tList_t object.
 *  @param[in]  p_pvNewValue The new value to add.
 *
 *  @return     0 if succes, -1 if it's fail.
 */
int  list_pushFront(tList_t *this, void *p_pvNewValue);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Add a new value at the back of this tList_t (the last value).
 *
 *  @param[in]  this         The tList_t object.
 *  @param[in]  p_pvNewValue The new value to add.
 *
 *  @return     0 if succes, -1 if it's fail.
 */
int  list_pushBack(tList_t *this, void *p_pvNewValue);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Get the value of the first tListNode_t in this tList_t (at the front).
 *              Remove the tListNode_t from the list and free it.
 *
 *  @param[in]  this    The tList_t object.
 *
 *  @return     The first value, or NULL if it's fail.
 */
void *list_popFirst(tList_t *this);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Get the value of the last tListNode_t in this tList_t (at the back).
 *              Remove the tListNode_t from the tList_t and free it.
 *
 *  @param[in]  this    The tList_t object.
 *
 *  @return     The last value, or NULL if it's fail.
 */
void *list_popLast(tList_t *this);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      get the value of the first tListNode_t in this tList_t (at the front).
 *
 *  @param[in]  this    The tList_t object.
 *
 *  @return     The first value, or NULL if it's fail.
 */
void *list_getFirst(tList_t *this);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      get the value of the last tListNode_t in this tList_t (at the back).
 *
 *  @param[in]  this    The tList_t object.
 *
 *  @return     The last value, or NULL if it's fail.
 */
void *list_getLast(tList_t *this);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Get the first tListNode_t object (at the front) in this tList_t.
 *
 *  @param[in]  this    The tList_t object.
 *
 *  @return     The first tListNode_t object, or NULL if this tList_t is empty.
 */
tListNode_t *list_getFirstNode(tList_t *this);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Get the last tListNode_t object (at the back) in this tList_t.
 *
 *  @param[in]  this    The tList_t object.
 *
 *  @return     The last tListNode_t object, or NULL if this tList_t is empty.
 */
tListNode_t *list_getLastNode(tList_t *this);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Check if the tListNode_t is the first tListNode_t in this tListNode_t.
 *
 *  @param[in]  this        The tList_t object.
 *  @param[in]  p_ptNode    The tListNode_t to test.
 *
 *  @return     true if the tListNode_t is the first, else if it's not.
 */
bool list_isFirstNode(tList_t *this, tListNode_t *p_ptNode);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Check if the tListNode_t is the last tListNode_t in this tList_t.
 *
 *  @param[in]  this        The tList_t object.
 *  @param[in]  p_ptNode    The tListNode_t to test.
 *
 *  @return     true if the tListNode_t is the last, else if it's not.
 */
bool list_isLastNode(tList_t *this, tListNode_t *p_ptNode);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Remove and free a tListNode_t from this tList_t, and return this value.
 *
 *  @param[in]  this        The tList_t object.
 *  @param[in]  p_ptNode    The tListNode_t to remove.
 *
 *  @return     the value of the tListNode_t, or NULL if it's fail.
 */
void *list_popNodeInList(tList_t *this, tListNode_t *p_ptNode);

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Print the tList_t to standard output (for debug).
 *
 *  @param[in]  this    The tList_t object.
 */
void list_print(tList_t *this);

/*!
 *  @public
 *  @memberof   tListNode_t
 *  @brief      Get the value of a tListNode_t.
 *
 *  @param[in]  this    The tListNode_t object.
 *
 *  @return     The value of the tListNode_t, or NULL if it's fail.
 */
void *listNode_getNodeValue(tListNode_t *this);

/*!
 *  @public
 *  @memberof   tListNode_t
 *  @brief      Get the next tListNode_t in the tList_t.
 *
 *  @param[in]  this    The tListNode_t object.
 *
 *  @return     The next tListNode_t, or NULL if this tListNode_t is the last.
 */
tListNode_t *listNode_getNextNode(tListNode_t *this);

/*!
 *  @public
 *  @memberof   tListNode_t
 *  @brief      Get the previous tListNode_t int the tList_t.
 *
 *  @param[in]  this    The tListNode_t object.
 *
 *  @return     The previous tListNode_t, or NULL if this tListNode_t is the first.
 */
tListNode_t *listNode_getPrevNode(tListNode_t *this);

#endif /* LIST_H */
