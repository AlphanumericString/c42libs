/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/28 03:36:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

/* ************************************************************************** */
/*                                                                            */
/* Module: FT_MAP                                                             */
/* Prefix: ft_map                                                             */
/*																			  */
/* The module FT_MAP provides a way to handle hash maps and function		  */
/*		related to hashmaps.												  */
/*                                                                            */
/* ************************************************************************** */

# include <stdbool.h>
# include <stddef.h>

# include "ft_defs.h"

# include "types/ft_map_types.h"

// TODO: resize function
// TODO: apply* functions
// TODO: clear with free user data (keeps node allocated in reserve pool)

/// @brief Create a new map
/// @param capacity possible number of elements in the map
/// @return a pointer to the new map
t_map		*ft_map_create(size_t capacity);

/// @brief Destroy a map and free the nodes
/// @param map map to destroy
/// @return void
void		ft_map_destroy(t_map *map);

/// @brief Destroy a map and free the nodes and the user data in them using a
/// function passed as an argument
/// @param map map to destroy
/// @param free_data function to free the data in the map
/// @return void
void		ft_map_destroy_free(t_map *map, t_data_apply free_data);

/// @brief Clears a map
/// @param map map to clear
/// @return void
/// @note does not free the user data in the nodes, just turns the node into
/// "empty"
void		ft_map_clear(t_map *map);

/// @brief Set a value in a map
/// @param map map to set the value in
/// @param key key of the value
/// @param value value to set
/// @param size size of the key
/// @return true if the value was set, otherwise if key creation failed false
bool		ft_map_set(t_map *map, const void *key,
				const void *value,	size_t size);

/// @brief Set the compare function of a map
/// @param map map to set the compare function
/// @param cmp compare function newly set
/// @return void
void		ft_map_set_cmp(t_map *map, const t_data_cmp cmp);

/// @brief Set the hash function of a map
/// @param map map to set the hash function
/// @param hash hash function newly set
/// @return void
void		ft_map_set_hash(t_map *map, t_memhash hash);

/// @brief Get a node from a map
/// @param map map to get the node from
/// @param key key of the node
/// @param size size of the key
/// @return a map_node if found, NULL otherwise
t_map_node	*ft_map_get_node(const t_map *map, const void *key,
				size_t size);

/// @brief Get a value from a map
/// @param map map to get the value from
/// @param key key of the value
/// @param key_size size of the key
/// @return a pointer to the user data or NULL if the key is not found
void		*ft_map_get(const t_map *map, const void *key,
				size_t key_size);

/// @brief Get the number of elements in a map
/// @param map map to get the size from
/// @return the number of elements in the map
size_t		ft_map_size(const t_map *map);

/// @brief Get the capacity of a map
/// @param map map to get the capacity from
/// @return the capacity of the map
size_t		ft_map_capacity(const t_map *map);

/// @brief Remove a value from a map
/// @param map map to remove the value from
/// @param key key of the value
/// @param size size of the key
/// @return the value removed or NULL if the key is not found
void		*ft_map_remove(t_map *map, const void *key,
				size_t size);

/// @brief Hash a key
/// @param key key to hash
/// @param size size of the key
/// @return the hash of the key
size_t		ft_hash_djb2(const void *key, size_t size);

/// @brief Hash a key
/// @param key key to hash
/// @param size size of the key
/// @return the hash of the key
size_t		ft_hash_sdbm(const void *key, size_t size);

/// @brief Hash a key
/// @param key key to hash
/// @param size size of the key
/// @return the hash of the key
size_t		ft_hash_fnv1a(const void *key, size_t size);

/// @brief Hash a key
/// @param key key to hash
/// @param size size of the key
/// @return the hash of the key
/// @note this hash function is not very good, full of collisions
/// but it's very fast, easy to understand and never overflows.
/// use it ONLY for TESTing purposes
size_t		ft_hash_dummy(const void *key, size_t size);

#endif /* FT_MAP_H */
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
