# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 00:11:55 by bgoulard          #+#    #+#              #
#    Updated: 2025/11/29 00:11:55 by bgoulard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

examples:=\
	ft_args/parse_opts \
	ft_list/phone_book_applet

all:
	@for e in $(examples); do \
		$(MAKE) -C $$e all; \
	done
clean:
	@for e in $(examples); do \
		$(MAKE) -C $$e clean; \
	done
fclean:
	@for e in $(examples); do \
		$(MAKE) -C $$e fclean; \
	done
re: fclean all
.PHONY: all clean fclean re $(examples)
