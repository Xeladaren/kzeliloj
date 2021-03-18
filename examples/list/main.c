#include <stdlib.h>
#include <stdio.h>

#include <kzeliloj/list.h>

int main()
{
    /* Init the list */
    tList_t *list = list_init();

    for(int i = 0; i < 10; i++)
    {

        /* Add Value to the list. */
        list_pushFront(list, (void *) i+1);

    }

    /* Print the list */
    list_print(list);

    for(tListNode_t *node = list_getFirstNode(list); node != NULL; node = list_getNextNode(node))
    {
        printf("Node %p : %p\n", node, list_getNodeValue(node));
    }

    /* Delete the list */
    list_delete(list);

    return 0;
}
