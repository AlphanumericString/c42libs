/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:25:27 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/08 15:03:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

// malloc + free
# include <stdlib.h>
# include <unistd.h>

// functions

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t weight);
void	ft_free(void **ptr);
int		ft_isalnum(int c);
char	*ft_strtok(char *str_init, char *delims);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
char	*ft_itoa(int nbr);
char	*ft_itoa_base(int nbr, char *base);
char	*ft_utoa(unsigned int nbr);
int		ft_llogof(long long nbr, int base);
int		ft_ullogof(unsigned long long nbr, int base);
int		ft_logof(int nbr, int base);
int		ft_log(int nbr);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putstr_fd(const char *s, int fd);
char	**ft_split(const char *str, char delim);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *strsrc);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *str, size_t n);
char	*ft_strdup(const char *src);
char	*ft_strnstr(const char *big, const char *small, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

// gnl

char	*get_next_line(int fd);
int		split_from(char **dst, char *from, int pos, char delim);
int		ft_strchr_index(const char *from, char c);

// printf

// missing ...

#endif