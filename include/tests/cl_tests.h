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

int	tcl_add_front(void);
int	tcl_add_back(void);

int	tcl_apply(void);
int	tcl_apply_range(void);
int	tcl_apply_range_node(void);

int	tcl_check_circular(void);
int	tcl_check_sorted(void);
int	tcl_check_health(void);

int	tcl_clear(void);
int	tcl_clear_range(void);

int	tcl_create(void);
int	tcl_copy_node(void);
int	tcl_copy_list(void);

int	tcl_delete(void);
int	tcl_delete_range(void);

int	tcl_find(void);

int	tcl_get_datas(void);
int	tcl_get_nodes(void);

int	tcl_at(void);
int	tcl_begin(void);
int	tcl_end(void);

int	tcl_map(void);

int	tcl_new(void);

int	tcl_push(void);
int	tcl_push_back(void);
int	tcl_pop(void);
int	tcl_pop_back(void);

int	tcl_rev(void);

int	tcl_size(void);
int	tcl_size_data_is(void);
int	tcl_size_cmp(void);

int	tcl_subrange(void);

#endif /* CL_TESTS_H */
