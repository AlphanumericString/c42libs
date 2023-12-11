/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:40:02 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 15:34:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "ft_list_types.h"
# include <stddef.h>

/* ************************************************************************** */
/*                           DOUBLY LINKED LIST                               */
/* ************************************************************************** */

// ft_list/ft_list_dl_add.c

void	ft_list_dl_add_back(t_dlist **head, t_dlist *added);
void	ft_list_dl_add_front(t_dlist **head, t_dlist *added);

// ft_list/ft_list_dl_apply.c

size_t	ft_list_dl_apply(t_dlist *start, t_data_apply applied);
size_t	ft_list_dl_apply_range(t_dlist *start, const t_dlist *end,
			t_data_apply applied);
size_t	ft_list_dl_apply_range_node(t_dlist *start, const t_dlist *end,
			t_dnode_apply applied);

// ft_list/ft_list_dl_clear.c

size_t	ft_list_dl_clear(t_dlist *head, t_data_apply del);
size_t	ft_list_dl_clear_range(t_dlist *start, t_dlist *end, t_data_apply del);

// ft_list/ft_list_dl_create.c

t_dlist	*ft_list_dl_create(void *const data);
t_dlist	*ft_list_dl_copy_node(const t_dlist *const other);
t_dlist	*ft_list_dl_copy_list(const t_dlist *const other);

// ft_list/ft_list_dl_delete.c

int		ft_list_dl_delete_self(t_dlist *node);
size_t	ft_list_dl_delete_range(t_dlist *start, t_dlist *target);
size_t	ft_list_dl_delete(t_dlist **head);
size_t	ft_list_dl_delete_dup(t_dlist **src);

// ft_list/ft_list_dl_find.c

t_dlist	*ft_list_dl_find(t_dlist *head, void *data, int (*cmp)());

// ft_list/ft_list_dl_getters.c

void	**ft_list_dl_get_datas(const t_dlist *src);
t_dlist	**ft_list_dl_get_nodes(const t_dlist *src);

// ft_list/ft_list_dl_iterator.c

t_dlist	*ft_list_dl_at(t_dlist *head, size_t index);
t_dlist	*ft_list_dl_end(t_dlist *head);
t_dlist	*ft_list_dl_begin(const t_dlist *head);

// ft_list/ft_list_dl_map.c

t_dlist	*ft_list_dl_map(t_dlist *lst, void *(*f)(void *), t_data_apply del);

// ft_list/ft_list_dl_new.c

t_dlist	*ft_list_dl_new(void);

// ft_list/ft_list_dl_pushpop.c

t_dlist	*ft_list_dl_push(t_dlist **node, void *data);
t_dlist	*ft_list_dl_push_back(t_dlist **node, void *data);
void	*ft_list_dl_pop(t_dlist **node);
void	*ft_list_dl_pop_back(t_dlist **node);

// ft_list/ft_list_dl_rev.c

void	ft_list_dl_rev(t_dlist **head);

// ft_list/ft_list_dl_size.c

size_t	ft_list_dl_size(const t_dlist *head);
size_t	ft_list_dl_size_of_data(const t_dlist *head, t_data_is function);

// ft_list/ft_list_dl_sub.c

t_dlist	*ft_list_dl_subrange(t_dlist *src, t_dlist *to);
t_dlist	*ft_list_dl_subrange_to(t_dlist *head, t_dlist *end);

/* ************************************************************************** */
/*                           SIMPLY LINKED LIST                               */
/* ************************************************************************** */

// ft_list/ft_list_ll_add.c

void	ft_listadd_front(t_list **lst, t_list *new);
void	ft_listadd_back(t_list **lst, t_list *new);

// ft_list/ft_list_ll_apply.c

void	ft_listapply(t_list *lst, t_data_apply f);
void	ft_listapply_range(t_list *lst, const t_list *end, t_data_apply f);
void	ft_listapply_range_node(t_list *lst, const t_list *end,
			t_lnode_apply f);

// ft_list/ft_list_ll_clear.c

void	ft_listclear(t_list **lst, t_data_apply del);

// ft_list/ft_list_ll_create.c

t_list	*ft_listcreate(const void *const data);
t_list	*ft_listcopy_node(const t_list *const other);
t_list	*ft_listcopy_list(const t_list *const other);

// ft_list/ft_list_ll_delete.c

void	ft_listdelone(t_list *lst, t_data_apply del);
size_t	ft_listdelete_range(t_list *lst, const t_list *end, t_data_apply del);

// ft_list/ft_list_ll_find.c

void	*ft_listfind(t_list *list, void *data, int (*cmp)(void *, void *));

// ft_list/ft_list_ll_getters.c

void	**ft_listget_datas(const t_list *src);
t_list	**ft_listget_nodes(const t_list *src);

// ft_list/ft_list_ll_iterator.c

t_list	*ft_listlast(t_list *lst);
t_list	*ft_listat(t_list *lst, size_t index);

// ft_list/ft_list_ll_map.c

t_list	*ft_listmap(t_list *lst, void *(*f)(void *), t_data_apply del);

// ft_list/ft_list_ll_new.c

t_list	*ft_listnew(void);

// ft_list/ft_list_ll_pushpop.c

t_list	*ft_listpush(t_list **lst, void *data);
t_list	*ft_listpush_back(t_list **lst, void *data);
void	*ft_listpop(t_list **lst);
void	*ft_listpop_back(t_list **lst);

// ft_list/ft_list_ll_rev.c

t_list	*ft_listrev(t_list **head);

// ft_list/ft_list_ll_size.c

size_t	ft_listsize(const t_list *lst);
size_t	ft_listsize_match(const t_list *lst, t_data_is function);

// ft_list/ft_list_ll_sub.c

t_list	*ft_listsubrange(t_list *lst, const t_list *end);

#endif /* FT_LIST_H */