/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_tests.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:10:07 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 16:11:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LL_TESTS_H
# define LL_TESTS_H

int	test_listadd_front(void);
int	test_listadd_back(void);

int	test_listapply(void);
int	test_listapply_range(void);
int	test_listapply_range_node(void);

int	test_listclear(void);

int	test_listcreate(void);

int	test_listcopy_node(void);
int	test_listcopy_list(void);

int	test_listdelone(void);
int	test_listdelete_range(void);

int	test_listfind(void);

int	test_listget_datas(void);
int	test_listget_nodes(void);

int	test_listend(void);
int	test_listat(void);

int	test_listmap(void);

int	test_listnew(void);

int	test_listpush(void);
int	test_listpush_back(void);
int	test_listpop(void);
int	test_listpop_back(void);

int	test_listrev(void);

int	test_listsize(void);
int	test_listsize_match(void);

int	test_listsubrange(void);

#endif /* LL_TESTS_H */
