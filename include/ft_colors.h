/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:01:55 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:18:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H

// ------------------------------
// Pick and choose section:
// ------------------------------

# define FT_C_START "\033["
# define FT_C_SEP ";"
# define FT_C_END "m"

// Text effects:
// bold, dim, italic, underline,
// blink, blink (fast), reverse, hidden, strikethrough
# define FT_C_TNONE		"0"
# define FT_C_TB		"1"
# define FT_C_TD		"2"
# define FT_C_TI		"3"
# define FT_C_TU		"4"
# define FT_C_TBLI		"5"
# define FT_C_TBLI2		"6"
# define FT_C_TREV		"7"
# define FT_C_THID		"8"
# define FT_C_TSTK		"9"

# define FT_C_TOPT_OFF	"2"
# define FT_C_TB_OFF	"21"
# define FT_C_TD_OFF	"22"
# define FT_C_TI_OFF	"23"
# define FT_C_TU_OFF	"24"
# define FT_C_TBLI_OFF	"25"
# define FT_C_TBLI2_OFF	"26"
# define FT_C_TREV_OFF	"27"
# define FT_C_THID_OFF	"28"
# define FT_C_TSTK_OFF	"29"

// Text colors:
// 'main' colors
# define FT_C_MTBLK		"30"
# define FT_C_MTRED		"31"
# define FT_C_MTGRN		"32"
# define FT_C_MTYEL		"33"
# define FT_C_MTBLU		"34"
# define FT_C_MTMAG		"35"
# define FT_C_MTCYN		"36"
# define FT_C_MTWHT		"37"
// 'bright' versions
# define FT_C_MTBBLK	"90"
# define FT_C_MTBRED	"91"
# define FT_C_MTBGRN	"92"
# define FT_C_MTBYEL	"93"
# define FT_C_MTBBLU	"94"
# define FT_C_MTBMAG	"95"
# define FT_C_MTBCYN	"96"
# define FT_C_MTBWHT	"97"

// 'main' background colors
# define FT_C_BGBLK "40"
# define FT_C_BGRED "41"
# define FT_C_BGGRN "42"
# define FT_C_BGYEL "43"
# define FT_C_BGBLU "44"
# define FT_C_BGMAG "45"
# define FT_C_BGCYN "46"
# define FT_C_BGWHT "47"
// 'bright' background versions
# define FT_C_BGBBLK "100"
# define FT_C_BGBRED "101"
# define FT_C_BGBGRN "102"
# define FT_C_BGBYEL "103"
# define FT_C_BGBBLU "104"
# define FT_C_BGBMAG "105"
# define FT_C_BGBCYN "106"
# define FT_C_BGBWHT "107"

// ------------------------------
// fast version:
// ------------------------------

// text
# define FT_CBLK	"\033[30m"
# define FT_CRED	"\033[31m"
# define FT_CGRN	"\033[32m"
# define FT_CYEL	"\033[33m"
# define FT_CBLU	"\033[34m"
# define FT_CMAG	"\033[35m"
# define FT_CCYN	"\033[36m"
# define FT_CWHT	"\033[37m"
// High intensty text
# define FT_CHBLK	"\033[90m"
# define FT_CHRED	"\033[91m"
# define FT_CHGRN	"\033[92m"
# define FT_CHYEL	"\033[93m"
# define FT_CHBLU	"\033[94m"
# define FT_CHMAG	"\033[95m"
# define FT_CHCYN	"\033[96m"
# define FT_CHWHT	"\033[97m"

// background
# define FT_CBLKB	"\033[40m"
# define FT_CREDB	"\033[41m"
# define FT_CGRNB	"\033[42m"
# define FT_CYELB	"\033[43m"
# define FT_CBLUB	"\033[44m"
# define FT_CMAGB	"\033[45m"
# define FT_CCYNB	"\033[46m"
# define FT_CWHTB	"\033[47m"
// High intensty background
# define FT_CBLKHB	"\033[100m"
# define FT_CREDHB	"\033[101m"
# define FT_CGRNHB	"\033[102m"
# define FT_CYELHB	"\033[103m"
# define FT_CBLUHB	"\033[104m"
# define FT_CMAGHB	"\033[105m"
# define FT_CCYNHB	"\033[106m"
# define FT_CWHTHB	"\033[107m"

// classic error, warning, success and info messages colors
# ifdef FT_CLASSIC_COLORS
#  define FT_C_ERROR	"\033[1;31m"
#  define FT_C_WARNING	"\033[4;35m"
#  define FT_C_SUCCESS	"\033[32m"
#  define FT_C_INFO		"\033[33m"
# endif

# define FT_C_RESET "\033[0m"

#endif /* FT_COLORS_H */
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
