# Libs - c
Library for c projects at 42.
## Summary
These module were made to conform to 42 school c norm (V3 norm), they are 
basically a very pushed version of the libft.
## table of content
- [summary](#summary)
- [table of content](#table-of-content)
- [usage](#usage)
- [ft_args](#ft_args)
- [ft_list](#ft_list)
- [ft_map](#ft_map)
- [ft_math](#ft_math)
- [ft_optional](#ft_optional)
- [ft_pair](#ft_pair)
- [ft_string](#ft_string)
- [ft_vector](#ft_vector)
- [how to contribute](#how-to-contribute)
- [todo](#todo)
- [to add](#to-add)
- [to fix](#to-fix)

## Usage

Each module has it's own header file, to have more information on how to use
functions of a specific module you can look at the header file of the module.

The documentation is in the style of doxygen with a description of :
    - The function
    - The parameters
    - The return value
And some notes on the function if judged necessary.

How to use the library:
- Include the header file in your code.
```c
#include "ft_string.h"
```

- Compile the library.
```bash
cd [PATH_TO_LIB] ; make
```

- Link the library to your project.
```bash
gcc -o my_program my_program.c -L[PATH_TO_LIB] -lc42libs
```

- Run your program.
```bash
./my_program
```

## ft_args
The **ft_args** module provides a basic implementation of arguments parser in c.
It also includes a small part to get the program name and environment variables.

## ft_list

The **ft_list** module contains all basic operations one should expect of a
linked list library with support for simply linked list and doubly linked list.

The following list types:
    - Queue 
    - Stack 
    - Circular list
Should be here but are not et implemented.

## ft_map

The **ft_map** module provides a basic implementation of maps in c.
The t_map type is generic and uses void * keys and values.

The following map types:
    - Tree map
Should be here but are not et implemented.

## ft_math

The **ft_math** module contains all basic operations one should expect of a
math.h header with some extra such as ft_pow, ft_sqrt, ft_abs.

There was a long discution on wether matrixes should be in the math module or
in the vector module. The final decision was to put them in the vector module.
(may be changed in the future)

## ft_optional

The **ft_optional** module provides a basic (if heavily inspired by rust)
implementation of optional in c.

## ft_pair

The **ft_pair** module provides a basic implementation of pair in c.

## ft_string
The **ft_string** module contains all basic operations one should expect of
string.h header with some extra such as get_next_line, ft_strreplace.
This module also contains t_string and memory operations.
The memory operation include some basics such as memcpy but also some more
advanced such as memmap or qsort.

## ft_vector

The **ft_vector** module contains all basic operations one should expect of a
vector library.

WARNING: THIS IS NOT A MATH VECTOR BUT A C++ VECTOR.
This is basically a smart array.


The following sections of this file are not for you if you dont want to
contribute to the project.

## how to contribute
To contribute to the project you can fork the project and make a pull request
to the main branch.

To add a new module to the project you must:
    - create the files
        - Create a new directory in the tests directory with the name of the module.
            - place a calling function with the naming scheme of 'test_<module>'
            (module should be trimed eg: ft_optional module -> test_optional).
            - check tests of other modules and try to make it in the same style:
                a list of test function with a name attached to know what it tests.
                (eg: test_optional -> test_optional_create, test_optional_is_some, ...)
                PLEASE USE THE RUN_TEST FUNCTION to run the tests.
        - Create a new directory in the src directory with the name of the module.
            - place any implementations of the module there.
        - Create a 2 new header files in the include directory
            - One for the functions prototypes (with the same name as the module).
            - typedefs in one header file of the same name but affixed with _types.
            eg: ft_new_module.h and ft_new_module_types.h
    - Add the new module to the Makefile.
        - Create a 2 variable in the Makefile for :
            - the directory of your module
            - the src files of your module
            eg: NEW_MODULE_DIR = new_module
                NEW_MODULE_SRC = $(NEW_MODULE_DIR)/new_module_implementation.c \
                                 $(NEW_MODULE_DIR)/new_module_implementation2.c
        - Update the INNER_SRC and the TESTS_SRC variables with the new module and
        its tests.
If you want to add a new function to an existing module you must:
    - Add the function to the header file of the module.
    - Add the implementation file to the directory of the module.
    - Add a test function in the test directory of the module.
    - Add the test function to the calling function array of the tests.
    - Add a documentation of the function in the header file of the module.


Of course you should not use any stdc functions in the project and respect the
42 school c norm (V3 norm).

You can find the norm at the following link:
[42 school norm](https://github.com/42School/norminette)

THE NORM IS NOT A GOAL BUT A CONSTRAINT. Any code that does not respect the norm
will be rejected.

The project is under the MIT license, you can find the license at the following
link:
[MIT License](https://opensource.org/licenses/MIT)

## todo
- [ ]   libs
    - [ ]   tests for all *finished* libs
    - [ ]   const nazi it. '(grep "^[a-zA-Z]" include/*.h | grep -v "const .*\*.*,.*")'
- [x]   Makefile
- [ ]   Tests
    - [ ]   Add tests for all *finished* libs
        - [~]   ft_map
        - [ ]   ft_string
            - [ ]   t_string
            - [x]   str
            - [x]   mem
    - [ ]   Add test fixture to test memory fail
        - [ ]   ft_args
        - [ ]   ft_list
        - [ ]   ft_map
        - [ ]   ft_math
        - [ ]   ft_optional
        - [ ]   ft_pair
        - [ ]   ft_string
        - [ ]   ft_vector
    - [ ]   Up the coverage percentage (fell lower due to new funcs)
        - [ ]   80% for all modules
        - [ ]   90% for all modules
        - [ ]   95% for all modules
        - [ ]   100% for all modules
- [x]   License
    - [x]   Add license to all files

## to add
- **NEW** Module to add
    - [ ]   ft_config : Config file parser (serializer/deserializer) (json, raw, idk...)
    - [x]   ft_optional : Optional type (like in rust)
    - [x]   ft_args : Arguments parser
    - [ ]   ft_db : Database bindings (yes i can use a lib but this is fun) (?sqlite3?)
    - [ ]   ft_bit : Bit manipulation functions
    - [ ]   ft_tree : Binary tree (avl, red-black, splay, ...)
    - [ ]   ft_thread : Thread management for c (thread pool, mutex, ...)
    - [ ]   ft_net : Network functions (socket, http, ...)

## to fix:
- Sub-Modules to create
    - ft_args
        - [x]  prog name
        - [ ]  env vars
        - [ ]  ctx relative to program
        - [x]  cli args parser
    - list
        - [ ]   circular
        - [ ]   stack
        - [ ]   queue
    - vector
        - [ ]   matrix
    - map
        - [x]   hash_map (current map (not resizable))
        - [ ]   tree_map
    - string
        - [ ]   regex
        - [ ]   printf
        - mem
            - [ ]   arena
            - [ ]   ft_malloc_impl
- Functions
    - vector
        - [ ]   Compatibility
            - [ ]    lists
                - [ ]   add from_ll + from_dl
                - [ ]   add to_ll + to_dl
            - [ ]   maps (not sure, map are not ordered)
                - [ ]   add from_map
                - [ ]   add to_map
        - [ ]   Algorithm functions
            - [ ]   sort -> call qsort :D
            - [x]   find
            - [ ]   rfind - reverse find (search from end)
    - list
        - [ ]   Alforithms functions
            - [x]   find
            - [ ]   rfind - reverse find (search from end)
            - [ ]   sort
        - [ ]   Compatibility
            - [ ]   with ft_vector
                - [ ]   add from_vector
                - [ ]   add to_vector
            - [ ]   ? with ft_map (not sure, map are not ordered)
                - [ ]   add from_map
                - [ ]   add to_map
            - [ ]   with c-style arrays
                - [ ]   add from_array
                - [ ]   add from_array with size
                - [ ]   add to_array
    - string
        - str
            - [ ]   regex
            - [x]  Gnl
                - [x]  Update gnl
                - [ ]  Optimise gnl to use func from lib (culd be pushed further)
            - [ ]  Printf
                - [ ]   basic printf
                - [ ]   you could at least support flags you scum bag
        - mem
            - [ ]   finish the god damn arena
            - [ ]   finish the god damn ft_malloc_impl
        - t_string
            - [ ]   remove the stupid +1.
            - [ ]   Implement ‘hard’ function to t_string
            - [ ]   kinda done but wanna optimise lib to return/use vars from t_string
    - map
        - [ ]   Re - implement maps to be growable
                - n linked lists (n being the number of ll starts)
                - save the hash in the node to be able to resize map aka n+=10%
        - [ ]   Destroy should take a db ptr to struct and set to null like
                the rest of the lib
    - Diverses::
        - [ ]   Optimise functions from ft_lib
            - [ ]   Add more re-link in-between function lib cf. Don't add a loc_strlen nor do a basic while loop to get char name but use ft_strlen; don't loop to add char in str but use ft_strlcat…
                - [ ]   simian
                - [ ]   manual rev
- Tests
    - [ ]   Fix tests return codes
            eg: `
            // test1_action
            if (test1_check)
                return (1);
            // test2 _action
            if (test2_check)
                return (1);
            return (0)
            `
            should be
            `
            // testN_action
            if (tetsN_check)
                return (N);
            ...
            return (0);
            `
            use `rg 'return \(1\);' tests/ -C 4 | less` to check faster
        - [ ]   ft_args
        - [ ]   ft_list
        - [ ]   ft_map
        - [ ]   ft_math
        - [ ]   ft_optional
        - [ ]   ft_pair
        - [ ]   ft_string
        - [ ]   ft_vector
