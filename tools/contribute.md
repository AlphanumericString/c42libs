# How to contribute

## What to do
To contribute to the project you can fork the project and make a pull request
to the main branch.

## Adding a new module
- create the files
    - Create a new directory in the tests directory with the name of the module.
        - place a calling function with the naming scheme of 'test_<module>'
        (module should be trimed eg: ft_optional -> test_optional).
        - check tests of other modules and try to make it in the same style:
            a list of test function with a name attached to know what it tests.
            (eg: ft_optional_create -> to_create, ft_optional_is_some -> to_is_some, ...)
            PLEASE USE THE RUN_TEST FUNCTION to run the tests.
    - Create a new directory in the src directory with the name of the module.
        - place any implementations of the module there.
    - Create a 2 new header files in the include directory
        - One for the functions prototypes (with the same name as the module).
        - typedefs in one header file of the same name but affixed with _types.
        eg: ft_new_module.h and types/ft_new_module_types.h
- Add the new module to the Makefile.
    - Create a 2 variable in the Makefile for :
        - the directory of your module
        - the src files of your module
        eg: NEW_MODULE_DIR = new_module
            NEW_MODULE_SRC = $(NEW_MODULE_DIR)/new_module_implementation.c \
                             $(NEW_MODULE_DIR)/[...].c
    - Update the INNER_SRC and the TESTS_SRC variables with the new module and
    its tests.
## Adding a new function
- Prototype it
    - Add the function to the header file of the module.
- Make it
    - Add the implementation file to the directory of the module.
- Test it
    - Add a test function in the test directory of the module.
    - Add the test function to the calling function array of the tests.
- Document it
    - Add a documentation of the function in the header file of the module.

## Norming
Snake case convention.
No stdc functions allowed appart from : read, write, free, malloc.
Follow the 42 school c norm (V3 norm).

You can find the 42norm at the following link:
[42 school norm](https://github.com/42School/norminette)
tldr of the norm:
25 lines and 80 columns for functions at max, 5 variables declaration max,
5 functions per file, new line for brace style, tabs not spaces.

THE NORM IS NOT A GOAL BUT A CONSTRAINT. Any code that does not respect the norm
will be rejected.

The project is under the MIT license, you can find the license at the following
link:
[MIT License](https://opensource.org/licenses/MIT)

## If you dont know what to do:
### todo
- [x]   libs
    - [x]   tests for all functions of *finished* libs module
    - [x]   const nazi it. 'grep "^[a-zA-Z].*\*.*" --recursive include/*.h | grep -v "const .*\*.*,.*" | less'
                                line starting with chars containing a '*' inside of include
                                filter by removing any line not containing 'const *,'
- [x]   Makefile
- [ ]   Tests
    - [ ]   Add tests for all *finished* libs
        - [x]   ft_map
            - [ ]   map_set is kind of in a weird state, fix it
        - [ ]   ft_string
            - [ ]   t_string
            - [x]   str
            - [x]   mem
    - [x]   Add test fixture to test memory fail
        - [x]   ft_args
        - [x]   ft_list
        - [x]   ft_map
        - [x]   ft_math
        - [x]   ft_optional
        - [x]   ft_pair
        - [ ]   ft_string
            - [x]   str
            - [ ]   string
            - [x]   mem
            - [x]   chr
        - [x]   ft_vector
    - [ ]   Up the coverage percentage (line + branch)(fell lower due to new funcs)
        - [x]   80% for all modules
        - [x]   90% for all modules
        - [x]   95% for all modules
            - [x] lines
            - [x] branches
        - [ ]   100% for all modules (unachievable, but still goal)
- [x]   License
    - [x]   Add license to all files

### to add
- **NEW** Module to add
    - [ ]   ft_config : Config file parser (serializer/deserializer) (json, raw, idk...)
    - [x]   ft_bitset : Bit manipulation functions
    - [x]   ft_optional : Optional type (like in rust)
    - [x]   ft_args : Arguments parser
    - [ ]   ft_db : Database bindings (yes i can use a lib but this is fun) (?sqlite3?)
    - [ ]   ft_tree : Binary tree (avl, red-black, splay, ...)
    - [ ]   ft_thread : Thread management for c (thread pool, mutex, ...)
    - [ ]   ft_net : Network functions (socket, http, ...)
    - [ ]   ft_fs : Handle files and directory
- **NEW** category to add
    - [ ]   examples of library use @ root/examples (maybe 42 projects)
        - [ ]   hangman game
        - [ ]   dummy_ls (ls clone)
        - [ ]   dummy_cat (cat clone)
    - [ ]   shell tests of all examples for no intempestives SIGSEGV

### to fix:
- Sub-Modules to create
    - ft_args
        - [x]  prog name
        - [x]  env vars
        - [ ]  ctx relative to program
            ? context missing ?
        - [x]  cli args parser
    - list
        - [x]   circular
        - [ ]   stack
        - [ ]   queue
    - math
        - [ ]   matrix
    - map
        - [x]   hash_map (current map (not resizable))
        - [ ]   tree_map
    - string
        - [ ]   regex
        - [~]   printf
            - [x]   basic printf -> ft_print_fd
        - mem
            - [x]   arena
                - [x]   v1 - (no free, no realloc, no extract ptr from arena)
                - [ ]   v2 -
                        free without del arena,
                        extract ptr from arena
            - [ ]   ft_malloc_impl
- Functions
    - vector
        - [ ]   Compatibility
            - [ ]    lists
                - [ ]   from_ll + from_dl + from_cl
                - [ ]   to_ll + to_dl + to_cl
            - [ ]   maps (not sure, map are not ordered)
                - [ ]   from_map
                - [ ]   to_map
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
                - [ ]   from_vector
                - [ ]   to_vector
            - [ ]   ? with ft_map (not sure, map are not ordered by default)
                - [ ]   from_map
                - [ ]   to_map
            - [ ]   with c-style arrays
                - [ ]   from_array
                - [ ]   from_array with size
                - [ ]   to_array
    - string
        - str
            - [ ]   regex
            - [x]  Gnl
                - [x]  Update gnl
                - [x]  Rename get_next_line -> ft_gnl
                - [ ]  Use local array and 'push' front last fd instead of 1024 tab
                - [ ]  Optimise gnl to use func from lib (culd be pushed further)
            - [~]  Printf
                - [x]   basic printf
                - [ ]   you could at least support flags you scum bag
                        - might not, dont wanna get in trouble with 42 adm
        - mem
            - [x]   finish the god damn arena
            - [ ]   finish the god damn ft_malloc_impl
                - [x]   bindings
                - [ ]   implementation
                    - [ ]   sbrk/pbrk
                    - [ ]   mmap
            - [ ]   Add search functions
                - [ ]   bsearch lsearch lfind
            - [ ]   Add sort functions
                - [ ]   mergesort heapsort (bsd)
        - t_string
            - [ ]   remove the stupid +1 ? might be util to keep to have access to base 'const char *' functions
                - [ ]   remove the +1 everywhere and re-implement all str function while using length attribute
                    - or -
                - [ ]   add a to_cstr function
            - [ ]   Implement ‘hard’ function to t_string
                - [ ]   kinda done but wanna optimise lib to return/use vars from t_string
    - map
        - [ ]   Re - implement maps to be growable
	                - n linked lists (n being the number of ll starts)
	                - save the hash in the node to be able to resize map aka n+=10%
	                -> put node in node->hash % map->nb_lists
        - [ ]   Destroy should take a db ptr to struct and set to null like
                the rest of the lib
    - math
        - [ ]   Add bindings for __builtin_***_overflow functions
            - [ ]   bindings are clang compliant
            - [ ]   bindings are gcc compliant
    - Diverses::
        - [ ]   Optimise functions from ft_lib
            - [ ]   Add more re-link in-between function lib cf. Don't add a loc_strlen nor do a basic while loop to get char name but use ft_strlen; don't loop to add char in str but use ft_strlcat…
                - [ ]   simian
                - [ ]   manual rev
- Tests
    - [x]   Fix tests return codes
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
        - [x]   ft_args
        - [x]   ft_bitset
        - [x]   ft_list
        - [x]   ft_map
        - [x]   ft_math
        - [x]   ft_optional
        - [x]   ft_pair
        - [x]   ft_string
            - [x]   char
            - [x]   mem
                - [x]   alg
                - [x]   alocator
                - [x]   arena               << 2025-12-06 22:20 >> stoped here
                - [x]   arr
                - [x]   mem - self
        - [ ]   ft_vector
