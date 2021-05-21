/*!
 *  @file       list.c
 *  @brief      A generic doubly linked list.
 *  @author     Xeladaren
 *  @version    1.0
 *  @date       2021-03-11
 */

#include <stdlib.h>
#include <stdio.h>

#include "kzeliloj/list.h"

/*****************************************************/
/***   Struct                                      ***/
/*****************************************************/

/*
 * Structure of atributes of tList_t class.
 */
struct tList
{
    /*!
     *  @private
     *  @memberof    tList_t
     *  @brief       The first node of the list.
     */
    tListNode_t  *ptFirst;

    /*!
     *  @private
     *  @memberof    tList_t
     *  @brief       The last node of the list.
     */
    tListNode_t  *ptLast;

    /*!
     *  @private
     *  @memberof    tList_t
     *  @brief       The number of nodes in the list.
     */
    unsigned int  uLen;
};

/*
 * Structure to describe the tListNode_t class.
 */
struct tListNode
{
    /*!
     *  @private
     *  @memberof    tListNode_t
     *  @brief       The previous node, or NULL if this node is the first.
     */
    tListNode_t *ptPrev;

    /*!
     *  @private
     *  @memberof    tListNode_t
     *  @brief       The next node, or NULL if this node is the last.
     */
    tListNode_t *ptNext;

    /*!
     *  @private
     *  @memberof    tListNode_t
     *  @brief       The value of the element.
     */
    void        *pvValue;
};

/*****************************************************/
/***   Methodes                                    ***/
/*****************************************************/

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Init the LIST object.
 *
 *  @return     A pointer to the list object, or NULL if it is fail.
 */
tList_t *list_init()
{
    tList_t *l_tNewList = NULL;

    l_tNewList = (tList_t *) malloc(sizeof(tList_t));

    if(l_tNewList != NULL)
    {
        l_tNewList->ptFirst = NULL;
        l_tNewList->ptLast  = NULL;

        l_tNewList->uLen  = 0U;
    }

    return l_tNewList;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Purge and delete the List.
 *
 *  @param[in]  p_ptList    The list to delete.
 */
void list_delete(tList_t *p_ptList)
{
    if(p_ptList != NULL)
    {
        while(p_ptList->uLen > 0)
        {
            list_popFirst(p_ptList);
        }

        free(p_ptList);
    }
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Get the size of the list.
 *
 *  @param[in]  p_ptList    The list to count.
 *
 *  @return     The number of nodes in the list, or -1 if it's fail.
 */
int list_len(tList_t *p_ptList)
{
    int l_iRet = -1;

    if(p_ptList != NULL)
    {
        l_iRet = p_ptList->uLen;
    }

    return l_iRet;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Add a new value at the front of the list (the first value).
 *
 *  @param[in]  p_ptList     The list to add the value to.
 *  @param[in]  p_pvNewValue The new value to add.
 *
 *  @return     0 if succes, -1 if it's fail.
 */
int list_pushFront(tList_t *p_ptList, void *p_pvNewValue)
{
    int          l_iRet      = -1;
    tListNode_t *l_ptNewElem = NULL;

    if(p_ptList != NULL)
    {
        l_ptNewElem = (tListNode_t *) malloc(sizeof(tListNode_t));

        if(l_ptNewElem != NULL)
        {
            l_ptNewElem->ptNext = NULL;
            l_ptNewElem->ptPrev = p_ptList->ptLast;

            l_ptNewElem->pvValue = p_pvNewValue;

            if(p_ptList->ptLast != NULL)
            {
                p_ptList->ptLast->ptNext = l_ptNewElem;
            }

            p_ptList->ptLast = l_ptNewElem;

            if(p_ptList->ptFirst == NULL)
            {
                p_ptList->ptFirst = l_ptNewElem;
            }

            p_ptList->uLen += 1U;

            l_iRet = 0;
        }
    }

    return l_iRet;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Add a new value at the back of the list (the last value).
 *
 *  @param[in]  p_ptList     The list to add the value to.
 *  @param[in]  p_pvNewValue The new value to add.
 *
 *  @return     0 if succes, -1 if it's fail.
 */
int list_pushBack(tList_t *p_ptList, void *p_pvNewValue)
{
    int          l_iRet      = -1;
    tListNode_t *l_ptNewElem = NULL;

    l_ptNewElem = (tListNode_t *) malloc(sizeof(tListNode_t));

    if(l_ptNewElem != NULL)
    {
        l_ptNewElem->ptNext = p_ptList->ptFirst;
        l_ptNewElem->ptPrev = NULL;

        l_ptNewElem->pvValue = p_pvNewValue;

        if(p_ptList->ptFirst != NULL)
        {
            p_ptList->ptFirst->ptPrev = l_ptNewElem;
        }

        p_ptList->ptFirst = l_ptNewElem;

        if(p_ptList->ptLast == NULL)
        {
            p_ptList->ptLast = l_ptNewElem;
        }

        p_ptList->uLen += 1U;

        l_iRet = 0;
    }

    return l_iRet;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Get the value of the first node in the list (at the at the front).
 *              Remove the node from the list and free it.
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The first value, or NULL if it's fail.
 */
void *list_popFirst(tList_t *p_ptList)
{
    void        *l_pvRet  = NULL;
    tListNode_t *l_ptElem = NULL;

    l_ptElem = p_ptList->ptFirst;

    if(l_ptElem != NULL)
    {
        l_pvRet = l_ptElem->pvValue;

        p_ptList->ptFirst = l_ptElem->ptNext;
        if(p_ptList->ptFirst != NULL)
        {
            p_ptList->ptFirst->ptPrev = NULL;
        }
        else
        {
            p_ptList->ptLast = NULL;
        }

        free(l_ptElem);

        p_ptList->uLen -= 1U;

    }

    return l_pvRet;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Get the value of the last node in the list (at the back).
 *              Remove the node from the list and free it.
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The last value, or NULL if it's fail.
 */
void *list_popLast(tList_t *p_ptList)
{
    void        *l_pvRet  = NULL;
    tListNode_t *l_ptElem = NULL;

    l_ptElem = p_ptList->ptLast;

    if(l_ptElem != NULL)
    {
        l_pvRet = l_ptElem->pvValue;

        p_ptList->ptLast = l_ptElem->ptPrev;
        if(p_ptList->ptLast != NULL)
        {
            p_ptList->ptLast->ptNext = NULL;
        }
        else
        {
            p_ptList->ptFirst = NULL;
        }

        free(l_ptElem);

        p_ptList->uLen -= 1U;

    }

    return l_pvRet;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      get the value of the first node in the list (at the front).
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The first value, or NULL if it's fail.
 */
void *list_getFirst(tList_t *p_ptList)
{
    void *l_pvRet = NULL;

    if(p_ptList != NULL && p_ptList->ptFirst != NULL)
    {
        l_pvRet = p_ptList->ptFirst->pvValue;
    }

    return l_pvRet;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      get the value of the last node in the list (at the back).
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The last value, or NULL if it's fail.
 */
void *list_getLast(tList_t *p_ptList)
{
    void *l_pvRet = NULL;

    if(p_ptList != NULL && p_ptList->ptLast != NULL)
    {
        l_pvRet = p_ptList->ptLast->pvValue;
    }

    return l_pvRet;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Get the first node object (at the front) in the list.
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The first node object, or NULL if the list is empty.
 */
tListNode_t *list_getFirstNode(tList_t *p_ptList)
{
    tListNode_t *l_ptOutNode = NULL;

    if(p_ptList != NULL)
    {
        l_ptOutNode = p_ptList->ptFirst;
    }

    return l_ptOutNode;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Get the last node object (at the back) in the list.
 *
 *  @param[in]  p_ptList    The list to get the node.
 *
 *  @return     The last node object, or NULL if the list is empty.
 */
tListNode_t *list_getLastNode(tList_t *p_ptList)
{
    tListNode_t *l_ptOutNode = NULL;

    if(p_ptList != NULL)
    {
        l_ptOutNode = p_ptList->ptLast;
    }

    return l_ptOutNode;
}

/*!
 *  @public
 *  @memberof   tListNode_t
 *  @brief      Get the next note.
 *
 *  @param[in]  p_ptNode    The actual node.
 *
 *  @return     The next node, or NULL if this node is the last.
 */
tListNode_t *list_getNextNode(tListNode_t *p_ptNode)
{
    tListNode_t *l_ptRet = NULL;

    if(p_ptNode != NULL)
    {
        l_ptRet = p_ptNode->ptNext;
    }

    return l_ptRet;
}

/*!
 *  @public
 *  @memberof   tListNode_t
 *  @brief      Get the previous note.
 *
 *  @param[in]  p_ptNode    The actual node.
 *
 *  @return     The previous node, or NULL if this node is the first.
 */
tListNode_t *list_getPrevNode(tListNode_t *p_ptNode)
{
    tListNode_t *l_ptRet = NULL;

    if(p_ptNode != NULL)
    {
        l_ptRet = p_ptNode->ptPrev;
    }

    return l_ptRet;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Check if the node is the first node in the list.
 *
 *  @param[in]  p_ptList    The list.
 *  @param[in]  p_ptNode    The node.
 *
 *  @return     true if the node is the first, else if it's not.
 */
bool list_isFirstNode(tList_t *p_ptList, tListNode_t *p_ptNode)
{
    bool l_bRet = false;

    if(p_ptNode != NULL)
    {
        if(p_ptNode == p_ptList->ptFirst)
        {
            l_bRet = true;
        }
    }

    return l_bRet;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Check if the node is the last node in the list.
 *
 *  @param[in]  p_ptList    The list.
 *  @param[in]  p_ptNode    The node.
 *
 *  @return     true if the node is the last, else if it's not.
 */
bool list_isLastNode(tList_t *p_ptList, tListNode_t *p_ptNode)
{
    bool l_bRet = false;

    if(p_ptNode != NULL)
    {
        if(p_ptNode == p_ptList->ptLast)
        {
            l_bRet = true;
        }
    }

    return l_bRet;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Remove and free a node from the list, and return this value.
 *
 *  @param[in]  p_ptList    The list
 *  @param[in]  p_ptNode    The node to remove.
 *
 *  @return     the value of the node, or NULL if it's fail.
 */
void *list_popNodeInList(tList_t *p_ptList, tListNode_t *p_ptNode)
{
    void *l_pvRet = NULL;

    if(p_ptList != NULL && p_ptNode != NULL)
    {
        if(list_isFirstNode(p_ptList, p_ptNode))
        {
            l_pvRet = list_popFirst(p_ptList);
        }
        else if(list_isLastNode(p_ptList, p_ptNode))
        {
            l_pvRet = list_popLast(p_ptList);
        }
        else
        {
            l_pvRet = list_getNodeValue(p_ptNode);

            p_ptNode->ptPrev->ptNext = p_ptNode->ptNext;
            p_ptNode->ptNext->ptPrev = p_ptNode->ptPrev;

            p_ptList->uLen -= 1;

            free(p_ptNode);
        }
    }

    return l_pvRet;
}

/*!
 *  @public
 *  @memberof   tListNode_t
 *  @brief      Get the value of a node.
 *
 *  @param[in]  p_ptNode    The note to get the value.
 *
 *  @return     The value of the node, or NULL if it's fail.
 */
void *list_getNodeValue(tListNode_t *p_ptNode)
{
    void *l_pvRet = NULL;

    if(p_ptNode != NULL)
    {
        l_pvRet = p_ptNode->pvValue;
    }

    return l_pvRet;
}

/*!
 *  @public
 *  @memberof   tList_t
 *  @brief      Print the list to standard output (for debug).
 *
 *  @param[in]  p_ptList    The list to print.
 */
void list_print(tList_t *p_ptList)
{
    tListNode_t *l_ptElem      = NULL;
    int          l_iElemIndex  = 0;

    if(p_ptList != NULL)
    {

        printf("List %p, elements count : %d\n", p_ptList, p_ptList->uLen);
        printf("First : %p\n", p_ptList->ptFirst);
        printf("Last  : %p\n", p_ptList->ptLast);

        printf("FRONT\n");

        l_ptElem = p_ptList->ptFirst;

        while(l_ptElem != NULL)
        {
            printf("%d) %p (%p, %p) = %p\n",
                    l_iElemIndex,
                    l_ptElem,
                    l_ptElem->ptPrev,
                    l_ptElem->ptNext,
                    l_ptElem->pvValue);
            l_iElemIndex += 1;

            l_ptElem = l_ptElem->ptNext;
        }

        printf("BACK\n\n");
    }
    else
    {
        printf("Uninitalised List\n");
    }

}
