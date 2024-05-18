/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:58 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 16:27:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGS_TYPES_H
# define FT_ARGS_TYPES_H

/// @brief Enum to define the type of the option
/// @details The type of the option will define how the argument of the option
/// will be parsed. You can use the following as masks:
/// OPT_NOARG: The option does not have any argument
/// OPT_EQSIGN: The option has an argument that is separated by an equal sign
/// OPT_SPACE: The option has an argument that is separated by a space
///
/// the following are the types of the argument that can be parsed:
/// OPT_INT: The argument is a whole number
/// OPT_STRING: The argument is a string
/// OPT_BOOL: The argument is a boolean
/// OPT_FLOAT: The argument is a decimal number
/// OPT_OTHER: The argument is another type aka
///   (your function will recieve the next argument without any checks)
/// eg. OPT_INT | OPT_SPACE will parse an option with an integer argument
/// separated by a space from the option identifier : -n 42 || --name 42
/// eg. OPT_INT | OPT_EQSIGN will parse an option with an integer argument
/// separated by an equal sign from the option identifier : -n=42 || --name=42
/// ...
///
typedef enum e_opt_type
{
	OPT_NOARG = 1,
	OPT_EQSIGN = 2,
	OPT_NXT = 3,
	OPT_INT = 4,
	OPT_STRING = 8,
	OPT_BOOL = 12,
	OPT_FLOAT = 16,
	OPT_OTHER = 20
}				t_opt_type;

/// @brief Structure to define the options
/// @param opt_long_name: The long name of the option "name" (without the "--")
/// @param opt_short_name: The short name of the option 'n' (without the "-")
/// @param opt_func: The function to call when the option is found
/// @param opt_type: The type of the option
/// @details The opt_func function must have the following prototype:
/// void opt_func(void *control_struct, char *arg)
/// Where:
///		The control_struct is a pointer to the structure that your function will
///		be given.
///		The arg is the argument of the option is the parsed string found after
///		the	option identifier.
///		(It doesnt cast. Only check if string is valid with the type
///		eg. OPT_INT type must only contain digits to be valid (doe
///		not check if the number is in the range of an int)).
///		If the option is a flag (with OPT_NONE eg. -v) the arg will be NULL.
typedef struct s_opt
{
	char		*long_name;
	char		short_name;
	void		(*func)(void *control_struct, char *arg);
	t_opt_type	type;
}				t_opt;

#endif
