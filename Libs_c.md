# Libs - c

Library for c projects at 42.

# TODO: global

- [ ]  remove useless includes
- [ ]  remove trailing comments
- [ ]  Makefile rule to compile without certain system functions e.g. compile ft_string with only functions that don’t reference *ft_calloc* and *malloc* or *free*.
- [ ]  Makefile add debug rule for “so” ? or run “so” in debug rule. idk idc will see…

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

- [x]  All lst function from ft lib
- [x]  All dl nodes from personal stack lib
    
    
    - [ ]  Compliance between dl and lst functions
        - [ ]  dl
            - [ ]  add_back
            - [ ]  add_front
            - [ ]  rev
            - [ ]  map
        - [ ]  lst
            - [ ]  iter_range
            - [ ]  iter_range_node
            - [ ]  size_match
            - [ ]  create
            - [ ]  copy
            - [ ]  copy_list
            - [ ]  del_range
            - [ ]  get_datas
            - [ ]  get_nodes
            - [ ]  at
            - [ ]  push
            - [ ]  push_back
            - [ ]  pop
            - [ ]  pop_front
            - [ ]  subrange
    - [ ]  Stack structure W/ functions (control for node + cached values/mem/whatever)
    - [ ]  functions to add
        - [ ]  find
        - [ ]  rfind
        - [ ]  create_from_array
        - [ ]  ? create from vec ?
- [x]  Split functions header from struct header
- [x]  Rename predicate to ft_list
- [ ]  Rename predicate of ft_list_dl% to ft_dl% and ft_list% to ft_lst%
- [ ]  ? Tree structure/functions ?
- [ ]  ? Circular support ?

[Linked list lib](Libs_c_md/Linked_list_lib.md)

# Strings

## Dependencies

**Self lib:**

- No internal libs dependency

**System functions :**

- Malloc
- Free

### TODO:

- [x]  All function from ft_lib (except lst- functions)
- [x]  Rename to ft_string
- [ ]  cleanup header file
    - [ ]  Add // <file>.c to the header to indicate position of functions
    - [x]  Add new struct t_string to alloc by chunk and have len + size cached
        - [x]  Implement Struct
        - [x]  Implement basic functions to t_string
        - [ ]  Implement ‘hard’ function to t_string
    - [x]  Remove string’s struct to a sperate struct header.
- [ ]  Add gnl and printf
    - [x]  gnl
        - [ ]  update gnl
    - [ ]  printf
- [ ]  Optimise functions from ft_lib
    - [ ]  Add more re-link in-between function lib cf. Don't add a loc_strlen nor do a basic while loop to get char name but use ft_strlen; don't loop to add char in str but use ft_strlcat…
    - [ ]  Add ft_strreplace

[String lib](Libs_c_md/String_lib.md)

# Config

Dependencies

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