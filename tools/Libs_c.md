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
(Warning: only the ft_c42lib.h file is guaranteed
to work with c++).
```c
#include "ft_c42lib.h"
```
Alternatively if you want only functions from a specific module you can
include the header file of the module. e.g. for the string module:
```c
#include "ft_string.h"
```

- Compile the library.
```bash
cd PATH/TO/C42LIB ; make
```

- Link the library to your project.


```bash
gcc -o my_program [my sources] -I PATH/TO/C42LIB/include -LPATH/TO/C42LIB -lc42libs
```
Warrning:If you use `.o` compilation you dont need to provide the library to
compile at this stage. However library need to be present for the linking step.
In such case it would look like something like that :
```bash
gcc my_source_code.o -c my_source_code.c -I PATH/TO/C42LIB/include [MY_OTHER_FLAGS]
gcc my_source_code_file_2.o -c my_source_code_file_2.c -I PATH/TO/C42LIB/include [MY_OTHER_FLAGS]

# for all source files

gcc -o my_program [.o files generated] -I PATH/TO/C42LIB/include [MY_OTHER_FLAGS] -L PATH/TO/C42LIB -lc42libs
```

We heavily recommend using the .o way to compile your program coupled with a
Makefile to compile your program.

- Run your program.
```bash
./my_program [my_program_args]
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
