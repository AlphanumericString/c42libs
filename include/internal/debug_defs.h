/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_defs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:13:22 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 00:34:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdio.h>
#include <stdarg.h>

/*
 *
** Usefull when debuging stuff, dont use in prod or else #GRRRRR
 *
#define LOG(fmt, ...) printf("[LOG]\t"fmt"\n", ##__VA_ARGS__); fflush(stdout);
#define LOG_VAR(fmt, var) LOG(#var":"fmt, var);
#define LOG_POS	LOG("@ %s ( %s:%d )", __func__, __FILE__, __LINE__);
*/
