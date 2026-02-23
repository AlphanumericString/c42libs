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
# include <stddef.h>

// todo: change search to return a t_const_arr at pos where cmp_d was found
// todo: sorts - see ft_defs.h
// todo: is_sorted[_with] -> check if the array is sorted
// todo: binary search -> requires sort

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
/// @param	ar the array the funcion f is applied to
/// @param	f the function to applied
/// @note MT-safe - depends on f being MT-safe
/// @note AC-Safe - depends on f being AC-Safe
/// @note AS-Safe - depends on f being AS-Safe
void			ft_aapply(t_oconst_arr ar, t_data_apply f);
/// @brief	aplies a function onto up to n member of the array
/// @param	ar the array the funcion f is applied to
/// @param	n the maximum number of elements to apply the function f to
/// @param	f the function to applied
/// @note MT-safe - depends on f being MT-safe
/// @note AC-Safe - depends on f being AC-Safe
/// @note AS-Safe - depends on f being AS-Safe
void			ft_anapply(t_oconst_arr ar, size_t n, t_data_apply f);

/// @brief function the same way as a strcat would, append to the end of
///		array ar_dst the array ar_src.
/// @param	ar_dst the destination array
/// @param	ar_src the source array
/// @note MT-safe
/// @note no guarantee of AC-Safe
/// @note no guarantee of AS-Safe
void			ft_acat(t_iconst_arr ar_dst, t_const_arr ar_src);
/// @brief function the same way as a strlcat would, append to the end of
///		array ar_dst the array ar_src but only if there is enough space
///		in ar_dst.
/// @param	ar_dst the destination array
/// @param	mx the maximum size of the destination array
/// @param	ar_src the source array
/// @note MT-safe
/// @note no guarantee of AC-Safe
/// @note no guarantee of AS-Safe
void			ft_alcat(t_iconst_arr ar_dst, size_t mx, t_const_arr ar_src);

/// @brief	copies the content of array src into dst
/// @param	dst the destination array
/// @param	src the source array
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
void			ft_acpy(t_iconst_arr dst, t_const_arr src);
/// @brief	copies the content of array src into dst but only if there is
///		enough space in dst.
///	@param	dst the destination array
///	@param	mx the maximum size of the destination array
///	@param	src the source array
/// @note MT-safe
/// @note no guarantee of AC-Safe - if interruptted dst might not have a
///		null terminator
/// @note no guarantee of AS-Safe - if interruptted dst might not have a
///		null terminator
void			ft_alcpy(t_iconst_arr dst, size_t mx, t_const_arr src);

/// @brief	returns the length of an array
/// @param	ar the array to gets the length of.
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
size_t			ft_alen(t_const_arr ar);
/// @brief	returns the length of an array or n
/// @param	ar the array to gets the length of.
/// @param	n the max number of elements accessed.
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
size_t			ft_anlen(t_const_arr array, size_t n);

/// @brief	sets all field of an array to null bytes
/// @param	ar the array to null the field of
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
void			ft_aclear(t_iconst_arr ar);

/// @brief	compare two set of array.
/// @param	a1 the first array of the comparaison
/// @param	a2 the second array of the comparaison
/// @return	-1, 0, 1, if a1 < a2, a1 == a2, a1 > a2
/// @note	only compares by raw pointer values in a1[i] == a2[i] style, use
///		ft_acmp_with to compare using a function.
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
int				ft_acmp(t_const_arr a1, t_const_arr a2);
/// @brief	compare up to n elements of two sets of array.
/// @param	a1 the first array of the comparaison
/// @param	a2 the second array of the comparaison
/// @param	n the maximum number of elements to compare
/// @return	-1, 0, 1, if a1 < a2, a1 == a2, a1 > a2
/// @note	only compares by raw pointer values in a1[i] == a2[i] style, use
///			ft_ancmp_with to compare using a function.
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
int				ft_ancmp(t_const_arr a1, t_const_arr a2, size_t n);

/// @brief	compare two set of array using a function.
/// @param	a1 the first array of the comparaison
/// @param	a2 the second array of the comparaison
/// @param	cmp the comparaison function
/// @return	-1, 0, 1, if a1 < a2, a1 == a2, a1 > a2
/// @note	compares by calling cmp on both element, for faster but less
///		accurate comparaisons use ft_acmp.
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
int				ft_acmp_with(t_const_arr a1, t_const_arr a2, t_data_cmp cmp);
/// @brief	compare up to n elements of two sets of array using a function.
/// @param	a1 the first array of the comparaison
/// @param	a2 the second array of the comparaison
/// @param	n the maximum number of elements to compare
/// @param	cmp the comparaison function
/// @return	-1, 0, 1, if a1 < a2, a1 == a2, a1 > a2
/// @note	compares by calling cmp on both element, for faster but less
///		accurate comparaisons use ft_ancmp.
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
int				ft_ancmp_with(t_const_arr a1, t_const_arr a2, size_t n,
					t_data_cmp cmp);

/// @brief	Duplicate an array arr
/// @param	arr the array to duplicate
/// @return	either a new array or null if allocation failed.
/// @note	This is NOT A DEEP COPY. As t_*arr types are void typed we dont
///		copy the data.
/// @note MT-safe
/// @note no guarantee of AC-Safe - if interruptted might leak memory
/// @note no guarantee of AS-Safe - if interruptted might leak memory
t_iconst_arr	ft_adup(t_const_arr arr);
/// @brief	Duplicate up to n elements of an array given
/// @param	arr the array to duplicate
/// @param	n the max number of elements to duplicate
/// @return	either a new array or null if allocation failed.
/// @note	This is NOT A DEEP COPY. As t_*arr types are void typed we dont
///		copy the data.
///	@note MT-safe
///	@note no guarantee of AC-Safe - if interruptted might leak memory
///	@note no guarantee of AS-Safe - if interruptted might leak memory
t_iconst_arr	ft_andup(t_const_arr arr, size_t n);

/// @brief	search for element n in array arr (linear search)
/// @param	arr the array to search into
/// @param	cmp_d the pointer used to search
/// @return	either null if not found or the adress of the first match in the
/// 	array for cmp_d.
/// 	eg: if arr = {&a, &b, &c, NULL} and cmp_d = &b, returns an offset to &b
/// 	in the array : {&b, &c, NULL}.
/// @note	very fast search but compares raw pointer and not the data in them
///		to compare the data in them use '_with' variant.
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
t_const_arr		ft_afind(t_const_arr arr, const void *cmp_d);
/// @brief	search for element n in array arr (linear search)
/// @param	arr the array to search into
/// @param	cmp_d the pointer used to search
/// @param	cmp the comparaison function
/// @return	either null if not found or the adress of the first match in the
/// 	array for cmp_d using cmp function.
/// 	eg: if arr = {&a, &b, &c, NULL} and cmp = &b, returns {&b, &c, NULL}
/// @note	compares by calling cmp elements, for faster but less accurate
///		searches, checkout ft_afind
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
t_const_arr		ft_afind_with(t_const_arr arr, const void *cmp_d,
					t_data_cmp cmp);

/// @brief	search for element n in array arr (linear search)
/// @param	arr the array to search into
/// @param	cmp_d the pointer used to search
/// @return	either null if not found or the adress of last match for cmp_d;
///		eg: if arr = {&b, &c, &b, NULL} and cmp_d = &b, returns {&b, NULL}
/// @note	very fast search but compares raw pointer and not the data in them
///		to compare the data in them use '_with' variant.
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
t_const_arr		ft_arfind(t_const_arr arr, const void *cmp_d);
/// @brief	search for element n in array arr (linear search)
/// @param	arr the array to search into
/// @param	cmp_d the pointer used to search
/// @param	cmp the comparaison function
/// @return	either null if not found or the adress of the last match for
///		cmp_d using the cmp function.
///		eg: if arr = {&b, &c, &b, NULL} and cmp_d = &b, returns {&b, NULL}
/// @note	compares by calling cmp elements, for faster but less accurate
///		searches, checkout ft_arfind
/// @note MT-safe
/// @note AC-Safe
/// @note AS-Safe
t_const_arr		ft_arfind_with(t_const_arr arr, const void *cmp_d,
					t_data_cmp cmp);

/// @brief	call ft_free on every sub elements and then on the array itself
/// @param	arr the array to free.
/// @note	if you only need to free the sub elements use ft_aaply. if you
///		only need to free the array itself call ft_free.
/// @note MT-safe
/// @note no guarantee of AC-Safe - if interruptted might be partially freed
/// @note no guarantee of AS-Safe - if interruptted might be partially freed
void			ft_afree(void **arr);

/// @brief	call ft_free on every sub elements and then on the array itself
/// @param	arr the array to free.
/// @param	n the number of max elements to free
/// @note	if you only need to free the sub elements use ft_aaply. if you
///		only need to free the array itself call ft_free.
/// @note MT-safe
/// @note no guarantee of AC-Safe - if interruptted might be partially freed
/// @note no guarantee of AS-Safe - if interruptted might be partially freed
void			ft_anfree(void **arr, size_t n);

/// @brief	allocate a 2D array of rows * cols elements of cell_size size
/// @param	rows the number of rows of the array
/// @param	cols the number of columns of the array
/// @param	cell_size the size of each cell
/// @return	either a new 2D array or null if any allocation failed.
/// @note	the array is NOT null terminated.
void			**ft_aalloc(size_t rows, size_t cols, size_t cell_size);

///	@brief	call a function f on every elements and expects data to not be
///		const to TRansform In-place.
///	@param	arr the array holding the elements to call the function on.
///	@param	tr the transformation function to transform the data in place
///	@note	if your array is const use ft_adup to copy it before calling this.
/// @note MT-safe - depends on tr being MT-safe
/// @note no guarantee of AC-Safe - if interruptted might be partially
///		transformed
/// @note no guarantee of AS-Safe - if interruptted might be partially
///		transformed
void			ft_atr(t_arr arr, t_data_tr_i tr);
///	@brief	call a function f on up to n element and expects data to not be
///		const to TRansform In-place.
///	@param	arr the array holding the elements to call the function on.
///	@param	n the number of max elements to transform
///	@param	tr the transformation function to transform the data in place
///	@note	if your array is const use ft_adup to copy it before calling this.
/// @note MT-safe - depends on tr being MT-safe
/// @note no guarantee of AC-Safe - if interruptted might be partially
///		transformed
/// @note no guarantee of AS-Safe - if interruptted might be partially
///		transformed
void			ft_antr(t_arr arr, size_t n, t_data_tr_i tr);

/// @brief	allocate a new array and populate it with the result of
///		function f applied to each element of arr.
///	@param	ar the array to map
///	@param	f the function to apply to each element of arr
/// @return	a new array with the result of f applied to each element of arr or
///		NULL if allocation failed.
///	@note MT-safe - depends on f being MT-safe
///	@note no guarantee of AC-Safe - if interruptted might leak memory
/// @note no guarantee of AS-Safe - if interruptted might leak memory
t_arr			ft_amap(t_const_arr ar, t_data_tr f);
/// @brief	allocate a new array and populate it with the result of
///		function f applied up to n elements of arr.
///	@param	ar the array to map
///	@param	n the number of max elements to map
///	@param	f the function to apply to each element of arr
/// @return	a new array with the result of f applied up to n element of arr or
///		NULL if allocation failed.
///	@note MT-safe - depends on f being MT-safe
///	@note no guarantee of AC-Safe - if interruptted might leak memory
///	@note no guarantee of AS-Safe - if interruptted might leak memory
t_arr			ft_anmap(t_const_arr ar, size_t n, t_data_tr f);

/// @brief itterate over the array with a function f and collects the result
/// in a value that is returned. The array is not modified.
///	@param	ar the array to collect
///	@param start_val the starting value for the collection
///	@param	f the function to apply to each element of ar
void	*ft_acollect(t_const_arr *ar, void *start_val, t_data_tr_w f);
/// @brief itterate over the array with a function f and collects the result
/// in a value that is returned. The array is not modified.
///	@param	ar the array to collect
///	@param	n the number of max elements to map
///	@param start_val the starting value for the collection
///	@param	f the function to apply to each element of ar
void	*ft_ancollect(t_const_arr *ar, size_t n, void *start_val,
			   t_data_tr_w f);
/// @brief itterate over the array in a reverse oreder with a function f and
/// collects the result in a value that is returned. The array is not modified.
///	@param	ar the array to collect
///	@param	n the number of max elements to map
///	@param start_val the starting value for the collection
///	@param	f the function to apply to each element of ar
void	*ft_ancollect_r(t_const_arr *ar, size_t n, void *start_val,
			   t_data_tr_w f);

/// @brief divides the length of the array by 2 by pairing up values and
/// inscribing result in the array.
///	@param	ar the array to fold
///	@param	f the function to apply to each element of ar
void	ft_afold(t_arr *ar, t_data_tr_w f);
/// @brief divides the length of the array by 2 by pairing up values and
/// inscribing result in the array. Reads at most N elements.
///	@param	ar the array to fold
///	@param  n  The number of max elements
///	@param	f the function to apply to each element of ar
void	ft_anfold(t_arr *ar, size_t n, t_data_tr_w f);
/// @brief divides the length of the array by 2 by pairing up values and
/// inscribing result in the array. Itterates over in a reverse order.
/// Reads at most N elements.
///	@param	ar the array to fold
///	@param  n  The number of max elements
///	@param	f the function to apply to each element of ar
void	ft_anfold_r(t_arr *ar, size_t n, t_data_tr_w f);
/// @brief divides the length of the array by 2 by pairing up values and
/// inscribing result in the array. Iterate mlt times over the results in the
/// array dividing each times the lenght by 2. Reads at most N elements.
///	@param	ar the array to fold
///	@param  n  The number of max elements
///	@param  mlt  The number of iterations.
///	@param	f the function to apply to each element of ar
void	ft_anfold_mltp(t_arr *ar, size_t n, t_data_tr_w f, size_t mlt);
/// @brief divides the length of the array by 2 by pairing up values and
/// inscribing result in the array. Iterate mlt times over the results in the
/// array dividing each times the lenght by 2. Reads at most N elements.
/// Itterates over in a reverse order.
///	@param	ar the array to fold
///	@param  n  The number of max elements
///	@param  mlt  The number of iterations.
///	@param	f the function to apply to each element of ar
void	ft_anfold_r_mltp(t_arr *ar, size_t n, t_data_tr_w f, size_t mlt);

/// @brief	reverse the array given
/// @param	ar the array to reverse
/// @note MT-safe
/// @note AC-Safe - might be partially reversed if interruptted
/// @note AS-Safe - might be partially reversed if interruptted
void			ft_arev(t_iconst_arr ar);
/// @brief	reverse up to n elements of the array given.
/// @param	ar the array to reverse
/// @param	n the number of max elements to reverse
/// @note MT-safe
/// @note AC-Safe - might be partially reversed if interruptted
/// @note AS-Safe - might be partially reversed if interruptted
void			ft_anrev(t_iconst_arr ar, size_t n);

#endif /* FT_ARR_H */
