/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:25:27 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/31 18:55:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

// gnl

# ifndef MAX_FD
#  ifdef TEST
#   define MAX_FD 5
#  else
#   define MAX_FD 1024
#  endif
# endif

# ifndef BUFFER_SIZE
#  ifdef TEST
#   define BUFFER_SIZE 5
#  else
#   define BUFFER_SIZE 4096
#  endif
# endif

# include "ft_string_struct.h"

// malloc + free

# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/* **                     FT_CHR SUB MODULE                                ** */
/* ************************************************************************** */

/// @brief check if the char is a digit or a letter
/// @param c the char to check
/// @return 1 if the char is a digit or a letter, 0 otherwise
int			ft_isalnum(int c);

/// @brief check if the char is a letter
/// @param c the char to check
/// @return 1 if the char is a letter, 0 otherwise
int			ft_isalpha(int c);

/// @brief check if the char is a ascii char
/// @param c the char to check
/// @return 1 if the char is a ascii char, 0 otherwise
int			ft_isascii(int c);

/// @brief check if the char is a digit
/// @param c the char to check
/// @return 1 if the char is a digit, 0 otherwise
int			ft_isdigit(int c);

/// @brief check if the char is a lower case letter
/// @param c the char to check
/// @return 1 if the char is a lower case letter, 0 otherwise
int			ft_islower(int c);

/// @brief check if the char is a printable char
/// @param c the char to check
/// @return 1 if the char is a printable char, 0 otherwise
int			ft_isprint(int c);

/// @brief check if the char is a space
/// @param c the char to check
/// @return 1 if the char is a space, 0 otherwise
int			ft_isspace(int c);

/// @brief check if the char is a upper case letter
/// @param c the char to check
/// @return 1 if the char is a upper case letter, 0 otherwise
int			ft_isupper(int c);

/// @brief convert the char to lower case
/// @param c the char to convert
/// @return the lower case char
int			ft_tolower(int c);

/// @brief convert the char to upper case
/// @param c the char to convert
/// @return the upper case char
int			ft_toupper(int c);

/* ************************************************************************** */
/* **                     FT_MEM SUB MODULE                                ** */
/* ************************************************************************** */

/// @brief fill the memory with 0
/// @param s start of the memory
/// @param n size of the memory
/// @return void
void		ft_bzero(void *s, size_t n);

/// @brief allocate memory and fill it with 0
/// @param nmemb number of elements
/// @param weight size of each element
/// @return pointer to the allocated memory
void		*ft_calloc(size_t nmemb, size_t weight);

/// @brief allocate memory and copy the content of the source memory
/// @param ptr pointer to the source memory.
/// @param sizeNew size of the destination memory
/// @param sizeOld size of the source memory
/// @return pointer to a larger chunk of allocated memory otherwise NULL
/// @note WARNING: the pointer is FREE'ed after the copy in case of success
void		*ft_realloc(void *ptr, size_t sizeNew, size_t sizeOld);

/// @brief free the memory
/// @param ptr pointer to the memory to free (set to NULL after)
/// @return void
void		ft_free(void **ptr);

/// @brief search for the first occurence of c in the memory
/// @param s start of the memory
/// @param c char to search
/// @param n size of the memory
/// @return pointer to the first occurence of c in the memory otherwise NULL
void		*ft_memchr(const void *s, int c, size_t n);

/// @brief compare the memory
/// @param s1 start of the first memory
/// @param s2 start of the second memory
/// @param n size of the memory to compare
/// @return 0 if the memory are identical, otherwise the difference between the
/// first different char
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/// @brief copy the memory
/// @param dest start of the destination memory
/// @param src start of the source memory
/// @param n size of the memory to copy
/// @return pointer to the destination memory
void		*ft_memcpy(void *dest, const void *src, size_t n);

/// @brief copy the memory
/// @param dest start of the destination memory
/// @param src start of the source memory
/// @param n size of the memory to copy
/// @return pointer to the destination memory
void		*ft_memmove(void *dest, const void *src, size_t n);

/// @brief set the memory with c
/// @param s start of the memory
/// @param c char to set
/// @param n size of the memory
/// @return pointer to the memory
void		*ft_memset(void *s, int c, size_t n);

/// @brief swap the memory
/// @param a first memory
/// @param b second memory
/// @return void
void		ft_swap(void **a, void **b);

/// @brief sort the memory with the cmp function by chunks of size
/// @param array pointer to the memory
/// @param nmb number of chunks
/// @param size size of each chunk
/// @param cmp comparison function
/// @return void
void		ft_qsort(void *array, size_t nmb, size_t size,
				int (*cmp)(const void *, const void *));

/* ************************************************************************** */
/* **                     FT_PUT SUB MODULE                                ** */
/* ************************************************************************** */

/// @brief print the char on the specified file descriptor
/// @param c char to print
/// @param fd file descriptor to print on
/// @return void
void		ft_putchar_fd(char c, int fd);

/// @brief print the string on the specified file descriptor followed by a new
/// line
/// @param s string to print
/// @param fd file descriptor to print on
/// @return void
void		ft_putendl_fd(const char *s, int fd);

/// @brief print the string on the specified file descriptor
/// @param nbr string to print
/// @param fd file descriptor to print on
/// @return void
void		ft_putnbr_fd(int nbr, int fd);

/// @brief print the string on the specified file descriptor
/// @param s string to print
/// @param fd file descriptor to print on
/// @return void
void		ft_putstr_fd(const char *s, int fd);

/* ************************************************************************** */
/* **                     FT_NBR SUB MODULE                                ** */
/* ************************************************************************** */

/// @brief return the logaritm of the number in the specified base
/// @param nbr number to get the logaritm
/// @param base base of the logaritm
/// @return the logaritm of the number in the specified base. in case of error
/// return -1
int			ft_llogof(long long nbr, int base);

/// @brief return the logaritm of the number in the specified base
/// @param nbr number to get the logaritm
/// @param base base of the logaritm
/// @return the logaritm of the number in the specified base. in case of error
/// return -1
int			ft_ullogof(unsigned long long nbr, int base);

/// @brief return the logaritm of the number in the specified base
/// @param nbr number to get the logaritm
/// @param base base of the logaritm
/// @return the logaritm of the number in the specified base. in case of error
/// return -1
int			ft_logof(int nbr, int base);

/// @brief return the logaritm of the number in the specified base
/// @param nbr number to get the logaritm
/// @param base base of the logaritm
/// @return the logaritm of the number in the specified base. in case of error
/// return -1
int			ft_log(int nbr);

/// @brief returns the minimum of a and b
/// @param a first number
/// @param b second number
/// @return the smallest between a and b
int			ft_min(int a, int b);

/// @brief returns the maximum of a and b
/// @param a first number
/// @param b second number
/// @return the biggest between a and b
int			ft_max(int a, int b);

/* ************************************************************************** */
/* **                     FT_STR MAIN MODULE                               ** */
/* ************************************************************************** */

/// @brief convert the string to an int
/// @param str string to convert
/// @return the int converted from the string
int			ft_atoi(const char *str);

/// @brief convert the string to an int in the specified base
/// @param str string to convert
/// @param base base of the string
/// @return the int converted from the string
int			ft_atoi_base(const char *str, const char *base);

/// @brief convert a string with the int converted in ascii chars
/// @param nbr number to convert
/// @return pointer to the string.
/// @note You must free the returned string
char		*ft_itoa(int nbr);

/// @brief convert the int to a string in the specified base
/// @param nbr number to convert
/// @param base base of the string to return.
/// @return pointer to the string.
/// @note You must free the returned string
char		*ft_itoa_base(int nbr, const char *base);

/// @brief
/// @param nbr
/// @return (char *ft_utoa(unsigned int nbr));

/// @brief Return a pointer to the first occurrence of any character contained
/// in the string delims in the string str
/// @param str_init string to search into WARNING: the string is modified by
/// this function. DO NOT PASS A CONST STRING.
/// @param delims string of delimiters
/// @return a pointer to the first occurrence of any character contained in the
/// string delims in the string str otherwise NULL
char		*ft_strtok(char *str_init, const char *delims);

/// @brief Split the string str with the specified delimiter
/// @param str String to split
/// @param delim Char to split the string
/// @return A pointer to the array of string
/// @note You must free the returned array of string and its content
char		**ft_split(const char *str, char delim);

/// @brief Search for the first occurence of the char c in the string str
/// @param str string to search into
/// @param c char to search
/// @return a pointer to the first occurence of c in the string str otherwise
/// NULL
/// @note TODO: pass return as const
char		*ft_strchr(const char *str, int c);

/// @brief duplicate the string src into a new allocated string
/// @param strsrc string to copy from
/// @return The copy of string src
/// @note You must free the returned string
char		*ft_strdup(const char *strsrc);

/// @brief Iterate over the string s and execute the function f on each char
/// @param s String to iterate over
/// @param f Function to execute on each char
/// @return void
/// @note The first parameter of the function f is the index of the char in the
/// string s.
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/// @brief Add up two strings s1 and s2 and return the result
/// @param s1 String to add
/// @param s2 String to add
/// @return The result of the addition of the two strings
/// @note You must free the returned string
char		*ft_strjoin(char const *s1, char const *s2);

/// @brief copy up to size - 1 characters from the NULL-terminated string src
/// to dst, NULL-terminating the result.
/// Puts the result after the characters already in dst.
/// @param dst string to copy to
/// @param src string to copy from
/// @param size maximum number of characters in destination string, including
/// the terminating null character.
/// @return returns the total length of the string they tried to create.
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/// @brief Copies up to size - 1 characters from the NULL-terminated string src
/// to dst, NULL-terminating the result.
/// Puts the result directly at dst.
/// @param dst string to copy to
/// @param src string to copy from
/// @param size maximum number of characters in destination string, including
/// the terminating null character.
/// @return returns the total length of the string they tried to create.
/// @note If the length of src is greater than or equal to size, the string
/// will be truncated.
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

/// @brief Get the length of the string str
/// @param str String to get the length of
/// @return the length of the string str
size_t		ft_strlen(const char *str);

/// @brief Execute the function f on each char of the string s
/// @param s String to iterate over
/// @param f function to execute on each char
/// @return an allocated string with the result of the function f on each char
/// of the string s otherwise NULL
/// @note You must free the returned string
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/// @brief Compare the two strings s1 and s2
/// @param s1 String to compare s1
/// @param s2 String to compare s2
/// @return 0 if the strings are identical, otherwise the difference between the
/// first different char (s1 - s2)
int			ft_strcmp(const char *s1, const char *s2);

/// @brief Compare the two strings s1 and s2 up to n characters or until a `\0'
/// @param s1 String to compare s1
/// @param s2 String to compare s2
/// @param n number of chars to compare maximum
/// @return 0 if the strings are identical, otherwise the difference between the
/// first different char (s1 - s2)
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/// @brief duplicate no more than n character of the string src into a 
//  new allocated string
/// @param str string to copy from
/// @param n number of chars to copy
/// @return A copy of the string src
/// @note You must free the returned string
char		*ft_strndup(const char *str, size_t n);

/// @brief duplicate the string src into a new allocated string
/// @param src string to copy from
/// @return A copy of the string src
/// @note You must free the returned string
char		*ft_strdup(const char *src);

/// @brief search for the first occurence of the string small in the string big
/// @param big string to search into
/// @param small string to search
/// @param n number of chars to search
/// @return returns a pointer to the first occurrence of the string small in the
/// string big, where not more than n characters are searched. Characters that
/// appear after a `\0' character are not searched.
/// @note TODO: pass return as const
char		*ft_strnstr(const char *big, const char *small, size_t n);

/// @brief search for the last occurence of c in the string
/// @param str string to search from
/// @param c char to search
/// @return pointer to the last occurence of c in the string otherwise NULL
/// @note TODO: pass return as const
char		*ft_strrchr(const char *str, int c);

/// @brief remove the specified chars from the string s1
/// @param s1 string to trim
/// @param set characters to remove from s1
/// @return allocated string without the specified chars otherwise NULL
/// @note You must free the returned string
char		*ft_strtrim(char const *s1, char const *set);

/// @brief return a substring of the string s from the specified position
/// @param s string to get the substring
/// @param start position of the substring
/// @param len length of the substring
/// @return allocated string with the substring otherwise NULL
/// @note You must free the returned string
char		*ft_substr(char const *s, unsigned int start, size_t len);

/// @brief search and replace the string to_replace in the string str
/// by the string replace_by
/// @param str String to in which the string will be searched and replaced
/// @param to_replace string to search and replace
/// @param replace_by string to replace with
/// @return the string with the modified chars otherwise NULL
/// @note You must free the returned string
/// @note TODO: pass str as const - clearer signal that it is not modified
char		*ft_str_replace(char *str, const char *to_replace,
				const char *replace_by);

/// @brief replace the chars to_replace in the string by the char replace_by
/// @param str string to in which the char will be replaced
/// @param to_replace char to replace
/// @param replace_by char to replace by
/// @return A pointer to the string str
char		*ft_str_replace_chr(char *str, char to_replace, char replace_by);

/* ************************************************************************** */
/*                        FT_GNL SUB MODULE                                   */
/* ************************************************************************** */

/// @brief Read the next line from the file descriptor
/// @param fd file descriptor to read from
/// @return the next line from the file descriptor otherwise NULL
/// @note You must free the returned string
/// @note You can see the number of supported file descriptor in the macro
/// MAX_FD
char		*get_next_line(int fd);

/// @brief Split the string from the specified position with the specified
/// delimiter
/// @param dst destination of string
/// @param from string to split
/// @param pos position to split from
/// @param delim delimiter to split the string
/// @return -1 if allocation failed, 0 otherwise
int			split_from(char **dst, char *from, int pos, char delim);

/// @brief Search for the first occurence of c in the string
/// @param from string to search from
/// @param c char to search
/// @return the index of the first occurence of c in the string otherwise -1
int			ft_strchr_index(const char *from, char c);

/// @brief Returns a pointer to the first string pointed to by args
/// @param args Pointer to a list of const char pointer
/// @param index Number of elements in Args
/// @return if index is negative or the first string of args
/// is null fails and return null otherwise return the first
/// const char pointed to by args
const char	*ft_shift_args(const char **args, int *index);

// printf

// missing ...

/* ************************************************************************** */
/*                        FT_STRING SUB MODULE                                */
/* ************************************************************************** */

//// TODO: add doc

/* ************************************************************************** */
/* **                     ft_string_new                                    ** */
/* ************************************************************************** */
t_string	*ft_string_new(size_t capacity);

/* ************************************************************************** */
/* **                     ft_string_from                                   ** */
/* ************************************************************************** */
t_string	*ft_string_from(char *str);
t_string	*ft_string_from_n(char *str, size_t n);
t_string	*ft_string_from_c(char c);

/* ************************************************************************** */
/* **                     ft_string_append                                 ** */
/* ************************************************************************** */
int			ft_string_append(t_string *str, char *src);
int			ft_string_append_n(t_string *str, char *src, size_t n);
int			ft_string_append_c(t_string *str, char c);
int			ft_string_append_s(t_string *str, t_string *src);
int			ft_string_append_s_n(t_string *str, t_string *src, size_t n);

/* ************************************************************************** */
/* **                     ft_string_clear                                  ** */
/* ************************************************************************** */
void		ft_string_clear(t_string *str);

/* ************************************************************************** */
/* **                     ft_string_destroy                                ** */
/* ************************************************************************** */
void		ft_string_destroy(t_string **str);

/* ************************************************************************** */
/* **                     ft_string_insert                                 ** */
/* ************************************************************************** */
int			ft_string_insert(t_string *str, char *src, size_t pos);
int			ft_string_insert_n(t_string *str, char *src, size_t pos, size_t n);
int			ft_string_insert_c(t_string *str, char c, size_t pos);
int			ft_string_insert_s(t_string *str, t_string *src, size_t pos);
int			ft_string_insert_s_n(t_string *str, t_string *src, size_t pos,
				size_t n);

/* ************************************************************************** */
/* **						ft_string_reserve                              ** */
/* ************************************************************************** */
int			ft_string_reserve(t_string *str, size_t capacity);

/* ************************************************************************** */
/* **                     ft_string_resize                                 ** */
/* ************************************************************************** */
int			ft_string_resize(t_string *str, size_t size);

/* ************************************************************************** */
/* **                     ft_string_shrink                                 ** */
/* ************************************************************************** */
int			ft_string_shrink(t_string *str);

/* ************************************************************************** */
/* **                     ft_string_substr                                 ** */
/* ************************************************************************** */
t_string	*ft_string_substr(t_string *str, size_t start, size_t len);

/* ************************************************************************** */
/* **                     ft_string_to_str                                 ** */
/* ************************************************************************** */
char		*ft_string_to_str(t_string *str);

/* ************************************************************************** */
/* **                     ft_string_trim                                   ** */
/* ************************************************************************** */
void		ft_string_trim(t_string *str);
void		ft_string_trim_chr(t_string *str, char c);
void		ft_string_trimstr(t_string *str, char *to_trim);

/* ************************************************************************** */
/* **                     ft_string_cmp                                    ** */
/* ************************************************************************** */
int			ft_string_cmp(t_string *str, const char *cmp);
int			ft_string_ncmp(t_string *str, const char *cmp, size_t n);
int			ft_string_cmpstr(t_string *str, t_string *cmp);
int			ft_string_ncmpstr(t_string *str, t_string *cmp, size_t n);

/* ************************************************************************** */
/* **                     ft_string_get                                    ** */
/* ************************************************************************** */
size_t		ft_string_len(t_string *str);
size_t		ft_string_cap(t_string *str);
const char	*ft_string_get(t_string *str);

/* ************************************************************************** */
/* **                     ft_string_set                                    ** */
/* ************************************************************************** */

/// @brief replace the content of the string with the new string src
/// @param str t_string to modify
/// @param src string to copy from
/// @return 1 if the string has been set otherwise 0
int			ft_string_set(t_string *str, const char *src);

/// @brief replace the content of the string with at most n chars of the new
/// string src
/// @param str t_string to modify
/// @param src string to copy from
/// @param n number of chars to set
/// @return 1 if the string has been set otherwise 0
int			ft_string_set_n(t_string *str, const char *src, size_t n);

/// @brief replace the content of the string with the new string src
/// @param str t_string to modify
/// @param src string to set
/// @return 1 if the string has been set otherwise 0
/// @note This function takes ownership of the string src and does no alloc.
int			ft_string_set_inplace(t_string *str, char *src);

/* ************************************************************************** */
/* **                     ft_string_chr                                    ** */
/* ************************************************************************** */
size_t		ft_string_offset(t_string *str, char c);
size_t		ft_string_roffset(t_string *str, char c);
char		*ft_string_chr(t_string *str, char c);
char		*ft_string_rchr(t_string *str, char c);

/* ************************************************************************** */
/* **                     ft_string_replace                                ** */
/* ************************************************************************** */
int			ft_string_replace(t_string *str, char *to_replace,
				char *replace_by);
int			ft_string_replace_chr(t_string *str, char to_replace,
				char replace_by);

#endif // FT_STRING_H