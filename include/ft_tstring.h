/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:30:09 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/08 23:30:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TSTRING_H
# define FT_TSTRING_H

# include "sys/types.h"
# include "types/ft_string_types.h"

# include <stddef.h>
# include <stdbool.h>

/// @brief create a new t_string
/// @param capacity initial capacity of the string
/// @return a pointer to the new t_string
/// @note You must free the returned string with ft_string_destroy
t_string	*ft_string_new(size_t capacity);

/// @brief create a new t_string from the string
/// @param str string to copy from
/// @return a pointer to the new t_string
/// @note You must free the returned string with ft_string_destroy
/// @note This function does NOT take ownership of the passed string.
t_string	*ft_string_from(const char *restrict str);
/// @brief create a new t_string from the string with at most n chars
/// @param str string to copy from
/// @param n number of chars to copy (including the '\0') "1234" with n = 3
///  -> "123"
/// @return a pointer to the new t_string
/// @note You must free the returned string with ft_string_destroy
t_string	*ft_string_from_n(const char *restrict str, size_t n);
/// @brief create a new t_string from the char c
/// @param c char to copy from
/// @return a pointer to the new t_string
/// @note You must free the returned string with ft_string_destroy
t_string	*ft_string_from_c(char c);
/// @brief create a new t_string from the t_string str
/// @param str t_string to copy from
/// @return a pointer to the new t_string
/// @note You must free the returned string with ft_string_destroy
t_string	*ft_string_from_s(const t_string *restrict str);
/// @brief create a new t_string from the t_string str using at most n chars
/// @param str t_string to copy from
/// @param n number of chars to copy
/// @return a pointer to the new t_string created
/// @note You must free the returned string with ft_string_destroy
t_string	*ft_string_from_s_n(const t_string *restrict str, size_t n);

/// @brief write the string on the specified file descriptor
/// @param str t_string to write
/// @param fd file descriptor to write on
/// @return the return of write if the fd and str are valid otherwise -1
int			ft_string_put(const t_string *restrict str, int fd);

/// @brief append the string src to the string str
/// @param str t_string to modify
/// @param src string to append
/// @return true if the string has been appended otherwise false
bool		ft_string_append(t_string *restrict str, const char *src);
/// @brief append at most n chars of the string src to the string str
/// @param str t_string to modify
/// @param src string to append
/// @param n number of chars to append
/// @return true if the string has been appended otherwise false
bool		ft_string_append_n(t_string *restrict str, const char *src,
				size_t n);
/// @brief append the char c to the string str
/// @param str t_string to modify
/// @param c char to append
/// @return true if the string has been appended otherwise false
bool		ft_string_append_c(t_string *restrict str, char c);
/// @brief append the string src to the string str
/// @param str t_string to modify
/// @param src string to append
/// @return true if the string has been appended otherwise false
bool		ft_string_append_s(t_string *restrict str,
				const t_string *restrict src);
/// @brief append at most n chars of the string src to the string str
/// @param str t_string to modify
/// @param src string to append
/// @param n number of chars to append
/// @return true if the string has been appended otherwise false
bool		ft_string_append_s_n(t_string *restrict str,
				const t_string *restrict src, size_t n);

/// @brief clear the string
/// @param str t_string to clear
/// @note the string is not freed but the content is cleared
void		ft_string_clear(t_string *restrict str);

/// @brief free the string
/// @param str pointer to the t_string to free
void		ft_string_destroy(t_string **str);

/// @brief insert the string src in the string str at the specified position
/// @param str t_string to modify
/// @param src string to insert
/// @param pos position to insert the string
/// @return true if the string has been inserted otherwise false
bool		ft_string_insert(t_string *str, const char *restrict src,
				size_t pos);
/// @brief insert at most n chars of the string src in the string str at the
/// specified position
/// @param str t_string to modify
/// @param src string to insert
/// @param pos position to insert the string
/// @param n number of chars to insert
/// @return true if the string has been inserted otherwise false
bool		ft_string_insert_n(t_string *str, const char *restrict src,
				size_t pos, size_t n);
/// @brief insert the char c in the string str at the specified position
/// @param str t_string to modify
/// @param c char to insert
/// @param pos position to insert the char
/// @return true if the string has been inserted otherwise false
bool		ft_string_insert_c(t_string *str, char c, size_t pos);
/// @brief insert the string src in the string str at the specified position
/// @param str t_string to modify
/// @param src string to insert
/// @param pos position to insert the string
/// @return true if the string has been inserted otherwise false
bool		ft_string_insert_s(t_string *str, const t_string *restrict src,
				size_t pos);
/// @brief insert at most n chars of the string src in the string str at the
/// specified position
/// @param str t_string to modify
/// @param src string to insert
/// @param pos position to insert the string
/// @param n number of chars to insert
/// @return true if the string has been inserted otherwise false
bool		ft_string_insert_s_n(t_string *str, const t_string *src,
				size_t pos, size_t n);

/// @brief reserve the specified capacity for the string
/// @param str t_string to modify
/// @param capacity capacity to reserve
/// @return true if the string has been reserved otherwise false
bool		ft_string_reserve(t_string *str, size_t capacity);

/// @brief resize the string to the specified size
/// @param str t_string to modify
/// @param size size to resize
/// @return true if the string has been resized otherwise false
/// @note if the size is smaller than the current size, the string is truncated
bool		ft_string_resize(t_string *str, size_t size);

/// @brief shrink the string to the minimum size
/// @param str t_string to modify
/// @return true if the string has been shrinked otherwise false
bool		ft_string_shrink(t_string *restrict str);

/// @brief return a substring of the string str from the specified position
/// @param str t_string to get the substring
/// @param start position of the substring
/// @param len length of the substring
/// @return allocated string with the substring otherwise NULL
/// @note You must free the returned string. use ft_string_destroy.
t_string	*ft_string_substr(const t_string *restrict str,
				size_t start, size_t len);

/// @brief convert the t_string to a string
/// @param str t_string to convert
/// @return allocated string with the content of the t_string otherwise NULL
/// @note You must free the returned string.
/// @note The t_string is not freed or modified.
char		*ft_string_to_str(t_string *restrict str);

/// @brief trim the characters ' ' from the string
/// @param str t_string to trim
/// @note the inner string is not freed but the content modified.
void		ft_string_trim(t_string *restrict str);
/// @brief trim the specified char from the string
/// @param str t_string to trim
/// @param c char to trim
/// @note the inner string is not freed but the content modified.
void		ft_string_trim_chr(t_string *restrict str, char c);
/// @brief trim the specified chars from the string
/// @param str t_string to trim
/// @param to_trim chars to trim from the string
/// @note The inner string is not freed but the content modified.
void		ft_string_trimstr(t_string *restrict str, const char *to_trim);

/// @brief compare the string with the string cmp
/// @param str t_string to compare
/// @param cmp string to compare
/// @return 0 if the strings are identical, otherwise the difference between the
/// first different char (s1 - s2)
int			ft_string_cmp(const t_string *restrict str,
				const char *restrict cmp);
/// @brief compare the string with the string cmp up to n chars
/// @param str t_string to compare
/// @param cmp string to compare
/// @param n number of chars to compare
/// @return 0 if the strings are identical, otherwise the difference between the
/// first different char (s1 - s2)
int			ft_string_ncmp(const t_string *restrict str,
				const char *restrict cmp, size_t n);
/// @brief compare the string with the string cmp
/// @param str t_string to compare
/// @param cmp string to compare
/// @return 0 if the strings are identical, otherwise the difference between the
/// first different char (s1 - s2)
int			ft_string_cmpstr(const t_string *restrict str,
				const t_string *restrict cmp);
/// @brief compare the string with the string cmp up to n chars
/// @param str t_string to compare
/// @param cmp string to compare
/// @param n number of chars to compare
/// @return 0 if the strings are identical, otherwise the difference between the
/// first different char (s1 - s2)
int			ft_string_ncmpstr(const t_string *restrict str,
				const t_string *restrict cmp, size_t n);

/// @brief get the length of the string
/// @param str t_string to get the length
/// @return the length of the string
size_t		ft_string_len(const t_string *restrict str);

/// @brief get the capacity of the string
/// @param str t_string to get the capacity
/// @return the capacity of the string
size_t		ft_string_cap(const t_string *restrict str);

/// @brief get the content of the string
/// @param str t_string to get the content
/// @return the content of the string
const char	*ft_string_get(const t_string *restrict str);

/// @brief replace the content of the string with the new string src
/// @param str t_string to modify
/// @param src string to copy from
/// @return true if the string has been set otherwise false
bool		ft_string_set(t_string *restrict str, const char *restrict src);
/// @brief replace the content of the string with at most n chars of the new
/// string src
/// @param str t_string to modify
/// @param src string to copy from
/// @param n number of chars to set (including the '\0') "1234" with n = 3
/// -> "123"
/// @return true if the string has been set otherwise false
bool		ft_string_set_n(t_string *restrict str,
				const char *restrict src, size_t n);
/// @brief replace the content of the string with the new string src
/// @param str t_string to modify
/// @param src string to set
/// @return true if the string has been set otherwise false
/// @note This function takes ownership of the string src and does no alloc.
bool		ft_string_set_inplace(t_string *restrict str, char *restrict src);

/// @brief search for the first occurence of c in the string
/// @param str t_string to search from
/// @param c char to search
/// @return an offset to the first occurence of c in the string otherwise -1
ssize_t		ft_string_offset(const t_string *restrict str, char c);
/// @brief search for the last occurence of c in the string
/// @param str t_string to search from
/// @param c char to search
/// @return an offset to the last occurence of c in the string otherwise -1
ssize_t		ft_string_roffset(const t_string *restrict str, char c);

/// @brief search for the first occurence of c in the string
/// @param str t_string to search from
/// @param c char to search
/// @return a pointer to the first occurence of c in the string otherwise NULL
char		*ft_string_chr(const t_string *restrict str, char c);
/// @brief search for the last occurence of c in the string
/// @param str t_string to search from
/// @param c char to search
/// @return a pointer to the last occurence of c in the string otherwise NULL
char		*ft_string_rchr(const t_string *restrict str, char c);

/// @brief search and replace the string to_replace in the string str
/// by the string replace_by
/// @param str t_string to in which the string will be searched and replaced
/// @param to_replace string to search and replace
/// @param replace_by string to replace with
/// @return true if the string has been replaced otherwise false
bool		ft_string_rpl(t_string *restrict str,
				const char *restrict to_replace,
				const char *restrict replace_by);
/// @brief search and replace the string to_replace in the string str
/// by the string replace_by
/// @param str t_string to in which the string will be searched and replaced
/// @param to_replace string to search and replace
/// @param replace_by string to replace with
/// @return true if the string has been replaced otherwise false
bool		ft_string_rpl_chr(t_string *restrict str, char to_replace,
				char replace_by);

#endif  /* FT_TSTRING_H */
/*
GPL-3.0 License:
c42libs - Library for c projects at 42.
Copyright (C) 2025  baptiste GOULARD

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
