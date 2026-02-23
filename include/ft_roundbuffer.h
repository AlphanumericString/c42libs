/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundbuffer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:48:38 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/23 17:00:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROUNDBUFFER_H
# define FT_ROUNDBUFFER_H

# define PRB_NB_ELEM_DFLT 4
# define PRB_SZ_ELEM_DFLT 1024

# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

typedef struct s_roundbuffer_array
{
	void	*array;
	size_t	nb_max;
	size_t	i_pos;
	size_t	o_pos;
	size_t	sz_e;
}	t_rb;

// init
t_rb	*ftrb_create(t_rb *rb, size_t sz_elem, size_t nb_e);
t_rb	*ftrb_init(t_rb *rb, size_t sz_elem);
t_rb	*ftrb_from_array(t_rb *rb, void *array, size_t nb_elem, size_t sz_elem);
t_rb	*ftrb_new(size_t sz_elem);

// delete
void	ftrb_destroy(t_rb *rb);
void	ftrb_clr(t_rb *rb);

// getters
bool	ftrb_full(t_rb rb);
bool	ftrb_empty(t_rb rb);
size_t	ftrb_size(t_rb rb);
size_t	ftrb_cappacity(t_rb rb);
size_t	ftrb_free(t_rb rb);

// remove
bool	ftrb_drop(t_rb *rb, size_t n);
void	*ftrb_pop(t_rb *rb, void *elem_out);
void	*ftrb_npop(t_rb *rb, size_t n, void *elem_out);
void	*ftrb_peek(t_rb rb, void *elem_out);
void	*ftrb_npeek(t_rb rb, size_t n, void *elem_out);

// add
void	ftrb_push(t_rb *rb, const void *data);
void	ftrb_npush(t_rb *rb, const void *data, size_t nb_elem);
bool	ftrb_push_safe(t_rb *rb, const void *data);
bool	ftrb_npush_safe(t_rb *rb, const void *data, size_t nb_elem);

#endif // !FT_ROUNDBUFFER_H
