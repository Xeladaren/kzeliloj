/**
 *  @file       debug.c
 *  @date       2022-01-22
 *  @copyright  GPL-v3
 *  @author     Xeladaren
 *
 *  @brief      Functions for debut and other print stuff.
 */

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#include <kzeliloj/debug.h>

/**
 *  @brief  Print a buffer content.
 *
 *  @param  buff    The buffer to print.
 *  @param  size    The size of the buffer (in octets).
 *  @param  offset  The offset of the printed address,
 *                  the data are print from the start of the buffer,
 *                  just display index change.
 *  @param color    Set if the func print colors or not.
 */
void printBuffer(void *buff, size_t size, size_t offset, bool color)
{
    size_t         index = 0;
    unsigned char *value = NULL;
    bool           lastIsSame = false;

    printf("Print buffer %p (size=%u):\n", buff, size);

    for(; index < size; index++)
    {
        value = buff + index;

        if( (index % 0x10) == 0)
        {
            if(index > 0x10 && index < (size-0x10))
            {
                if(memcmp(value, value-0x10, 0x10) == 0)
                {
                    if(lastIsSame == false)
                    {
                        printf("\n\t***");
                    }
                    lastIsSame = true;
                    index += 0xF;
                    continue;
                }
                else
                {
                    lastIsSame = false;
                }
            }

            if(index != 0)
            {
                printf("\n");
                fflush(stdout);
            }
            if(color)
            {
                printf("\033[36m" "0x%04zX" "\033[0m" "-" "\033[36m" "0x%04zX" "\033[0m" " >", index+offset, index+offset+0x0F);
            }
            else
            {
                printf("0x%04zX-0x%04zX >", index, index+0x0F);
            }
        }
        if(color)
        {
            if(*value < 0x80)
            {
                printf(" \033[38;2;%d;255;0m", *value*2);
            }
            else
            {
                printf(" \033[38;2;255;%d;0m", 0xFF - ((*value-0x80)*2));
            }

            printf("%02X" "\033[0m", *value);
        }
        else
        {
            printf("%02X", *value);
        }
    }
    printf("\n");
}
