/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:53:56 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 13:10:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARR_H
# define FT_ARR_H

# include "ft_defs.h"
// TODO: docs! tests!

/* ************************************************************************** */
/* 					                                                          */
/* Module: ft_array                                                           */
/* Prefix:	ft_a,                      										  */
/*																		      */
/* This interface provide all the usefull features one might want to do on	  */
/*		an array of ellements, such as apply a function to each element,	  */
/*		just getting the lenght of said array. Even though the array are	  */
/*		void typed and do NOT provide type safety, this is mitigated by the   */
/*		t_[[io]const_]arr structures.										  */
/*		t_const_arr -> the whole array is const								  */
/*		t_iconst_arr -> the intrenal data is const							  */
/*			(cant modify the 'cases' but can switch order and what is pointed)*/
/*		t_oconst_arr -> the outer pointer to the data is const				  */
/*			(can modify 'cases' but cant switch order and what is pointed)	  */
/*																			  */
/* ************************************************************************** */

void			ft_aapply(t_oconst_arr array, t_data_apply f);

void			ft_acat(t_iconst_arr ar_dst, t_const_arr ar_src);

size_t			ft_alen(t_const_arr array);

void			ft_aclear(t_iconst_arr arr);

bool			ft_acmp(t_const_arr a1, t_const_arr a2);
bool			ft_acmp_with(t_const_arr a1, t_const_arr a2, t_data_cmp cmp);

t_iconst_arr	ft_adup(t_const_arr arr);

const void		*ft_afind(t_const_arr arr, const void *cmp_d);
const void		*ft_afind_with(t_const_arr arr, const void *cmp_d,
					t_data_cmp cmp);
const void		*ft_arfind(t_const_arr arr, const void *cmp_d);
const void		*ft_arfind_with(t_const_arr arr, const void *cmp_d,
					t_data_cmp cmp);

void			ft_afree(void **arr);

void			ft_atr(t_arr arr, t_data_tr_i tr);

#endif /* FT_ARR_H */
