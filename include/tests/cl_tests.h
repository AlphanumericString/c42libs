/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_tests.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:52:14 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 12:58:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_TESTS_H
# define CL_TESTS_H

int	t_cl_add_front(void);
int	t_cl_add_back(void);

int	t_cl_apply(void);
int	t_cl_apply_range(void);
int	t_cl_apply_range_node(void);

int	t_cl_check_circular(void);
int	t_cl_check_sorted(void);
int	t_cl_check_health(void);

int	t_cl_clear(void);
int	t_cl_clear_range(void);

int	t_cl_create(void);
int	t_cl_copy_node(void);
int	t_cl_copy_list(void);

int	t_cl_delete(void);
int	t_cl_delete_range(void);

int	t_cl_find(void);

int	t_cl_get_datas(void);
int	t_cl_get_nodes(void);

int	t_cl_at(void);
int	t_cl_begin(void);
int	t_cl_end(void);

int	t_cl_map(void);

int	t_cl_new(void);

int	t_cl_push(void);
int	t_cl_push_back(void);
int	t_cl_pop(void);
int	t_cl_pop_back(void);

int	t_cl_rev(void);

int	t_cl_size(void);
int	t_cl_size_data_is(void);
int	t_cl_size_cmp(void);

int	t_cl_subrange(void);

#endif /* CL_TESTS_H */
