/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 15:36:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGS_H
# define FT_ARGS_H

// Change version with -DVERSION="x.y.z-W" via Makefile
# ifndef VERSION
#  define VERSION "1.0.0"
# endif

# include "ft_args_types.h"

int			ft_parse_args(int argc, char **argv, void *usr_control_struct);

void		ft_set_opt_list(const t_opt *opt_list);
const t_opt	*ft_get_opt_list(void);

void		ft_set_progname(const char *program_name);
const char	*ft_progname(void);

void		ft_set_version(const char *version);
const char	*ft_progversion(void);

#endif
