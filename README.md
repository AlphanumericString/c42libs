# c42libs

library for 42 school in c.
This library is an extreme and modified version of libft. It si comprised of
diverse module in the src.
Each module has a litle flavor text bellow to see their purposes.
These module were made to conform to 42 school c norm (V3 norm).

This library is private because people kept annoying me about it.
If you have access to it, GO FUCK YOURSELF.

## 42 norm version
norminette 3.3.58, Python 3.12.9, Linux-6.12.26-x86_64-with-glibc2.40
github link to norminette:
https://github.com/42school/norminette

## contained libraries

### ft_string

The **ft_string** module contains all basic operations one should expect of
string.h header with some extra such as ft_gnl, ft_strreplace.
This module also contains t_string operations.
A t_string is a smart implementation of a string keeping both the size of the
allocated memory block and the size of the string in memory.
This module also contains memory operations.
The memory operation include some basics such as memcpy but also some more
advanced such as memmap.

### ft_list

The **ft_list** module contains all basic operations one should expect of a
linked list library with support for:
    -simply linked list
    -doubly linked list
    -doubly linked circular list


### ft_vector

The **ft_vector** module contains all basic operations one should expect of a
vector library.
WARNING: THIS IS NOT A MATH VECTOR BUT A C++ VECTOR.
This is basically a smart array.

### ft_map

The **ft_map** module provides a basic implementation of maps in c.
The t_map type is generic and uses void * keys and values.

### ft_optional

The **ft_optional** module provides a basic implementation of optional in c.
The t_optional type is generic.

### ft_pair

The **ft_pair** module contains all basic operations one should expect of a
pair type.
This is basically a c++ pair implemented using `void *`.

### ft_args

The **ft_args** module provides a basic implementation of arguments parser in
c.
It also can set and hold ac, av, ev.


## Usage

Does **NOT** follow the define xxx_IMPLEMENTATION and #include xxx convention.

To use the library you must include the header file in your code and link the
library to your project.
To do so you can use the following flag at compile time.
```sh
cc whatever.c -I<path/to/lib/dir>/include -L<path/to/lib/dir> -l:libc42libs.a \
    -o whatever.out
```

Theres also a rule to compile the library as .so file, but if you're at that
point you probably know already know how to compile an executable with a
shared library.

## Documentation

For details please consult the respective Markdown files or the global [Markdown file](tools/Libs_c.md)
For contribution please consult the [Markdown file](tools/Libs_c.md) in the tools directory.

For usage please consult the respective usage file specified in epithath under each lib.

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.
tldr: you can use it for free but you must share your modifications.
