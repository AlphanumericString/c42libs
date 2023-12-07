# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 09:04:05 by bgoulard          #+#    #+#              #
#    Updated: 2023/12/07 13:51:12 by bgoulard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRAY		= "\\e[90m"
GREEN		= "\\e[42m"
RED			= "\\e[41m"
RESET		= "\\e[0m"
BOLD		= "\\e[1m"

CC			=	clang
NAME		=	ft_personal
SRC_DIR		=	./src
BUILD_DIR	=	./build
INC_DIR		=	./include
CPPFLAGS	=	-I$(INC_DIR)
CFLAGS		=	-Wall -Wextra $(CPPFLAGS) -Werror -fPIC -fdiagnostics-color

FT_LIST_DIR	=	ft_list
FT_LIST_SRC	=	\
			$(FT_LIST_DIR)/ft_list_dl_apply.c		\
			$(FT_LIST_DIR)/ft_list_dl_clear.c		\
			$(FT_LIST_DIR)/ft_list_dl_create.c		\
			$(FT_LIST_DIR)/ft_list_dl_delete.c		\
			$(FT_LIST_DIR)/ft_list_dl_get.c			\
			$(FT_LIST_DIR)/ft_list_dl_iterator.c	\
			$(FT_LIST_DIR)/ft_list_dl_manip.c		\
			$(FT_LIST_DIR)/ft_list_dl_size.c		\
			$(FT_LIST_DIR)/ft_list_dl_subrange.c	\
			$(FT_LIST_DIR)/ft_list_ll_add_back.c	\
			$(FT_LIST_DIR)/ft_list_ll_add_front.c	\
			$(FT_LIST_DIR)/ft_list_ll_clear.c		\
			$(FT_LIST_DIR)/ft_list_ll_delone.c		\
			$(FT_LIST_DIR)/ft_list_ll_iter.c		\
			$(FT_LIST_DIR)/ft_list_ll_last.c		\
			$(FT_LIST_DIR)/ft_list_ll_map.c			\
			$(FT_LIST_DIR)/ft_list_ll_new.c			\
			$(FT_LIST_DIR)/ft_list_ll_rev.c			\
			$(FT_LIST_DIR)/ft_list_ll_size.c

FT_STRING_DIR	=	ft_string
FT_STRING_SRC	=	\
			$(FT_STRING_DIR)/ft_atoi.c			\
			$(FT_STRING_DIR)/ft_bzero.c			\
			$(FT_STRING_DIR)/ft_calloc.c		\
			$(FT_STRING_DIR)/ft_isalnum.c		\
			$(FT_STRING_DIR)/ft_isalpha.c		\
			$(FT_STRING_DIR)/ft_isascii.c		\
			$(FT_STRING_DIR)/ft_isdigit.c		\
			$(FT_STRING_DIR)/ft_islower.c		\
			$(FT_STRING_DIR)/ft_isprint.c		\
			$(FT_STRING_DIR)/ft_isspace.c		\
			$(FT_STRING_DIR)/ft_isupper.c		\
			$(FT_STRING_DIR)/ft_itoa.c			\
			$(FT_STRING_DIR)/ft_itoa_base.c		\
			$(FT_STRING_DIR)/ft_log.c			\
			$(FT_STRING_DIR)/ft_memchr.c		\
			$(FT_STRING_DIR)/ft_memcmp.c		\
			$(FT_STRING_DIR)/ft_memcpy.c		\
			$(FT_STRING_DIR)/ft_memmove.c		\
			$(FT_STRING_DIR)/ft_memset.c		\
			$(FT_STRING_DIR)/ft_minmax.c		\
			$(FT_STRING_DIR)/ft_putchar_fd.c	\
			$(FT_STRING_DIR)/ft_putendl_fd.c	\
			$(FT_STRING_DIR)/ft_putnbr_fd.c		\
			$(FT_STRING_DIR)/ft_putstr_fd.c		\
			$(FT_STRING_DIR)/ft_split.c			\
			$(FT_STRING_DIR)/ft_strchr.c		\
			$(FT_STRING_DIR)/ft_strdup.c		\
			$(FT_STRING_DIR)/ft_striteri.c		\
			$(FT_STRING_DIR)/ft_strjoin.c		\
			$(FT_STRING_DIR)/ft_strlcat.c		\
			$(FT_STRING_DIR)/ft_strlcpy.c		\
			$(FT_STRING_DIR)/ft_strlen.c		\
			$(FT_STRING_DIR)/ft_strmapi.c		\
			$(FT_STRING_DIR)/ft_strncmp.c		\
			$(FT_STRING_DIR)/ft_strndup.c		\
			$(FT_STRING_DIR)/ft_strnstr.c		\
			$(FT_STRING_DIR)/ft_strrchr.c		\
			$(FT_STRING_DIR)/ft_strtrim.c		\
			$(FT_STRING_DIR)/ft_substr.c		\
			$(FT_STRING_DIR)/ft_tolower.c		\
			$(FT_STRING_DIR)/ft_toupper.c		\
			$(FT_STRING_DIR)/ft_utoa.c

VEC_DIR		=	ft_vector
VEC_SRC		=	\
			$(VEC_DIR)/ft_vec_add.c		\
			$(VEC_DIR)/ft_vec_apply.c	\
			$(VEC_DIR)/ft_vec_at.c		\
			$(VEC_DIR)/ft_vec_cat.c		\
			$(VEC_DIR)/ft_vec_clear.c	\
			$(VEC_DIR)/ft_vec_destroy.c	\
			$(VEC_DIR)/ft_vec_filter.c	\
			$(VEC_DIR)/ft_vec_map.c		\
			$(VEC_DIR)/ft_vec_new.c		\
			$(VEC_DIR)/ft_vec_reserve.c	\
			$(VEC_DIR)/ft_vec_shift.c	\
			$(VEC_DIR)/ft_vec_sort.c

CONF_DIR	=	ft_config
CONF_SRC	=	\
			$(CONF_DIR)/ftc_baseop.c		\
			$(CONF_DIR)/ftc_get_parser.c

SRC_FILES	=	\
			$(FT_LIST_SRC)		\
			$(VEC_SRC)			\
			$(FT_STRING_SRC)	\
			$(CONF_SRC)

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			=	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/,$(SRC_FILES)))

CLOG_FILE	=	./compilation.log

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo -n	$(GRAY)	"building from " $< "..." $(RESET)
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) -c $< -o $@ 2>> $(CLOG_FILE) && \
	echo $(GREEN) "Success" $(RESET) ) || \
	echo $(RED) "Failed" $(RESET) "see:" $(CLOG_FILE)

all:	lib$(NAME).a

so: $(OBJ)
	@echo -n $(GRAY) "Making ... " $(RESET) $(BOLD) "lib$(NAME).so" \
	$(RESET) $(GRAY) " ... " $(RESET)
	@( $(CC)	-nostartfiles  -shared -o lib$(NAME).so	$(CFLAGS) $(OBJ) \
	 2>> $(CLOG_FILE) && echo $(GREEN) "Success" $(RESET) && $(RM) $(CLOG_FILE) ) || \
	echo $(RED) "Failed" $(RESET) "see:" $(CLOG_FILE)
	

lib$(NAME).a:	$(OBJ)
	@echo -n $(GRAY) "Making ... " $(RESET) $(BOLD) "lib$(NAME).a" \
	$(RESET)	$(GRAY) " ... " $(RESET)
	@( $(AR) -rcs lib$(NAME).a $(OBJ) 2> /dev/null && \
	echo $(GREEN) "Success" $(RESET) && $(RM) $(CLOG_FILE) ) || \
	echo $(RED) "Failed" $(RESET) "see:" $(CLOG_FILE)

debug:
	make -C ./ re CFLAGS="$(CFLAGS) -g2"
	make -C ./ so CFLAGS="$(CFLAGS) -g2"

clean:
	@echo -n $(GRAY) "Clean ... " $(RESET)
	@( $(RM) -rf $(BUILD_DIR) $(CLOG_FILE) 2> /dev/null && \
	echo $(GREEN) "Success" $(RESET) ) || \
	echo $(RED) "Failed" $(RESET)

fclean: clean
	@echo -n $(GRAY) "FClean ... " $(RESET)
	@( $(RM) lib$(NAME).a lib$(NAME).so 2> /dev/null && \
	echo $(GREEN) "Success" $(RESET) ) || \
	echo $(RED) "Failed" $(RESET)
	

re:	fclean all

.PHONY: re fclean clean
