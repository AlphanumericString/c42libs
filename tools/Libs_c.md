# Libs - c

Library for c projects at 42.

# TODO: global

- [ ]   TODO
    - [ ]   add dependancies to map + config
    - [ ]   add md files for map
- [ ]   libs
    - [ ]   includes
        - [ ]   remove useless includes
        - [ ]   remove trailing comments
        - [ ]   doxygen
            - [X]   ll
            - [X]   dl
            - [X]   map
            - [X]   vector
            - [ ]   string
            - [X]   str
    - [ ]   tests for all *finished* libs
        - [X]   ft_list
        - [X]     ll
        - [X]     dl
        - [X]  ft_map
        - [ ]  ft_string
            - [ ]   t_string
            - [ ]   str
        - [X]  ft_vector
- [ ]   Makefile
    - [X]   Makefile add debug rule for “so” ? or run “so” in debug rule. idk idc will see…
    - [X]   check if cmd exist for llvm suite
    - [X]   tests_run rule
        -[ ]    remodel tests_run to compile only needed sources by adding a patern rule build/tests/%.o to TESTS_SRC compiling with TEST_FLAGS
Specific libs have their own todos further down and how to use pages.

# Linked lists

## Dependencies

**Self libs**
- Ft_string
- Ft_list

**System functions**
- Open
- Close
- Write
- Free

### TODO:
- [x]   All lst function from ft lib
- [x]   All dl nodes from personal stack lib
    - [x]   Compliance between dl and lst functions
        - [x]   dl
            - [x]   add_back
            - [x]   add_front
            - [x]   rev
            - [x]   map
        - [x]   lst
            - [x]   iter_range
            - [x]   iter_range_node
            - [x]   size_match
            - [x]   create
            - [x]   copy
            - [x]   copy_list
            - [x]   del_range
            - [x]   get_datas
            - [x]   get_nodes
            - [x]   at
            - [x]   push
            - [x]   push_back
            - [x]   pop
            - [x]   pop_front
            - [x]   subrange
    - [ ]   Stack structure W/ functions (control for node + cached values/mem/whatever)
    - [x]   Functions to add
        - [ ]   Find functions
            - [x]   Find
            - [ ]   Rfind - reverse find
        - [ ]   Create_from_array
            - [ ]   Create from null ended arr
            - [ ]   Create from array of known size
        - [ ]   If FT_VECTOR is defined create from vector
- [x]   Split functions header from struct header
- [ ]   Rename
    - [x]   Rename predicate to ft_list
    - [ ]   Rename predicate of ft_list_dl_% to ft_dl_% and ft_list% to ft_ll_%
- [ ]   Functionality
    - [ ]   Circular ll
    - [ ]   Circular dl
    - [ ]   Stack
    - [ ]   Queu
    - [ ]   Tree

[Linked list lib](Libs_c_md/Linked_list_lib.md)

# Strings

## Dependencies

**Self lib:**

- No internal libs dependency

**System functions :**

- Malloc
- Free

### TODO:

- [x]   All function from ft_lib (except lst- functions)
- [x]   Rename to ft_string
- [x]   Cleanup header file
    - [x]   Add // <file>.c to the header to indicate position of functions
    - [x]   Add new struct t_string to alloc by chunk and have len + size cached
        - [x]   Implement Struct
        - [x]   Implement basic functions to t_string
        - [ ]   Implement ‘hard’ function to t_string
            - [ ]   Kinda done but wanna optimise lib to return/use vars from t_string
    - [x]  Remove string’s struct to a sperate struct header.
- [ ]  Add gnl and printf
    - [x]  Gnl
        - [ ]  Update gnl
        - [ ]  Optimise gnl
    - [ ]  Printf
        - [ ]   Basic printf
        - [ ]   you could at least support flags you scum bag
- [ ]   Optimise functions from ft_lib
    - [ ]   Add more re-link in-between function lib cf. Don't add a loc_strlen nor do a basic while loop to get char name but use ft_strlen; don't loop to add char in str but use ft_strlcat…
      - [x] kinda started but MOAR.
    - [x]   Add ft_strreplace
    - [X]   Add ft_shift_args
        -[ ]    Add ft_shift_args to include

[String lib](Libs_c_md/String_lib.md)

# Config

## Dependencies

**self libs**
N/A
**system functions**
N/A

- All string module
- List module
- Open & Close
- [ ]  Main frame to launch parser functions
    - [x]  Init
    - [ ]  Load
    - [ ]  Get
    - [ ]  Set
    - [ ]  Save
- [x]  INI CORE specific function
    - [x]  Init
- [x]  INI EXTENDED specific functions
    - [x]  Init
- [ ]  INI mixed functions
    - [ ]  Load - (current)
    - [ ]  Get
    - [ ]  Set
    - [ ]  Save
        - [ ]  Already existing file > replace values ignore #comments
        - [ ]  Non existing file > dump
- [ ]  JSON
- [ ]  YAML
- [ ]  Custom

[Config lib](Libs_c_md/Config_lib.md)

# Maps

## Dependdencies

**Self libs:**
N/A
**System function**
N/A
### TODO:
- [ ] make the libs
    - [ ] get / set
        - [ ] capacity
            - [ ] set
            - [X] get
        - [ ] cmp
            - [X] set
            - [ ] get
        - [ ] hash
            - [X] set
            - [ ] get
        - [ ] keys
            - [ ] get (current get is more of a get_mapkv)
            - [X] set 
        - [ ] size
            - [ ] get
            - [X] ~~set~~ size should not be touched by end user
    - [X] get_map_node -- current map_get
    - [X] new / destroy
    - [X] remove