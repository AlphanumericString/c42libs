/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stris.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:56:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/08 20:56:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRIS_H
# define FT_STRIS_H

# include <stdbool.h>

/// @brief Checks if the string str is composed only of alphabetical characters
/// @param str string to check
/// @return true if the string is composed only of alphabetical characters,
/// false otherwise
bool		ft_str_isalpha(const char *str);

/// @brief Checks if the string str is composed only of alphabetical and
/// numerical characters
/// @param str string to check
/// @return true if the string is composed only of alphabetical and numerical
/// characters, false otherwise
bool		ft_str_isalnum(const char *str);

/// @brief Checks if the string str is comprised of only numbers.
/// @param str string to check
/// @return true if the string is composed only of numerical characters, false
/// otherwise
/// @note This function is not the same as ft_str_isdigit, as it checks for
/// and accepts negative symbols.
bool		ft_str_isnum(const char *str);

/// @brief Checks if the string str is a valid boolean value ("false" ||
/// "true" || "0" || "1")
/// @param str string to check
/// @return true if it ;atches with any of the following: "false" "0" "true" "1"
///  false otherwise
bool		ft_str_isbool(const char *str);

/// @brief Checks if the string str is composed only of numerical characters
/// @param str string to check
/// @return true if the string is composed only of numerical characters, false
/// otherwise
/// @note This function is not the same as ft_str_isnum, as it does not accept
/// ANYTHING other than numerical characters.
bool		ft_str_isdigit(const char *str);

/// @brief Check if the string is a float
/// @param str string to check
/// @return 1 if the string is a float, 0 otherwise
bool		ft_str_isfloat(const char *str);

/// @brief Check if the string is a float
/// @param str string to check
/// @return 1 if the string is a float, 0 otherwise
/// @file: src/ft_string/ft_char/ft_isdouble.c
bool		ft_str_isdouble(const char *str);

/// @brief Check if the string is an int valid value
/// @param str string to check
/// @return 1 if the string is an int, 0 otherwise
bool		ft_str_isint(const char *str);

/// @brief Check if the string is a long
/// @param str string to check
///	@return 1 if the string is a number, 0 otherwise
bool		ft_str_islong(const char *str);

/// @brief check if the string is made of hex base character [0-9A-Fa-f]
/// @param str to check if is made of hex chars
/// @return 1 if the char is a hex character, 0 otherwise
bool		ft_str_ishex(const char *str);

/// @brief check if the string is made of octal base charactes [0-8]
/// @param str string to check
/// @return 1 if the string is an octal number, 0 otherwise
bool		ft_str_isoct(const char *str);

/// @brief Check if the string is valid using a function pointer
/// @param str string to check
/// @param f function pointer to check the string (takes a char c as int
///		and returns 0 if the char is invalid)
/// @return 1 if the string is valid, 0 otherwise
bool		ft_str_isvalid(const char *str, int (*f)(int));

/// @brief check if the string is a valid filename
/// @param str string to check
/// @return 1 if the string is a possible filename, 0 otherwise
bool		ft_str_isfname(const char *str);

/// @brief check if the string is a valid path
/// @param str string to check
/// @return 1 if the string is a possible path, 0 otherwise
bool		ft_str_ispath(const char *str);

#endif /* FT_STRIS_H */
