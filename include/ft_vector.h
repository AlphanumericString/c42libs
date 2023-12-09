/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:37:46 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 19:08:51 by bgoulard         ###   ########.fr       */
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

bool		ft_vec_add(t_vector **vec, void *data);
void		ft_vec_apply(t_vector *vec, void (*func)(void *));
void		*ft_vec_at(t_vector *vec, size_t n);
bool		ft_vec_cat(t_vector **vec_a, const t_vector *vec_b);
void		ft_vec_clear(t_vector **vec);
bool		ft_vec_destroy(t_vector **vec);
void		ft_vec_filter(t_vector *vec, bool (*func)(void *),
				void (*del)(void *));
t_vector	*ft_vec_map(t_vector *vec, void *(*func)(void *));
t_vector	*ft_vec_new(void);
t_vector	*ft_vec_from_size(size_t n);
t_vector	*ft_vec_from_array(void **data, size_t count);
t_vector	*ft_vec_convert_alloccarray(void **data, size_t count);
bool		ft_vec_reserve(t_vector **vec, size_t size);
void		ft_vec_shift(t_vector *vec, size_t start, size_t shift);
void		ft_vec_sort(t_vector *vec, int (*cmp_f)(void *, void *));
void		ft_vec_swap(t_vector *vec, size_t a, size_t b);

// todo
void		ft_vec_reverse(t_vector *vec);
void		ft_vec_remove(t_vector *vec, size_t n, void (*del)(void *));
void		ft_vec_remove_if(t_vector *vec, bool (*func)(void *),
				void (*del)(void *));

#endif // FT_VECTOR_H
