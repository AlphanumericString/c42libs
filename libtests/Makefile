# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 21:58:51 by bgoulard          #+#    #+#              #
#    Updated: 2025/03/14 22:34:51 by bgoulard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GRAY		= "\\e[90m"
GREEN		= "\\e[42m"
RED			= "\\e[41m"
RESET		= "\\e[0m"
BOLD		= "\\e[1m"

# Project name
NAME		:=	$(shell basename $(shell pwd))
TEST_NAME	:=	$(NAME)_tests

# Commands
CC			?=	clang
AR			?=	ar
COV			=	llvm-cov
PRD			=	llvm-profdata
ECHO		?=	$(shell which echo) -e
PRINTF		?=	$(shell which printf)

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


# Directories
## base
SRC_DIR			=	.
INC_DIR			=	.
BUILD_DIR		=	build
## tests
TESTS_DIR		=	tests
COVERAGE_DIR	=
## dependencies
LIB_DIR			=
LIBS			=

# If theres no lib_dir, set it to ""
ifneq (,$(LIB_DIR))
	LIB_DIR		:=	""
	LIBS		:=	""
endif
# Counpound directories
## e.g. STRINGS_DIR	=	$(SRC_DIR)/strings

# Compilation flags
# Normal compilation flags

WFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:=\
			$(addprefix -I, $(INC_DIR)) -MMD -MP
FFLAGS		=\
			-fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined	   \
			-fsanitize=leak -fsanitize=pointer-compare 						   \
			-fsanitize=pointer-subtract										   \
			-fsanitize-address-use-after-scope -fsanitize=pointer-overflow
CFLAGS		:=\
			$(WFLAGS) $(CPPFLAGS) $(FFLAGS)

LDFLAGS		:=\
			$(addprefix -L, $(sort $(dir $(LIB_DIR))))\
			$(addprefix -l, $(LIBS))
# Test flags

TEST_FLAGS	=\
		-g2	-DTEST \
		-fprofile-instr-generate -ftest-coverage -fcoverage-mapping \
		-DFORK_TESTS=0 -O0

# Debug flags
## To change debug level run make DEBUG_LEVEL=xxx

DEBUG_LEVEL	=\
			0
DEBUG_FLAGS	:=\
			-g3 -ggdb -DDEBUG	$(FFLAGS) -DDEBUG_LEVEL=$(DEBUG_LEVEL)

# Inner variables

MAX_FILE_LEN	=	0
TARGET			?=	"ALL"
CLOG_FILE		=	./compilation.log

# Sources

SRCS		=	$(shell for dir in $(SRC_DIR); do find $$dir -type f -name "*.c"; done)
INNER_SRC	=	$(notdir $(SRCS))

# Objects creation

#   add prefix to sources to specify the directory build/ for objects
OBJ			=	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/,$(INNER_SRC)))

#   add prefix to sources to specify the directory build/tests/ for test objects
TOBJ		=	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/$(TESTS_DIR)/,$(INNER_SRC)))
TOBJ		+=	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/,$(TESTS_SRC)))

#  Inner variables for rules

# Get the max length of the sources names to align the output
SRC_MAX_FILE_LEN	=\
	$(shell $(PRINTF) "%s\n" $(SRCS) | \
	awk '{print length}' | sort -n | tail -1)

TEST_MAX_FILE_LEN	=\
	$(shell $(PRINTF) "%s\n" $(TESTS_SRC) | \
	awk '{print length}' | sort -n | tail -1)

# Rules

# Default rule for objects imported from src/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(ECHO) -n	$(GRAY)	"building from "
	@$(PRINTF) "%-*s ... "$(RESET) $(SRC_MAX_FILE_LEN) $<
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) -c $< -o $@ 2>> $(CLOG_FILE) 	&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )				|| \
	$(ECHO) $(RED) "Failed" $(RESET)					\
	$(BOLD) "see:" $(CLOG_FILE) $(RESET)

# Rule for tests objects imported from src/
$(BUILD_DIR)/$(TESTS_DIR)/%.o: $(SRC_DIR)/%.c
	@$(ECHO) -n	$(GRAY)	"building from "
	@$(PRINTF) "%-*s ... "$(RESET) $(TEST_MAX_FILE_LEN) $<
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) $(TEST_FLAGS) -c $< -o $@		\
	2>>	$(CLOG_FILE) 									&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )				|| \
	$(ECHO) $(RED) "Failed" $(RESET)					\
	$(BOLD) "see:" $(CLOG_FILE) $(RESET)

# Rule for tests objects imported from tests/
$(BUILD_DIR)/$(TESTS_DIR)/%.o: $(TESTS_DIR)/%.c
	@$(ECHO) -n	$(GRAY)	"building from "
	@$(PRINTF) "%-*s ... "$(RESET) $(TEST_MAX_FILE_LEN) $<
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) $(TEST_FLAGS) -c $< -o $@		\
	2>>	$(CLOG_FILE) 									&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )				|| \
	$(ECHO) $(RED) "Failed" $(RESET)					\
	$(BOLD) "see:" $(CLOG_FILE) $(RESET)

# Default rule
all:	$(NAME)

# Rule to compile the libraries
$(LIBS):
	@$(shell for dir in $(LIB_DIR); do make --no-print-directory -C $$dir; done)

# Rule to compile the project
$(NAME):	$(OBJ) $(LIBS)
	@$(ECHO) -n $(GRAY) "Making ... " $(RESET) $(BOLD) 			\
		$(NAME) $(RESET) $(GRAY) " ... " $(RESET)				&& \
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) 2>> $(CLOG_FILE)	&& \
	$(ECHO) $(GREEN) "Success" $(RESET) && $(RM) $(CLOG_FILE)	|| \
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
	"$(CFLAGS) $(DEBUG_FLAGS)" $(RESET)						&& \
	make --no-print-directory -C . re							\
	CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)"							&& \
	$(ECHO) $(GREEN) "Success" $(RESET)							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

# Linter file creation
.clangd: Makefile
	@echo "Making clangd configuration file"
	@$(ECHO) -n																\
	"CompileFlags:\n"														\
	"  Compiler: clang\n"													\
	"  Add:\n"																\
	"   - \"-Wall -Wextra -Werror\"\n"										\
	"   - \""$(WFLAGS)"\"\n"												\
	"   - \"-xc\"\n"  > .clangd
	@for file in $(INC_DIR); do												\
		echo "    - \"-I"$(shell pwd)"/"$$file"\"" >> .clangd;				\
	done
	@$(ECHO) $(GREEN) "Done" $(RESET)

fclean_libs:
	@$(shell for dir in $(LIB_DIR); do make --no-print-directory -C $$dir fclean; done)
clean_libs:
	@$(shell for dir in $(LIB_DIR); do make --no-print-directory -C $$dir clean; done)
re_libs:
	@$(shell for dir in $(LIB_DIR); do make --no-print-directory -C $$dir re; done)

# Rule to clean objects
clean: clean_libs
	@$(ECHO) -n $(GRAY) "Clean ... " $(RESET)						&& \
	( $(RM) -rf $(BUILD_DIR) $(CLOG_FILE) $(TEST_NAME) *.gcov		\
		*.gcno *.gcda 2> /dev/null 									&& \
	$(ECHO) $(GREEN) "Success" $(RESET) )							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

# Rule to clean objects and libraries/compiled files
fclean: clean fclean_libs
	@$(ECHO) -n $(GRAY) "FClean ... " $(RESET)						&& \
	$(RM) -rf $(COVERAGE_DIR) $(NAME) $(TEST_NAME) *.profraw *.profdata 	\
		Doxygen 2> /dev/null 										&& \
	$(ECHO) $(GREEN) "Success" $(RESET)								|| \
	$(ECHO) $(RED) "Failed" $(RESET)

# Rule to recompile
re:	fclean re_libs
	@$(ECHO) -ne $(GRAY) "Recompiling ..." $(RESET) "\n"		&& \
	make --no-print-directory all								&& \
	$(ECHO) $(GREEN) "Success" $(RESET)							|| \
	$(ECHO) $(RED) "Failed" $(RESET)

-include $(OBJ:.o=.d)

# rule to force rules to be executed even if files exist
.PHONY: re fclean clean

