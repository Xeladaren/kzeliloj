/**
 *  @file       debug.h
 *  @date       2022-01-22
 *  @copyright  GPL-v3
 *  @author     Xeladaren
 *
 *  @brief      All debug tools definitions and prototype.
 */

/**************************************************/
/***  Defines                                   ***/
/**************************************************/

#ifndef PRINT_DEBUG_H
#define PRINT_DEBUG_H

#ifdef DEBUG
#define PRINT_DEBUG(str, ...)   fprintf(stdout, "[\033[35;1mDEBUG\033[0m] %s:%d: " str "\n", __func__, __LINE__, ##__VA_ARGS__)
#define PRINT_INFO(str, ...)    fprintf(stdout, "[\033[36;1mINFO\033[0m] %s:%d: " str "\n", __func__, __LINE__, ##__VA_ARGS__)
#define PRINT_WARNING(str, ...) fprintf(stderr, "[\033[33;1mWARNING\033[0m] %s:%d: " str "\n", __func__, __LINE__, ##__VA_ARGS__)
#define PRINT_ERROR(str, ...)   fprintf(stderr, "[\033[31;1mERROR\033[0m] %s:%d: " str "\n", __func__, __LINE__, ##__VA_ARGS__)
#else
#define PRINT_DEBUG(str, ...)
#define PRINT_INFO(str, ...)    fprintf(stdout, "[\033[36;1mINFO\033[0m] " str "\n", ##__VA_ARGS__)
#define PRINT_WARNING(str, ...) fprintf(stderr, "[\033[33;1mWARNING\033[0m] " str "\n", ##__VA_ARGS__)
#define PRINT_ERROR(str, ...)   fprintf(stderr, "[\033[31;1mERROR\033[0m] " str "\n", ##__VA_ARGS__)
#endif

#define RETURN_OK 0
#define RETURN_FAILURE -1

/**
 *  @brief Jump to jumpLable if cond is false.
 */
#define ASSERT_JUMP(cond, jumpLabel) \
if(!(cond)) { \
    goto jumpLabel; \
}

/**
 *  @brief Jump to jumpLable if cond is false and print error message.
 */
#define ASSERT_JUMP_PRINT(cond, jumpLabel, str, ...) \
if(!(cond)) { \
    PRINT_ERROR(str, ##__VA_ARGS__); \
    goto jumpLabel; \
}

/**
 *  @brief Jump to jumpLable if cond is false and set the errno.
 */
#define ASSERT_JUMP_ERRNO(cond, jumpLabel, err) \
if(!(cond)) { \
    errno = err; \
    goto jumpLabel; \
}

/**
 *  @brief Jump to jumpLable if cond is false, print error message and set the errno.
 */
#define ASSERT_JUMP_PRINT_ERRNO(cond, jumpLabel, err, str, ...) \
if(!(cond)) { \
    PRINT_ERROR(str, ##__VA_ARGS__); \
    errno = err; \
    goto jumpLabel; \
}

#endif /* PRINT_DEBUG_H */

/**
 *  @brief Return retCode if cond is false.
 */
#define ASSERT_RETURN(cond, retCode) \
if(!(cond)) { \
    return ret; \
}

/**
 *  @brief Return retCode if cond is false and print error message.
 */
#define ASSERT_RETURN_PRINT(cond, retCode, str, ...) \
if(!(cond)) { \
    PRINT_ERROR(str, ##__VA_ARGS__); \
    return ret; \
}

/**
 *  @brief Return retCode if cond is false and set the errno.
 */
#define ASSERT_RETURN(cond, retCode, err) \
if(!(cond)) { \
    errno = err; \
    return ret; \
}

/**
 *  @brief Return retCode if cond is false, print error message and set the errno.
 */
#define ASSERT_RETURN_PRINT(cond, retCode, err, str, ...) \
if(!(cond)) { \
    PRINT_ERROR(str, ##__VA_ARGS__); \
    errno = err; \
    return ret; \
}

/**************************************************/
/***  Functions prototype                       ***/
/**************************************************/

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
void printBuffer(void *buff, size_t size, off_t offset, bool color);
