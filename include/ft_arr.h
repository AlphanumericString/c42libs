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

// # TODO: add the following array functions:
// # ft_arev	- reverse any array
// # ft_ancmp	- n version of cmp
// # ft_andup	- n version of dup
// todo: change search to return a t_const_arr at pos where cmp_d was found

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

/// @brief	aplies a function to all member of the array
/// @param	array, the array the funcion f is applied to
/// @param	f, the function to applied
void			ft_aapply(t_oconst_arr array, t_data_apply f);

/// @brief function the same way as a strcat would, append to the end of
///	 array ar_dst the array ar_src.
/// @param ar_dst, the destination array
/// @param ar_src, the source array
void			ft_acat(t_iconst_arr ar_dst, t_const_arr ar_src);

/// @brief function the same way as a strlcat would, append to the end of
///	 array ar_dst the array ar_src but only if there is enough space
///	 in ar_dst.
/// @param ar_dst, the destination array
/// @param mx, the maximum size of the destination array
/// @param ar_src, the source array
void			ft_alcat(t_iconst_arr ar_dst, size_t mx, t_const_arr ar_src);

/// @brief	copies the content of array src into dst
/// @param	dst, the destination array
/// @param	src, the source array
void			ft_acpy(t_iconst_arr dst, t_const_arr src);

/// @brief	copies the content of array src into dst but only if there is
///	 enough space in dst.
///	 @param	dst, the destination array
///	 @param	mx, the maximum size of the destination array
///	 @param	src, the source array
void			ft_alcpy(t_iconst_arr dst, size_t mx, t_const_arr src);

/// @brief	returns the length of an array
/// @param	array, the array to gets the length of.
size_t			ft_alen(t_const_arr array);

/// @brief	sets all field of an array to null bytes
/// @param	array, the array to null the field of.
void			ft_aclear(t_iconst_arr arr);

/// @brief	compare two set of array.
/// @param	a1, the first array of the comparaison
/// @param	a2, the second array of the comparaison
/// @return	-1, 0, 1, if a1 < a2, a1 == a2, a1 > a2
/// @note	only compares by raw pointer values in a1[i] == a2[i] style, use
///		ft_acmp_with to compare using a function.
int				ft_acmp(t_const_arr a1, t_const_arr a2);

/// @brief	compare two set of array.
/// @param	a1, the first array of the comparaison
/// @param	a2, the second array of the comparaison
/// @param	cmp, the comparaison function
/// @return	-1, 0, 1, if a1 < a2, a1 == a2, a1 > a2
/// @note	compares by calling cmp on both element, for faster but less
///		accurate comparaisons use ft_acmp.
int				ft_acmp_with(t_const_arr a1, t_const_arr a2, t_data_cmp cmp);

/// @brief	Duplicate an array arr
/// @param	arr, the array to duplicate
/// @return	either a new array or null if allocation failed.
/// @note	This is NOT A DEEP COPY. As t_*arr types are void typed we dont
///		copy the data.
t_iconst_arr	ft_adup(t_const_arr arr);

/// @brief	search for element n in array arr (linear search)
/// @param	arr, the array to search into
/// @param	cmp_d, the pointer used to search
/// @return	either null if not found or first match for cmp_d;
/// @note	very fast search but compares raw pointer and not the data in them
///		to compare the data in them use '_with' variant.
const void		*ft_afind(t_const_arr arr, const void *cmp_d);
/// @brief	search for element n in array arr (linear search)
/// @param	arr, the array to search into
/// @param	cmp_d, the pointer used to search
/// @param	cmp, the comparaison function
/// @return	either null if not found or first match for cmp_d using cmp
///		function.
/// @note	compares by calling cmp elements, for faster but less accurate
///		searches, checkout ft_afind
const void		*ft_afind_with(t_const_arr arr, const void *cmp_d,
					t_data_cmp cmp);

/// @brief	search for element n in array arr (linear search)
/// @param	arr, the array to search into
/// @param	cmp_d, the pointer used to search
/// @return	either null if not found or last match for cmp_d;
/// @note	very fast search but compares raw pointer and not the data in them
///		to compare the data in them use '_with' variant.
const void		*ft_arfind(t_const_arr arr, const void *cmp_d);
/// @brief	search for element n in array arr (linear search)
/// @param	arr, the array to search into
/// @param	cmp_d, the pointer used to search
/// @param	cmp, the comparaison function
/// @return	either null if not found or last match for cmp_d using cmp
///		function.
/// @note	compares by calling cmp elements, for faster but less accurate
///		searches, checkout ft_arfind
const void		*ft_arfind_with(t_const_arr arr, const void *cmp_d,
					t_data_cmp cmp);

/// @brief	call ft_free on every sub elements and then on the array itself
/// @param	arr, the array to free.
/// @note	if you only need to free the sub elements use ft_aaply. if you
///		only need to free the array itself call ft_free.
void			ft_afree(void **arr);

///	@brief	call a function f on every elements and expects data to not be
///	const to TRansform In-place.
///	@param	arr, the array holding the elements to call the function on.
///	@note	if your array is const use ft_adup to copy it before calling this.
void			ft_atr(t_arr arr, t_data_tr_i tr);

/// @brief	allocate a new array and populate it with the result of
///		function f applied to each element of arr.
///	@param	arr, the array to map
///	@param	f, the function to apply to each element of arr
/// @return	a new array with the result of f applied to each element of arr or
///		NULL if allocation failed.
t_arr			ft_amap(t_const_arr arr, t_data_tr f);

/// @brief	allocate a new array and populate it with the result of
///		function f applied up to n elements of arr.
///	@param	arr, the array to map
///	@param	n, the number of max elements to map
///	@param	f, the function to apply to each element of arr
/// @return	a new array with the result of f applied up to n element of arr or
///		NULL if allocation failed.
t_arr			ft_anmap(t_const_arr array, size_t n, t_data_tr f);

#endif /* FT_ARR_H */
