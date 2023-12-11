/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:37:46 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 15:18:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "ft_vector_types.h"

/* ************************************************************************** */
/*                            VECTOR MODULE                                   */
/* ************************************************************************** */

// ft_vector/ft_vec_add.c

bool		ft_vec_add(t_vector **vec, void *data);

// ft_vector/ft_vec_apply.c

void		ft_vec_apply(t_vector *vec, void (*func)(void *));

// ft_vector/ft_vec_at.c

void		*ft_vec_at(t_vector *vec, size_t n);

// ft_vector/ft_vec_cat.c

bool		ft_vec_cat(t_vector **vec_a, const t_vector *vec_b);

// ft_vector/ft_vec_clear.c

void		ft_vec_clear(t_vector **vec);

// ft_vector/ft_vec_destroy.c

bool		ft_vec_destroy(t_vector **vec);

// ft_vector/ft_vec_filter.c

void		ft_vec_filter(t_vector *vec, bool (*func)(void *),
				void (*del)(void *));

// ft_vector/ft_vec_map.c

t_vector	*ft_vec_map(t_vector *vec, void *(*func)(void *));

// ft_vector/ft_vec_new.c

t_vector	*ft_vec_new(void);
t_vector	*ft_vec_from_size(size_t n);
t_vector	*ft_vec_from_array(void **data, size_t count);
t_vector	*ft_vec_convert_alloccarray(void **data, size_t count);

// ft_vector/ft_vec_remove.c

void		ft_vec_remove(t_vector *vector, size_t n, void (*del)(void *));
void		ft_vec_remove_if(t_vector *vector, bool (*func)(void *),
				void (*del)(void *));

// ft_vector/ft_vec_reserve.c

bool		ft_vec_reserve(t_vector **vec, size_t size);

// ft_vector/ft_vec_reverse.c

void		ft_vec_reverse(t_vector *vector);

// ft_vector/ft_vec_shift.c

void		ft_vec_shift(t_vector *vec, size_t start, size_t shift);

// ft_vector/ft_vec_sort.c

void		ft_vec_sort(t_vector *vec, int (*cmp_f)(void *, void *));

// ft_vector/ft_vec_swap.c

void		ft_vec_swap(t_vector *vec, size_t a, size_t b);

#endif /* FT_VECTOR_H */