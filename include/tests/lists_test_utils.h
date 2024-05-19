/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_test_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:30:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 17:56:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_TEST_UTILS_H
# define LISTS_TEST_UTILS_H

# include "ft_list_types.h"
# include <stdbool.h>

void	create_2elem_dlist(t_dlist **list, void **data1, void **data2);
void	create_2elem_list(t_list **list, void **data1, void **data2);

int		compare_int(const void *data1, const void *data2);
bool	is42(const void *data);
void	add42(void *data);
void	*add42_ret(const void *data);

#endif
