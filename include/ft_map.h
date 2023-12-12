/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/12 11:45:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_map_node
{
	void		*data;
	void		*key;
	bool		used;
}				t_map_node;

typedef struct s_map
{
	size_t		capacity;
	size_t		size;
	t_map_node	*nodes;
	int			(*cmp)(void *, void *);
	size_t		(*hash)(void *, size_t, size_t);
}				t_map;

/// @brief Create a new map
/// @param capacity possible number of elements in the map
/// @return a pointer to the new map
t_map			*ft_map_create(size_t capacity);

/// @brief Destroy a map
/// @param map map to destroy
/// @return void
void			ft_map_destroy(t_map *map);
/// @brief Destroy a map and free the data
/// @param map map to destroy
/// @param free_data function to free the data
/// @return void
void			ft_map_destroy_free(t_map *map, void (*free_data)(void *));

/// @brief Clears a map by setting all the nodes to unused
/// @param map map to clear
/// @return void
void			ft_map_clear(t_map *map);

/// @brief Set a value in a map
/// @param map map to set the value in
/// @param key key of the value
/// @param value value to set
/// @param size size of the key
/// @return 0 if the value was set, 1 if the key doesn't exist and couldn't be
/// created
int				ft_map_set(t_map *map, void *key, void *value, size_t size);
/// @brief Set the compare function of a map
/// @param map map to set the compare function
/// @param cmp compare function newly set
/// @return void
void			ft_map_set_cmp(t_map *map, int (*cmp)(void *, void *));
/// @brief Set the hash function of a map
/// @param map map to set the hash function
/// @param hash hash function newly set
/// @return void
void			ft_map_set_hash(t_map *map, size_t (*hash)(void *, size_t,
						size_t));

/// @brief Get a value from a map
/// @param map map to get the value from
/// @param key key of the value
/// @param key_size size of the key
/// @return a pointer to the value if it exists, NULL otherwise
t_map_node		*ft_map_get(t_map *map, void *key, size_t key_size);
/// @brief Get the size of a map
/// @param map map to get the size from
/// @return the size of the map
size_t			ft_map_size(t_map *map);
/// @brief Get the capacity of a map
/// @param map map to get the capacity from
/// @return the capacity of the map
size_t			ft_map_capacity(t_map *map);

/// @brief Remove a value from a map
/// @param map map to remove the value from
/// @param key key of the value
/// @param size size of the key
/// @return void
void			ft_map_remove(t_map *map, void *key, size_t size);

size_t			ft_map_hash(void *key, size_t capacity, size_t size);

#endif /* FT_MAP_H */
