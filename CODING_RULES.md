# The coding rules of the projects.

This file is created to describe the coding rules of the project.
Why describe a project coding rule ?
To make the code more readable and limite the coding errors.

## reference rules

To limit errors and bugs, respect as much as possible the recommendations of this document:

https://www.ssi.gouv.fr/entreprise/guide/regles-de-programmation-pour-le-developpement-securise-de-logiciels-en-langage-c/

(Sorry it is a French document ;-) )

## Bocks styles

Use the [Allman](https://en.wikipedia.org/wiki/Indentation_style) style.
Don't omit the `{}` on conditional block (like `if` statement), even for one instruction `if` statement.

Example :
```c
int main()
{   
    if(1)
    {
        printf("Hello World");
    }
}
```

## Naming

Use a [Camel case](https://en.wikipedia.org/wiki/Camel_case).

### Variables

Use an [Hungarian](https://en.wikipedia.org/wiki/Hungarian_notation) style naming, with this prefix :

#### Scopes

| Prefix | Description                                       |
|--------|---------------------------------------------------|
| `l_`   | local                                             |
| `p_`   | function parameter                                |
| `s_`   | static                                            |
| `g_`   | global (use only if it is absolutely necessary  ) |

#### Types

| Prefix | Description                       |
|--------|-----------------------------------|
| `b`    | `bool`                            |
| `i`    | `int`                             |
| `h`    | `short`                           |
| `f`    | `float`                           |
| `d`    | `double`                          |
| `u`    | `unsigned`                        |
| `s`    | `signed`                          |
| `c`    | `char`                            |
| `p`    | `pointer`                         |
| `z`    | `size_t`                          |
| `sz`   | `ssize_t`                         |
| `t`    | `struct`, `typedef`               |
| `e`    | `enum` (or `typedef` of `struct`) |
| `u8`   | `uint8_t `                        |
| `u16`  | `uint16_t`                        |
| `u32`  | `uint32_t`                        |
| `u64`  | `uint64_t`                        |
| `s8`   | `int8_t `                         |
| `s16`  | `int16_t`                         |
| `s32`  | `int32_t`                         |
| `s64`  | `int64_t`                         |


Example :
```c
static bool s_bRunLoop;

int main(int p_iArgc, char **p_ppcArgv)
{
    int l_iRet;

    while(s_bRunLoop)
    {
        l_iRet = printf("%d %s \n", p_iArgc, p_ppcArgv[0]);
    }
}
```

### Enum, Struct and Typedef

#### Enum

enum values are always in uppercase.
for enum use a comun prefix started by `E_`.
name start with `e` prefix (like variables names).

Example :
```c
enum eTest
{
    E_TEST_VAL1;
    E_TEST_VAL2;
};
```

#### Struct

name start with `t` prefix (like variables names).
the elements of the struct use the types prefix, like the standard variables.

Example :
```c
struct tTest
{
    int   iCount;
    char *pcValue;
};
```

#### Typedef

Typedef end with a `_t` suffix, when it is a typedef of struct or enum, the name of the typedef is the same as the struct or enum name with the suffix.

Example :
```c
typedef struct tTest
{
    int   iCount;
    char *pcValue;
} tTest_t;
```
### Function

The functions are alwase explicite input and output types.
The functions have file or 'object' prefix like `prefixName_functionName`.
All functions have prototype definitions, on a `.h` file for "public" function or on the top of the `.c` file for "private" static function.

Example :
```c
/* example.h */

int example_test(int p_iTest);
```

```c
/* example.c */

static void example_print(void);

int example_test(int p_iTest)
{
    example_print();

    return 0;
}

static void example_print(void)
{
    printf("Example\n");
}
```

## Object oriented programing

Yes, object oriented programing is posible in C language.
The object arguments is defined in a structure defined in the `.c` file, and is exported for externe use by a `typedef` in the `.h`.
All methods are named with the object name prefix (`objectName_methodeName`).
The object is created by an `objectName_new` methode and delete with a `objectName_delete` methode.
The object's structure are the first argument of all methodes (exept the new methode) and it is called `this` (without any prefix).
The prototype public functions is defined on the header file of the object, and the private prototype are defined at the top of the source file.
All private methodes are `static` functions.
All methodes (exept `new`) check if the arg `this` is not `NULL`.

Example :
```c
/* object.h */

typedef struct tObject tObject_t;

tObject_t *object_new(void);
void       object_delete(tObject_t *this);

int        object_methode1(tObject_t *this, int p_iArg);
```

```c
/* object.c */

struct tObject 
{
    int  iArg1;
    char cArg2;
}

static void object_print(tObject_t *this);

tObject_t *object_new(void)
{
    return (tObject_t *) malloc(sizeof(tObject_t));
}
void       object_delete(tObject_t *this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int        object_methode1(tObject_t *this, int p_iArg)
{
    if(this != NULL)
    {
        this->iArg1 = p_iArg;
    }
}

static void object_print(tObject_t *this)
{
    if(this != NULL)
    {
        printf("%d %c \n", this->iArg1, this->cArg2);
    }
}
```

## Comments ans Docs

Don't use the C++ comments style (`//`), only C comments style are accepted (`/*  */`)
Use the Doxygen style with the `/**` starter.

For function write the doc on the prototype definition, and on the implementation, write a comment to indicate the protorype's doc location.
For the `typedef struct`, write the doc ont the `typedef` location (if the `struct` and `typedef` deffinition are separated), and use the `@struct` tag.
For object oriented programing, use the `@memberof`, `@private` and `@public` doxygen tags.

Example :
```c
/* object.h */

/**
 * @struct tObject_t
 * 
 * @brief  Object.
 */
typedef struct tObject tObject_t;

/**
 * @public
 * @memberof tObject_t
 *
 * @brief    Creator.
 *
 * @return   The new object.
 */
tObject_t *object_new(void);

/**
 * @public
 * @memberof tObject_t
 *
 * @brief          Destructor.
 *
 * @param[in,out]  this  The object
 */
void       object_delete(tObject_t *this);
```

```c
/* object.c */

/* Docs in the `object.h` file. */
struct tObject 
{

    /**
     * @private
     * @memberof tObject_t
     *
     * @brief    int argument.
     */
    int  iArg1;
    
    /**
     * @private
     * @memberof tObject_t
     *
     * @brief    char argument.
     */
    char cArg2;
}

/**
 * @private
 * @memberof tObject_t
 *
 * @brief    Print the object.
 */
static void object_print(tObject_t *this);

/* Docs in the `object.h` file */
tObject_t *object_new(void)
{
    return (tObject_t *) malloc(sizeof(tObject_t));
}

/* Docs in the `object.h` file */
void       object_delete(tObject_t *this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/* Docs at the top of this file. */
static void object_print(tObject_t *this)
{
    if(this != NULL)
    {
        printf("%d %c \n", this->iArg1, this->cArg2);
    }
}
```

