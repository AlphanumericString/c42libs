/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:48 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 16:56:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_STRUCT_H
# define FT_STRING_STRUCT_H

# include <stddef.h>

typedef struct s_string
{
	char	*str;
	size_t	length;
	size_t	capacity;
}			t_string;

#endif // FT_STRING_STRUCT_H
