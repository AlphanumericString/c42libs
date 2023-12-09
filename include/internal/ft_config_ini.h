/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_ini.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:32:30 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/08 11:21:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONFIG_INI_H
# define FT_CONFIG_INI_H
# include <stdbool.h>
# include "ft_list_struct.h"

typedef struct s_ini_section
{
	struct s_ini_section	*parent;
	const char				*name;
	t_list					*kv_pairs;
}							t_ini_section;

typedef struct s_ini_node
{
	t_ini_section			*parent;
	const char				*key;
	void					*value;
	bool					array;
}							t_ini_node;

typedef struct s_inifile
{
	char					equ_token;
	char					com_token;
	char					arr_token;
	bool					dup_crash;
	bool					com_inline;
	bool					multi_line;
	char					*section_default;
	t_list					*sections;
}							t_inifile;

// init functions, base fill of struct t_inifile
void						*ftc_ini_core_init(void);
void						*ftc_ini_extended_init(void);

// load function takes the path to a file - tries to open + read - and fill
//   up a t_inifile * as the control_struct
// fail -> not 0 (likely 1 but not guaranteed) 
// ok   ->     0
int							ftc_ini_load(const char *file,
								void *control_struct);
// save function takes the path to a file - tries to open + write - and fill
//   up a file with a t_inifile * as the control struct.
// if >> file already exist, will try to match key and section to write to
//   present keys and section. will ignore #. otherwise it will write 
//   present keys and section if the open and write call succeed.
// fail -> not 0 (likely 1 but not guaranteed) 
// ok   ->     0
int							ftc_ini_save(const char *file,
								void *control_struct);
//	return the value associated with key;
void						*ftc_ini_get(const char *key, void *control_struct);
// !!!TODO:
int							ftc_ini_set(const char *key, void *value,
								void *control_struct);
// internal requirements
// mixed
int							ftc_ini_push_section(const char *parent,
								const char *s, t_inifile *file);
int							ftc_ini_push_kv(const char *k, const char *v,
								t_inifile *file);
t_ini_section				*ftc_ini_get_section(const char *s,
								t_inifile *file);
void						*ftc_ini_get_k(const char *k, t_inifile *file);

//// INI_EXTENDED
// default add
// default '='
// deault '#'
// default yes
// default "global"

//// INI_EXTENDED
// default crash - error
// default '='
// deault '#'
// default no
// default "global"

/*
** INI STABLE
Keys (properties)
Sections
Case sensitivity
Comments
Non ordered.

** INI VARIABLE
Global section as default
Name / value delim being ':' or ' '
Hierarchy (nesting)
Comments using '#'
Comments inline
Duplicates names support
Quoted values
Support for '\' chars and logic line continuation.
*/

#endif