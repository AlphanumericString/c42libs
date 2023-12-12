# String lib

String library from bgoulard.

This document is private, please do NOT share it around.

This document contains the following:

- dependency of this lib
- list of action needed to be taken
- list of function in this lib and their usage

## Dependencies

**Self lib:**

- No internal libs dependency

**System functions :**

- Malloc
- Free

The disambiguation on self_libs and function call is only because i like it…and also that 42 is a weird school where sometime you don’t have the right to use malloc.

### TODO:

- [x]  All function from ft_lib (except lst- functions)
- [x]  Rename to ft_string
- [ ]  cleanup header file
    - [ ]  Add // <file>.c to the header to indicate position of functions
    - [ ]  Add new struct t_string to alloc by chunk and have len + size cached
        - [ ]  Implement Struct
        - [ ]  Implement basic functions to t_string
        - [ ]  Implement ‘hard’ function to t_string
    - [ ]  Remove string’s struct to a sperate struct header.
- [ ]  Add gnl and printf
    - [x]  gnl
        - [ ]  update gnl
    - [ ]  printf
- [ ]  Optimise functions from ft_lib
    - [ ]  Add more re-link in-between function lib cf. Don't add a loc_strlen nor do a basic while loop to get char name but use ft_strlen; don't loop to add char in str but use ft_strlcat…
    - [ ]  Add ft_strreplace

This list suggest an t_string module to be added to ft_string and while fitting for the name I’m not so sure I want to “pollute” this lib by adding another module.