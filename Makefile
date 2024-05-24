# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 09:04:05 by bgoulard          #+#    #+#              #
#    Updated: 2024/05/24 12:47:41 by bgoulard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GRAY		= "\\e[90m"
GREEN		= "\\e[42m"
RED			= "\\e[41m"
RESET		= "\\e[0m"
BOLD		= "\\e[1m"

# Commands
CC			=	clang
NAME		=	ft_personal
TEST_NAME	=	tests_run
AR			=	ar
COV			=	llvm-cov
PRD			=	llvm-profdata
ECHO		=	$(shell which echo) -e
PRINTF		=	$(shell which printf)

# Directories

SRC_DIR			=	src
BUILD_DIR		=	build
TESTS_DIR		=	tests
INC_DIR			=	include
COVERAGE_DIR	=	coverage

FT_MAP_DIR		=	ft_map
FT_LIST_DIR		=	ft_list
FT_STRING_DIR	=	ft_string
FT_CONF_DIR		=	ft_config
FT_VEC_DIR		=	ft_vector
FT_OPTIONAL_DIR	=	ft_optional
FT_ARGS_DIR		=	ft_args
FT_MATH_DIR		=	ft_math

# Counpound directories

FT_LIST_LL_DIR	=	$(FT_LIST_DIR)/ft_ll
FT_LIST_DL_DIR	=	$(FT_LIST_DIR)/ft_dl
FT_CHR_DIR		=	$(FT_STRING_DIR)/ft_chr
FT_MEM_DIR		=	$(FT_STRING_DIR)/ft_mem
FT_STR_DIR		=	$(FT_STRING_DIR)/ft_str
FT_T_STRING_DIR	=	$(FT_STRING_DIR)/ft_string

# Compilation flags

LDFLAGS		=	
CPPFLAGS	=	-I$(INC_DIR) -MMD
FFLAGS		=\
			 -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined\
			 -fsanitize=leak -fsanitize=pointer-compare -fsanitize=pointer-subtract\
			 -fsanitize-address-use-after-scope -fsanitize=pointer-overflow

CFLAGS		=	-Wall -Wextra $(CPPFLAGS) -Werror -fPIC \
				-fdiagnostics-color -g
TEST_FLAGS	=	\
			-g2											\
			-DDEBUG	-DTEST								\
			-ftest-coverage 							\
			-fprofile-instr-generate					\
			-fcoverage-mapping							\

# Inner variables

MAX_FILE_LEN	=	0
TARGET			?=	"ALL"
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

FT_MATH_SRC	=	\
			$(FT_MATH_DIR)/ft_clamp.c		\
			$(FT_MATH_DIR)/ft_complex.c		\
			$(FT_MATH_DIR)/ft_intrange.c	\
			$(FT_MATH_DIR)/ft_log.c			\
			$(FT_MATH_DIR)/ft_minmax.c		\
			$(FT_MATH_DIR)/ft_sqrt.c		\
			$(FT_MATH_DIR)/ft_pow.c			\
			$(FT_MATH_DIR)/ft_abs.c			\
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
			$(FT_LIST_LL_DIR)/ft_list_ll_find.c			\
			$(FT_LIST_LL_DIR)/ft_list_ll_add.c			\
			$(FT_LIST_LL_DIR)/ft_list_ll_clear.c		\
			$(FT_LIST_LL_DIR)/ft_list_ll_delete.c		\
			$(FT_LIST_LL_DIR)/ft_list_ll_apply.c		\
			$(FT_LIST_LL_DIR)/ft_list_ll_iterator.c		\
			$(FT_LIST_LL_DIR)/ft_list_ll_map.c			\
			$(FT_LIST_LL_DIR)/ft_list_ll_new.c			\
			$(FT_LIST_LL_DIR)/ft_list_ll_rev.c			\
			$(FT_LIST_LL_DIR)/ft_list_ll_size.c			\
			$(FT_LIST_LL_DIR)/ft_list_ll_create.c		\
			$(FT_LIST_LL_DIR)/ft_list_ll_getters.c		\
			$(FT_LIST_LL_DIR)/ft_list_ll_pushpop.c		\
			$(FT_LIST_LL_DIR)/ft_list_ll_sub.c			\

FT_LIST_DL_SRC	=	\
			$(FT_LIST_DL_DIR)/ft_list_dl_apply.c		\
			$(FT_LIST_DL_DIR)/ft_list_dl_clear.c		\
			$(FT_LIST_DL_DIR)/ft_list_dl_create.c		\
			$(FT_LIST_DL_DIR)/ft_list_dl_delete.c		\
			$(FT_LIST_DL_DIR)/ft_list_dl_getters.c		\
			$(FT_LIST_DL_DIR)/ft_list_dl_iterator.c		\
			$(FT_LIST_DL_DIR)/ft_list_dl_pushpop.c		\
			$(FT_LIST_DL_DIR)/ft_list_dl_size.c			\
			$(FT_LIST_DL_DIR)/ft_list_dl_sub.c			\
			$(FT_LIST_DL_DIR)/ft_list_dl_add.c			\
			$(FT_LIST_DL_DIR)/ft_list_dl_rev.c			\
			$(FT_LIST_DL_DIR)/ft_list_dl_map.c			\
			$(FT_LIST_DL_DIR)/ft_list_dl_new.c			\
			$(FT_LIST_DL_DIR)/ft_list_dl_find.c			\

FT_STR_SRC	=	\
			$(FT_STR_DIR)/ft_atof.c				\
			$(FT_STR_DIR)/ft_atoi.c				\
			$(FT_STR_DIR)/ft_atoi_base.c		\
			$(FT_STR_DIR)/ft_itoa.c				\
			$(FT_STR_DIR)/ft_itoa_base.c		\
			$(FT_STR_DIR)/ft_putendl_fd.c		\
			$(FT_STR_DIR)/ft_putnbr_fd.c		\
			$(FT_STR_DIR)/ft_putstr_fd.c		\
			$(FT_STR_DIR)/ft_shift_args.c		\
			$(FT_STR_DIR)/ft_split.c			\
			$(FT_STR_DIR)/ft_splits.c			\
			$(FT_STR_DIR)/ft_str_isalpha.c		\
			$(FT_STR_DIR)/ft_str_isalphanum.c	\
			$(FT_STR_DIR)/ft_str_isbool.c		\
			$(FT_STR_DIR)/ft_str_isdigit.c		\
			$(FT_STR_DIR)/ft_str_isfloat.c		\
			$(FT_STR_DIR)/ft_str_ishex.c		\
			$(FT_STR_DIR)/ft_str_isdouble.c		\
			$(FT_STR_DIR)/ft_str_isint.c		\
			$(FT_STR_DIR)/ft_str_islong.c		\
			$(FT_STR_DIR)/ft_str_isnum.c		\
			$(FT_STR_DIR)/ft_str_isoct.c		\
			$(FT_STR_DIR)/ft_str_isvalid.c		\
			$(FT_STR_DIR)/ft_str_replace.c		\
			$(FT_STR_DIR)/ft_strappend_c.c		\
			$(FT_STR_DIR)/ft_strchr.c			\
			$(FT_STR_DIR)/ft_strclen.c			\
			$(FT_STR_DIR)/ft_strcmp.c			\
			$(FT_STR_DIR)/ft_strcnb.c			\
			$(FT_STR_DIR)/ft_strcspn.c			\
			$(FT_STR_DIR)/ft_strdup.c			\
			$(FT_STR_DIR)/ft_strend_with.c		\
			$(FT_STR_DIR)/ft_striteri.c			\
			$(FT_STR_DIR)/ft_strjoin.c			\
			$(FT_STR_DIR)/ft_strlcat.c			\
			$(FT_STR_DIR)/ft_strlcpy.c			\
			$(FT_STR_DIR)/ft_strlen.c			\
			$(FT_STR_DIR)/ft_strmapi.c			\
			$(FT_STR_DIR)/ft_strncmp.c			\
			$(FT_STR_DIR)/ft_strndup.c			\
			$(FT_STR_DIR)/ft_strnstr.c			\
			$(FT_STR_DIR)/ft_strrchr.c			\
			$(FT_STR_DIR)/ft_strstart_with.c	\
			$(FT_STR_DIR)/ft_strtok.c			\
			$(FT_STR_DIR)/ft_strtrim.c			\
			$(FT_STR_DIR)/ft_substr.c			\
			$(FT_STR_DIR)/ft_utoa.c				\
			$(FT_STR_DIR)/get_next_line.c		\
			$(FT_STR_DIR)/get_next_line_utils.c

FT_T_STRING_SRC	=	\
			$(FT_T_STRING_DIR)/ft_string_append.c	\
			$(FT_T_STRING_DIR)/ft_string_new.c		\
			$(FT_T_STRING_DIR)/ft_string_put.c		\
			$(FT_T_STRING_DIR)/ft_string_from.c		\
			$(FT_T_STRING_DIR)/ft_string_clear.c	\
			$(FT_T_STRING_DIR)/ft_string_destroy.c	\
			$(FT_T_STRING_DIR)/ft_string_insert.c	\
			$(FT_T_STRING_DIR)/ft_string_reserve.c	\
			$(FT_T_STRING_DIR)/ft_string_resize.c	\
			$(FT_T_STRING_DIR)/ft_string_shrink.c	\
			$(FT_T_STRING_DIR)/ft_string_substr.c	\
			$(FT_T_STRING_DIR)/ft_string_to_str.c	\
			$(FT_T_STRING_DIR)/ft_string_trim.c		\
			$(FT_T_STRING_DIR)/ft_string_cmp.c		\
			$(FT_T_STRING_DIR)/ft_string_get.c		\
			$(FT_T_STRING_DIR)/ft_string_chr.c		\
			$(FT_T_STRING_DIR)/ft_string_replace.c	\
			$(FT_T_STRING_DIR)/ft_string_set.c

FT_MEM_SRC	=	\
			$(FT_MEM_DIR)/ft_bzero.c		\
			$(FT_MEM_DIR)/ft_calloc.c		\
			$(FT_MEM_DIR)/ft_free.c			\
			$(FT_MEM_DIR)/ft_memchr.c		\
			$(FT_MEM_DIR)/ft_memcmp.c		\
			$(FT_MEM_DIR)/ft_memcpy.c		\
			$(FT_MEM_DIR)/ft_memmove.c		\
			$(FT_MEM_DIR)/ft_memset.c		\
			$(FT_MEM_DIR)/ft_qsort.c		\
			$(FT_MEM_DIR)/ft_realloc.c		\
			$(FT_MEM_DIR)/ft_swap.c

FT_CHR_SRC	=	\
			$(FT_CHR_DIR)/ft_isalnum.c		\
			$(FT_CHR_DIR)/ft_isalpha.c		\
			$(FT_CHR_DIR)/ft_isascii.c		\
			$(FT_CHR_DIR)/ft_isdigit.c		\
			$(FT_CHR_DIR)/ft_ishexdigit.c	\
			$(FT_CHR_DIR)/ft_islower.c		\
			$(FT_CHR_DIR)/ft_isoctdigit.c	\
			$(FT_CHR_DIR)/ft_isprint.c		\
			$(FT_CHR_DIR)/ft_isspace.c		\
			$(FT_CHR_DIR)/ft_isupper.c		\
			$(FT_CHR_DIR)/ft_putchar_fd.c	\
			$(FT_CHR_DIR)/ft_tolower.c		\
			$(FT_CHR_DIR)/ft_toupper.c

FT_VEC_SRC	=	\
			$(FT_VEC_DIR)/ft_vec_add.c		\
			$(FT_VEC_DIR)/ft_vec_apply.c	\
			$(FT_VEC_DIR)/ft_vec_at.c		\
			$(FT_VEC_DIR)/ft_vec_cat.c		\
			$(FT_VEC_DIR)/ft_vec_clear.c	\
			$(FT_VEC_DIR)/ft_vec_destroy.c	\
			$(FT_VEC_DIR)/ft_vec_filter.c	\
			$(FT_VEC_DIR)/ft_vec_get.c		\
			$(FT_VEC_DIR)/ft_vec_map.c		\
			$(FT_VEC_DIR)/ft_vec_new.c		\
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
			$(FT_ARGS_DIR)/arg_err.c				\
			$(FT_ARGS_DIR)/checker_arg.c			\
			$(FT_ARGS_DIR)/ft_arg_custom_checker.c	\
			$(FT_ARGS_DIR)/ft_parse_long.c			\
			$(FT_ARGS_DIR)/parse_short_opt.c		\
			$(FT_ARGS_DIR)/run_opt_func.c			\
			$(FT_ARGS_DIR)/ft_parse_args.c			\
			$(FT_ARGS_DIR)/ft_progname.c			\
			$(FT_ARGS_DIR)/ft_set_opt_args.c		\
			$(FT_ARGS_DIR)/ft_setup_prog.c			\
			$(FT_ARGS_DIR)/ft_version.c

# Counpound sources

FT_CONF_SRC		=	\
			$(FT_CONF_DIR)/ftc_baseop.c		\
			$(FT_CONF_DIR)/ftc_get_parser.c

FT_LIST_SRC		=	\
			$(FT_LIST_LL_SRC)	\
			$(FT_LIST_DL_SRC)	\

FT_STRING_SRC	=	\
			$(FT_CHR_SRC)		\
			$(FT_MEM_SRC)		\
			$(FT_STR_SRC)		\
			$(FT_T_STRING_SRC)

# Tests sources

TESTS_SRC	=\
			$(TESTS_DIR)/ft_args/tests_progname.c				\
			$(TESTS_DIR)/ft_args/tests_version.c				\
			$(TESTS_DIR)/ft_args/args_tests.c					\
			\
			$(TESTS_DIR)/ft_list/ll_tests/ll_tests_utils.c		\
			$(TESTS_DIR)/ft_list/ll_tests/ll_list_tests.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_push.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_new.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_map.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_rev.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_sizers.c	\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_apply.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_iterators.c	\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_clear.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_copy.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_create.c	\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_deletors.c	\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_find.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_get.c		\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_subrange.c	\
			$(TESTS_DIR)/ft_list/ll_tests/tests_list_add.c		\
			$(TESTS_DIR)/ft_list/dl_tests/dl_tests_utils.c		\
			$(TESTS_DIR)/ft_list/dl_tests/dl_list_tests.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_add.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_clear.c	\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_copy.c	\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_create.c	\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_delete.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_iterators.c	\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_get.c			\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_subrange.c	\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_map.c			\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_new.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_push.c	\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_rev.c		\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_sizers.c	\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_apply.c	\
			$(TESTS_DIR)/ft_list/dl_tests/tests_dlist_find.c	\
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
			$(TESTS_DIR)/ft_math/tests_clamp.c					\
			$(TESTS_DIR)/ft_math/tests_complex.c				\
			$(TESTS_DIR)/ft_math/tests_intrange.c				\
			$(TESTS_DIR)/ft_math/tests_log.c					\
			$(TESTS_DIR)/ft_math/tests_minmax.c					\
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
			$(TESTS_DIR)/ft_string/ft_char/tests_isalnum.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_isalpha.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_isascii.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_isdigit.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_ishexdigit.c	\
			$(TESTS_DIR)/ft_string/ft_char/tests_isoctdigit.c	\
			$(TESTS_DIR)/ft_string/ft_char/tests_isspace.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_isprint.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_puchar.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_tolower.c		\
			$(TESTS_DIR)/ft_string/ft_char/tests_toupper.c		\
			$(TESTS_DIR)/ft_string/ft_char/ft_char_tests.c		\
			\
			$(TESTS_DIR)/ft_string/ft_mem/mem_tests.c			\
			$(TESTS_DIR)/ft_string/ft_str/str_tests.c			\
			$(TESTS_DIR)/ft_string/ft_t_string/t_string_tests.c	\
			$(TESTS_DIR)/ft_string/string_tests.c				\
			\
			$(TESTS_DIR)/ft_vector/tests_vec_add.c				\
			$(TESTS_DIR)/ft_vector/tests_vec_apply.c			\
			$(TESTS_DIR)/ft_vector/tests_vec_at.c				\
			$(TESTS_DIR)/ft_vector/tests_vec_cat.c				\
			$(TESTS_DIR)/ft_vector/tests_vec_clear.c				\
			$(TESTS_DIR)/ft_vector/tests_vec_convert_alloc_array.c	\
			$(TESTS_DIR)/ft_vector/tests_vec_destroy.c				\
			$(TESTS_DIR)/ft_vector/tests_vec_filter.c			\
			$(TESTS_DIR)/ft_vector/tests_vec_from_array.c		\
			$(TESTS_DIR)/ft_vector/tests_vec_from_size.c		\
			$(TESTS_DIR)/ft_vector/tests_vec_map.c				\
			$(TESTS_DIR)/ft_vector/tests_vec_new.c				\
			$(TESTS_DIR)/ft_vector/tests_vec_remove.c			\
			$(TESTS_DIR)/ft_vector/tests_vec_remove_if.c		\
			$(TESTS_DIR)/ft_vector/tests_vec_reserve.c			\
			$(TESTS_DIR)/ft_vector/tests_vec_reverse.c			\
			$(TESTS_DIR)/ft_vector/tests_vec_shift.c			\
			$(TESTS_DIR)/ft_vector/tests_vec_shrink.c			\
			$(TESTS_DIR)/ft_vector/tests_vec_sort.c				\
			$(TESTS_DIR)/ft_vector/tests_vec_swap.c				\
			$(TESTS_DIR)/ft_vector/vector_tests.c				\
			\
			$(TESTS_DIR)/main_tests.c							\
			$(TESTS_DIR)/lambdas_for_tests.c					\
			$(TESTS_DIR)/tests_utils.c

# Inner variables for targets

STABLE		=	\
			$(FT_MATH_SRC)		\
			$(FT_LIST_SRC)		\
			$(FT_VEC_SRC)		\
			$(FT_STRING_SRC)	\
			$(FT_MAP_SRC)		\
			$(FT_OPTIONAL_SRC)	\

UNSTABLE	=	\
			$(FT_ARGS_SRC)
#			$(FT_CONF_SRC)		\

INNER_SRC   = \
			$(STABLE)

# Check if user wants to compile unstable sources
#   to compile unstable sources run make with TARGET=UNSTABLE
ifeq (UNSTABLE, $(findstring UNSTABLE, $(TARGET)))
INNER_SRC   += \
			$(UNSTABLE)
endif
# Check if user wants to compile all sources
#   to compile all sources run make with TARGET=ALL
ifeq (ALL, $(findstring ALL, $(TARGET)))
INNER_SRC   = \
			$(STABLE)	\
			$(UNSTABLE)
endif

# Objects creation

#   add prefix to sources to specify the directory src/
SRCS		=	$(addprefix $(SRC_DIR)/, $(INNER_SRC))

#   add prefix to sources to specify the directory build/ for objects
OBJ			=	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/,$(INNER_SRC)))

#   add prefix to sources to specify the directory build/tests/ for test objects
TOBJ		=	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/$(TESTS_DIR)/,$(INNER_SRC)))
TOBJ		+=	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/,$(TESTS_SRC)))

#  Inner variables for rules

# Get the max length of the sources names to align the output
MAX_FILE_LEN	=	$(shell $(PRINTF) "%s\n" $(SRCS) | \
					awk '{print length}' | sort -n | tail -1)

# Rules

# Default rule for objects imported from src/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(ECHO) -n	$(GRAY)	"building from "
	@$(PRINTF) "%*s ... "$(RESET) $(MAX_FILE_LEN) $<
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) -c $< -o $@ 2>> $(CLOG_FILE) 	&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )				|| \
	$(ECHO) $(RED) "Failed" $(RESET)					\
	$(BOLD) "see:" $(CLOG_FILE) $(RESET)

# Rule for tests objects imported from src/
$(BUILD_DIR)/$(TESTS_DIR)/%.o: $(SRC_DIR)/%.c
	@$(ECHO) -n	$(GRAY)	"building from " $< "..." $(RESET)
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) $(TEST_FLAGS) -c $< -o $@		\
	2>>	$(CLOG_FILE) 									&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )				|| \
	$(ECHO) $(RED) "Failed" $(RESET)					\
	$(BOLD) "see:" $(CLOG_FILE) $(RESET)

# Rule for tests objects imported from tests/
$(BUILD_DIR)/$(TESTS_DIR)/%.o: $(TESTS_DIR)/%.c
	@$(ECHO) -n	$(GRAY)	"building from " $< "..." $(RESET)
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) $(TEST_FLAGS) -c $< -o $@		\
	2>>	$(CLOG_FILE) 									&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )				|| \
	$(ECHO) $(RED) "Failed" $(RESET)					\
	$(BOLD) "see:" $(CLOG_FILE) $(RESET)

# Default rule
all:	lib$(NAME).a

so: lib$(NAME).so

# Rule for shared library
lib$(NAME).so:	$(OBJ)
	@$(ECHO) -n $(GRAY) "Making ... " $(RESET) $(BOLD) 			\
	"lib$(NAME).so" $(RESET) $(GRAY) " ... " $(RESET)
	@( $(CC) -shared -o lib$(NAME).so $(OBJ) 2> /dev/null		&& \
	$(ECHO) $(GREEN) "Success" $(RESET) && $(RM) $(CLOG_FILE) )	|| \
	$(ECHO) $(RED) "Failed" $(RESET) "see:" $(CLOG_FILE)
	
# Rule for static library
lib$(NAME).a:	$(OBJ)
	@$(ECHO) -n $(GRAY) "Making ... " $(RESET) $(BOLD)				\
	"lib$(NAME).a" $(RESET)	$(GRAY) " ... " $(RESET)
	@( $(AR) -rcs lib$(NAME).a $(OBJ) 2> /dev/null					&& \
	$(ECHO) $(GREEN) "Success" $(RESET) && $(RM) $(CLOG_FILE) ) 	|| \
	$(ECHO) $(RED) "Failed" $(RESET) "see:" $(CLOG_FILE)

# Rule to compile and run tests
$(TEST_NAME): $(TOBJ)
	@$(ECHO) -n $(GRAY) "Compiling tests ... " $(RESET)
	@$(CC) $(CFLAGS) $(TOBJ) -o $(TEST_NAME) $(TEST_FLAGS)		\
	$(LDFLAGS) -lgcov								\
	2>> $(CLOG_FILE)											&& \
	$(ECHO) $(GREEN) "Success" $(RESET)							|| \
	$(ECHO) $(RED) "Failed" $(RESET)
	@$(ECHO) -n $(GRAY) "Running tests ... " $(RESET)			&& \
	./$(TEST_NAME) 												&& \
	$(ECHO) $(GREEN) "Success" $(RESET)							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

# Rule to generate coverage using llvm
$(COVERAGE_DIR): $(TEST_NAME)
	@$(ECHO) -n $(GRAY) "Generating profraw ... " $(RESET)		&& \
	./$(TEST_NAME)												&& \
	$(ECHO) -n $(GRAY) " profdata ... " $(RESET)				&& \
	$(PRD) merge -sparse default.profraw -o 					\
	$(TEST_NAME).profdata										&& \
	$(ECHO) -n $(GRAY) "coverage in html ... "					\
	$(RESET)													&& \
	$(COV) show -format=html									\
	-instr-profile=$(TEST_NAME).profdata						\
	-ignore-filename-regex=$(TESTS_DIR)/*						\
	--show-branches=count										\
	./$(TEST_NAME) -output-dir=$(COVERAGE_DIR) > /dev/null		&& \
	$(RM) *.profraw *.profdata									&& \
	$(ECHO) $(GREEN) "Success" $(RESET)							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

# Rule to compile using debug flags
debug:
	@$(ECHO) $(GRAY) "Compiling debug, flags are" $(RESET) 		\
	"$(CFLAGS) $(DEBUG_FLAGS)" $(RESET)							&& \
	make -C ./ re CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)"				&& \
	make -C ./ so CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)"				&& \
	$(ECHO) $(GREEN) "Success" $(RESET)							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

# Rule to clean objects
clean:
	@$(ECHO) -n $(GRAY) "Clean ... " $(RESET)						&& \
	( $(RM) -rf $(BUILD_DIR) $(CLOG_FILE) $(TEST_NAME) *.gcov			\
	*.gcno *.gcda 2> /dev/null 										&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

# Rule to clean objects and libraries/compiled files
fclean: clean
	@$(ECHO) -n $(GRAY) "FClean ... " $(RESET)						&& \
	( $(RM) -rf lib$(NAME).a lib$(NAME).so $(COVERAGE_DIR)			\
	$(TEST_NAME)													\
	*.profraw *.profdata Doxygen 2> /dev/null 						&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

# Rule to generate Doxygen documentation
Doxygen:
	@$(ECHO) -n $(GRAY) "Generating Doxygen ... " $(RESET)			&& \
	( doxygen tools/doxyfile 2> /dev/null							&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

# Rule to recompile
re:	fclean all

# rule to clean everything and make the project ready for 42 norm
42ready: fclean
	@$(ECHO) -n $(GRAY) "42ready ... " $(RESET)					&& \
	$(RM) -rf $(COVERAGE_DIR) $(TESTS_DIR) tools README.md		\
	.vscode 													&& \
	awk '														\
	BEGIN {to_del=0}											\
    (/^TEST*/ || /^test*/ || /^coverage*/ || /so:/ || /^#/ && 	\
	$$NF > 11 || /^debug/ || /^Doxygen/ || /^42ready/ ) 		\
		{to_del=1}												\
    (to_del == 0) 												\
		{print}													\
    (to_del==1 && /^$$/)										\
		{to_del=0}' Makefile > Makefile.tmp						&& \
	mv Makefile.tmp Makefile									&& \
	$(ECHO) $(GREEN) "Success" $(RESET)							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

-include $(OBJ:.o=.d)

# rule to force rules to be executed even if files exist
.PHONY: re fclean clean

