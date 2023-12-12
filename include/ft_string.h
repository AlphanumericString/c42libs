/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:25:27 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/12 18:03:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

// gnl

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
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
/// @param ptr pointer to the source memory
/// @param size size of the source memory
/// @return pointer to a larger chunk of allocated memory otherwise NULL
void		*ft_realloc(void *ptr, size_t size);

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
				int (*cmp)(void *, void *));

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

/// @brief 
/// @param str 
/// @return 
int			ft_atoi(const char *str);

/// @brief 
/// @param str 
/// @param base 
/// @return 
int			ft_atoi_base(const char *str, const char *base);

/// @brief 
/// @param nbr 
/// @return 
char		*ft_itoa(int nbr);

/// @brief 
/// @param nbr 
/// @param base 
/// @return 
char		*ft_itoa_base(int nbr, char *base);

/// @brief 
/// @param nbr 
/// @return 
char		*ft_utoa(unsigned int nbr);

/// @brief 
/// @param str_init 
/// @param delims 
/// @return 
char		*ft_strtok(char *str_init, char *delims);

/// @brief 
/// @param str 
/// @param delim 
/// @return 
char		**ft_split(const char *str, char delim);

/// @brief 
/// @param str 
/// @param c 
/// @return 
char		*ft_strchr(const char *str, int c);

/// @brief 
/// @param strsrc 
/// @return 
char		*ft_strdup(const char *strsrc);

/// @brief 
/// @param s 
/// @param f 
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/// @brief 
/// @param s1 
/// @param s2 
/// @return 
char		*ft_strjoin(char const *s1, char const *s2);

/// @brief 
/// @param dst 
/// @param src 
/// @param size 
/// @return 
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/// @brief 
/// @param dst 
/// @param src 
/// @param size 
/// @return 
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

/// @brief 
/// @param str 
/// @return 
size_t		ft_strlen(const char *str);

/// @brief 
/// @param s 
/// @param f 
/// @return 
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/// @brief 
/// @param s1 
/// @param s2 
/// @return 
int			ft_strcmp(const char *s1, const char *s2);

/// @brief 
/// @param s1 
/// @param s2 
/// @param n 
/// @return 
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/// @brief 
/// @param str 
/// @param n 
/// @return 
char		*ft_strndup(const char *str, size_t n);

/// @brief 
/// @param src 
/// @return 
char		*ft_strdup(const char *src);

/// @brief 
/// @param big 
/// @param small 
/// @param n 
/// @return 
char		*ft_strnstr(const char *big, const char *small, size_t n);

/// @brief 
/// @param str 
/// @param c 
/// @return 
char		*ft_strrchr(const char *str, int c);

/// @brief 
/// @param s1 
/// @param set 
/// @return 
char		*ft_strtrim(char const *s1, char const *set);

/// @brief 
/// @param s 
/// @param start 
/// @param len 
/// @return 
char		*ft_substr(char const *s, unsigned int start, size_t len);

/// @brief 
/// @param str 
/// @param to_replace 
/// @param replace_by 
/// @return 
char		*ft_str_replace(char *str, const char *to_replace,
				const char *replace_by);

/// @brief 
/// @param str 
/// @param to_replace 
/// @param replace_by 
/// @return 
char		*ft_str_replace_chr(char *str, char to_replace, char replace_by);

/* ************************************************************************** */
/*                        FT_GNL SUB MODULE                                   */
/* ************************************************************************** */

/// @brief 
/// @param fd 
/// @return 
char		*get_next_line(int fd);

/// @brief 
/// @param dst 
/// @param from 
/// @param pos 
/// @param delim 
/// @return 
int			split_from(char **dst, char *from, int pos, char delim);

/// @brief 
/// @param from 
/// @param c 
/// @return 
int			ft_strchr_index(const char *from, char c);

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
int			ft_string_set(t_string *str, const char *src);
int			ft_string_set_n(t_string *str, const char *src, size_t n);
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