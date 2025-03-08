/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator_failpoint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:55:07 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/10 12:57:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	*talloc_get_failpoint(void)
{
	static int	failpoint = 0;

	return (&failpoint);
}

void	talloc_set_failpoint(int val)
{
	int	*current;

	current = talloc_get_failpoint();
	*current = val;
	return ;
}

int	*talloc_get_currentpoint(void)
{
	static int	currentpoint = 0;

	return (&currentpoint);
}

void	talloc_set_currentpoint(int val)
{
	int	*current;

	current = talloc_get_currentpoint();
	*current = val;
	return ;
}

bool	talloc_is_ok(void)
{
	const int	*failpoint = talloc_get_failpoint();
	int			*current;

	current = talloc_get_currentpoint();
	if (*current < *failpoint)
	{
		*current += 1;
		return (true);
	}
	return (false);
}
