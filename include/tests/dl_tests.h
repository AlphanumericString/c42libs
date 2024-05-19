/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_tests.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:51:11 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:52:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DL_TESTS_H
# define DL_TESTS_H

int	test_dlistadd_front(void);
int	test_dlistadd_back(void);

int	test_dlistapply(void);
int	test_dlistapply_range(void);
int	test_dlistapply_range_node(void);

int	test_dlistclear(void);
int	test_dlistclear_range(void);

int	test_dlistcreate(void);

int	test_dlistcopy_node(void);
int	test_dlistcopy_list(void);

int	test_dlist_delete_self(void);
int	test_dlistdelete_range(void);
int	test_dlistdelete(void);

int	test_dlistfind(void);

int	test_dlistget_datas(void);
int	test_dlistget_nodes(void);

int	test_dlist_at(void);
int	test_dlist_begin(void);
int	test_dlist_end(void);

int	test_dlist_map(void);

int	test_dlist_new(void);

int	test_dlist_pop(void);
int	test_dlist_pop_back(void);
int	test_dlist_push(void);
int	test_dlist_push_back(void);

int	test_dlist_rev(void);

int	test_dlist_size(void);
int	test_dlist_size_of_data(void);

int	test_dlist_subrange(void);

#endif /* DL_TESTS_H */
