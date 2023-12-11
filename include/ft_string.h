/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:25:27 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 15:17:11 by bgoulard         ###   ########.fr       */
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

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isupper(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

/* ************************************************************************** */
/* **                     FT_MEM SUB MODULE                                ** */
/* ************************************************************************** */

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t weight);
void		*ft_realloc(void *ptr, size_t size);
void		ft_free(void **ptr);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);

/* ************************************************************************** */
/* **                     FT_PUT SUB MODULE                                ** */
/* ************************************************************************** */

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putnbr_fd(int nbr, int fd);
void		ft_putstr_fd(const char *s, int fd);

/* ************************************************************************** */
/* **                     FT_NBR SUB MODULE                                ** */
/* ************************************************************************** */

int			ft_llogof(long long nbr, int base);
int			ft_ullogof(unsigned long long nbr, int base);
int			ft_logof(int nbr, int base);
int			ft_log(int nbr);
int			ft_min(int a, int b);
int			ft_max(int a, int b);

/* ************************************************************************** */
/* **                     FT_STR MAIN MODULE                               ** */
/* ************************************************************************** */

int			ft_atoi(const char *str);
int			ft_atoi_base(const char *str, const char *base);
char		*ft_itoa(int nbr);
char		*ft_itoa_base(int nbr, char *base);
char		*ft_utoa(unsigned int nbr);
char		*ft_strtok(char *str_init, char *delims);
char		**ft_split(const char *str, char delim);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *strsrc);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strndup(const char *str, size_t n);
char		*ft_strdup(const char *src);
char		*ft_strnstr(const char *big, const char *small, size_t n);
char		*ft_strrchr(const char *str, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_str_replace(char *str, const char *to_replace,
				const char *replace_by);
char		*ft_str_replace_chr(char *str, char to_replace, char replace_by);

/* ************************************************************************** */
/*                        FT_GNL SUB MODULE                                   */
/* ************************************************************************** */

char		*get_next_line(int fd);
int			split_from(char **dst, char *from, int pos, char delim);
int			ft_strchr_index(const char *from, char c);

// printf

// missing ...

/* ************************************************************************** */
/*                        FT_STRING SUB MODULE                                */
/* ************************************************************************** */

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