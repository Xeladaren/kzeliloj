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
        list_pushFront(list, NULL);

    }

    /* Print the list */
    list_print(list);

    /* Delete the list */
    list_delete(list);

    return 0;
}
