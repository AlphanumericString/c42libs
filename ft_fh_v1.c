#include "ft_string.h"
#include "ft_tstring.h"
#include "ft_vector.h"
#include "ft_mem.h"

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define LS_OPTION_SUPPORTED	'larRt'

typedef struct s_ls {
	bool	a;
	bool	l;
	bool	r;
	bool	R;
	bool	t;
} t_ls;

enum e_fh_type {
	FT_FH_DIR,
	FT_FH_FILE,
};

struct	op_to_pos {
	char	c;
	bool	*pos;
};

typedef struct s_dir_entry {
	DIR					*dir_hndl;
	struct stat			statinfos;

	const char			*name;
	struct s_dir_entry	*parent;
	t_vector			*files;
} t_dir_entry ;

typedef struct s_file_entry {
	struct dirent		*dirent_info;
	struct stat			statinfos;
	struct stat			lstatinfos;
	t_dir_entry			*parent;
} t_file_entry ;

typedef struct s_fh {
	union {
		t_dir_entry *dir;
		t_file_entry *file;
	} entry;
	enum e_fh_type entry_type;
} t_fh;

char	*get_full_dir_name(const t_dir_entry *dir_hdl)
{
	t_string	*ret;
	char		*s;

	if (!dir_hdl)
		return (NULL);
	ret = ft_string_new(256);
	while (dir_hdl)
	{
		ft_string_append(ret, dir_hdl->name);
		dir_hdl = dir_hdl->parent;
	}
	s = ft_string_to_str(ret);
	ft_string_destroy(&ret);
	return (s);
}
char	*get_full_file_name(const t_file_entry *file_hd)
{
	char	*ret;
	char	*t;

	if (!file_hd || !file_hd->parent || !file_hd->dirent_info)
		return (NULL);
	t = get_full_dir_name(file_hd->parent);
	if (!t)
		return (NULL);
	ret = ft_strjoin(t, file_hd->dirent_info->d_name);
	ft_free(t);
	return (ret);
}

