/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:25:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/16 23:34:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

/* ************************************************************************** */
/* 					                                                          */
/* Module: FT_STRING														  */
/* Prefix:	ft_, ft_string (t_string)										  */
/*																		      */
/* This module provides a usefull c function for manipulationg string and     */
/*		manipulating memory. It also includes the type t_string a string that */
/*		caches it's malloc and allocates by chunks instead of 'JIT' in the	  */
/*		code.																  */
/*																			  */
/* ************************************************************************** */

// sys types
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <sys/types.h>
# include <stdarg.h>

// self types
# include "ft_defs.h"
# include "types/ft_string_types.h"

/* ************************************************************************** */
/*							   FT_PUT SUB MODULE                              */
/* ************************************************************************** */

// TODO:
//	justify_to -> justify a string to a number n by splitting and adding the
//		minimum of number space between each words

/// @brief Print the string s if present to STDERR followed by the erno error
/// code as a string
/// @param s String to print before the error code
void		ft_perror(const char *s);
/// @brief print the string on the specified file descriptor followed by a new
/// line
/// @param s string to print
/// @param fd file descriptor to print on
int			ft_putendl_fd(const char *s, int fd);
/// @brief print the string on the specified file descriptor
/// @param s string to print
/// @param fd file descriptor to print on
/// @return The value returned bu the write syscall
/// @note Does minimal processing to not change the errno values in case of
///  error.
int			ft_putstr_fd(const char *s, int fd);

/// @brief print the number on the specified file descriptor using base10
/// @param nbr string to print
/// @param fd file descriptor to print on
/// @return The value returned bu the write syscall
int			ft_putnbr_fd(int nbr, int fd);
/// @brief print the number on the specified file descriptor using given base
/// @param nb string to print
/// @param base the base to use for the conversion
/// @param fd file descriptor to print on
/// @return The value returned bu the write syscall
int			ft_putnbr_base_fd(ssize_t nb, const char *base, int fd);
/// @brief print the number on the specified file descriptor using given base
/// @param nb string to print
/// @param base the base to use for the conversion
/// @param fd file descriptor to print on
/// @return The value returned bu the write syscall
int			ft_putunbr_base_fd(size_t nb, const char *base, int fd);

/// @brief returns either a string representation of the double value
/// or NULL if the value is not a special value (inf, -inf, nan)
/// @param maj true if the string should be in upper case, false otherwise
/// @param val double value to check
/// @return a pointer to a constant string representing the special value
const char	*flt_spevals(bool maj, double val);
/// @brief print the double value on the specified file descriptor
/// @param value double value to print
/// @param fd file descriptor to print on
/// @return	return the number of character written to fd or -1
int			ft_putdbl_fd(double value, int fd);

/// @brief Print the string str on the specified file descriptor with the
/// specified format (only sdiuxXcspfFeEm)
/// @param fd file descriptor to print on
/// @param str string to print
/// @param ... variable arguments to format the string
/// @return the number of printed characters
int			ft_print_fd(int fd, const char *str, ...);
/// @brief Print the string str on the specified file descriptor with the
/// specified format (only sdiuxXcspfFeEm)
/// @param fd file descriptor to print on
/// @param str string to print
/// @param args	the va_list containing the arguments for the format string
/// @return the number of printed characters
int			ft_vaprint_fd(int fd, const char *str, va_list args);
/// @brief Print the string str on STDOUT with the specified format
///		(only sdiuxXcspfFeEm)
/// @param str string to print
/// @param ... variable arguments to format the string
/// @return the number of printed characters
int			ft_print(const char *str, ...);
/// @brief Print the string str on STDERR with the specified format
///		(only sdiuxXcspfFeEm)
/// @param str string to print
/// @param ... variable arguments to format the string
/// @return the number of printed characters
int			ft_print_err(const char *str, ...);

/* ************************************************************************** */
/* **                      FT_NUM SUB MODULE                               ** */
/* ************************************************************************** */

/// @brief convert the string to a int
/// @param str string to convert
/// @return the number converted from the string
int			ft_atoi(const char *str);
/// @brief convert the string to a double
/// @param str string to convert
/// @return the number converted from the string
double		ft_atod(const char *str);
/// @brief convert the string to a long
/// @param str string to convert
/// @return the number converted from the string
long		ft_atol(const char *str);
/// @brief convert the string to a long long
/// @param str string to convert
/// @return the number converted from the string
long long	ft_atoll(const char *str);
// TODO: missing u f

/// @brief convert the string to a int in the specified base
/// @param str string to convert
/// @param base base of the string
/// @return the number converted from the string
int			ft_atoi_base(const char *str, const char *base);
/// @brief convert the string to a long from the given base
/// @param str string to convert
/// @param base base of the string
/// @return the number converted from the string
long		ft_atol_base(const char *str, const char *base);
/// @brief convert the string to a long long from the given base
/// @param str string to convert
/// @param base base of the string
/// @return the number converted from the string
long long	ft_atoll_base(const char *str, const char *base);
// TODO: missing f u

/// @brief convert the int to a string
/// @param nbr number to convert
/// @return pointer to the string.
/// @note You must free the returned string
char		*ft_itoa(int nbr);
/// @brief convert the unsigned int to a string
/// @param nbr number to convert
/// @return pointer to the string.
/// @note You must free the returned string
char		*ft_utoa(unsigned int nbr);
// TODO: missing: f l ll

/// @brief convert the int to a string in the specified base
/// @param nbr number to convert
/// @param base base of the string to return.
/// @return pointer to the string.
/// @note You must free the returned string
char		*ft_itoa_base(int nbr, const char *base);
/// @brief convert the unsigned int to a string in the specified base
/// @param nbr number to convert
/// @param base base of the string to return.
/// @return pointer to the string.
/// @note You must free the returned string
char		*ft_utoa_base(unsigned int nbr, const char *base);
/// @brief convert the signed size_t to a string in the specified base
/// @param nbr number to convert
/// @param base base of the string to return.
/// @return pointer to the string.
/// @note You must free the returned string
char		*ft_sstoa_base(ssize_t nbr, const char *base);
/// @brief convert the size_t to a string in the specified base
/// @param nbr number to convert
/// @param base base of the string to return.
/// @return pointer to the string.
/// @note You must free the returned string
char		*ft_stoa_base(size_t nbr, const char *base);
// TODO: missing: f ll

/// @brief convert the size_t to a pointed array in the specified base
/// @param nbr	number to convert
/// @param base	base of the string to return with ordered digits
/// @param ptr	The pointer to the array to write to
/// @param max	The maximum size of the array buffer
/// @return true if sucessfull otherwise false.
/// @note the size 'max' of the pointed array includes the space for a '\0'
///		so writing '42' would take 3 as minimum for max. with 2 spaces for 42
///		and one for the null-byte.
bool		ft_stopa_base(size_t nbr, const char *base, char *ptr,\
				size_t max);
/// @brief convert the signed size_t to a pointed array in the specified base
/// @param nbr	number to convert
/// @param base	base of the string to return with ordered digits
/// @param ptr	The pointer to the array to write to
/// @param max	The maximum size of the array buffer
/// @return true if sucessfull otherwise false.
/// @note the size 'max' of the pointed array includes the space for a '\0'
///		so writing '42' would take 3 as minimum for max. with 2 spaces for 42
///		and one for the null-byte.
bool		ft_sstopa_base(ssize_t nbr, const char *base, char *ptr,\
				size_t max);
// TODO: missing: f d

/// @brief Check if a string is a valid base for numbers
/// @param base string to check
/// @return true if the base is valid, false otherwise
bool		ft_base_valid(const char *base);

/* ************************************************************************** */
/* **                     FT_STR MAIN MODULE                               ** */
/* ************************************************************************** */

// ---
// str - conversions
// ---

/// @brief Return a pointer to a constant string describing the error code
/// @param errnum Error code
/// @return A pointer to a constant string describing the error code
/// @note The returned pointer can be null if errnum is out of range (0 - 133)
/// @warning Not thread safe on errno > 133. (returns a poitner to a static
///  string array "Unkown error \d\d\d").
const char	*ft_strerror(int errnum);

/// @brief Read the next line from the file descriptor
/// @param fd file descriptor to read from
/// @return the next line from the file descriptor otherwise NULL
/// @note You must free the returned string
/// @note You can see the number of supported file descriptor in the macro
/// MAX_FD
/// @warning: this function is not thread safe.
char		*ft_gnl(int fd);
/// @brief Read the next line from the file descriptor using the provided buffer
/// as a persistent buffer between calls
/// @param fd file descriptor to read from
/// @param buffer pointer to the buffer to use between calls
/// @return the next line from the file descriptor otherwise NULL
/// @note You must free the returned string
/// @note This function is thread safe if each thread uses its own buffer
char		*ft_gnl_r(int fd, char **buffer);
/// @brief Read the next line from the file descriptor using the provided buffer
/// as a persistent buffer between calls
/// @param fd file descriptor to read from
/// @param buffer pointer to the buffer to use between calls
/// @param buffer_size size of the provided buffer
/// @return the next line from the file descriptor otherwise NULL
/// @note You must free the returned string
/// @note This function is thread safe if each thread uses its own buffer
char		*ft_gnl_rn(int fd, char *buffer, ssize_t buffer_size);

/// @brief load the content of the file descriptor into a string
/// @param fd file descriptor to read from
/// @return pointer to the string otherwise NULL
/// @note You must free the returned string
char		*ft_fd_to_buff(int fd);

// ---
// str - modifs : function that modify the strings
// ---

/// @brief Removes consecutives ' ' characters in the string.
/// @param	str the string to opearate on
/// @return the string being given
char		*ft_strrmdup_space(char *str);
/// @brief Removes consecutives isspace characters in the string.
/// @param	str the string to opearate on
/// @return the string being given
char		*ft_strrmdup_spaceall(char *str);
/// @brief The function suite of ft_strrmdup removes the duplicate characters
/// in string.
/// @param	str the string to opearate on
/// @param	set the character to check to duplications
/// @return the string being given
char		*ft_strrmdup(char *str, const char *set);
/// @brief The function suite of ft_strrmdup removes the duplicate characters
/// in string.
/// @param	str the string to opearate on
/// @param	set the character to check to duplications
/// @param	n	Number of bytes to check for dups
/// @return the string being given.
char		*ft_strnrmdup(char *str, const char *set, size_t n);

/// @brief Convert a string to uppercase
/// @param str String to convert
/// @return returns the string pointer to the capitalized string
char		*ft_strupper(char *str);
/// @brief Convert a string to uppercase
/// @param str String to convert
/// @param n	Number of bytes to upperize in the string.
/// @return returns the string pointer to the capitalized string
char		*ft_strnupper(char *str, size_t n);

/// @brief Convert a string to lowercase
/// @param str	String to convert
/// @return returns the string pointer to the 'lowerize' string
char		*ft_strlower(char *str);
/// @brief Convert a n caharters of a string to lowercase
/// @param str	String to convert
/// @param n	Number of bytes to lowerize in the string.
/// @return returns the string pointer to the 'lowerize' string
char		*ft_strnlower(char *str, size_t n);

/// @brief Capitalize the first letter of each word in a string
/// @param str String to capitalize
/// @return returns the string pointer to the capitalized string
char		*ft_strcapitalize(char *str);
/// @brief Capitalize the first letter of each word in a string in the first
///  n bytes
/// @param str	String to capitalize
/// @param n	Number of bytes to check for capitalization in the string
/// @return returns the string pointer to the capitalized string
char		*ft_strncapitalize(char *str, size_t n);
/// @brief Capitalize the first letter of the first n words in a string
/// @param str	String to capitalize
/// @param nb_words	Number of words to capitalize in the string
/// @return returns the string pointer to the capitalized string
/// @note A word is defined as a sequence of characters separated by spaces
///		(isspace) and in the case of "a 1b c" the '1b' is considered a word and
///		is neither capitalized nor skipped. as such the result of
///		"a 1b c" with nb_words = 2 is "A 1b c" and not "A 1b C"
char		*ft_strnwcapitalize(char *str, size_t nb_words);
/// @brief Capitalize the first letter of each sentence in a string
/// @param str String to capitalize
/// @return returns the string pointer to the capitalized string
char		*ft_strcapitalize_grammar(char *str);

/// @brief Justify a string in place by replacing a space ' ' to a '\n' after
///	 the last word before width charater
///	@param str String to justify
///	@param width integer width to justify to
///	@return the string justified
///	@note
///	In case of word bigger than width the word is left whole
///	eg:
///	"this is a long woooooooooord" 5
/// "this\nis a\nlong\nwoooooooooord"
/// (the '\n' is counted in the length of the line)
/// @note does not remove consecutives spaces in the string
char		*ft_strwlgn_inplace(char *str, size_t width);
/// @brief justify a constant string to an allocated justified string
///  without inserting spaces
/// @param str the string to justify and duplicate
/// @param width the width to justify to
/// @return the string allocated and justified or NULL if alloaction failed
/// @note You must free the returned string
char		*ft_strwlgn_nospace(const char *str, size_t width);

/// @brief	Add up two strings s1 and s2 and return the result
/// @param	s1 String to add
/// @param	s2 String to add
/// @return	The result of the addition of the two strings
/// @note	You must free the returned string
char		*ft_strjoin(char const *s1, char const *s2);
/// @brief	Add up a char c at the end of a pre-existing and allocated string
/// @param	str String to append to
/// @param	c Char to append
/// @return The new string with the char appended at the end
///	@note	If the string fails to be allocated the string *str is not freed
///	but NULL will be returned. Otherwise the string *str is replaced by the
///	new string with the char appended at the end.
///	@note	You must free the returned string
char		*ft_strappend_c(char **str, char c);

/// @brief copy up to size - 1 characters from the NULL-terminated string src
/// to dst, NULL-terminating the result.
/// Puts the result after the characters already in dst.
/// @param dst string to copy to
/// @param src string to copy from
/// @param size maximum number of characters in destination string, including
/// the terminating null character.
/// @return returns the total length of the string they tried to create.
size_t		ft_strlcat(char *dst, const char *src,
				size_t size);
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
size_t		ft_strlcpy(char *dst, const char *src,
				size_t size);

/// @brief Reverse the string s
/// @param s string to reverse
void		ft_strrev(char *s);
/// @brief Reverse the string s
/// @param s string to reverse
/// @param n number of bytes to reverse in the string
/// @note if n is greater than strlen uses strlen as n
void		ft_strnrev(char *s, size_t n);

/// @brief replace the chars to_replace in the string by the char replace_by
/// @param str string to in which the char will be replaced
/// @param to_replace char to replace
/// @param replace_by char to replace by
/// @return A pointer to the string str
/// @note The string is modified in place
char		*ft_strrpl_chr(char *str, char to_replace,
				char replace_by);
/// @brief replace the chars in to_replace by the char replace_by
/// @param str string to in which the chars will be replaced
/// @param to_replace string of char to replace
/// @param replace_by string of char to replace by
/// @return A pointer to the string str
/// @note The string is modified in place, and the replace_by is indexed using
///		a modulo of the length. eg:
///		to_replace = "abcd" replace_by = "123" str = "aabbccdd"
///		-> "11223311"
char		*ft_strrpl_chrs(char *str, const char *to_replace,
				const char *replace_by);
/// @brief replace the char srch in the first n bytes of the string by the
///		char rpl
///	@param str string to in which the char will be replaced
///	@param n number of bytes to check in the string
///	@param srch char to replace
///	@param rpl char to replace by
///	@return A pointer to the string str
char		*ft_strnrpl_chr(char *str, size_t n, char srch, char rpl);
/// @brief replace the chars str from the set of srch by the chars from the set
///		rpl_by in the first n bytes of the string
///	@param str string to in which the chars will be replaced
///	@param n number of bytes to check in the string
///	@param srch string of char to replace
///	@param rpl_by string of char to replace by
///	@return A pointer to the string str
char		*ft_strnrpl_chrs(char *str, size_t n, const char *srch,
				const char *rpl_by);

/// @brief remove the specified chars from the string s1 in place without alloc
/// @param s1 string to trim
/// @param set characters to remove from s1
/// @return A pointer to the string s1
char		*ft_strtrim_inplace(char *s1, const char *set);

/// @brief Iterate over the string s and execute the function f on each char
/// @param s String to iterate over
/// @param f Function to execute on each char
/// @note The first parameter of the function f is the index of the char in the
/// string s.
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

// ---
// str - finds : functions that find stuff in strings
// ---

/// @brief Get the length of the string str
/// @param str String to get the length of
/// @return the length of the string str
size_t		ft_strlen(const char *str);
/// @brief Get the length of the string without exceeding max
/// @param str String to get the length of
/// @param max Maximum length of the string
/// @return the length of the string str up to max
size_t		ft_strnlen(const char *str, size_t max);

/// @brief Get the length of the string str up to the first occurence of c
/// @param str String to get the length of
/// @param c Char to search
/// @return the length of the string str up to the first c, if c is not found
/// the length of the string str
size_t		ft_strclen(const char *str, char c);
/// @brief Get the length of the string str up to the first occurence of c or
///		n bytes being read
///	@param str String to get the length of
///	@param n Maximum number of bytes to read
///	@param c Char to search
///	@return the length of the string str up to the first c or n bytes being
///		read or the length of the string str whichever comes first.
///		If c is not found in the first n bytes returns n or strlen of str
size_t		ft_strnclen(const char *str, size_t n, char c);

/// @brief Get the number of occurance of char c in string str
/// @param str String to search from
/// @param c Char to search
/// @return the number of occurance of char c in string str
size_t		ft_strcnb(const char *str, char c);
/// @brief Get the number of occurance of char c in the first n bytes of string
///		str.
/// @param str String to search from
/// @param n Maximum number of bytes to search
/// @param c Char to search
/// @return the number of occurance of char c in string str
size_t		ft_strncnb(const char *str, size_t n, char c);

/// @brief strtok - str tokenzier
/// @param str_init string to search into
/// @param delims string of delimiters
/// @return Return a pointer to the first 'word' in a string using the charaters
///		in the string delims as delimiters.
/// @warning:
///		1. this function is not thread safe.
///		2. you lose the information on the separator that was used to split
///		3. this modify the string str
char		*ft_strtok(char *str_init, const char *delims);
/// @brief strtok_r - str tokenzier reentrant
/// @param str string to search into (should be NULL on subsequent calls)
/// @param delims string of delimiters
/// @param saveptr a string pointer that 'holds' the value in between calls
///  of the function.
/// @return a pointer to the first word separated by character in the string
///  delims str otherwise NULL
/// @warning: you lose the information on the separator that was used to split,
///		and this modifies the string str.
char		*ft_strtok_r(char *str, const char *delims, char **saveptr);

/// @brief Calculate the length of the starting segment of str that contain
/// char from the accept string
/// @param str String to search from
/// @param accept String of the valid char
/// @return The calculated length.
size_t		ft_strspn(const char *str, const char *accept);
/// @brief Calculate the length of the starting segment of str that don't
/// contain chars from the exclude string
/// @param str String to search from
/// @param exclude String of char to exclude
/// @return The calculated length.
size_t		ft_strcspn(const char *str, const char *exclude);

/// @brief search for the first occurence of the string small in the string big
/// @param big string to search into
/// @param small string to search
/// @return returns a pointer to the first occurrence of the string small in the
/// string big, where not more than n characters are searched. Characters that
/// appear after a '\0' character are not searched.
/// @note The returned pointer is from str and has the same constness as str
///  it was left as non-const to align with glibc's strnstr
char		*ft_strstr(const char *big, const char *small);
/// @brief search for the first occurence of the string small in the string big
/// @param big string to search into
/// @param small string to search
/// @param n minimum number of characters to search
/// @return returns a pointer to the first occurrence of the string small in the
/// string big, where not more than n characters are searched. Characters that
/// appear after a '\0' character are not searched.
/// @note The returned pointer is from str and has the same constness as str
///  it was left as non-const to align with glibc's strnstr
char		*ft_strnstr(const char *big, const char *small,
				size_t n);

/// @brief Search for the first occurence of the char c in the string str
/// @param str string to search into
/// @param c char to search
/// @return a pointer to the first occurence of c in the string str otherwise
/// NULL
/// @note The returned pointer is from str and has the same constness as str
///  it was left as non-const to align with glibc's strchr
char		*ft_strchr(const char *str, int c);
/// @brief Search for the first occurence of the char c in the string str
/// @param str string to search into
/// @param c char to search
/// @return a pointer to the first occurence of c in the string str otherwise
/// to the \0 at the end.
/// @note The returned pointer is from str and has the same constness as str
///  it was left as non-const to align with glibc's strchr
char		*ft_strchr_null(const char *str, int c);
/// @brief Search for the first occurence of the char c in the string str up to
///		n bytes.
/// @param str string to search into
/// @param n maximum number of bytes to search
/// @param c char to search
/// @return a pointer to the first occurence of c in the string str otherwise
/// NULL
/// @note The returned pointer is from str and has the same constness as str
///  it was left as non-const to align with glibc's strchr
char		*ft_strnchr(const char *str, size_t n, int c);
/// @brief Search for the first occurence of the char c in the string str
/// @param str string to search into
/// @param n maximum number of bytes to search
/// @param c char to search
/// @return a pointer to the first occurence of c in the string str otherwise
/// to the \0 at the end.
/// @note The returned pointer is from str and has the same constness as str
///  it was left as non-const to align with glibc's strchr
char		*ft_strnchr_null(const char *str, size_t n, int c);

/// @brief search for the last occurence of c in the string
/// @param str string to search from
/// @param c char to search
/// @return pointer to the last occurence of c in the string otherwise NULL
/// @note The returned pointer is from str and has the same constness as str
///  it was left as non-const to align with glibc's strrchr
char		*ft_strrchr(const char *str, int c);
/// @brief search for the last occurence of c in the string up to n bytes
/// @param str string to search from
/// @param n maximum number of bytes to search
/// @param c char to search
/// @return pointer to the last occurence of c in the string otherwise NULL
/// @note The returned pointer is from str and has the same constness as str
///  it was left as non-const to align with glibc's strrchr
char		*ft_strnrchr(const char *str, size_t n, int c);

//TODO:
//	implement:
//	ft_strchr_set(const char *str, const char *set);
//	ft_strrchr_set(const char *str, const char *set);
//	-> like str[r]chr but search for any char in set
//	ft_strnchr_set(const char *str, const char *set, size_t n);
//	ft_strnrchr_set(const char *str, const char *set, size_t n);
//	-> like strn[r]chr but search for any char in set until nth bytes

// TODO:
//  ft_strcount(const char *str, const char *sub);
//  ft_strcount_c(const char *str, char c);
//  -> count the number of occurence of sub|c in str

// ---
// str - comparators : functions that compare strings
// ---

/// @brief Compare the two strings s1 and s2
/// @param s1 String to compare s1
/// @param s2 String to compare s2
/// @return 0 if the strings are identical, otherwise the difference between the
/// first different char (s1 - s2)
int			ft_strcmp(const char *s1, const char *s2);
/// @brief Compare the two strings s1 and s2 up to n characters or until a '\0'
/// @param s1 String to compare s1
/// @param s2 String to compare s2
/// @param n number of chars to compare maximum
/// @return 0 if the strings are identical, otherwise the difference between the
/// first different char (s1 - s2)
int			ft_strncmp(const char *s1, const char *s2,
				size_t n);
/// @brief Compare the two strings s1 and s2 in reverse order up to n bytes
/// @param s1 String to compare s1
/// @param s2 String to compare s2
/// @param n number of chars to compare maximum
/// @return 0 if the strings are identical, otherwise the difference between
///  the last different char (s1 - s2)
int			ft_strnrcmp(const char *s1, const char *s2,
				size_t n);
/// @brief Compare the two strings s1 and s2 being case insensitive
/// @param s1 String to compare s1
/// @param s2 String to compare s2
/// @return 0 if the strings are identical, otherwise the difference between
///  the first case insensitive different char (s1 - s2)
int			ft_stricmp(const char *s1, const char *s2);
/// @brief Compare the two strings s1 and s2 being case insensitive up to n
///  bytes or until a '\0'
/// @param s1 String to compare s1
/// @param s2 String to compare s2
/// @param n number of chars to compare maximum
/// @return 0 if the strings are identical, otherwise the difference between
///  the first case insensitive different char (s1 - s2) up to n bytes
int			ft_strnicmp(const char *s1, const char *s2,
				size_t n);

/// @brief search if the string str ends with the string end
/// @param str string to search from
/// @param end string to search
/// @return 1 if the string str ends with the string end, 0 otherwise
int			ft_strend_with(const char *str, const char *end);
/// @brief search if the string str starts with the string start
/// @param str string to search from
/// @param start string to search
/// @return 1 if the string str starts with the string start, 0 otherwise
int			ft_strstart_with(const char *str,
				const char *start);
// TODO: ft_str[i][n][end|start]_with -> n : n byte, i : case insensitive
// TODO: ft_str_contains -> strstr but return bool

// ---
// str - copy operations : copies string (generally also does another action)
// ---

/// @brief duplicate the string src into a new allocated string
/// @param src string to copy from
/// @return A copy of the string src
/// @note You must free the returned string
char		*ft_strdup(const char *src);
/// @brief duplicate no more than n character of the string src into a
///  new allocated string
/// @param str string to copy from
/// @param n number of chars to copy
/// @return A copy of the string src
/// @note You must free the returned string
char		*ft_strndup(const char *str, size_t n);

/// @brief return a substring of the string s from the specified position
/// @param s string to get the substring
/// @param start position of the substring
/// @param len length of the substring
/// @return allocated string with the substring otherwise NULL
/// @note You must free the returned string
char		*ft_substr(char const *s, unsigned int start, size_t len);

/// @brief remove the specified chars from the string s1
/// @param s1 string to trim
/// @param set characters to remove from s1
/// @return allocated string without the specified chars otherwise NULL
/// @note You must free the returned string
char		*ft_strtrim(char const *s1, char const *set);

/// @brief search and replace the string to_replace in the string str
/// by the string replace_by
/// @param str String to in which the string will be searched and replaced
/// @param to_replace string to search and replace
/// @param replace_by string to replace with
/// @return the string with the modified chars otherwise NULL
/// @note to_replace and replace_by must not be NULL
/// @note You must free the returned string !
char		*ft_strrpl(const char *str,
				const char *to_replace,
				const char *replace_by);

/// @brief Execute the function f on each char of the string s
/// @param s String to iterate over
/// @param f function to execute on each char
/// @return an allocated string with the result of the function f on each char
/// of the string s otherwise NULL
/// @note You must free the returned string
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/// @brief Split the string str with the specified delimiter
/// @param str String to split
/// @param delim Char to split the string
/// @return A pointer to the array of string
/// @note You must free the returned array of string and its content
char		**ft_split(const char *str, char delim);
/// @brief Same as ft_split but with multiple delimiters
/// @param str string to split
/// @param delims delimiters to split the string
/// @return a pointer to the array of string
/// @note You must free the returned array of string and its content
char		**ft_splits(const char *str, const char *delims);

/// @brief justify a string to width characters by packing the maximum amount
///  of words in a line and adding ' ' between each of said words to ga a
///  string with uniform line lengths
/// @param src the string to justify
/// @param width the width to justify to.
/// @return the justified allocated string or NULL if allocation failed
/// @note You must free the returned string
/// @warning: not implemented.
///	@todo: implement.
// FIXME:	implement full fledged justification
// WARN:	probably will be moved to other file + renamed
char		*ft_strjustify(const char *src, size_t width);

#endif // FT_STRING_H
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
