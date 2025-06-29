/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:40:02 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 17:20:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

/* ************************************************************************** */
/*																			  */
/* Module: FT_LIST															  */
/* Prefix: ft_dl, ft_ll, ft_cl												  */
/*																			  */
/* The module FT_LIST provides a way to handle task related to linked		  */
/*		lists whether the list happens to be simply linked, doubly linked.	  */
/*		Due to the nature of the module (handling different types of the same */
/*		variety of struct the prototypes are arranged using functionality	  */
/*		instead of type as would be common.									  */
/*		Currently supported types:											  */
/*			-simply_linked,													  */
/*			-doubly_linked.													  */
/*			-doubly_circular_linked											  */
/*																			  */
/* ************************************************************************** */

// TODO: Test cl

# include <stdbool.h>
# include <stddef.h>
# include <sys/types.h>

# include "types/ft_list_types.h"
# include "ft_defs.h"

/* ************************************************************************** */
/*                                    ADD                                     */
/* ************************************************************************** */

/// @brief Add a node at the end of the list
/// @param head The head of the list
/// @param added The node to add
void	ft_dl_add_back(t_dlist **head, t_dlist *restrict added);

/// @brief Add a node at the beginning of the list
/// @param head The head of the list
/// @param added The node to add
void	ft_dl_add_front(t_dlist **head, t_dlist *restrict added);

/// @brief Add a node at the begining of the list
/// @param head The head of the list
/// @param added The node to add
/// @return void
void	ft_ll_add_front(t_list **lst, t_list *restrict new_node);

/// @brief Add a node at the end of the list
/// @param head The head of the list
/// @param added The node to add
/// @return void
void	ft_ll_add_back(t_list **lst, t_list *restrict new_node);

/// @brief Add a node at the end of the list
/// @param head The head of the list
/// @param added The node to add
/// @note if there's no head added is set to head
void	ft_cl_add_back(t_clist **head, t_clist *restrict added);

/// @brief Add a node at the beginning of the list
/// @param head The head of the list
/// @param added The node to add
/// @note if there's no head added is set to head
void	ft_cl_add_front(t_clist **head, t_clist *restrict added);

/* ************************************************************************** */
/*                                  APPLY                                     */
/* ************************************************************************** */

/// @brief Apply a function on every node of the list
/// @param start The start of the list
/// @param applied The function to apply
/// @return The number of nodes applied
size_t	ft_dl_apply(const t_dlist *start, const t_data_apply applied);

/// @brief Apply a function on every node of the list until the end
/// @param start The start of the list
/// @param end The end of the list
/// @param applied The function to apply
/// @return The number of nodes applied
size_t	ft_dl_apply_range(const t_dlist *start, const t_dlist *end,
			const t_data_apply applied);

/// @brief Apply a function on every node of the list until the end
/// @param start The start of the list
/// @param end The end of the list
/// @param applied The function to apply
/// @return The number of nodes applied
size_t	ft_dl_apply_range_node(const t_dlist *start, const t_dlist *end,
			const t_dnode_apply applied);

/// @brief Apply a function on every node of the list
/// @param lst The list
/// @param f The function to apply
/// @return void
void	ft_ll_apply(const t_list *lst, const t_data_apply f);

/// @brief Apply a function on every node of the list until the element end
/// @param lst The list
/// @param end The end of the list
/// @param f The function to apply
/// @return void
void	ft_ll_apply_range(const t_list *lst, const t_list *end,
			const t_data_apply f);

/// @brief Apply a function on every node of the list until the element end
/// @param lst The list
/// @param end The end of the list
/// @param f The function to apply
/// @return void
void	ft_ll_apply_range_node(const t_list *lst, const t_list *end,
			const t_lnode_apply f);

/// @brief Apply a function on every node of the list
/// @param start The start of the list
/// @param applied The function to apply
/// @return The number of nodes applied
size_t	ft_cl_apply(const t_clist *start, const t_data_apply applied);

/// @brief Apply a function on every node of the list until the end
/// @param start The start of the list
/// @param end The end of the list
/// @param applied The function to apply
/// @return The number of nodes applied
size_t	ft_cl_apply_range(const t_clist *start, const t_clist *end,
			const t_data_apply applied);

/// @brief Apply a function on every node of the list until the end
/// @param start The start of the list
/// @param end The end of the list
/// @param applied The function to apply
/// @return The number of nodes applied
size_t	ft_cl_apply_range_node(const t_clist *start, const t_clist *end,
			const t_cnode_apply applied);

/* ************************************************************************** */
/*                                  CHECKS                                    */
/* ************************************************************************** */

/// @brief Check if a list is circular
/// @param lst The list
/// @return true if the list is circular, false otherwise
bool	ft_dl_check_circular(const t_dlist *lst);

/// @brief Check if a list is sorted
/// @param lst The list
/// @param cmp The compare function
bool	ft_dl_check_sorted(const t_dlist *lst, const t_data_cmp cmp);

/// @brief Check if a list is healthy
/// @param lst The list
/// @return true if the list is healthy, false otherwise
bool	ft_dl_check_health(const t_dlist *_lst);

/// @brief Check if a list is circular
/// @param lst The list
/// @return true if the list is circular, false otherwise
bool	ft_ll_check_circular(const t_list *lst);

/// @brief Check if a list is sorted
/// @param lst The list
/// @param cmp The compare function
bool	ft_ll_check_sorted(const t_list *lst, const t_data_cmp cmp);

/// @brief Check if a list is healthy
/// @param lst The list
/// @return true if the list is healthy, false otherwise
/// @note -> no op function as there's no prev --
bool	ft_ll_check_health(const t_list *lst);

/// @brief Check if a list is circular
/// @param lst The list
/// @return true if the list is circular, false otherwise
bool	ft_cl_check_circular(const t_clist *lst);

/// @brief Check if a list is sorted
/// @param lst The list
/// @param cmp The compare function
bool	ft_cl_check_sorted(const t_clist *lst, const t_data_cmp cmp);

/// @brief Check if a list is healthy
/// @param lst The list
/// @return true if the list is healthy, false otherwise
bool	ft_cl_check_health(const t_clist *lst);

/* ************************************************************************** */
/*                                  CLEAR                                     */
/* ************************************************************************** */

/// @brief Clear a list
/// @param head The adress of head of the list to clear
/// @param del The function to clear the data befor setting to null (eg: free)
/// @return The number of node set to null
/// @note The head is set to NULL
size_t	ft_dl_clear(t_dlist **head, const t_data_apply del);

/// @brief Clear a list until the end
/// @param start The start of the list
/// @param end The end of the list
/// @param del The function to delete the data
/// @return The number of nodes deleted
size_t	ft_dl_clear_range(t_dlist *start, const t_dlist *end,
			const t_data_apply del);

/// @brief Clear a list
/// @param lst The list
/// @param del The function to delete the data
/// @return void
void	ft_ll_clear(t_list **lst, const t_data_apply del);

// TODO: implement clear range for ll
// size_t	ft_ll_clear_range(t_dlist *start, const t_dlist *end,
//						 const t_data_apply del);

/// @brief Clear a list
/// @param head The adress of head of the list to clear
/// @param del The function to delete the data
/// @return The number of nodes deleted
/// @note The head is set to NULL
size_t	ft_cl_clear(t_clist **head, const t_data_apply del);

/// @brief Clear a list until the end (if no end, clear all)
/// @param start The start of the list
/// @param end The end of the list
/// @param del The function to delete the data
/// @return The number of nodes deleted
/// @note The range is inclusive on start and exclusive on end [start, end[
size_t	ft_cl_clear_range(t_clist *start, const t_clist *end,
			const t_data_apply del);

/* ************************************************************************** */
/*                              CREATE & COPY                                 */
/* ************************************************************************** */

/// @brief Create a new node
/// @param data The data of the node
/// @return The new node
t_dlist	*ft_dl_create(const void *data);

/// @brief Copy a node
/// @param other The node to copy
/// @return The new node
/// @note The node is a copy of the original node but does not copy the data
/// in a new ptr
t_dlist	*ft_dl_copy_node(const t_dlist *restrict other);

/// @brief Copy a node
/// @param other The node to copy
/// @return The new node
/// @note The node is a copy of the original node but does not copy the data
/// in a new ptr. This is wgy it doesn't need a delete function.
t_dlist	*ft_dl_copy_list(const t_dlist *restrict other);

/// @brief Create a new node
/// @param data The data of the node
/// @return The new node
t_list	*ft_ll_create(const void *restrict data);

/// @brief Copy a node
/// @param other The node to copy
/// @return The new node
/// @note Warning: this returns an ABSOLUTE copy of the t_list node given
/// as such bothe the data ptr AND the next ptr are the same.
t_list	*ft_ll_copy_node(const t_list *restrict other);

/// @brief Copy a list
/// @param other The list to copy
/// @return The new list
t_list	*ft_ll_copy_list(const t_list *restrict other);

/// @brief Create a new node
/// @param data The data of the node
/// @return The new node
t_clist	*ft_cl_create(const void *data);

/// @brief Copy a node
/// @param other The node to copy
/// @return The new node
/// @note The node is a copy of the original node but does not copy the data
/// in a new ptr
t_clist	*ft_cl_copy_node(const t_clist *restrict other);

/// @brief Copy a node
/// @param other The node to copy
/// @return The new node
/// @note The node is a copy of the original node but does not copy the data
/// in a new ptr. This is wgy it doesn't need a delete function.
t_clist	*ft_cl_copy_list(const t_clist *restrict other);

/* ************************************************************************** */
/*                                  DELETE                                    */
/* ************************************************************************** */

/// @brief Delete a node
/// @param node The node to delete
/// @param del The function to delete the data
/// @return The number of nodes deleted
int		ft_dl_delete_self(t_dlist *node, const t_data_apply del);

/// @brief Delete a range of nodes
/// @param start The node from which to delete
/// @param end The node until which to delete
/// @return The number of nodes deleted
size_t	ft_dl_delete_range(t_dlist *start, const t_dlist *restrict end,
			const t_data_apply del);

/// @brief Delete a doubly linked list entirely
/// @param head The head of the list
/// @return The number of nodes deleted
size_t	ft_dl_delete(t_dlist **head, const t_data_apply del);

// TODO: implement delete dup for dl
// /// @brief Delete duplicates node
// /// @param head The head of the list
// /// @param cmp The compare function
// /// @param del The function to delete the data
// /// @return The number of nodes deleted
// size_t	ft_dl_delete_dup(t_dlist **src, t_data_cmp cmp,
//  			const t_data_apply del);

/// @brief Delete a node
/// @param node The node to delete
/// @param del The function to delete the data
/// @return void
/// @note this is a useles function, it is here for compatibility with the
/// libft project.
void	ft_ll_delone(t_list *lst, const t_data_apply del);

/// @brief Delete a range of nodes
/// @param lst The node from which to delete
/// @param target The node until which to delete
/// @param del The function to delete the data
/// @return void
size_t	ft_ll_delete_range(t_list *lst, const t_list *restrict end,
			const t_data_apply del);

/// @brief Delete a simply linked list entirely
/// @param lst The head of the list
/// @param del The function to delete the data
/// @return The number of nodes deleted
size_t	ft_ll_delete(t_list **lst, const t_data_apply del);

// TODO: implement delete dup for ll
// /// @brief Delete duplicates node
// /// @param head The head of the list
// /// @param cmp The compare function
// /// @param del The function to delete the data
// /// @return The number of nodes deleted
// size_t	ft_ll_delete_dup(t_list **src, t_data_cmp cmp,
//  			t_data_apply del);

/// @brief Delete a range of nodes
/// @param start The node from which to delete
/// @param end The node until which to delete
/// @return The number of nodes deleted
size_t	ft_cl_delete_range(t_dlist *start, const t_dlist *restrict end,
			const t_data_apply del);

/// @brief Delete a doubly linked list entirely
/// @param head The head of the list
/// @return The number of nodes deleted
size_t	ft_cl_delete(t_dlist **head, const t_data_apply del);

/* ************************************************************************** */
/*                                  FIND                                      */
/* ************************************************************************** */

/// @brief Find a node in a list
/// @param head The head of the list
/// @param data The data to find
/// @param cmp The compare function
/// @return The node found or NULL
t_dlist	*ft_dl_find(const t_dlist *head, const void *restrict data,
			const t_data_cmp cmp);

/// @brief Find a node in a list
/// @param list The list
/// @param data The data to find
/// @param cmp The compare function
/// @return The node found or NULL
void	*ft_ll_find(const t_list *list, const void *restrict data,
			const t_data_cmp cmp);

/// @brief Find a node in a list
/// @param head The head of the list
/// @param data The data to find
/// @param cmp The compare function
/// @return The node found or NULL
t_dlist	*ft_cl_find(const t_dlist *head, const void *restrict data,
			const t_data_cmp cmp);

/* ************************************************************************** */
/*                                 GETTERS                                    */
/* ************************************************************************** */

/// @brief Get the datas of a list
/// @param src The list
/// @return The datas of the list
/// @note The datas are in the same order as the nodes and the pointers to the
/// datas need to be freed
void	**ft_dl_get_datas(const t_dlist *restrict src);

/// @brief Get the nodes of a list
/// @param src The list
/// @return The nodes of the list
/// @note The nodes are in the same order as the datas and the pointers to the
/// nodes need to be freed
t_dlist	**ft_dl_get_nodes(const t_dlist *restrict src);

/// @brief Get the datas of a list
/// @param src The list
/// @return The datas of the list
void	**ft_ll_get_datas(const t_list *restrict src);

/// @brief Get the nodes of a list
/// @param src The list
/// @return The nodes of the list
t_list	**ft_ll_get_nodes(const t_list *restrict src);

/// @brief Get the datas of a list
/// @param src The list
/// @return The datas of the list
/// @note The datas are in the same order as the nodes and the pointers to the
/// datas need to be freed
void	**ft_cl_get_datas(const t_clist *restrict src);

/// @brief Get the nodes of a list
/// @param src The list
/// @return The nodes of the list
/// @note The nodes are in the same order as the datas and the pointers to the
/// nodes need to be freed
t_clist	**ft_cl_get_nodes(const t_clist *restrict src);

/* ************************************************************************** */
/*                                  ITERATORS                                 */
/* ************************************************************************** */

/// @brief Get the last node of a list
/// @param head The head of the list
/// @param index The index of the node
/// @return The node at index or NULL,
/// @note The index is 0 based
t_dlist	*ft_dl_at(const t_dlist *head, size_t index);

/// @brief Get the last node of a list
/// @param head The head of the list
/// @return The last node of the list
t_dlist	*ft_dl_end(const t_dlist *head);

/// @brief Get the first node of a list
/// @param head The head of the list
/// @return The first node of the list
t_dlist	*ft_dl_begin(const t_dlist *head);

/// @brief Get the last node of a list
/// @param lst The list
/// @return The last node of the list
t_list	*ft_ll_end(const t_list *lst);

/// @brief Get the node of a list at position index
/// @param lst The list
/// @param index The index of the node
/// @return The node at index or NULL
t_list	*ft_ll_at(const t_list *const lst, size_t index);

/// @brief Get the first node of a list
/// @param head The head of the list
/// @return The first node of the list
/// @note: this is a simply linked list...
///   Why are you using this function?
t_list	*ft_ll_begin(const t_list *head);

/// @brief Get the last node of a list
/// @param head The head of the list
/// @param index The index of the node (if negative take
/// the nth node from the end)
/// @return The node at index or NULL,
/// @note The index is 0 based
t_clist	*ft_cl_at(const t_clist *head, ssize_t index);

/// @brief Get the last node of a list
/// @param head The head of the list
/// @return The last node of the list
t_clist	*ft_cl_end(const t_clist *head);

/// @brief Get the first node of a list
/// @param head The head of the list
/// @return The first node of the list
t_clist	*ft_cl_begin(const t_clist *head);

/* ************************************************************************** */
/*                                  MAP                                       */
/* ************************************************************************** */

/// @brief Apply a function on every node of the list
/// @param lst The list
/// @param f The function to apply
/// @param del The function to delete the data if allocation fails
/// @return The new list
t_dlist	*ft_dl_map(const t_dlist *lst, t_data_tr f, t_data_apply del);

/// @brief Apply a function on every node of the list
/// @param lst The list
/// @param f The function to apply
/// @param del The function to delete the data if allocation fails
/// @return The new list
t_list	*ft_ll_map(const t_list *lst, t_data_tr f, t_data_apply del);

/// @brief Apply a function on every node of the list
/// @param lst The list
/// @param f The function to apply
/// @param del The function to delete the data if allocation fails
/// @return The new list
t_clist	*ft_cl_map(const t_clist *lst, t_data_tr f, t_data_apply del);

/* ************************************************************************** */
/*                                  NEW                                       */
/* ************************************************************************** */

/// @brief Create a new node
/// @return The new node
t_dlist	*ft_dl_new(void);

/// @brief Create a new node
/// @return The new node
t_list	*ft_ll_new(void);

/// @brief Create a new node
/// @return The new node
t_clist	*ft_cl_new(void);

/* ************************************************************************** */
/*								PUSH & POP									  */
/* ************************************************************************** */

/// @brief Push a node at the beginning of the list
/// @param node The head of the list
/// @param data The data of the node
/// @return The new head of the list
t_dlist	*ft_dl_push(t_dlist **node, const void *restrict data);

/// @brief Push a node at the end of the list
/// @param node The head of the list
/// @param data The data of the node
/// @return The new head of the list
t_dlist	*ft_dl_push_back(t_dlist **node, const void *restrict data);

/// @brief Pop a node at the beginning of the list
/// @param node The head of the list
/// @return The data of the node
void	*ft_dl_pop(t_dlist **node);

/// @brief Pop a node at the end of the list
/// @param node The head of the list
/// @return The data of the node
void	*ft_dl_pop_back(t_dlist **node);

/// @brief Push a node at the beginning of the list
/// @param lst The head of the list
/// @param data The data of the node
/// @return The new head of the list
t_list	*ft_ll_push(t_list **lst, const void *restrict data);

/// @brief Push a node at the end of the list
/// @param lst The head of the list
/// @param data The data of the node
/// @return The new head of the list
t_list	*ft_ll_push_back(t_list **lst, const void *restrict data);

/// @brief Pop a node at the beginning of the list
/// @param lst The head of the list
/// @return The data of the node
void	*ft_ll_pop(t_list **lst);

/// @brief Pop a node at the end of the list
/// @param lst The head of the list
/// @return The data of the node
void	*ft_ll_pop_back(t_list **lst);

/// @brief Push a node at the beginning of the list
/// @param node The head of the list
/// @param data The data of the node
/// @return The new head of the list
t_clist	*ft_cl_push(t_clist **node, const void *restrict data);

/// @brief Push a node at the end of the list
/// @param node The head of the list
/// @param data The data of the node
/// @return The new head of the list
t_clist	*ft_cl_push_back(t_clist **node, const void *restrict data);

/// @brief Pop a node at the beginning of the list
/// @param node The head of the list
/// @return The data of the node
void	*ft_cl_pop(t_clist **node);

/// @brief Pop a node at the end of the list
/// @param node The head of the list
/// @return The data of the node
void	*ft_cl_pop_back(t_clist **node);

/* ************************************************************************** */
/*                                  REVERSE                                   */
/* ************************************************************************** */

/// @brief Reverse a list
/// @param head The head of the list
/// @return the new head of the list
t_dlist	*ft_dl_rev(t_dlist **head);

/// @brief Reverse a list
/// @param head The head of the list
/// @return the new head of the list
t_list	*ft_ll_rev(t_list **head);

/// @brief Reverse a list
/// @param head The head of the list
/// @return the new head of the list
t_dlist	*ft_cl_rev(t_dlist **head);

/* ************************************************************************** */
/*                                  SIZE                                      */
/* ************************************************************************** */

/// @brief Get the size of a list
/// @param head The head of the list
/// @return The size of the list
size_t	ft_dl_size(const t_dlist *head);

/// @brief Get the size of a list with a matching function
/// @param head The head of the list
/// @param function The function to check if the data is something
/// @return The size of the list
size_t	ft_dl_size_data_is(const t_dlist *head, const t_data_is function);

/// @brief Get the size of a list using a compare function
/// @param lst The list
/// @param function The function to check if the data is something
/// @return The size of the list
size_t	ft_dl_size_cmp(const t_dlist *lst, const void *restrict data,
			const t_data_cmp function);

/// @brief Get the size of a list
/// @param lst The list
/// @return The size of the list
size_t	ft_ll_size(const t_list *lst);

/// @brief Get the size of a list with a matching function
/// @param lst The list
/// @param function The function to check if the data is something
/// @return The size of the list
size_t	ft_ll_size_data_is(const t_list *lst, const t_data_is function);

/// @brief Get the size of a list using a compare function
/// @param lst The list
/// @param function The function to check if the data is something
/// @return The size of the list
size_t	ft_ll_size_cmp(const t_list *lst, const void *restrict data,
			const t_data_cmp function);

/// @brief Get the size of a list
/// @param head The head of the list
/// @return The size of the list
size_t	ft_cl_size(const t_clist *head);

/// @brief Get the size of a list with a matching function
/// @param head The head of the list
/// @param function The function to check if the data is something
/// @return The size of the list
size_t	ft_cl_size_data_is(const t_clist *head, const t_data_is function);

/// @brief Get the size of a list using a compare function
/// @param lst The list
/// @param function The function to check if the data is something
/// @return The size of the list
size_t	ft_cl_size_cmp(const t_clist *lst, const void *restrict data,
			const t_data_cmp function);

/* ************************************************************************** */
/*                                  SUB									      */
/* ************************************************************************** */

/// @brief Get a sublist of a list
/// @param lst The list
/// @param end The node until which to get the sublist
/// @return The sublist
/// @note The sublist is a copy of the original list but does not copy
/// the data in a new ptr. This is why it doesn't need a delete function.
t_dlist	*ft_dl_subrange(const t_dlist *lst, const t_dlist *restrict end);

/// @brief Get a sublist of a list
/// @param lst The list
/// @param end The node until which to get the sublist
/// @note The sublist is a copy of the original list but does not copy
/// the data in a new ptr. This is why it doesn't need a delete function.
/// @return The sublist
t_list	*ft_ll_subrange(const t_list *lst, const t_list *restrict end);

/// @brief Get a sublist of a list
/// @param lst The list
/// @param end The node until which to get the sublist
/// @note The sublist is a copy of the original list but does not copy
/// the data in a new ptr. This is why it doesn't need a delete function.
/// @return The sublist
t_clist	*ft_cl_subrange(const t_clist *src, const t_clist *restrict end);

#endif /* FT_LIST_H */
/*
GPL-3.0 License:
c42libs - Library for c projects at 42.
Copyright (C) 2025  baptiste GOULARD

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
