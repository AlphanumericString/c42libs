/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:17:11 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/13 16:17:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include "types/ft_list_types.h"

typedef struct s_contact
{
	char	*name;
	char	*infos;
	char	*number;
}	t_contact;

// contact op
int		cmp_contact_name(const t_contact *cntact, const char *name);
int		cmp_contact_phnb(const t_contact *cntact, const char *phnb);
void	del_contact(t_contact *con);
void	contact_printstdout(const t_contact *con);

// phbook
void	add_contact( char *line, t_list **contact_l);
void	rm_contact(char	*line, t_list **contact_l);
void	disp(char *line, t_list **contact_l);
void	disp_all(t_list	*contact_l);

#endif // !CONTACT_H
