/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:33:46 by iron              #+#    #+#             */
/*   Updated: 2023/12/13 09:27:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		tests_map(void);
int		tests_linked_list_all(void);
int		tests_doubly_linked_list_all(void);
int		tests_vector(void);

int main()
{
	printf("== lib all tests ==\n");
	tests_linked_list_all();
	tests_doubly_linked_list_all();
	tests_map();
	tests_vector();
	printf("== end ==\n");
}