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

/* Doc in "list.h". */
tList_t *list_init()
{
    tList_t *this = NULL;

    this = (tList_t *) malloc(sizeof(tList_t));

    if(this != NULL)
    {
        this->ptFirst = NULL;
        this->ptLast  = NULL;

        this->uLen  = 0U;
    }

    return this;
}

/* Doc in "list.h". */
void list_delete(tList_t *this)
{
    if(this != NULL)
    {
        while(this->uLen > 0)
        {
            list_popFirst(this);
        }

        free(this);
    }
}

/* Doc in "list.h". */
int list_len(tList_t *this)
{
    int l_iRet = -1;

    if(this != NULL)
    {
        l_iRet = this->uLen;
    }

    return l_iRet;
}

/* Doc in "list.h". */
int list_pushFront(tList_t *this, void *p_pvNewValue)
{
    int          l_iRet      = -1;
    tListNode_t *l_ptNewElem = NULL;

    if(this != NULL)
    {
        l_ptNewElem = (tListNode_t *) malloc(sizeof(tListNode_t));

        if(l_ptNewElem != NULL)
        {
            l_ptNewElem->ptNext = NULL;
            l_ptNewElem->ptPrev = this->ptLast;

            l_ptNewElem->pvValue = p_pvNewValue;

            if(this->ptLast != NULL)
            {
                this->ptLast->ptNext = l_ptNewElem;
            }

            this->ptLast = l_ptNewElem;

            if(this->ptFirst == NULL)
            {
                this->ptFirst = l_ptNewElem;
            }

            this->uLen += 1U;

            l_iRet = 0;
        }
    }

    return l_iRet;
}

/* Doc in "list.h". */
int list_pushBack(tList_t *this, void *p_pvNewValue)
{
    int          l_iRet      = -1;
    tListNode_t *l_ptNewElem = NULL;

    l_ptNewElem = (tListNode_t *) malloc(sizeof(tListNode_t));

    if(l_ptNewElem != NULL)
    {
        l_ptNewElem->ptNext = this->ptFirst;
        l_ptNewElem->ptPrev = NULL;

        l_ptNewElem->pvValue = p_pvNewValue;

        if(this->ptFirst != NULL)
        {
            this->ptFirst->ptPrev = l_ptNewElem;
        }

        this->ptFirst = l_ptNewElem;

        if(this->ptLast == NULL)
        {
            this->ptLast = l_ptNewElem;
        }

        this->uLen += 1U;

        l_iRet = 0;
    }

    return l_iRet;
}

/* Doc in "list.h". */
void *list_popFirst(tList_t *this)
{
    void        *l_pvRet  = NULL;
    tListNode_t *l_ptElem = NULL;

    l_ptElem = this->ptFirst;

    if(l_ptElem != NULL)
    {
        l_pvRet = l_ptElem->pvValue;

        this->ptFirst = l_ptElem->ptNext;
        if(this->ptFirst != NULL)
        {
            this->ptFirst->ptPrev = NULL;
        }
        else
        {
            this->ptLast = NULL;
        }

        free(l_ptElem);

        this->uLen -= 1U;

    }

    return l_pvRet;
}

/* Doc in "list.h". */
void *list_popLast(tList_t *this)
{
    void        *l_pvRet  = NULL;
    tListNode_t *l_ptElem = NULL;

    l_ptElem = this->ptLast;

    if(l_ptElem != NULL)
    {
        l_pvRet = l_ptElem->pvValue;

        this->ptLast = l_ptElem->ptPrev;
        if(this->ptLast != NULL)
        {
            this->ptLast->ptNext = NULL;
        }
        else
        {
            this->ptFirst = NULL;
        }

        free(l_ptElem);

        this->uLen -= 1U;

    }

    return l_pvRet;
}

/* Doc in "list.h". */
void *list_getFirst(tList_t *this)
{
    void *l_pvRet = NULL;

    if(this != NULL && this->ptFirst != NULL)
    {
        l_pvRet = this->ptFirst->pvValue;
    }

    return l_pvRet;
}

/* Doc in "list.h". */
void *list_getLast(tList_t *this)
{
    void *l_pvRet = NULL;

    if(this != NULL && this->ptLast != NULL)
    {
        l_pvRet = this->ptLast->pvValue;
    }

    return l_pvRet;
}

/* Doc in "list.h". */
tListNode_t *list_getFirstNode(tList_t *this)
{
    tListNode_t *l_ptOutNode = NULL;

    if(this != NULL)
    {
        l_ptOutNode = this->ptFirst;
    }

    return l_ptOutNode;
}

/* Doc in "list.h". */
tListNode_t *list_getLastNode(tList_t *this)
{
    tListNode_t *l_ptOutNode = NULL;

    if(this != NULL)
    {
        l_ptOutNode = this->ptLast;
    }

    return l_ptOutNode;
}

/* Doc in "list.h". */
bool list_isFirstNode(tList_t *this, tListNode_t *p_ptNode)
{
    bool l_bRet = false;

    if(p_ptNode != NULL)
    {
        if(p_ptNode == this->ptFirst)
        {
            l_bRet = true;
        }
    }

    return l_bRet;
}

/* Doc in "list.h". */
bool list_isLastNode(tList_t *this, tListNode_t *p_ptNode)
{
    bool l_bRet = false;

    if(p_ptNode != NULL)
    {
        if(p_ptNode == this->ptLast)
        {
            l_bRet = true;
        }
    }

    return l_bRet;
}

/* Doc in "list.h". */
void *list_popNodeInList(tList_t *this, tListNode_t *p_ptNode)
{
    void *l_pvRet = NULL;

    if(this != NULL && p_ptNode != NULL)
    {
        if(list_isFirstNode(this, p_ptNode))
        {
            l_pvRet = list_popFirst(this);
        }
        else if(list_isLastNode(this, p_ptNode))
        {
            l_pvRet = list_popLast(this);
        }
        else
        {
            l_pvRet = listNode_getNodeValue(p_ptNode);

            p_ptNode->ptPrev->ptNext = p_ptNode->ptNext;
            p_ptNode->ptNext->ptPrev = p_ptNode->ptPrev;

            this->uLen -= 1;

            free(p_ptNode);
        }
    }

    return l_pvRet;
}

/* Doc in "list.h". */
void list_print(tList_t *this)
{
    tListNode_t *l_ptElem      = NULL;
    int          l_iElemIndex  = 0;

    if(this != NULL)
    {

        printf("List %p, elements count : %d\n", this, this->uLen);
        printf("First : %p\n", this->ptFirst);
        printf("Last  : %p\n", this->ptLast);

        printf("FRONT\n");

        l_ptElem = this->ptFirst;

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

/* Doc in "list.h". */
void *listNode_getNodeValue(tListNode_t *this)
{
    void *l_pvRet = NULL;

    if(this != NULL)
    {
        l_pvRet = this->pvValue;
    }

    return l_pvRet;
}

/* Doc in "list.h". */
tListNode_t *listNode_getNextNode(tListNode_t *this)
{
    tListNode_t *l_ptRet = NULL;

    if(this != NULL)
    {
        l_ptRet = this->ptNext;
    }

    return l_ptRet;
}

/* Doc in "list.h". */
tListNode_t *listNode_getPrevNode(tListNode_t *this)
{
    tListNode_t *l_ptRet = NULL;

    if(this != NULL)
    {
        l_ptRet = this->ptPrev;
    }

    return l_ptRet;
}
