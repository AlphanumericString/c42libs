# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 09:04:05 by bgoulard          #+#    #+#              #
#    Updated: 2025/06/21 22:01:03 by bgoulard         ###   ########.fr        #
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
TEST_NAME	=	tests
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
TESTS_DIR		=	tests_src
INC_DIR			=	include includes .
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

# vars
FT_COMPILE_TIME_HASH	:= $(shell date +%Y%m%d%H%M%S | shasum -a 256 | awk '{print $1}')
FT_VERSION				:= $(shell git describe --tags --dirty 2> /dev/null || echo "0.0.0")

# flags
WFLAGS		= -Wall -Wextra -Werror -Wmissing-prototypes
LDFLAGS		= -L./testing_lib -lsimple_tests
STDFLAGS	= -std=c99

VAR_FLAGS	=\
			-DFT_COMPILE_TIME_HASH="$(FT_COMPILE_TIME_HASH)"	\
			-DFT_VERSION="$(FT_VERSION)"						\

# ifndef VERBOSE

CPPFLAGS	=\
			$(addprefix -I, $(INC_DIR)) -MMD -MP

FFLAGS		=\
			-fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined	   \
			-fsanitize=leak -fsanitize=pointer-compare 						   \
			-fsanitize=pointer-subtract										   \
			-fsanitize-address-use-after-scope -fsanitize=pointer-overflow

CFLAGS		=\
			$(WFLAGS) $(CPPFLAGS) -fPIC -fdiagnostics-color					\
			-fno-inline -fno-inline-functions ${STDFLAGS}					\
			$(VAR_FLAGS)

TEST_FLAGS	=\
			-fprofile-instr-generate -ftest-coverage -fcoverage-mapping		\
			-fno-inline -fno-inline-functions -O0	-DTEST					\
			-DFORK_TESTS=1													\

#-DVERBOSE=1


DEBUG_LEVEL	?=\
		0
# do not optimize tests
DEBUG_FLAGS	=\
		-g2	-DDEBUG	-DDEBUG_LEVEL=$(DEBUG_LEVEL)	\
		-fno-inline -fno-inline-functions

ifeq ($(DEBUG_LEVEL), 0)
	CFLAGS := $(CFLAGS)
else
	CFLAGS := $(CFLAGS) $(DEBUG_FLAGS) -DTEST
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

FT_MEM_SRC		=\
			$(FT_MEM_DIR)/ft_allocator/ft_al_arena.c	\
			$(FT_MEM_DIR)/ft_allocator/ft_al_group.c	\
			$(FT_MEM_DIR)/ft_allocator/ft_al_hooks.c	\
			$(FT_MEM_DIR)/ft_allocator/ft_al_memimpl.c	\
			$(FT_MEM_DIR)/ft_arena/ft_arena.c		\
			$(FT_MEM_DIR)/ft_arena/ft_narena.c		\
			$(FT_MEM_DIR)/ft_arena/ft_narena_utils.c	\
			$(FT_MEM_DIR)/ft_arr/ft_aapply.c			\
			$(FT_MEM_DIR)/ft_arr/ft_acat.c			\
			$(FT_MEM_DIR)/ft_arr/ft_aclear.c		\
			$(FT_MEM_DIR)/ft_arr/ft_acmp.c			\
			$(FT_MEM_DIR)/ft_arr/ft_acpy.c			\
			$(FT_MEM_DIR)/ft_arr/ft_adup.c			\
			$(FT_MEM_DIR)/ft_arr/ft_afind.c			\
			$(FT_MEM_DIR)/ft_arr/ft_afree.c			\
			$(FT_MEM_DIR)/ft_arr/ft_alen.c			\
			$(FT_MEM_DIR)/ft_arr/ft_amap.c			\
			$(FT_MEM_DIR)/ft_arr/ft_arev.c			\
			$(FT_MEM_DIR)/ft_arr/ft_arfind.c		\
			$(FT_MEM_DIR)/ft_arr/ft_atr.c			\
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
			$(FT_PUT_DIR)/processors/meta.c				\
			$(FT_PUT_DIR)/ft_perror.c			\
			$(FT_PUT_DIR)/ft_print.c			\
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
			$(FT_STR_DIR)/ft_stris/ft_sis_fname.c		\
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
			$(TESTS_DIR)/ft_args/args_tests.c								\
			$(TESTS_DIR)/ft_args/ft_parse_args/targ_parse.c					\
			$(TESTS_DIR)/ft_args/ft_parse_args/targp_usrt_bindings_utils1.c	\
			$(TESTS_DIR)/ft_args/ft_parse_args/targp_usrt_bindings_utils2.c	\
			$(TESTS_DIR)/ft_args/ft_set/targ__ac_av_ev.c					\
			$(TESTS_DIR)/ft_args/ft_set/targ__progname.c					\
			$(TESTS_DIR)/ft_args/ft_set/targ__version.c						\
			$(TESTS_DIR)/ft_args/targ_consume_args.c						\
			$(TESTS_DIR)/ft_args/targ_custom_checker.c						\
			$(TESTS_DIR)/ft_args/targ_get_envp.c							\
			$(TESTS_DIR)/ft_args/targ_optlist.c								\
			$(TESTS_DIR)/ft_args/targ_setup_prog.c							\
			$(TESTS_DIR)/ft_args/targ_shift_args.c							\
			\
			$(TESTS_DIR)/ft_bitset/bitset_tests.c		\
			$(TESTS_DIR)/ft_bitset/tb_append.c			\
			$(TESTS_DIR)/ft_bitset/tb_clear.c			\
			$(TESTS_DIR)/ft_bitset/tb_create.c			\
			$(TESTS_DIR)/ft_bitset/tb_free.c			\
			$(TESTS_DIR)/ft_bitset/tb_free_inner.c		\
			$(TESTS_DIR)/ft_bitset/tb_get.c				\
			$(TESTS_DIR)/ft_bitset/tb_get_raw.c			\
			$(TESTS_DIR)/ft_bitset/tb_new.c				\
			$(TESTS_DIR)/ft_bitset/tb_new_from_mem.c	\
			$(TESTS_DIR)/ft_bitset/tb_print.c			\
			$(TESTS_DIR)/ft_bitset/tb_print_binary.c	\
			$(TESTS_DIR)/ft_bitset/tb_print_decimal.c	\
			$(TESTS_DIR)/ft_bitset/tb_print_hex.c		\
			$(TESTS_DIR)/ft_bitset/tb_remove.c			\
			$(TESTS_DIR)/ft_bitset/tb_remove_front.c	\
			$(TESTS_DIR)/ft_bitset/tb_set.c				\
			$(TESTS_DIR)/ft_bitset/tb_set_raw.c			\
			$(TESTS_DIR)/ft_bitset/tb_toggle.c			\
			$(TESTS_DIR)/ft_bitset/tb_toggle_raw.c		\
			\
			$(TESTS_DIR)/ft_list/clt/cl_list_tests.c	\
			$(TESTS_DIR)/ft_list/clt/cl_tests_utils.c	\
			$(TESTS_DIR)/ft_list/clt/tcl_add.c			\
			$(TESTS_DIR)/ft_list/clt/tcl_apply.c		\
			$(TESTS_DIR)/ft_list/clt/tcl_check.c		\
			$(TESTS_DIR)/ft_list/clt/tcl_clear.c		\
			$(TESTS_DIR)/ft_list/clt/tcl_copy.c			\
			$(TESTS_DIR)/ft_list/clt/tcl_create.c		\
			$(TESTS_DIR)/ft_list/clt/tcl_delete.c		\
			$(TESTS_DIR)/ft_list/clt/tcl_find.c			\
			$(TESTS_DIR)/ft_list/clt/tcl_get.c			\
			$(TESTS_DIR)/ft_list/clt/tcl_iterators.c	\
			$(TESTS_DIR)/ft_list/clt/tcl_map.c			\
			$(TESTS_DIR)/ft_list/clt/tcl_new.c			\
			$(TESTS_DIR)/ft_list/clt/tcl_pop.c			\
			$(TESTS_DIR)/ft_list/clt/tcl_push.c			\
			$(TESTS_DIR)/ft_list/clt/tcl_rev.c			\
			$(TESTS_DIR)/ft_list/clt/tcl_sizers.c		\
			$(TESTS_DIR)/ft_list/clt/tcl_subrange.c		\
			\
			$(TESTS_DIR)/ft_list/dlt/dl_list_tests.c	\
			$(TESTS_DIR)/ft_list/dlt/dl_tests_utils.c	\
			$(TESTS_DIR)/ft_list/dlt/tdl_add.c			\
			$(TESTS_DIR)/ft_list/dlt/tdl_apply.c		\
			$(TESTS_DIR)/ft_list/dlt/tdl_check.c		\
			$(TESTS_DIR)/ft_list/dlt/tdl_clear.c		\
			$(TESTS_DIR)/ft_list/dlt/tdl_copy.c			\
			$(TESTS_DIR)/ft_list/dlt/tdl_create.c		\
			$(TESTS_DIR)/ft_list/dlt/tdl_delete.c		\
			$(TESTS_DIR)/ft_list/dlt/tdl_find.c			\
			$(TESTS_DIR)/ft_list/dlt/tdl_get.c			\
			$(TESTS_DIR)/ft_list/dlt/tdl_iterators.c	\
			$(TESTS_DIR)/ft_list/dlt/tdl_map.c			\
			$(TESTS_DIR)/ft_list/dlt/tdl_new.c			\
			$(TESTS_DIR)/ft_list/dlt/tdl_push.c			\
			$(TESTS_DIR)/ft_list/dlt/tdl_rev.c			\
			$(TESTS_DIR)/ft_list/dlt/tdl_sizers.c		\
			$(TESTS_DIR)/ft_list/dlt/tdl_subrange.c		\
			\
			$(TESTS_DIR)/ft_list/llt/ll_list_tests.c	\
			$(TESTS_DIR)/ft_list/llt/ll_tests_utils.c	\
			$(TESTS_DIR)/ft_list/llt/tll_add.c			\
			$(TESTS_DIR)/ft_list/llt/tll_apply.c		\
			$(TESTS_DIR)/ft_list/llt/tll_check.c		\
			$(TESTS_DIR)/ft_list/llt/tll_clear.c		\
			$(TESTS_DIR)/ft_list/llt/tll_copy.c			\
			$(TESTS_DIR)/ft_list/llt/tll_create.c		\
			$(TESTS_DIR)/ft_list/llt/tll_deletors.c		\
			$(TESTS_DIR)/ft_list/llt/tll_find.c			\
			$(TESTS_DIR)/ft_list/llt/tll_get.c			\
			$(TESTS_DIR)/ft_list/llt/tll_iterators.c	\
			$(TESTS_DIR)/ft_list/llt/tll_map.c			\
			$(TESTS_DIR)/ft_list/llt/tll_new.c			\
			$(TESTS_DIR)/ft_list/llt/tll_push.c			\
			$(TESTS_DIR)/ft_list/llt/tll_rev.c			\
			$(TESTS_DIR)/ft_list/llt/tll_sizers.c		\
			$(TESTS_DIR)/ft_list/llt/tll_subrange.c		\
			$(TESTS_DIR)/ft_list/lists_tests.c			\
			\
			$(TESTS_DIR)/ft_map/map_tests.c			\
			$(TESTS_DIR)/ft_map/tmap_cappacity.c	\
			$(TESTS_DIR)/ft_map/tmap_clear.c		\
			$(TESTS_DIR)/ft_map/tmap_create.c		\
			$(TESTS_DIR)/ft_map/tmap_destroy.c		\
			$(TESTS_DIR)/ft_map/tmap_get.c			\
			$(TESTS_DIR)/ft_map/tmap_hash.c			\
			$(TESTS_DIR)/ft_map/tmap_remove.c		\
			$(TESTS_DIR)/ft_map/tmap_set.c			\
			$(TESTS_DIR)/ft_map/tmap_set_cmphash.c	\
			$(TESTS_DIR)/ft_map/tmap_size.c			\
			\
			$(TESTS_DIR)/ft_math/math_tests.c		\
			$(TESTS_DIR)/ft_math/tm_abs.c			\
			$(TESTS_DIR)/ft_math/tm_align.c			\
			$(TESTS_DIR)/ft_math/tm_clamp.c			\
			$(TESTS_DIR)/ft_math/tm_complex.c		\
			$(TESTS_DIR)/ft_math/tm_intrange.c		\
			$(TESTS_DIR)/ft_math/tm_log.c			\
			$(TESTS_DIR)/ft_math/tm_minmax.c		\
			$(TESTS_DIR)/ft_math/tm_nbrlen.c		\
			$(TESTS_DIR)/ft_math/tm_pow.c			\
			$(TESTS_DIR)/ft_math/tm_round.c			\
			$(TESTS_DIR)/ft_math/tm_sqrt.c			\
			\
			$(TESTS_DIR)/ft_optional/optional_tests.c	\
			$(TESTS_DIR)/ft_optional/to_chain.c			\
			$(TESTS_DIR)/ft_optional/to_copy.c			\
			$(TESTS_DIR)/ft_optional/to_destroy.c		\
			$(TESTS_DIR)/ft_optional/to_dup.c			\
			$(TESTS_DIR)/ft_optional/to_from_val.c		\
			$(TESTS_DIR)/ft_optional/to_map.c			\
			$(TESTS_DIR)/ft_optional/to_new.c			\
			$(TESTS_DIR)/ft_optional/to_unwrap.c		\
			\
			$(TESTS_DIR)/ft_pair/pair_tests.c			\
			$(TESTS_DIR)/ft_pair/pair_utils.c			\
			$(TESTS_DIR)/ft_pair/tp_cmp.c				\
			$(TESTS_DIR)/ft_pair/tp_cmp_first.c			\
			$(TESTS_DIR)/ft_pair/tp_cmp_second.c		\
			$(TESTS_DIR)/ft_pair/tp_destroy.c			\
			$(TESTS_DIR)/ft_pair/tp_get_first.c			\
			$(TESTS_DIR)/ft_pair/tp_get_second.c		\
			$(TESTS_DIR)/ft_pair/tp_new.c				\
			$(TESTS_DIR)/ft_pair/tp_set.c				\
			\
			$(TESTS_DIR)/ft_string/ft_chr/char_tests.c			\
			$(TESTS_DIR)/ft_string/ft_chr/tc_isalnum.c			\
			$(TESTS_DIR)/ft_string/ft_chr/tc_isalpha.c			\
			$(TESTS_DIR)/ft_string/ft_chr/tc_isascii.c			\
			$(TESTS_DIR)/ft_string/ft_chr/tc_isdigit.c			\
			$(TESTS_DIR)/ft_string/ft_chr/tc_ishexdigit.c		\
			$(TESTS_DIR)/ft_string/ft_chr/tc_isoctdigit.c		\
			$(TESTS_DIR)/ft_string/ft_chr/tc_isprint.c			\
			$(TESTS_DIR)/ft_string/ft_chr/tc_isspace.c			\
			$(TESTS_DIR)/ft_string/ft_chr/tc_tolower.c			\
			$(TESTS_DIR)/ft_string/ft_chr/tc_toupper.c			\
			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_allocator/allocator_tests.c	\
			$(TESTS_DIR)/ft_string/ft_mem/ft_allocator/tmal_allocator.c		\
			$(TESTS_DIR)/ft_string/ft_mem/ft_allocator/tmal_calloc.c		\
			$(TESTS_DIR)/ft_string/ft_mem/ft_allocator/tmal_free.c			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_allocator/tmal_malloc.c		\
			$(TESTS_DIR)/ft_string/ft_mem/ft_allocator/tmal_realloc.c		\
			$(TESTS_DIR)/ft_string/ft_mem/ft_allocator/tmal_reallocarray.c	\
			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arena/arena_tests.c		\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arena/tma_arena.c			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arena/tma_narena_alloc.c	\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arena/tma_narena_calloc.c	\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arena/tma_narena_belong.c	\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arena/tma_narena_free.c	\
			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/arr_tests.c		\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_aapply.c		\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_acat.c			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_aclear.c		\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_acmp.c			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_acpy.c			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_adup.c			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_afind.c		\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_afree.c		\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_alen.c			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_amap.c			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_arev.c			\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_arfind.c		\
			$(TESTS_DIR)/ft_string/ft_mem/ft_arr/tca_atr.c			\
			\
			$(TESTS_DIR)/ft_string/ft_mem/mem_tests.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_bzero.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_calloc.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_fd_to_buff.c		\
			$(TESTS_DIR)/ft_string/ft_mem/tm_free.c				\
			$(TESTS_DIR)/ft_string/ft_mem/tm_freecl.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_memchr.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_memcmp.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_memcpy.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_memmap.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_memmove.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_memset.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_qsort.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_realloc.c			\
			$(TESTS_DIR)/ft_string/ft_mem/tm_swap.c				\
			\
			$(TESTS_DIR)/ft_string/ft_num/num_tests.c			\
			$(TESTS_DIR)/ft_string/ft_num/tsn_atod.c			\
			$(TESTS_DIR)/ft_string/ft_num/tsn_atoi.c			\
			$(TESTS_DIR)/ft_string/ft_num/tsn_atoi_base.c		\
			$(TESTS_DIR)/ft_string/ft_num/tsn_atol.c			\
			$(TESTS_DIR)/ft_string/ft_num/tsn_atol_base.c		\
			$(TESTS_DIR)/ft_string/ft_num/tsn_atoll.c			\
			$(TESTS_DIR)/ft_string/ft_num/tsn_base_valid.c		\
			$(TESTS_DIR)/ft_string/ft_num/tsn_itoa.c			\
			$(TESTS_DIR)/ft_string/ft_num/tsn_itoa_base.c		\
			$(TESTS_DIR)/ft_string/ft_num/tsn_stoa_base.c		\
			$(TESTS_DIR)/ft_string/ft_num/tsn_stopa_base.c		\
			$(TESTS_DIR)/ft_string/ft_num/tsn_sstoa_base.c		\
			$(TESTS_DIR)/ft_string/ft_num/tsn_sstopa_base.c		\
			$(TESTS_DIR)/ft_string/ft_num/tsn_utoa.c			\
			\
			$(TESTS_DIR)/ft_string/ft_put/put_tests.c			\
			$(TESTS_DIR)/ft_string/ft_put/tsp_perror.c			\
			$(TESTS_DIR)/ft_string/ft_put/tsp_print.c			\
			$(TESTS_DIR)/ft_string/ft_put/tsp_printfd.c			\
			$(TESTS_DIR)/ft_string/ft_put/tsp_putchar.c			\
			$(TESTS_DIR)/ft_string/ft_put/tsp_putdbl_fd.c		\
			$(TESTS_DIR)/ft_string/ft_put/tsp_putnchar.c		\
			$(TESTS_DIR)/ft_string/ft_put/tsp_putendl.c			\
			$(TESTS_DIR)/ft_string/ft_put/tsp_putnbr.c			\
			$(TESTS_DIR)/ft_string/ft_put/tsp_putunbr_base.c	\
			$(TESTS_DIR)/ft_string/ft_put/tsp_putnbr_base.c		\
			$(TESTS_DIR)/ft_string/ft_put/tsp_putstr.c			\
			$(TESTS_DIR)/ft_string/ft_put/tsp_va_printfd.c		\
			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/stris_tests.c		\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_alnum.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_alpha.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_bool.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_digit.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_double.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_float.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_fname.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_hex.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_int.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_long.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_num.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_oct.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_path.c			\
			$(TESTS_DIR)/ft_string/ft_str/ft_stris/tsi_valid.c			\
			\
			$(TESTS_DIR)/ft_string/ft_str/str_tests.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_gnl.c				\
			$(TESTS_DIR)/ft_string/ft_str/ts_split.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_splits.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_str_replace.c		\
			$(TESTS_DIR)/ft_string/ft_str/ts_str_replace_chr.c	\
			$(TESTS_DIR)/ft_string/ft_str/ts_strappend_c.c		\
			$(TESTS_DIR)/ft_string/ft_str/ts_strchr.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strclen.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strcmp.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strcnb.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strcspn.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strdup.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strend_with.c		\
			$(TESTS_DIR)/ft_string/ft_str/ts_striteri.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strjoin.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strlcat.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strlcpy.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strlen.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strmapi.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strncmp.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strndup.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strnstr.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strrchr.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strrev.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strspn.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strstart_with.c	\
			$(TESTS_DIR)/ft_string/ft_str/ts_strtok.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_strtrim.c			\
			$(TESTS_DIR)/ft_string/ft_str/ts_substr.c			\
			\
			$(TESTS_DIR)/ft_string/ft_string/t_string_tests.c		\
			$(TESTS_DIR)/ft_string/ft_string/tts_append.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_append_c.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_append_n.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_append_s.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_append_sn.c		\
			$(TESTS_DIR)/ft_string/ft_string/tts_cap.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_chr.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_clear.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_cmp.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_cmp_str.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_destroy.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_from.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_from_c.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_from_n.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_from_s.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_from_sn.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_get.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_insert.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_insert_c.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_insert_n.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_insert_s.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_insert_sn.c		\
			$(TESTS_DIR)/ft_string/ft_string/tts_len.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_ncmp.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_ncmp_str.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_new.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_offset.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_put.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_rchr.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_replace.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_replace_chr.c		\
			$(TESTS_DIR)/ft_string/ft_string/tts_reserve.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_resize.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_roffset.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_set.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_set_inplace.c		\
			$(TESTS_DIR)/ft_string/ft_string/tts_set_n.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_shrink.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_substr.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_to_str.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_trim.c				\
			$(TESTS_DIR)/ft_string/ft_string/tts_trim_chr.c			\
			$(TESTS_DIR)/ft_string/ft_string/tts_trimstr.c			\
			\
			$(TESTS_DIR)/ft_string/string_tests.c	\
			\
			$(TESTS_DIR)/ft_vector/tv_add.c					\
			$(TESTS_DIR)/ft_vector/tv_apply.c				\
			$(TESTS_DIR)/ft_vector/tv_at.c					\
			$(TESTS_DIR)/ft_vector/tv_cat.c					\
			$(TESTS_DIR)/ft_vector/tv_clear.c				\
			$(TESTS_DIR)/ft_vector/tv_convert_alloc_array.c	\
			$(TESTS_DIR)/ft_vector/tv_destroy.c				\
			$(TESTS_DIR)/ft_vector/tv_filter.c				\
			$(TESTS_DIR)/ft_vector/tv_from_array.c			\
			$(TESTS_DIR)/ft_vector/tv_from_size.c			\
			$(TESTS_DIR)/ft_vector/tv_get.c					\
			$(TESTS_DIR)/ft_vector/tv_map.c					\
			$(TESTS_DIR)/ft_vector/tv_new.c					\
			$(TESTS_DIR)/ft_vector/tv_pop.c					\
			$(TESTS_DIR)/ft_vector/tv_remove.c				\
			$(TESTS_DIR)/ft_vector/tv_remove_if.c			\
			$(TESTS_DIR)/ft_vector/tv_reserve.c				\
			$(TESTS_DIR)/ft_vector/tv_reverse.c				\
			$(TESTS_DIR)/ft_vector/tv_shift.c				\
			$(TESTS_DIR)/ft_vector/tv_shrink.c				\
			$(TESTS_DIR)/ft_vector/tv_sort.c				\
			$(TESTS_DIR)/ft_vector/tv_swap.c				\
			$(TESTS_DIR)/ft_vector/tv_to_array.c			\
			$(TESTS_DIR)/ft_vector/vector_tests.c			\
			\
			$(TESTS_DIR)/tests_fixtures/talloc_failpoint.c		\
			$(TESTS_DIR)/tests_fixtures/talloc_group.c			\
			$(TESTS_DIR)/tests_fixtures/talloc_testimpl.c		\
			$(TESTS_DIR)/tests_fixtures/tests_files_handling.c	\
			$(TESTS_DIR)/tests_utils/lambdas_general.c			\
			$(TESTS_DIR)/tests_utils/lmdb_i_add.c				\
			$(TESTS_DIR)/tests_utils/lmdb_i_cmp.c				\
			$(TESTS_DIR)/tests_utils/lmdb_i_is.c				\
			$(TESTS_DIR)/tests_utils/lmdb_s_cmp.c				\
			$(TESTS_DIR)/tests_utils/tab_create_set.c			\
			$(TESTS_DIR)/main_tests.c

SRCS	=\
		$(FT_FILEHANDLER_SRC)	\
		$(FT_BITSET_SRC)		\
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
-include $(OBJ:.o=.d)
-include $(TOBJ:.o=.d)
-include $(QTEST_OBJ:.o=.d)

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

testing_lib/libsimple_tests.a:
	make -C ./testing_lib/

# Rule to compile and run tests
$(TEST_NAME): $(TOBJ) testing_lib/libsimple_tests.a
	@$(PRINTF) "$(GRAY)Compiling tests %-*s... $(RESET)"			\
	$(TEST_MAX_FILE_LEN) $(TEST_NAME)								&& \
	$(CC) $(CFLAGS) $(TOBJ) -o $(TEST_NAME) $(TEST_FLAGS)			\
	$(LDFLAGS) 2>> $(CLOG_FILE)								&& \
	$(RM) -- $(CLOG_FILE)											&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"						|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(LOG_INFO)\tSee:%s$(RESET)\n"	\
	$(CLOG_FILE)

$(TEST_NAME)_run: $(TEST_NAME)
	@$(PRINTF) "$(GRAY)Running tests ... $(RESET)"					&& \
	./$(TEST_NAME) 													&& \
	$(PRINTF) "$(GOOD_COLOR)Success$(RESET)\n"						|| \
	$(PRINTF) "$(ERROR_COLOR)Failed$(RESET)\n"

# Rule to generate coverage using llvm
$(COVERAGE_DIR): $(TEST_NAME)
	@$(PRINTF) "$(BG_INFO)Generating coverage ... $(RESET)"		&& \
	$(PRINTF) "$(BG_INFO)profraw ... $(RESET)\n"				&& \
	./$(TEST_NAME)												; \
	$(PRINTF) "$(BG_INFO)profdata ... $(RESET)"					&& \
	$(PRD) merge -sparse default.profraw -o 					\
	$(TEST_NAME).profdata										&& \
	$(PRINTF) "$(BG_INFO)coverage to html ... $(RESET)"			&& \
	$(COV) show -format=html									\
	-instr-profile=$(TEST_NAME).profdata						\
	-ignore-filename-regex=$(TESTS_DIR)/*						\
	-ignore-filename-regex=$(FT_MEM_DIR)/ft_allocator/ft_al_memimpl.c	\
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
	./testing_lib/libsimple_tests.a								\
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
.PHONY: re fclean clean $(TEST_NAME)_run
