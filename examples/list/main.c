#include <stdlib.h>
#include <stdio.h>

#include <kzeliloj/list.h>

int main()
{
    /* Init the list */
    tList_t *list = list_new();

    for(size_t i = 0; i < 10; i++)
    {

        /* Add Value to the list. */
        list_pushFront(list, (void *) 0x01+i);
        list_pushBack(list, (void *)  0xFF-i);

    }

    /* Print the list */
    list_print(list);
    
    /* Print all nodes */
    for(tListNode_t *node = list_getFirstNode(list); node != NULL; node = listNode_getNextNode(node))
    {
        printf("Node %p : %p\n", node, listNode_getNodeValue(node));
    }

    /* Delete the list */
    list_delete(list);

    return 0;
}
