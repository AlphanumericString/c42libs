/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_narena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:41:16 by bgoulard          #+#    #+#             */
/*   Updated: 2024/10/14 17:07:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_string.h"
#include "ft_math.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FT__TEST_BLOCK_SIZE_SMALL 4
#define FT__TEST_BLOCK_SIZE_MEDIUM 64
#define FT__TEST_BLOCK_SIZE_LARGE 1024

#define FT__PRODUCTION_BLOCK_SIZE 4096

#define FT_NARENAS_MAX 16
#define FT_AREA_BLOCK_SIZE FT__TEST_BLOCK_SIZE_SMALL

typedef struct s_memblock t_memblock;
typedef struct s_memsgmnt t_memsgmnt;

// info on the block
//  - is the block curently used?
//  - is the block a source (aka first of arena)?
typedef enum e_memblk_info {
	FT_NAR_BLK_USED = 1 << 0,
	FT_NAR_BLK_SRC = 1 << 1,
} t_memblk_info;

struct s_memblock {
	t_memblock	*block_nxt;
	t_memsgmnt	*last_ret;
	void		*max;
	int			blk_info;
};

// potential optimization: add a pointer to the parent block in the segment
struct s_memsgmnt {
	t_memsgmnt	*prv;
	t_memsgmnt	*nxt;
	size_t		size;
};

t_memblock	*ft_get_arena_n(int request, bool set, t_memblock *restrict data)
{
	static t_memblock	*block_source[FT_NARENAS_MAX] = {0};

	if (request < 0 || request > FT_NARENAS_MAX)
		return (NULL);
	if (set)
		block_source[request] = data;
	return (block_source[request]);
}

t_memblock	*search_sz(t_memblock **blk, size_t sz_search)
{
	t_memsgmnt	*lst;
	void		*cur;
	t_memblock	*iterator;

	iterator = *blk;
	while (iterator)
	{
		lst = (iterator)->last_ret;
		// if the blcok is new or not used use block from start
		// else use from last returned segment
		if (!lst || ((iterator)->blk_info & FT_NAR_BLK_USED) == false)
			cur = (void *)((size_t)iterator + sizeof(*iterator));
		else
			cur = (void *)((size_t)lst + lst->size);
		// check if there is enough space in the block
		if ((size_t)(iterator->max - cur) > sz_search)
			break;
		iterator = (iterator)->block_nxt;
	}
	if (iterator)
		*blk = iterator;
	return (iterator);
}

bool	add_blk(t_memblock **blk, size_t min_blk_sz, int arena)
{
	t_memblock	*blck_cr;

	(void)arena;
	if (min_blk_sz < FT_AREA_BLOCK_SIZE)
		min_blk_sz = FT_AREA_BLOCK_SIZE;
	min_blk_sz = ft_align_2(min_blk_sz + sizeof(t_memblock));
	blck_cr = malloc(min_blk_sz);
	if (!blck_cr)
		return (false);
	while (*blk && (*blk)->block_nxt)
		(*blk) = (*blk)->block_nxt;
	if (*blk)
		(*blk)->block_nxt = blck_cr;
	*blk = blck_cr;
	blck_cr->block_nxt = NULL;
	blck_cr->last_ret = NULL;
	blck_cr->max = (void *)((size_t)blck_cr + min_blk_sz - sizeof(t_memblock));
	blck_cr->blk_info = 0;
	return (true);
}

void	*ft_narena_alloc(size_t	request, int arena)
{
	t_memblock	*blk;
	t_memsgmnt	*prev;
	t_memsgmnt	*segment;

	if (arena < 0 || arena > FT_NARENAS_MAX)
		return (NULL);
	blk = ft_get_arena_n(arena, 0, NULL);
	request += sizeof(typeof(*prev));
	if (!blk)
	{
		if (!add_blk(&blk, request, arena))
			return (NULL);
		ft_get_arena_n(arena, true, blk);
	}
	else if (!search_sz(&blk, request) && !add_blk(&blk, request, arena))
		return (NULL);
	// if no block or no space in block   -and-  add block failed
	prev = blk->last_ret;
	segment = (void *)((size_t)blk + sizeof(*blk));
	if (prev)
		segment = (void *)((size_t)prev + sizeof(*prev) + prev->size);
	blk->blk_info = blk->blk_info | 1 << FT_NAR_BLK_USED;
	segment->prv = prev;
	segment->size = request;
	segment->nxt = NULL;
	return (blk->last_ret = segment, segment + 1);
}

void *search_segment(t_memblock **blk, t_memsgmnt *seg)
{
	t_memblock	*iterator;
	t_memsgmnt	*seg_iter;

	iterator = *blk;
	while (iterator)
	{
		seg_iter = (t_memsgmnt *)(iterator + 1);
		while (seg_iter)
		{
			if (seg_iter == seg)
				return (*blk = iterator, iterator);
			seg_iter = seg_iter->nxt;
		}
		iterator = iterator->block_nxt;
	}
	return (NULL);
}

void	ft_narena_free(void *usr_ptr, int arena)
{
	t_memsgmnt	*seg;
	t_memblock	*blk;

	if (arena < 0 || arena > FT_NARENAS_MAX || !usr_ptr)
		return ;
	seg = (t_memsgmnt *)usr_ptr - 1;
	if (seg->prv)
	{
		seg->prv->nxt = seg->nxt;
		seg->prv->size += seg->size + sizeof(*seg);
	}
	if (seg->nxt)
		seg->nxt->prv = seg->prv;
	if (!seg->prv && !seg->nxt)
	{
		blk = 
	}
}

void	*ft_narena_realloc(void *usr_ptr, size_t memsz, int arena)
{
	t_memsgmnt	*seg;
	void		*new_ptr;
	t_memblock	*blk;

	if (arena < 0 || arena > FT_NARENAS_MAX)
		return (NULL);
	seg = (t_memsgmnt *)usr_ptr - 1;
	if (seg->size >= memsz)
		return (usr_ptr);
	blk = ft_get_arena_n(arena, 0, NULL);
	if (!seg->nxt) {
		if (search_segment(&blk, seg) == NULL)
			return (NULL);
		if ((size_t)(blk->max - (void *)(seg + 1)) >= memsz) {
			seg->size = memsz;
			return (usr_ptr);
		} else {
			new_ptr = ft_narena_alloc(memsz, arena);
			if (!new_ptr)
				return (NULL);
			ft_memcpy(new_ptr, usr_ptr, seg->size);
			ft_narena_free(usr_ptr, arena);
			return (new_ptr);
		}
	}
	else if ((size_t)(seg->nxt - (seg + 1)) >= memsz)
	{
		seg->size = memsz;
		return (usr_ptr);
	}
	else
	{
	}
	return (NULL);
}

void	*ft_narena_calloc(size_t count, size_t size, int arena)
{
	void	*ptr;

	ptr = ft_narena_alloc(count * size, arena);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	*ft_narena_destroy(int arena_n)
{
	t_memblock	*blk;
	t_memblock	*tmp;

	if (arena_n < 0 || arena_n > FT_NARENAS_MAX)
		return (NULL);
	blk = ft_get_arena_n(arena_n, false, NULL);
	while (blk)
	{
		tmp = blk->block_nxt;
		free(blk);
		blk = tmp;
	}
	ft_get_arena_n(arena_n, true, NULL);
	return (NULL);
}

void	*ft_narena_destroy_all(void)
{
	int	i;

	i = 0;
	while (i < FT_NARENAS_MAX)
		ft_narena_destroy(i++);
	return (NULL);
}

void	garbage_collector(void) __attribute__((destructor(65535), used));

void	garbage_collector(void)
{
	ft_narena_destroy_all();
}
