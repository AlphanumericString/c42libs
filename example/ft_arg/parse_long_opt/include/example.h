/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:57:08 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 15:08:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_H
# define EXAMPLE_H

# include "usr_strct.h"

int		lc_opt_int(t_usr_struct *data, const char *arg);
int		lc_opt_long(t_usr_struct *data, const char *arg);
int		lc_opt_float(t_usr_struct *data, const char *arg);
int		lc_opt_double(t_usr_struct *data, const char *arg);
int		lc_opt_bool(t_usr_struct *data, const char *arg);
int		lc_opt_string(t_usr_struct *data, const char *arg);

void	printf_reaminer_args(const char *const *av, size_t offset);
int		print_long_version(void *usr);

#endif // EXAMPLE_H
