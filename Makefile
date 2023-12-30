# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 09:04:05 by bgoulard          #+#    #+#              #
#    Updated: 2023/12/30 11:17:10 by bgoulard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRAY		= "\\e[90m"
GREEN		= "\\e[42m"
RED			= "\\e[41m"
RESET		= "\\e[0m"
BOLD		= "\\e[1m"

CC			=	clang
NAME		=	ft_personal
COV			=	llvm-cov
PRD			=	llvm-profdata
ECHO		=	$(shell which echo) -e

# check if we found llvm-cov and llvm-profdata
# if not, we try to find the version 12 (42 version)
ifeq (, $(shell which $(COV) 2> /dev/null))
	COV			=	llvm-cov-12
endif

ifeq (, $(shell which $(PRD) 2> /dev/null))
	PRD			=	llvm-profdata-12
endif

SRC_DIR			=	src
BUILD_DIR		=	build
TESTS_DIR		=	tests
INC_DIR			=	include
COVERAGE_DIR	=	coverage

LDFLAGS		=	
CPPFLAGS	=	-I$(INC_DIR)
CFLAGS		=	-Wall -Wextra $(CPPFLAGS) -Werror -fPIC -fdiagnostics-color
TEST_FLAGS	=\
			-g2											\
			-DDEBUG	-DTEST								\
			-fprofile-arcs	-ftest-coverage 			\
			-fprofile-instr-generate			 		\
			-fcoverage-mapping

TARGET		?=	"ALL"

FT_MAP_DIR		=	ft_map
FT_LIST_DIR		=	ft_list
FT_STRING_DIR	=	ft_string
FT_CONF_DIR		=	ft_config
FT_VEC_DIR		=	ft_vector

FT_LIST_LL_DIR	=	$(FT_LIST_DIR)/ft_ll
FT_LIST_DL_DIR	=	$(FT_LIST_DIR)/ft_dl
FT_MEM_DIR		=	$(FT_STRING_DIR)/ft_mem
FT_STR_DIR		=	$(FT_STRING_DIR)/ft_str
FT_T_STRING_DIR	=	$(FT_STRING_DIR)/ft_string


FT_MAP_SRC	=	\
			$(FT_MAP_DIR)/ft_map_clear.c		\
			$(FT_MAP_DIR)/ft_map_create.c		\
			$(FT_MAP_DIR)/ft_map_destroy.c		\
			$(FT_MAP_DIR)/ft_map_get.c			\
			$(FT_MAP_DIR)/ft_map_hash.c			\
			$(FT_MAP_DIR)/ft_map_remove.c		\
			$(FT_MAP_DIR)/ft_map_set.c

FT_LIST_LL_SRC	=\
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

FT_LIST_DL_SRC	=\
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

FT_STR_SRC	=\
			$(FT_STR_DIR)/ft_atoi.c			\
			$(FT_STR_DIR)/ft_atoi_base.c	\
			$(FT_STR_DIR)/ft_isalnum.c		\
			$(FT_STR_DIR)/ft_isalpha.c		\
			$(FT_STR_DIR)/ft_isascii.c		\
			$(FT_STR_DIR)/ft_isdigit.c		\
			$(FT_STR_DIR)/ft_islower.c		\
			$(FT_STR_DIR)/ft_isprint.c		\
			$(FT_STR_DIR)/ft_isspace.c		\
			$(FT_STR_DIR)/ft_isupper.c		\
			$(FT_STR_DIR)/ft_itoa.c			\
			$(FT_STR_DIR)/ft_itoa_base.c	\
			$(FT_STR_DIR)/ft_log.c			\
			$(FT_STR_DIR)/ft_minmax.c		\
			$(FT_STR_DIR)/ft_putchar_fd.c	\
			$(FT_STR_DIR)/ft_putendl_fd.c	\
			$(FT_STR_DIR)/ft_putnbr_fd.c	\
			$(FT_STR_DIR)/ft_putstr_fd.c	\
			$(FT_STR_DIR)/ft_shift_args.c	\
			$(FT_STR_DIR)/ft_split.c		\
			$(FT_STR_DIR)/ft_splits.c		\
			$(FT_STR_DIR)/ft_str_replace.c	\
			$(FT_STR_DIR)/ft_strchr.c		\
			$(FT_STR_DIR)/ft_strcmp.c		\
			$(FT_STR_DIR)/ft_strdup.c		\
			$(FT_STR_DIR)/ft_striteri.c		\
			$(FT_STR_DIR)/ft_strjoin.c		\
			$(FT_STR_DIR)/ft_strlcat.c		\
			$(FT_STR_DIR)/ft_strlcpy.c		\
			$(FT_STR_DIR)/ft_strlen.c		\
			$(FT_STR_DIR)/ft_strmapi.c		\
			$(FT_STR_DIR)/ft_strncmp.c		\
			$(FT_STR_DIR)/ft_strndup.c		\
			$(FT_STR_DIR)/ft_strnstr.c		\
			$(FT_STR_DIR)/ft_strrchr.c		\
			$(FT_STR_DIR)/ft_strtok.c		\
			$(FT_STR_DIR)/ft_strtrim.c		\
			$(FT_STR_DIR)/ft_substr.c		\
			$(FT_STR_DIR)/ft_swap.c			\
			$(FT_STR_DIR)/ft_tolower.c		\
			$(FT_STR_DIR)/ft_toupper.c		\
			$(FT_STR_DIR)/ft_utoa.c				\
			$(FT_STR_DIR)/get_next_line.c		\
			$(FT_STR_DIR)/get_next_line_utils.c

FT_T_STRING_SRC	=\
			$(FT_T_STRING_DIR)/ft_string_new.c		\
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
			$(FT_MEM_DIR)/ft_realloc.c

FT_VEC_SRC		=	\
			$(FT_VEC_DIR)/ft_vec_add.c		\
			$(FT_VEC_DIR)/ft_vec_apply.c	\
			$(FT_VEC_DIR)/ft_vec_at.c		\
			$(FT_VEC_DIR)/ft_vec_cat.c		\
			$(FT_VEC_DIR)/ft_vec_clear.c	\
			$(FT_VEC_DIR)/ft_vec_destroy.c	\
			$(FT_VEC_DIR)/ft_vec_filter.c	\
			$(FT_VEC_DIR)/ft_vec_map.c		\
			$(FT_VEC_DIR)/ft_vec_new.c		\
			$(FT_VEC_DIR)/ft_vec_remove.c	\
			$(FT_VEC_DIR)/ft_vec_reserve.c	\
			$(FT_VEC_DIR)/ft_vec_reverse.c	\
			$(FT_VEC_DIR)/ft_vec_shift.c	\
			$(FT_VEC_DIR)/ft_vec_shrink.c	\
			$(FT_VEC_DIR)/ft_vec_sort.c		\
			$(FT_VEC_DIR)/ft_vec_swap.c
			
FT_CONF_SRC		=	\
			$(CONF_DIR)/ftc_baseop.c		\
			$(CONF_DIR)/ftc_get_parser.c

FT_LIST_SRC		=	\
			$(FT_LIST_LL_SRC)	\
			$(FT_LIST_DL_SRC)	\

FT_STRING_SRC	=	\
			$(FT_MEM_SRC)		\
			$(FT_STR_SRC)		\
			$(FT_T_STRING_SRC)

TESTS_SRC	=	\
			$(TESTS_DIR)/ft_list/ll_list_tests.c	\
			$(TESTS_DIR)/ft_list/dl_list_tests.c	\
			$(TESTS_DIR)/ft_map/map_tests.c			\
			$(TESTS_DIR)/ft_vector/vector_tests.c	\
			$(TESTS_DIR)/main_tests.c

STABLE		=	\
			$(FT_LIST_SRC)		\
			$(FT_VEC_SRC)		\
			$(FT_STRING_SRC)	\
			$(FT_MAP_SRC)		\

UNSTABLE	=	\
			$(CONF_SRC)			\

INNER_SRC	=

INNER_SRC   += \
			$(STABLE)

ifeq (UNSTABLE, $(findstring UNSTABLE, $(TARGET)))
INNER_SRC   += \
			$(UNSTABLE)
endif
ifeq (ALL, $(findstring ALL, $(TARGET)))
INNER_SRC   = \
			$(STABLE)	\
			$(UNSTABLE)
endif

SRCS		=	$(addprefix $(SRC_DIR)/, $(INNER_SRC))
OBJ			=	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/,$(INNER_SRC)))
TOBJ		=	$(patsubst %.c, %.test.o, $(addprefix $(BUILD_DIR)/$(TESTS_DIR)/,$(INNER_SRC)))
TOBJ		+=	$(patsubst %.c, %.test.o, $(addprefix $(BUILD_DIR)/,$(TESTS_SRC)))

CLOG_FILE	=	./compilation.log

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(ECHO) -n	$(GRAY)	"building from " $< "..." $(RESET)
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) -c $< -o $@ 2>> $(CLOG_FILE) 	&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )				|| \
	$(ECHO) $(RED) "Failed" $(RESET)					\
	$(BOLD) "see:" $(CLOG_FILE) $(RESET)

$(BUILD_DIR)/$(TESTS_DIR)/%.test.o: $(SRC_DIR)/%.c
	@$(ECHO) -n	$(GRAY)	"building from " $< "..." $(RESET)
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) $(TEST_FLAGS) -c $< -o $@		\
	2>>	$(CLOG_FILE) 									&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )				|| \
	$(ECHO) $(RED) "Failed" $(RESET)					\
	$(BOLD) "see:" $(CLOG_FILE) $(RESET)

$(BUILD_DIR)/$(TESTS_DIR)/%.test.o: $(TESTS_DIR)/%.c
	@$(ECHO) -n	$(GRAY)	"building from " $< "..." $(RESET)
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) $(TEST_FLAGS) -c $< -o $@		\
	2>>	$(CLOG_FILE) 									&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )				|| \
	$(ECHO) $(RED) "Failed" $(RESET)					\
	$(BOLD) "see:" $(CLOG_FILE) $(RESET)

all:	lib$(NAME).a

so: lib$(NAME).so

lib$(NAME).so:	$(OBJ)
	@$(ECHO) -n $(GRAY) "Making ... " $(RESET) $(BOLD) 			\
	"lib$(NAME).so" $(RESET) $(GRAY) " ... " $(RESET)
	@( $(CC) -shared -o lib$(NAME).so $(OBJ) 2> /dev/null		&& \
	$(ECHO) $(GREEN) "Success" $(RESET) && $(RM) $(CLOG_FILE) )	|| \
	$(ECHO) $(RED) "Failed" $(RESET) "see:" $(CLOG_FILE)
	

lib$(NAME).a:	$(OBJ)
	@$(ECHO) -n $(GRAY) "Making ... " $(RESET) $(BOLD)				\
	"lib$(NAME).a" $(RESET)	$(GRAY) " ... " $(RESET)
	@( $(AR) -rcs lib$(NAME).a $(OBJ) 2> /dev/null				&& \
	$(ECHO) $(GREEN) "Success" $(RESET) && $(RM) $(CLOG_FILE) ) 	|| \
	$(ECHO) $(RED) "Failed" $(RESET) "see:" $(CLOG_FILE)

tests_run: $(TOBJ)
	@$(ECHO) -n $(GRAY) "Compiling tests ... " $(RESET)
	@$(CC) $(CFLAGS) $(TOBJ) -o tests_run $(TEST_FLAGS)			\
	$(LDFLAGS) -lgcov 2> /dev/null								&& \
	$(ECHO) $(GREEN) "Success" $(RESET)							|| \
	$(ECHO) $(RED) "Failed" $(RESET)
	@$(ECHO) -n $(GRAY) "Running tests ... " $(RESET)			&& \
	./tests_run 												&& \
	$(ECHO) $(GREEN) "Success" $(RESET)							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

$(COVERAGE_DIR): tests_run
	@$(ECHO) -n $(GRAY) "Generating profraw ... " $(RESET)			&& \
	./tests_run													&& \
	$(ECHO) -n $(GRAY) " profdata ... " $(RESET)					&& \
	$(PRD) merge -sparse default.profraw -o 					\
	tests_run.profdata											&& \
	$(ECHO) -n $(GRAY) "coverage in html ... "					\
	$(RESET)													&& \
	$(COV) show -format=html									\
	-instr-profile=tests_run.profdata							\
	-ignore-filename-regex=$(TESTS_DIR)/*						\
	-ignore-filename-regex=$(FT_STRING_DIR)/*					\
	./tests_run -output-dir=$(COVERAGE_DIR) > /dev/null			&& \
	$(RM) *.profraw *.profdata									&& \
	$(ECHO) $(GREEN) "Success" $(RESET)							|| \
	$(ECHO) $(RED) "Failed" $(RESET)


debug:
	@$(ECHO) $(GRAY) "Compiling debug, flags are" $(RESET) 		\
	"$(CFLAGS) $(DEBUG_FLAGS)" $(RESET)							&& \
	make -C ./ re CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)"				&& \
	make -C ./ so CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)"				&& \
	$(ECHO) $(GREEN) "Success" $(RESET)							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

clean:
	@$(ECHO) -n $(GRAY) "Clean ... " $(RESET)						&& \
	( $(RM) -rf $(BUILD_DIR) $(CLOG_FILE) tests_run *.gcov		\
	*.gcno *.gcda 2> /dev/null 									&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

fclean: clean
	@$(ECHO) -n $(GRAY) "FClean ... " $(RESET)						&& \
	( $(RM) -rf lib$(NAME).a lib$(NAME).so $(COVERAGE_DIR)		\
	*.profraw *.profdata Doxygen 2> /dev/null 					&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

Doxygen:
	@$(ECHO) -n $(GRAY) "Generating Doxygen ... " $(RESET)			&& \
	( doxygen tools/doxyfile 2> /dev/null						&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )							|| \
	$(ECHO) $(RED) "Failed" $(RESET)
	

re:	fclean all

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

.PHONY: re fclean clean
