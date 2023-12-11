/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 18:16:38 by bgoulard         ###   ########.fr       */
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
	int			(*cmp)(void *, void *, size_t);
	size_t		(*hash)(void *, size_t);
}				t_map;

t_map			*ft_map_create(size_t capacity);

void			ft_map_destroy(t_map *map);

void			ft_map_clear(t_map *map);

int				ft_map_set(t_map *map, void *key, void *value, size_t size);
void			ft_map_set_cmp(t_map *map, int (*cmp)(void *, void *, size_t));
void			ft_map_set_hash(t_map *map, size_t (*hash)(void *, size_t));

void			*ft_map_get(t_map *map, void *key, size_t size);
size_t			ft_map_size(t_map *map);
size_t			ft_map_capacity(t_map *map);

void			ft_map_remove(t_map *map, void *key, size_t size);

size_t			ft_map_hash(void *key, size_t capacity);

#endif /* FT_MAP_H */
