/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:55:34 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 12:37:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFS_H
# define FT_DEFS_H

# include <stdbool.h>
# include <stddef.h>

/// @brief Type of function to compare two elements
/// @param a The first element to compare
/// @param b The second element to compare
/// @return standard cmp c function ( < 0, 0, > 0 for a < b, a == b, a > b)
typedef int				(*t_data_cmp)(const void *, const void *);

/// @brief Type of function to apply on a node data
/// @param data The data to apply the function on
/// @return void
typedef void			(*t_data_apply)(void *);

/// @brief Type of function to see if a node data is something
/// @return true if the data is what we are looking for, false otherwise
typedef bool			(*t_data_is)(const void *);

/// @brief Type of function to transform a data into something else
/// @return The new data
typedef void			*(*t_data_tr)(const void *);

#endif /* FT_DEFS_H */
