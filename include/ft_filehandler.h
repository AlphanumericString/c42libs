/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filehandler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 00:15:56 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/04 10:45:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILEHANDLER_H
# define FT_FILEHANDLER_H

# include "ft_defs.h"
# include "types/ft_filehandler_types.h"
# include <stddef.h>

// return mode eg perm of file
int		ft_fname_mode(const char *fname);
// true=> yes exist, false => no
bool	ft_fname_exist(const char *fname);
// true=> success, false => faillure
bool	ft_fname_copy(const char *fname_src, const char *fname_dst);
bool	ft_fname_delete(const char *fname);
// true=> success, false => faillure
// /dir1/a/dir2/../././././ => /dir1/a/
bool	ft_normalize_path(char **fname_addr);

// true=> success, false => faillure
// 'name/a.o' => 'name_a.o' change forbidens char to _ and other stuff
bool	ft_normalize_fname(char **fname_addr);

t_fh	*ft_fh_create(t_fh *hdl, const char *fname);
t_fh	*ft_fh_new(t_fh *hdl);
bool	ft_fh_set_fname(t_fh *hdl, const char *fname);
// -- get
int		ft_fh_mode(t_fh *hdl);
size_t	ft_fh_size(t_fh *hdl);
// -- open/close
bool	ft_fh_open(t_fh *hdl);
bool	ft_fh_close(t_fh *hdl);
// -- reads
char	*ft_fh_read(t_fh *hdl, size_t bytes);
char	*ft_fh_readline(t_fh *hdl);
char	**ft_fh_readlines(t_fh *hdl, size_t nb_lines);
// -- write
size_t	ft_fh_write(t_fh *hdl, const char *str);
size_t	ft_fh_writeline(t_fh *hdl, const char *str);
size_t	ft_fh_writeline(t_fh *hdl, const char *str);
// -- fh state
// ----file is
bool	ft_fh_isfile(t_fh *hdl);
bool	ft_fh_isdir(t_fh *hdl);
bool	ft_fh_islink(t_fh *hdl);
// ----read_state
bool	ft_fh_eof(t_fh *hdl);
bool	ft_fh_error(t_fh *hdl);

const char *ft_fh_perror(t_fh *hdl);

#endif  // FT_FILEHANDLER_H
