
#ifndef PRINT_DEBUG_H
#define PRINT_DEBUG_H

#include <errno.h>
#include <stdio.h>

#ifdef DEBUG
#define PRINT_DEBUG(str, ...)   fprintf(stdout, "[\033[35;1mDEBUG\033[0m] %s:%d : " str "\n", __func__, __LINE__, ##__VA_ARGS__)
#define PRINT_INFO(str, ...)    fprintf(stdout, "[\033[36;1mINFO\033[0m] %s:%d : " str "\n", __func__, __LINE__, ##__VA_ARGS__)
#define PRINT_WARNING(str, ...) fprintf(stderr, "[\033[33;1mWARNING\033[0m] %s:%d : " str "\n", __func__, __LINE__, ##__VA_ARGS__)
#define PRINT_ERROR(str, ...)   fprintf(stderr, "[\033[31;1mERROR\033[0m] %s:%d : " str "\n", __func__, __LINE__, ##__VA_ARGS__)
#else
#define PRINT_DEBUG(str, ...)
#define PRINT_INFO(str, ...)    fprintf(stdout, "[\033[36;1mINFO\033[0m] " str "\n", ##__VA_ARGS__)
#define PRINT_WARNING(str, ...) fprintf(stderr, "[\033[33;1mWARNING\033[0m] " str "\n", ##__VA_ARGS__)
#define PRINT_ERROR(str, ...)   fprintf(stderr, "[\033[31;1mERROR\033[0m] " str "\n", ##__VA_ARGS__)
#endif

#define ASSERT(cond, jumpLabel) \
if(!(cond)) { \
    goto jumpLabel; \
}

#define ASSERT_PRINT(cond, jumpLabel, msg) \
if(!(cond)) { \
    perror(msg); \
    goto jumpLabel; \
}

#define ASSERT_ERROR(cond, jumpLabel, err) \
if(!(cond)) { \
    errno = err; \
    goto jumpLabel; \
}

#define ASSERT_PRINT_ERROR(cond, jumpLabel, err, msg) \
if(!(cond)) { \
    errno = err; \
    perror(msg); \
    goto jumpLabel; \
}

#endif /* PRINT_DEBUG_H */
