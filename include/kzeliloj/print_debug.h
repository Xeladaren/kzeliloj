#include <stdio.h>

#ifndef PRINT_DEBUG
#define PRINT_DEBUG

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


#endif
