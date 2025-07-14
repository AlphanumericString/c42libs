/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixtures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:27:56 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/12 16:27:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXTURES_H
# define FIXTURES_H

# include "ft_defs.h"

# define TESTS_FPREFIX		"build/test_"
# define TESTS_FPREFIX_TMP	"/tmp/c42libs_test_"

int		open_test_file(char **func_to_test);
void	destroy_test_file(int fd, const char *file);

// memory alloc fail tests
/// set/get fail point + counter for allocs
int		*talloc_get_failpoint(void);
int		*talloc_get_currentpoint(void);
void	talloc_set_failpoint(int val);
void	talloc_set_currentpoint(int val);
bool	talloc_is_ok(void);
/// setup
void	*talloc_prev_group(void);
void	talloc_wrapper_setup(void);

void	*talloc_alloc(size_t s);
void	*talloc_calloc(size_t a, size_t b);
void	*talloc_realloc(void *p, size_t s);
void	talloc_free(void *p);
void	*talloc_reallocarray(void *p, size_t a, size_t b);
/// memory fail end

#endif  /* FIXTURE.H */
