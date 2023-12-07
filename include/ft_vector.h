/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:37:46 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 10:37:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H
# define FT_VECTOR_BASE_LEN 4096

# include <stdbool.h>
# include <stddef.h>

typedef struct s_vector
{
	void	**datas;
	size_t	count;
	size_t	cappacity;
}			t_vector;

// ft_vec_add
bool		ft_vec_add(t_vector **vec, void *data);

// ft_vec_apply
void		ft_vec_apply(t_vector *vec, void (*func)(void *));

// ft_vec_at
void		*ft_vec_at(t_vector *vec, size_t n);

// ft_vec_cat
bool		ft_vec_cat(t_vector **vec_a, const t_vector *vec_b);

// ft_vec_clear
void		ft_vec_clear(t_vector **vec);

// ft_vec_destroy
bool		ft_vec_destroy(t_vector **vec);

// ft_vec_filter
void		ft_vec_filter(t_vector *vec, bool (*func)(void *),
				void (*del)(void *));

// ft_vec_map
t_vector	*ft_vec_map(t_vector *vec, void *(*func)(void *));

// ft_vec_new
t_vector	*ft_vec_new(void);
t_vector	*ft_vec_from_size(size_t n);
t_vector	*ft_vec_from_array(void **data, size_t count);
t_vector	*ft_vec_convert_alloccarray(void **data, size_t count);

// ft_vec_reserve
bool		ft_vec_reserve(t_vector **vec, size_t size);

// ft_vec_shift
void		ft_vec_shift(t_vector *vec, size_t start, size_t shift);

// ft_vec_sort
void		ft_vec_sort(t_vector *vec, int (*cmp_f)(void *, void *));

#endif // FT_VECTOR_H
