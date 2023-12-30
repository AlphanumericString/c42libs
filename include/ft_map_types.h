/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:02:13 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:20:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_TYPES_H
# define FT_MAP_TYPES_H

# include <stdbool.h>
# include <stddef.h>

/// @brief Structure representing a node in a map
/// @param data The data of the node
/// @param key The key of the node
/// @param used Whether the node is used or not
typedef struct s_map_node
{
	void		*data;
	const void	*key;
	bool		used;
}				t_map_node;

/// @brief Structure representing a map
/// @param capacity The capacity of the map
/// @param size The size of the map
/// @param nodes The nodes of the map
/// @param cmp The compare function of the map
/// @param hash The hash function of the map
typedef struct s_map
{
	size_t		capacity;
	size_t		size;
	t_map_node	*nodes;
	int			(*cmp)(const void *, const void *);
	size_t		(*hash)(const void *, size_t, size_t);
}				t_map;

#endif /* FT_MAP_TYPES_H */
