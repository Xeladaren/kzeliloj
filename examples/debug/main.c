
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <kzeliloj/debug.h>

int main(void)
{
    
    PRINT_INFO("Info print %d", 42);
    PRINT_DEBUG("Debug print %c", 'z');
    PRINT_WARNING("Warning print %f", 3.1415926);
    PRINT_ERROR("Error print %p", "coucou");

    ASSERT(true, err);
    ASSERT_PRINT(true, err, "ASSER PRINT %e", 2.998e8);
    ASSERT_ERROR(true, err, EINVAL);
    ASSERT_PRINT_ERROR(false, err, EIO, "ASSER PRINT ERROR : %s", strerror(EIO));

    return 0;

err:

    return 1;
}
