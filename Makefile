# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 09:04:05 by bgoulard          #+#    #+#              #
#    Updated: 2025/06/15 15:13:32 by bgoulard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GRAY		= \e[90m
GREEN		= \e[42m
RED			= \e[41m
RESET		= \e[0m
BOLD		= \e[1m
YELLOW		= \e[33m

ERROR_COLOR	= $(RED)$(BOLD)
GOOD_COLOR	= $(GREEN)$(BOLD)
INFO_COLOR	= $(YELLOW)$(BOLD)
BG_INFO		= $(GRAY)
LOG_INFO	= $(RESET)$(BOLD)

# Commands - dependancies
CC			=	clang
NAME		=	c42lib
TEST_NAME	=	tests_run
QTEST_NAME	=	quick_tests_run
AR			=	ar
COV			=	llvm-cov
PRD			=	llvm-profdata
ECHO		=	$(shell which echo		2>/dev/null) -e
PRINTF		=	$(shell which printf	2>/dev/null)
BEAR		=	$(shell which bear		2>/dev/null)
CTAGS		=	$(shell which ctags		2>/dev/null)

# Directories

SRC_DIR			=	src
BUILD_DIR		=	build
TESTS_DIR		=	tests
INC_DIR			=	include
COVERAGE_DIR	=	coverage

FT_MAP_DIR		=	$(SRC_DIR)/ft_map
FT_LIST_DIR		=	$(SRC_DIR)/ft_list
FT_STRING_DIR	=	$(SRC_DIR)/ft_string
FT_VEC_DIR		=	$(SRC_DIR)/ft_vector
FT_OPTIONAL_DIR	=	$(SRC_DIR)/ft_optional
FT_ARGS_DIR		=	$(SRC_DIR)/ft_args
FT_MATH_DIR		=	$(SRC_DIR)/ft_math
FT_PAIR_DIR		=	$(SRC_DIR)/ft_pair
FT_BITSET_DIR	=	$(SRC_DIR)/ft_bitset

FT_LIST_LL_DIR	=	$(FT_LIST_DIR)/ft_ll
FT_LIST_DL_DIR	=	$(FT_LIST_DIR)/ft_dl
FT_LIST_CL_DIR	=	$(FT_LIST_DIR)/ft_cl

FT_CHR_DIR		=	$(FT_STRING_DIR)/ft_chr
FT_MEM_DIR		=	$(FT_STRING_DIR)/ft_mem
FT_NUM_DIR		=	$(FT_STRING_DIR)/ft_num
FT_PUT_DIR		=	$(FT_STRING_DIR)/ft_put
FT_STR_DIR		=	$(FT_STRING_DIR)/ft_str
FT_T_STRING_DIR	=	$(FT_STRING_DIR)/ft_string

# Compilation flags
##
## To change debug level run make DEBUG_LEVEL=xxx
##

WFLAGS		= -Wall -Wextra -Werror -Wmissing-prototypes
LDFLAGS		=
STDFLAGS	= -std=c99

CPPFLAGS	=\
			 $(addprefix -I, $(INC_DIR)) -MMD -MP
FFLAGS		=\
			-fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined	   \
			-fsanitize=leak -fsanitize=pointer-compare 						   \
			-fsanitize=pointer-subtract										   \
			-fsanitize-address-use-after-scope -fsanitize=pointer-overflow

CFLAGS		=\
			$(WFLAGS) $(CPPFLAGS) -fPIC -fdiagnostics-color                    \
			-fno-inline -fno-inline-functions ${STDFLAGS}

TEST_FLAGS	=\
			-g2	-DTEST														\
			-fprofile-instr-generate -ftest-coverage -fcoverage-mapping		\
			-fno-inline -fno-inline-functions -DFORK_TESTS=1 -O0

DEBUG_LEVEL	?=\
		0
# do not optimize tests
DEBUG_FLAGS	=\
		-g2	-DDEBUG	-DDEBUG_LEVEL=$(DEBUG_LEVEL)	\
		-fno-inline -fno-inline-functions

ifeq ($(DEBUG_LEVEL), 0)
	CFLAGS := $(CFLAGS)
else
	CFLAGS := $(CFLAGS) $(DEBUG_FLAGS)
endif

# Inner variables

MAX_FILE_LEN	=	0
CLOG_FILE		=	./compilation.log

# Check for llvm-cov and llvm-profdata
#   If not found, use the version 12 if available
#   If not found, use the version 14 (latest version)
ifeq (, $(shell which $(COV) 2> /dev/null))
	COV			=	llvm-cov-12
	ifeq (, $(shell which $(COV) 2> /dev/null))
		COV			=	llvm-cov-14
	endif
endif

ifeq (, $(shell which $(PRD) 2> /dev/null))
	PRD			=	llvm-profdata-12
	ifeq (, $(shell which $(PRD) 2> /dev/null))
		PRD			=	llvm-profdata-14
	endif
endif

# Sources

FT_BITSET_SRC	=	\
			$(FT_BITSET_DIR)/ft_bs_append.c		\
			$(FT_BITSET_DIR)/ft_bs_free.c		\
			$(FT_BITSET_DIR)/ft_bs_get.c		\
			$(FT_BITSET_DIR)/ft_bs_new.c		\
			$(FT_BITSET_DIR)/ft_bs_print.c		\
			$(FT_BITSET_DIR)/ft_bs_remove.c		\
			$(FT_BITSET_DIR)/ft_bs_set.c		\
			$(FT_BITSET_DIR)/ft_bs_toggle.c

FT_PAIR_SRC	=	\
			$(FT_PAIR_DIR)/ft_pair_cmp.c		\
			$(FT_PAIR_DIR)/ft_pair_destroy.c	\
			$(FT_PAIR_DIR)/ft_pair_get.c		\
			$(FT_PAIR_DIR)/ft_pair_new.c		\
			$(FT_PAIR_DIR)/ft_pair_set.c		\

FT_MATH_SRC	=	\
			$(FT_MATH_DIR)/ft_clamp.c		\
			$(FT_MATH_DIR)/ft_complex.c		\
			$(FT_MATH_DIR)/ft_intrange.c	\
			$(FT_MATH_DIR)/ft_log.c			\
			$(FT_MATH_DIR)/ft_minmax.c		\
			$(FT_MATH_DIR)/ft_mod.c			\
			$(FT_MATH_DIR)/ft_nbrlen.c		\
			$(FT_MATH_DIR)/ft_sqrt.c		\
			$(FT_MATH_DIR)/ft_pow.c			\
			$(FT_MATH_DIR)/ft_abs.c			\
			$(FT_MATH_DIR)/ft_align.c		\
			$(FT_MATH_DIR)/ft_round.c

FT_MAP_SRC	=	\
			$(FT_MAP_DIR)/ft_map_clear.c		\
			$(FT_MAP_DIR)/ft_map_create.c		\
			$(FT_MAP_DIR)/ft_map_destroy.c		\
			$(FT_MAP_DIR)/ft_map_get.c			\
			$(FT_MAP_DIR)/ft_map_hash.c			\
			$(FT_MAP_DIR)/ft_map_remove.c		\
			$(FT_MAP_DIR)/ft_map_set.c

FT_LIST_LL_SRC	=	\
			$(FT_LIST_LL_DIR)/ft_ll_find.c			\
			$(FT_LIST_LL_DIR)/ft_ll_add.c			\
			$(FT_LIST_LL_DIR)/ft_ll_clear.c			\
			$(FT_LIST_LL_DIR)/ft_ll_check.c			\
			$(FT_LIST_LL_DIR)/ft_ll_delete.c		\
			$(FT_LIST_LL_DIR)/ft_ll_apply.c			\
			$(FT_LIST_LL_DIR)/ft_ll_iterator.c		\
			$(FT_LIST_LL_DIR)/ft_ll_map.c			\
			$(FT_LIST_LL_DIR)/ft_ll_new.c			\
			$(FT_LIST_LL_DIR)/ft_ll_rev.c			\
			$(FT_LIST_LL_DIR)/ft_ll_size.c			\
			$(FT_LIST_LL_DIR)/ft_ll_create.c		\
			$(FT_LIST_LL_DIR)/ft_ll_getters.c		\
			$(FT_LIST_LL_DIR)/ft_ll_pushpop.c		\
			$(FT_LIST_LL_DIR)/ft_ll_sub.c			\

FT_LIST_DL_SRC	=	\
			$(FT_LIST_DL_DIR)/ft_dl_apply.c		\
			$(FT_LIST_DL_DIR)/ft_dl_clear.c		\
			$(FT_LIST_DL_DIR)/ft_dl_check.c		\
			$(FT_LIST_DL_DIR)/ft_dl_create.c		\
			$(FT_LIST_DL_DIR)/ft_dl_delete.c		\
			$(FT_LIST_DL_DIR)/ft_dl_getters.c		\
			$(FT_LIST_DL_DIR)/ft_dl_iterator.c		\
			$(FT_LIST_DL_DIR)/ft_dl_pushpop.c		\
			$(FT_LIST_DL_DIR)/ft_dl_size.c			\
			$(FT_LIST_DL_DIR)/ft_dl_sub.c			\
			$(FT_LIST_DL_DIR)/ft_dl_add.c			\
			$(FT_LIST_DL_DIR)/ft_dl_rev.c			\
			$(FT_LIST_DL_DIR)/ft_dl_map.c			\
			$(FT_LIST_DL_DIR)/ft_dl_new.c			\
			$(FT_LIST_DL_DIR)/ft_dl_find.c			\

FT_LIST_CL_SRC	=	\
			$(FT_LIST_CL_DIR)/ft_cl_add.c			\
			$(FT_LIST_CL_DIR)/ft_cl_apply.c			\
			$(FT_LIST_CL_DIR)/ft_cl_check.c			\
			$(FT_LIST_CL_DIR)/ft_cl_clear.c			\
			$(FT_LIST_CL_DIR)/ft_cl_create.c		\
			$(FT_LIST_CL_DIR)/ft_cl_delete.c		\
			$(FT_LIST_CL_DIR)/ft_cl_find.c			\
			$(FT_LIST_CL_DIR)/ft_cl_getters.c		\
			$(FT_LIST_CL_DIR)/ft_cl_iterator.c		\
			$(FT_LIST_CL_DIR)/ft_cl_map.c			\
			$(FT_LIST_CL_DIR)/ft_cl_new.c			\
			$(FT_LIST_CL_DIR)/ft_cl_pushpop.c		\
			$(FT_LIST_CL_DIR)/ft_cl_rev.c			\
			$(FT_LIST_CL_DIR)/ft_cl_size.c			\
			$(FT_LIST_CL_DIR)/ft_cl_sub.c			\

FT_VEC_SRC	=	\
			$(FT_VEC_DIR)/ft_vec_add.c		\
			$(FT_VEC_DIR)/ft_vec_apply.c	\
			$(FT_VEC_DIR)/ft_vec_at.c		\
			$(FT_VEC_DIR)/ft_vec_cat.c		\
			$(FT_VEC_DIR)/ft_vec_clear.c	\
			$(FT_VEC_DIR)/ft_vec_destroy.c	\
			$(FT_VEC_DIR)/ft_vec_filter.c	\
			$(FT_VEC_DIR)/ft_vec_find.c		\
			$(FT_VEC_DIR)/ft_vec_map.c		\
			$(FT_VEC_DIR)/ft_vec_new.c		\
			$(FT_VEC_DIR)/ft_vec_pop.c		\
			$(FT_VEC_DIR)/ft_vec_remove.c	\
			$(FT_VEC_DIR)/ft_vec_reserve.c	\
			$(FT_VEC_DIR)/ft_vec_reverse.c	\
			$(FT_VEC_DIR)/ft_vec_shift.c	\
			$(FT_VEC_DIR)/ft_vec_shrink.c	\
			$(FT_VEC_DIR)/ft_vec_sort.c		\
			$(FT_VEC_DIR)/ft_vec_swap.c		\
			$(FT_VEC_DIR)/ft_vec_to_array.c

FT_OPTIONAL_SRC	=	\
			$(FT_OPTIONAL_DIR)/ft_optional_chain.c		\
			$(FT_OPTIONAL_DIR)/ft_optional_copy.c		\
			$(FT_OPTIONAL_DIR)/ft_optional_destroy.c	\
			$(FT_OPTIONAL_DIR)/ft_optional_new.c		\
			$(FT_OPTIONAL_DIR)/ft_optional_unwrap.c

FT_ARGS_SRC		=	\
			$(FT_ARGS_DIR)/ft_parse_args/ft_hold_custom_checker.c	\
			$(FT_ARGS_DIR)/ft_parse_args/ft_hold_nbparg.c			\
			$(FT_ARGS_DIR)/ft_parse_args/ft_hold_opt_list.c			\
			$(FT_ARGS_DIR)/ft_parse_args/ft_parse_long_opt.c		\
			$(FT_ARGS_DIR)/ft_parse_args/ft_parse_perror.c			\
			$(FT_ARGS_DIR)/ft_parse_args/ft_parse_print_opt.c		\
			$(FT_ARGS_DIR)/ft_parse_args/ft_parse_print_type.c		\
			$(FT_ARGS_DIR)/ft_parse_args/ft_parse_short_opt.c		\
			$(FT_ARGS_DIR)/ft_parse_args/ft_parse_utils.c			\
			$(FT_ARGS_DIR)/ft_parse_args/ft_parse_wrapper.c			\
			$(FT_ARGS_DIR)/ft_set/ft_set_ac.c					\
			$(FT_ARGS_DIR)/ft_set/ft_set_av.c					\
			$(FT_ARGS_DIR)/ft_set/ft_set_ev.c					\
			$(FT_ARGS_DIR)/ft_set/ft_set_progname.c		\
			$(FT_ARGS_DIR)/ft_set/ft_set_version.c		\
			$(FT_ARGS_DIR)/ft_consume_args.c			\
			$(FT_ARGS_DIR)/ft_get_env.c					\
			$(FT_ARGS_DIR)/ft_setup_prog.c				\
			$(FT_ARGS_DIR)/ft_shift_args.c				\

FT_CHR_SRC		=	\
			$(FT_CHR_DIR)/ft_isalnum.c				\
			$(FT_CHR_DIR)/ft_isalpha.c				\
			$(FT_CHR_DIR)/ft_isascii.c				\
			$(FT_CHR_DIR)/ft_isdigit.c				\
			$(FT_CHR_DIR)/ft_ishexdigit.c			\
			$(FT_CHR_DIR)/ft_islower.c				\
			$(FT_CHR_DIR)/ft_isoctdigit.c			\
			$(FT_CHR_DIR)/ft_isprint.c				\
			$(FT_CHR_DIR)/ft_isspace.c				\
			$(FT_CHR_DIR)/ft_isupper.c				\
			$(FT_CHR_DIR)/ft_tolower.c				\
			$(FT_CHR_DIR)/ft_toupper.c				\

# TODO: add ft_arr functions:
# ft_arrcat
# ft_arrcmp
# ft_arrdup
# ft_arrfind + find_with
# ft_arrclear

FT_MEM_SRC		=\
			$(FT_MEM_DIR)/ft_allocator/ft_al_arena.c	\
			$(FT_MEM_DIR)/ft_allocator/ft_al_group.c	\
			$(FT_MEM_DIR)/ft_allocator/ft_al_hooks.c	\
			$(FT_MEM_DIR)/ft_allocator/ft_al_memimpl.c	\
			$(FT_MEM_DIR)/ft_arr/ft_arrapply.c			\
			$(FT_MEM_DIR)/ft_arr/ft_arrfree.c			\
			$(FT_MEM_DIR)/ft_arr/ft_arrlen.c			\
			$(FT_MEM_DIR)/ft_bzero.c				\
			$(FT_MEM_DIR)/ft_fd_to_buff.c			\
			$(FT_MEM_DIR)/ft_free_clear.c			\
			$(FT_MEM_DIR)/ft_memchr.c				\
			$(FT_MEM_DIR)/ft_memcmp.c				\
			$(FT_MEM_DIR)/ft_memcpy.c				\
			$(FT_MEM_DIR)/ft_memmap.c				\
			$(FT_MEM_DIR)/ft_memmove.c				\
			$(FT_MEM_DIR)/ft_memset.c				\
			$(FT_MEM_DIR)/ft_qsort.c				\
			$(FT_MEM_DIR)/ft_swap.c

FT_NUM_SRC		=\
			$(FT_NUM_DIR)/ft_atod.c			\
			$(FT_NUM_DIR)/ft_atoi_base.c	\
			$(FT_NUM_DIR)/ft_atoi.c			\
			$(FT_NUM_DIR)/ft_base_valid.c	\
			$(FT_NUM_DIR)/ft_itoa.c			\
			$(FT_NUM_DIR)/ft_stoa_base.c	\
			$(FT_NUM_DIR)/ft_stopa_base.c	\
			$(FT_NUM_DIR)/ft_utoa.c

FT_PUT_SRC		=\
			$(FT_PUT_DIR)/processors/char.c				\
			$(FT_PUT_DIR)/processors/doubles.c			\
			$(FT_PUT_DIR)/processors/extentions.c		\
			$(FT_PUT_DIR)/processors/integers.c			\
			$(FT_PUT_DIR)/processors/integers_conv.c	\
			$(FT_PUT_DIR)/processors/string.c			\
			$(FT_PUT_DIR)/ft_perror.c			\
			$(FT_PUT_DIR)/ft_print_fd.c			\
			$(FT_PUT_DIR)/ft_putdbl_fd.c		\
			$(FT_PUT_DIR)/ft_putendl_fd.c		\
			$(FT_PUT_DIR)/ft_putnbr_base_fd.c	\
			$(FT_PUT_DIR)/ft_putchar_fd.c		\
			$(FT_PUT_DIR)/ft_putnchar_fd.c		\
			$(FT_PUT_DIR)/ft_putnbr_fd.c		\
			$(FT_PUT_DIR)/ft_putstr_fd.c

FT_STR_SRC		=\
			$(FT_STR_DIR)/ft_stris/ft_sis_alnum.c		\
			$(FT_STR_DIR)/ft_stris/ft_sis_alpha.c		\
			$(FT_STR_DIR)/ft_stris/ft_sis_bool.c		\
			$(FT_STR_DIR)/ft_stris/ft_sis_digit.c		\
			$(FT_STR_DIR)/ft_stris/ft_sis_double.c		\
			$(FT_STR_DIR)/ft_stris/ft_sis_float.c		\
			$(FT_STR_DIR)/ft_stris/ft_sis_hex.c			\
			$(FT_STR_DIR)/ft_stris/ft_sis_int.c			\
			$(FT_STR_DIR)/ft_stris/ft_sis_long.c		\
			$(FT_STR_DIR)/ft_stris/ft_sis_num.c			\
			$(FT_STR_DIR)/ft_stris/ft_sis_oct.c			\
			$(FT_STR_DIR)/ft_stris/ft_sis_valid.c		\
			$(FT_STR_DIR)/ft_gnl.c					\
			$(FT_STR_DIR)/ft_split.c			\
			$(FT_STR_DIR)/ft_splits.c			\
			$(FT_STR_DIR)/ft_strappend_c.c		\
			$(FT_STR_DIR)/ft_strchr.c			\
			$(FT_STR_DIR)/ft_strclen.c			\
			$(FT_STR_DIR)/ft_strcmp.c			\
			$(FT_STR_DIR)/ft_strcnb.c			\
			$(FT_STR_DIR)/ft_strcspn.c			\
			$(FT_STR_DIR)/ft_strdup.c			\
			$(FT_STR_DIR)/ft_strend_with.c		\
			$(FT_STR_DIR)/ft_strerror.c			\
			$(FT_STR_DIR)/ft_striteri.c			\
			$(FT_STR_DIR)/ft_strjoin.c			\
			$(FT_STR_DIR)/ft_strlcat.c			\
			$(FT_STR_DIR)/ft_strlcpy.c			\
			$(FT_STR_DIR)/ft_strlen.c			\
			$(FT_STR_DIR)/ft_strmapi.c			\
			$(FT_STR_DIR)/ft_strncmp.c			\
			$(FT_STR_DIR)/ft_strndup.c			\
			$(FT_STR_DIR)/ft_strnlen.c			\
			$(FT_STR_DIR)/ft_strnstr.c			\
			$(FT_STR_DIR)/ft_strrchr.c			\
			$(FT_STR_DIR)/ft_str_replace.c		\
			$(FT_STR_DIR)/ft_strrev.c			\
			$(FT_STR_DIR)/ft_strspn.c			\
			$(FT_STR_DIR)/ft_strstart_with.c	\
			$(FT_STR_DIR)/ft_strtok.c			\
			$(FT_STR_DIR)/ft_strtrim.c			\
			$(FT_STR_DIR)/ft_substr.c			\

FT_T_STRING_SRC	=\
			$(FT_T_STRING_DIR)/ft_string_append.c	\
			$(FT_T_STRING_DIR)/ft_string_chr.c		\
			$(FT_T_STRING_DIR)/ft_string_clear.c	\
			$(FT_T_STRING_DIR)/ft_string_cmp.c		\
			$(FT_T_STRING_DIR)/ft_string_destroy.c	\
			$(FT_T_STRING_DIR)/ft_string_from.c		\
			$(FT_T_STRING_DIR)/ft_string_get.c		\
			$(FT_T_STRING_DIR)/ft_string_insert.c	\
			$(FT_T_STRING_DIR)/ft_string_new.c		\
			$(FT_T_STRING_DIR)/ft_string_put.c		\
			$(FT_T_STRING_DIR)/ft_string_replace.c	\
			$(FT_T_STRING_DIR)/ft_string_reserve.c	\
			$(FT_T_STRING_DIR)/ft_string_resize.c	\
			$(FT_T_STRING_DIR)/ft_string_set.c		\
			$(FT_T_STRING_DIR)/ft_string_shrink.c	\
			$(FT_T_STRING_DIR)/ft_string_substr.c	\
			$(FT_T_STRING_DIR)/ft_string_to_str.c	\
			$(FT_T_STRING_DIR)/ft_string_trim.c		\

# Counpound sources

FT_LIST_SRC		=	\
			$(FT_LIST_LL_SRC)	\
			$(FT_LIST_DL_SRC)	\
			$(FT_LIST_CL_SRC)	\

FT_STRING_SRC	=	\
			$(FT_CHR_SRC)		\
			$(FT_MEM_SRC)		\
			$(FT_NUM_SRC)		\
			$(FT_PUT_SRC)		\
			$(FT_STR_SRC)		\
			$(FT_T_STRING_SRC)

# Tests sources

QTEST_SRC	=\
			$(TESTS_DIR)/quick_main_test.c

TESTS_SRC	=\
			$(TESTS_DIR)/ft_args/args_tests.c					\
			$(TESTS_DIR)/ft_args/tests__ac_av_ev.c				\
			$(TESTS_DIR)/ft_args/tests__progname.c				\
			$(TESTS_DIR)/ft_args/tests__version.c				\
			$(TESTS_DIR)/ft_args/tests_custom_checker.c			\
			$(TESTS_DIR)/ft_args/tests_optlist.c				\
			$(TESTS_DIR)/ft_args/tests_setup_prog.c				\
			\
			$(TESTS_DIR)/ft_list/ll_tests/ll_tests_utils.c			\
			$(TESTS_DIR)/ft_list/ll_tests/ll_list_tests.c			\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_push.c			\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_new.c			\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_map.c			\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_rev.c			\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_sizers.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_apply.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_iterators.c	\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_clear.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_check.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_copy.c			\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_create.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_deletors.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_find.c			\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_get.c			\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_subrange.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_add.c			\
			$(TESTS_DIR)/ft_list/dl_tests/dl_tests_utils.c			\
			$(TESTS_DIR)/ft_list/dl_tests/dl_list_tests.c			\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_add.c			\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_clear.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_check.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_copy.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_create.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_delete.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_iterators.c	\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_get.c			\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_subrange.c	\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_map.c			\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_new.c			\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_push.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_rev.c			\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_sizers.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_apply.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_find.c		\
			$(TESTS_DIR)/ft_list/cl_tests/cl_list_tests.c			\
			$(TESTS_DIR)/ft_list/cl_tests/tests_clist_add.c			\
			$(TESTS_DIR)/ft_list/cl_tests/tests_clist_apply.c		\
			\
			$(TESTS_DIR)/ft_map/map_tests.c						\
			$(TESTS_DIR)/ft_map/tests_map_remove.c				\
			$(TESTS_DIR)/ft_map/tests_map_hash.c				\
			$(TESTS_DIR)/ft_map/tests_map_create.c				\
			$(TESTS_DIR)/ft_map/tests_map_destroy.c				\
			$(TESTS_DIR)/ft_map/tests_map_set_cmphash.c			\
			$(TESTS_DIR)/ft_map/tests_map_get.c					\
			$(TESTS_DIR)/ft_map/tests_map_size.c				\
			$(TESTS_DIR)/ft_map/tests_map_cappacity.c			\
			$(TESTS_DIR)/ft_map/tests_map_clear.c				\
			$(TESTS_DIR)/ft_map/tests_map_set.c					\
			\
			$(TESTS_DIR)/ft_math/tests_abs.c					\
			$(TESTS_DIR)/ft_math/tests_align.c					\
			$(TESTS_DIR)/ft_math/tests_clamp.c					\
			$(TESTS_DIR)/ft_math/tests_complex.c				\
			$(TESTS_DIR)/ft_math/tests_intrange.c				\
			$(TESTS_DIR)/ft_math/tests_log.c					\
			$(TESTS_DIR)/ft_math/tests_minmax.c					\
			$(TESTS_DIR)/ft_math/tests_nbrlen.c					\
			$(TESTS_DIR)/ft_math/tests_pow.c					\
			$(TESTS_DIR)/ft_math/tests_sqrt.c					\
			$(TESTS_DIR)/ft_math/tests_round.c					\
			$(TESTS_DIR)/ft_math/math_tests.c					\
			\
			$(TESTS_DIR)/ft_optional/tests_optional_chain.c		\
			$(TESTS_DIR)/ft_optional/tests_optional_copy.c		\
			$(TESTS_DIR)/ft_optional/tests_optional_destroy.c	\
			$(TESTS_DIR)/ft_optional/tests_optional_dup.c		\
			$(TESTS_DIR)/ft_optional/tests_optional_from_val.c	\
			$(TESTS_DIR)/ft_optional/tests_optional_map.c		\
			$(TESTS_DIR)/ft_optional/tests_optional_new.c		\
			$(TESTS_DIR)/ft_optional/tests_optional_unwrap.c	\
			$(TESTS_DIR)/ft_optional/optional_tests.c			\
			\
			$(TESTS_DIR)/ft_pair/tests_pair_cmp.c				\
			$(TESTS_DIR)/ft_pair/tests_pair_cmp_first.c			\
			$(TESTS_DIR)/ft_pair/tests_pair_cmp_second.c		\
			$(TESTS_DIR)/ft_pair/tests_pair_destroy.c			\
			$(TESTS_DIR)/ft_pair/tests_pair_get_first.c			\
			$(TESTS_DIR)/ft_pair/tests_pair_get_second.c		\
			$(TESTS_DIR)/ft_pair/tests_pair_new.c				\
			$(TESTS_DIR)/ft_pair/tests_pair_set.c				\
			$(TESTS_DIR)/ft_pair/pair_tests.c					\
			\
			$(TESTS_DIR)/ft_string/ft_char/tests_isalnum.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_isalpha.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_isascii.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_isdigit.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_ishexdigit.c	\
			$(TESTS_DIR)/ft_string/ft_char/tests_isoctdigit.c	\
			$(TESTS_DIR)/ft_string/ft_char/tests_isspace.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_isprint.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_putchar.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_putnchar.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_tolower.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_toupper.c		\
			$(TESTS_DIR)/ft_string/ft_char/char_tests.c			\
			\
			$(TESTS_DIR)/ft_string/ft_mem/tests_apply_2d.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_bzero.c					\
			$(TESTS_DIR)/ft_string/ft_mem/tests_calloc.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_fd_to_buff.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tests_free.c					\
			$(TESTS_DIR)/ft_string/ft_mem/tests_free_2d.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_freecl.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_len_2d.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_membd_allocator.c		\
			$(TESTS_DIR)/ft_string/ft_mem/tests_membd_calloc.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tests_membd_free.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tests_membd_malloc.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tests_membd_realloc.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tests_membd_reallocarray.c	\
			$(TESTS_DIR)/ft_string/ft_mem/tests_memchr.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_memcmp.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_memcpy.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_memmap.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_memmove.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_memset.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_qsort.c					\
			$(TESTS_DIR)/ft_string/ft_mem/tests_realloc.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tests_swap.c					\
			$(TESTS_DIR)/ft_string/ft_mem/mem_tests.c					\
			\
			$(TESTS_DIR)/ft_string/ft_str/test_atoi_base.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_atol_base.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_atoi.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_atol.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_atoll.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_atod.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_gnl.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_itoa_base.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_itoa.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_putendl.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_putnbr.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_putstr.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_perror.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_split.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_splits.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_str_isalpha.c		\
			$(TESTS_DIR)/ft_string/ft_str/test_str_isalnum.c		\
			$(TESTS_DIR)/ft_string/ft_str/test_str_isdouble.c		\
			$(TESTS_DIR)/ft_string/ft_str/test_str_isdigit.c		\
			$(TESTS_DIR)/ft_string/ft_str/test_str_isbool.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_str_isfloat.c		\
			$(TESTS_DIR)/ft_string/ft_str/test_str_ishex.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_str_isint.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_str_islong.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_str_isnum.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_str_isoct.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_str_isvalid.c		\
			$(TESTS_DIR)/ft_string/ft_str/test_strchr.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_strclen.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_strcmp.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_strcnb.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_strcspn.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_strdup.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_strend_with.c		\
			$(TESTS_DIR)/ft_string/ft_str/test_striteri.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_strjoin.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_strlcat.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_strlcpy.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_strlen.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_strmapi.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_strncmp.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_strndup.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_strnstr.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_strrchr.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_strrev.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_strspn.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_strstart_with.c		\
			$(TESTS_DIR)/ft_string/ft_str/test_str_replace.c		\
			$(TESTS_DIR)/ft_string/ft_str/test_str_replace_chr.c	\
			$(TESTS_DIR)/ft_string/ft_str/test_strappend_c.c		\
			$(TESTS_DIR)/ft_string/ft_str/test_strtok.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_strtrim.c			\
			$(TESTS_DIR)/ft_string/ft_str/test_substr.c				\
			$(TESTS_DIR)/ft_string/ft_str/test_utoa.c				\
			$(TESTS_DIR)/ft_string/ft_str/str_tests.c				\
			$(TESTS_DIR)/ft_string/string_tests.c					\
			\
			$(TESTS_DIR)/ft_string/ft_string/test_append.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_append_c.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_append_n.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_append_s.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_append_sn.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_cap.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_chr.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_clear.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_cmp.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_cmp_str.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_destroy.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_from.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_from_c.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_from_n.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_from_s.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_from_sn.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_get.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_insert.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_insert_c.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_insert_n.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_insert_s.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_insert_sn.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_len.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_ncmp.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_ncmp_str.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_new.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_offset.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_put.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_rchr.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_replace.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_replace_chr.c	\
			$(TESTS_DIR)/ft_string/ft_string/test_reserve.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_resize.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_roffset.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_set.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_set_inplace.c	\
			$(TESTS_DIR)/ft_string/ft_string/test_set_n.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_shrink.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_substr.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_to_str.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_trim.c			\
			$(TESTS_DIR)/ft_string/ft_string/test_trim_chr.c		\
			$(TESTS_DIR)/ft_string/ft_string/test_trimstr.c		\
			$(TESTS_DIR)/ft_string/ft_string/t_string_tests.c				\
			\
			$(TESTS_DIR)/ft_vector/tests_vec_add.c							\
			$(TESTS_DIR)/ft_vector/tests_vec_apply.c						\
			$(TESTS_DIR)/ft_vector/tests_vec_at.c							\
			$(TESTS_DIR)/ft_vector/tests_vec_cat.c							\
			$(TESTS_DIR)/ft_vector/tests_vec_clear.c						\
			$(TESTS_DIR)/ft_vector/tests_vec_convert_alloc_array.c			\
			$(TESTS_DIR)/ft_vector/tests_vec_destroy.c						\
			$(TESTS_DIR)/ft_vector/tests_vec_filter.c						\
			$(TESTS_DIR)/ft_vector/tests_vec_from_array.c					\
			$(TESTS_DIR)/ft_vector/tests_vec_from_size.c					\
			$(TESTS_DIR)/ft_vector/tests_vec_get.c							\
			$(TESTS_DIR)/ft_vector/tests_vec_map.c							\
			$(TESTS_DIR)/ft_vector/tests_vec_new.c							\
			$(TESTS_DIR)/ft_vector/tests_vec_pop.c							\
			$(TESTS_DIR)/ft_vector/tests_vec_remove.c						\
			$(TESTS_DIR)/ft_vector/tests_vec_remove_if.c					\
			$(TESTS_DIR)/ft_vector/tests_vec_reserve.c						\
			$(TESTS_DIR)/ft_vector/tests_vec_reverse.c						\
			$(TESTS_DIR)/ft_vector/tests_vec_shift.c						\
			$(TESTS_DIR)/ft_vector/tests_vec_shrink.c						\
			$(TESTS_DIR)/ft_vector/tests_vec_sort.c							\
			$(TESTS_DIR)/ft_vector/tests_vec_swap.c							\
			$(TESTS_DIR)/ft_vector/tests_vec_to_array.c						\
			$(TESTS_DIR)/ft_vector/vector_tests.c							\
			\
			$(TESTS_DIR)/tests_fixtures/talloc_failpoint.c					\
			$(TESTS_DIR)/tests_fixtures/talloc_group.c						\
			$(TESTS_DIR)/tests_fixtures/talloc_testimpl.c					\
			\
			$(TESTS_DIR)/main_tests.c		\
			$(TESTS_DIR)/lambdas_add.c		\
			$(TESTS_DIR)/lambdas_general.c	\
			$(TESTS_DIR)/tests_utils.c

SRCS	=\
		$(FT_MATH_SRC)          \
		$(FT_LIST_SRC)          \
		$(FT_VEC_SRC)           \
		$(FT_STRING_SRC)        \
		$(FT_MAP_SRC)           \
		$(FT_OPTIONAL_SRC)      \
		$(FT_ARGS_SRC)          \
		$(FT_PAIR_SRC)          \

# Objects creation
#   add prefix to sources to specify the directory src/
SRCS		:=	$(sort $(SRCS))

#OBJ - objects for the library
#   add prefix to sources to specify the directory build/ for objects
OBJ			=	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/,$(SRCS)))
#TOBJ - objects for unit tests
#   add prefix to sources to specify the directory build/tests/ for test objects
TOBJ		=\
			$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/$(TESTS_DIR)/,$(SRCS)))	\
			$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/$(TESTS_DIR)/,$(TESTS_SRC)))
#QOBJ - objects for quick tests
#   add prefix to sources to specify the directory build/tests/ for quick test objects
QTEST_OBJ	=	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/$(TESTS_DIR)/,$(QTEST_SRC)))

#  Inner variables for rules

# Get the max length of the sources names to align the output
SRC_MAX_FILE_LEN	=\
	$(shell $(PRINTF) "%s\n" $(SRCS) | \
	awk '{print length}' | sort -n | tail -1)

TEST_MAX_FILE_LEN	=\
	$(shell $(PRINTF) "%s\n" $(TESTS_SRC) | \
	awk '{print length}' | sort -n | tail -1)

# Rules
# Default rule for 'normal' objects
$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(PRINTF) "$(BG_INFO)building from $(YELLOW)%-*s$(RESET) ..."	\
	$(SRC_MAX_FILE_LEN) $< 											&& \
	mkdir -p $(dir $@)												&& \
	$(CC) $(CFLAGS) -c $< -o $@ 2>> $(CLOG_FILE) 					&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"						|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(LOG_INFO)\tSee:%s$(RESET)\n"	\
	$(CLOG_FILE)

# Rule for tests objects
$(BUILD_DIR)/$(TESTS_DIR)/%.o: %.c
	@$(PRINTF) "$(BG_INFO)building from $(YELLOW)%-*s$(RESET) ..."	\
	$(TEST_MAX_FILE_LEN) $<											&& \
	mkdir -p $(dir $@)												&& \
	$(CC) $(CFLAGS) $(TEST_FLAGS) -c $< -o $@						\
	2>>	$(CLOG_FILE) 												&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"						|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(LOG_INFO)\tSee:%s$(RESET)\n"	\
	$(CLOG_FILE)

.DEFAULT_GOAL	:= lib$(NAME).a
.PRECIOUS		: $(TEST_NAME)
-include		$(OBJ:.o=.d)

so: lib$(NAME).so

# Rule for shared library
lib$(NAME).so:	$(OBJ)
	@$(PRINTF) "$(BG_INFO)Making ... $(LOG_INFO)%s$(BG_INFO) ... $(RESET)"	\
	"lib$(NAME).so"															&& \
	$(CC) -shared -o lib$(NAME).so $(OBJ) 2> $(CLOG_FILE)					&& \
	$(RM) -- $(CLOG_FILE)													&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"								|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(LOG_INFO)\tSee:%s$(RESET)\n"			\
	$(CLOG_FILE)

# Rule for static library
lib$(NAME).a:	$(OBJ)
	@$(PRINTF) "$(BG_INFO)Making ... $(LOG_INFO)%s$(BG_INFO) ... $(RESET)"	\
	"lib$(NAME).a"															&& \
	$(AR) -rcs lib$(NAME).a $(OBJ) 2>> $(CLOG_FILE)							&& \
	$(RM) -- $(CLOG_FILE)													&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"								|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(LOG_INFO)\tSee:%s$(RESET)\n"			\
	$(CLOG_FILE)

$(QTEST_NAME): lib$(NAME).a	$(QTEST_OBJ)
	@$(PRINTF) "$(BG_INFO)Compiling quick tests $(LOG_INFO)%-*s ...$(RESET)"	\
	$(TEST_MAX_FILE_LEN) $(QTEST_NAME)											&& \
	$(CC) $(CFLAGS) $(OBJ) $(QTEST_OBJ) -o $(QTEST_NAME) -L.	 				\
	-l$(NAME) -lm $(LDFLAGS) 2>> $(CLOG_FILE)									&& \
	$(RM) -- $(CLOG_FILE)														&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"									|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(LOG_INFO)\tSee:%s$(RESET)\n"				\
	$(CLOG_FILE)

# Rule to compile and run tests
$(TEST_NAME): $(TOBJ)
	@$(RM) -f $(TEST_NAME)
	@$(PRINTF) "$(GRAY)Compiling tests %-*s... $(RESET)"			\
	$(TEST_MAX_FILE_LEN) $(TEST_NAME)								&& \
	$(CC) $(CFLAGS) $(TOBJ) -o $(TEST_NAME) $(TEST_FLAGS)			\
	$(LDFLAGS) -lgcov 2>> $(CLOG_FILE)								&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"						|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(LOG_INFO)\tSee:%s$(RESET)\n"	\
	$(CLOG_FILE)
	@$(PRINTF) "$(GRAY)Running tests ... $(RESET)"					&& \
	./$(TEST_NAME) 													&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"						|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(RESET)\n"

# Rule to generate coverage using llvm
$(COVERAGE_DIR): $(TEST_NAME)
	@$(PRINTF) "$(BG_INFO)Generating coverage ... $(RESET)"		&& \
	$(PRINTF) "$(BG_INFO)profraw ... $(RESET)"					&& \
	./$(TEST_NAME)												&& \
	$(PRINTF) "$(BG_INFO)profdata ... $(RESET)"					&& \
	$(PRD) merge -sparse default.profraw -o 					\
	$(TEST_NAME).profdata										&& \
	$(PRINTF) "$(BG_INFO)coverage to html ... $(RESET)"			&& \
	$(COV) show -format=html									\
	-instr-profile=$(TEST_NAME).profdata						\
	-ignore-filename-regex=$(TESTS_DIR)/*						\
	--show-branches=count	--show-directory-coverage			\
	./$(TEST_NAME) -output-dir=$(COVERAGE_DIR)					&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"					|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(RESET)\n"

.clangd: Makefile
	@$(PRINTF) "$(BG_INFO)Making clangd configuration file$(RESET) "	&&\
	$(ECHO) -n														\
	"CompileFlags:\n"												\
	"  Compiler: clang\n"											\
	"  Add:\n"														\
	"   - \"-Wall -Wextra -Werror\"\n"								\
	"   - \""$(WFLAGS)"\"\n"										\
	"   - \"-xc\"\n"  > .clangd										&& \
	for file in $(INC_DIR); do										\
		echo "    - \"-I"$(shell pwd)"/"$$file"\"" >> .clangd;		\
	done															&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"						|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(RESET)\n"

tags: Makefile $(SRCS)
	ctags	-Ra

compile_commands.json: Makefile $(SRCS)
	bear	-- make
	bear	--append -- make tests_run

# Rule to clean objects
clean:
	@$(PRINTF) "$(BG_INFO)Cleaning ... $(RESET)"				&& \
	$(RM) -rf $(BUILD_DIR) $(CLOG_FILE)							\
	*.gcov *.gcno *.gcda callgrind.out.* *.profraw *.profdata 	\
	2> /dev/null 												&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"					|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(RESET)\n"

# Rule to clean objects and libraries/compiled files
fclean: clean
	@$(PRINTF) "$(BG_INFO)FCleaning ... $(RESET)"				&& \
	$(RM) -rf lib$(NAME).a lib$(NAME).so $(COVERAGE_DIR)		\
	$(TEST_NAME) $(QTEST_NAME) 2> /dev/null 					&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"					|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(RESET)\n"

uclean:
	@$(PRINTF) "$(BG_INFO)Cleaning development environment ... $(RESET)"	&& \
	$(RM) -rf .clangd compile_commands.json tags $(CLOG_FILE)		\
	2> /dev/null 													&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"					|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(RESET)\n"

# Rule to recompile
re:	fclean
	@$(PRINTF) "$(BG_INFO)Recompiling ... $(RESET)"				&& \
	make --no-print-directory									&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"					|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(RESET)\n"

dev_env: .clangd compile_commands.json tags
	@$(PRINTF) "$(BG_INFO)Development environment is ready!$(RESET)\n"	&& \
	$(PRINTF) "$(BG_INFO)You can use 'make dev_env' to update it!$(RESET)\n"

# rule to force rules to be executed even if files exist
.PHONY: re fclean clean
