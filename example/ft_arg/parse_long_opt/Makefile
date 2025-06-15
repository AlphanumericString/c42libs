.DEFAULT_GOAL := $(NAME)
.PRECIOUS:	$(NAME)
# -- commands
ECHO	=	$(shell which echo)
RM		=	$(shell which rm)
MKDIR	=	$(shell which mkdir)
CP		=	$(shell which cp)
PRINT	=	$(shell which printf)
AR		=	$(shell which ar)
CC		=	$(shell which clang)
CXX		=	$(shell which clang++)
MAKE_SL =	$(shell which make) --no-print-directory

# -- Defaults vars
#  -- Colors
GRAY        = \e[90m
GREEN       = \e[42m
RED         = \e[41m
RESET       = \e[0m
BOLD        = \e[1m
YELLOW      = \e[33m

OK		=	$(GREEN)
KO		=	$(RED)
LOG_MIN	=	$(GRAY)
LOG_MAJ	=	$(YELLOW)


#  -- Dirs
INCLUDES_DIRS	=	./include ./includes ./inc ./ ../../../../include
LIB_DIRS		=	./lib ./libs ./lib64 ./       ../../../../
SRC_DIR			=	src
BUILD_DIR		=	build

# -- Files
LIBS_LIST		=	$(shell find $(LIB_DIRS) -name "*.a" -type f -or \
							-name "*.so" -type f 2>/dev/null)
MAKE_SELF		=	$(abs_path $(lastword $(MAKEFILE_LIST)))
LOGFILE			=	compilation.log

# -- Flags
CPPFLGS			=\
				-MMD -MP
WFLAGS			=\
				-Wall -Wextra -Werror -Wno-unused-parameter \
				-Wmissing-prototypes
C_STD			=	c99
CXX_STD			=	c++98
INCLUDES		=	$(addprefix -I, $(INCLUDES_DIRS))

CFLAGS			:=	$(WFLAGS) -pedantic -std=$(C_STD) $(INCLUDES) $(CPP_FLAGS)
CXXFLAGS		:=	$(WFLAGS) -pedantic -std=$(CXX_STD) $(INCLUDES) $(CPP_FLAGS)
LIBS_LS			=	$(addprefix -L, $(LIB_DIRS))
LD_FLAGS		:=	$(LIBS_LS) $(addprefix -l:, $(notdir $(LIBS_LIST)))

DBG_FLAGS		:=	-g2 -ggdb -fno-inline -fno-inline-functions -DDEBUG
DEBUG_LEVEL		?=	0

# -- pure
TARGET_LANG	=	c
ifeq ($(TARGET_LANG),cpp)
	FLAGS	=	$(CXXFLAGS)
	COMP	=	$(CXX)
	CLGD_PREAMBLE := "CompileFlags:\n"	\
	"	- \"$(WFLAGS)\"\n" \
	"	- \"-std=$(CXX_STD)\"\n" \
	"	- \"-xcpp\"\n"
else ifeq ($(TARGET_LANG),c)
	FLAGS	=	$(CFLAGS)
	COMP	=	$(CC)
	CLGD_PREAMBLE := "CompileFlags:\n"	\
	"	- \"$(WFLAGS)\"\n" \
	"	- \"-std=$(C_STD)\"\n" \
	"	- \"-xc\"\n"
else
	$(error "TARGET_LANG must be either 'c' or 'cpp' but was '$(TARGET_LANG)'")
endif

ifeq ($(DEBUG_LEVEL),0)
	FLAGS	:=	$(FLAGS)
else
	FLAGS	:=	$(FLAGS)	$(DBG_FLAGS) -DDEBUG_LEVEL=$(DEBUG_LEVEL)
endif

NAME			=	parse_long_opt

# -- sources
OBJS			=	$(addprefix $(BUILD_DIR)/, $(patsubst %.c, %.o, $(SRCS)))
REQS			=	$(patsubst %.o, %.d, $(OBJS))
SRCS			=	$(shell find $(SRC_DIR) -name "*.c" -or -name "*.cpp" -type f 2>/dev/null)

# -- Rules
$(BUILD_DIR)/%.o:%.c
	@$(PRINT) "$(LOG_MIN)Compiling $(notdir $<)...$(RESET)" && \
	$(MKDIR) -p $(dir $@) 									&& \
	$(CC) $(FLAGS) -c $< -o $@ 2>> $(LOGFILE)				&& \
	$(PRINT) "$(OK)Success$(RESET)\n"						|| \
	$(PRINT) "$(KO)Fail$(RESET)\n"
$(BUILD_DIR)/%.o:%.cpp
	@$(PRINT) "$(LOG_MIN)Compiling $(notdir $<)...$(RESET)" && \
	$(MKDIR) -p $(dir $@)									&& \
	$(CXX) $(FLAGS) -c $< -o $@ 2>> $(LOGFILE)				&& \
	$(PRINT) "$(OK)Success$(RESET)\n"						|| \
	$(PRINT) "$(KO)Fail$(RESET)\n"
# -- Targets
-include $(REQS)
all:$(NAME)
print:
	@$(ECHO) $(OBJS)
	@$(ECHO) $(SRCS)

$(NAME): $(OBJS)
	@$(PRINT) "$(LOG_MAJ)Linking $(NAME)...$(RESET)"	&& \
	$(COMP) $(OBJS) $(FLAGS) -o $(NAME) $(LD_FLAGS)		&& \
	$(PRINT) "$(OK)Success$(RESET)\n"					|| \
	$(PRINT) "$(KO)Fail$(RESET)\n"
dbg_make:
	@$(ECHO) -e "$(LOG_MIN)SRCS:$(RESET)" $(SRCS)
	@$(ECHO) -e "$(LOG_MIN)OBJS:$(RESET)" $(OBJS)
	@$(ECHO) -e "$(LOG_MIN)REQS:$(RESET)" $(REQS)
	@$(ECHO) -e "$(LOG_MIN)CFLAGS:$(RESET)" $(CFLAGS)
	@$(ECHO) -e "$(LOG_MIN)CXXFLAGS:$(RESET)" $(CXXFLAGS)
	@$(ECHO) -e "$(LOG_MIN)LD_FLAGS:$(RESET)" $(LD_FLAGS)
	@$(ECHO) -e "$(LOG_MIN)MAKE_SELF:$(RESET)" $(MAKE_SELF)
clean:
	@$(PRINT) "$(LOG_MAJ)Cleaning build files...$(RESET)"	&& \
	$(RM) -rf $(BUILD_DIR) $(LOGFILE)						&& \
	$(PRINT) "$(OK)Success$(RESET)\n"						|| \
	$(PRINT) "$(KO)Fail$(RESET)\n"
fclean: clean
	@$(PRINT) "$(LOG_MAJ)Cleaning compiled files...$(RESET)"		&& \
	$(RM) -f $(NAME) 										&& \
	$(PRINT) "$(OK)Success$(RESET)\n"						|| \
	$(PRINT) "$(KO)Fail$(RESET)\n"
uclean: fclean
	@$(PRINT) "$(LOG_MAJ)Cleaning all dev files...$(RESET)"		&& \
	$(RM) -f .clangd $(LOGFILE) ./tags ./compile_commands.json	\
	.clang-format callgrind.* vgcore.*							&& \
	$(PRINT) "$(OK)Success$(RESET)\n"							|| \
	$(PRINT) "$(KO)Fail$(RESET)\n"
re: fclean all
re_env: uclean dev_env
tags: $(SRCS)
	@$(PRINT) "$(LOG_MAJ)Creating tags file...$(RESET)"					&& \
	ctags -R --languages=$(TARGET_LANG) --exclude=.git --exclude=build	\
	 $(prepend --exclude=, $(LIB_DIRS) $(INCLUDES_DIRS))				&& \
	$(PRINT) "$(OK)Success$(RESET)\n"									|| \
	$(PRINT) "$(KO)Fail$(RESET)\n"
.clangd: $(MAKE_SELF)
	@$(PRINT) "$(LOG_MAJ)Creating .clangd file...$(RESET)"		&& \
	$(ECHO) -n -e $(CLGD_PREAMBLE) > .clangd					&& \
	for dir in $(INCLUDES_DIRS); do								\
		$(ECHO) "	- \"-I"$(shell pwd)"/"$$dir"\"" >> .clangd;	\
	done														&& \
	$(PRINT) "$(OK)Success$(RESET)\n"							|| \
	$(PRINT) "$(KO)Fail$(RESET)\n"
.clang_format:
	$(PRINT) "$(LOG_MAJ)Setting up clang-format...$(RESET)"		&& \
	$(CP) $(shell echo $$DOTFILES_DIR)/base_clf .clang-format	&& \
	$(PRINT) "$(OK)Success$(RESET)\n"							|| \
	$(PRINT) "$(KO)Fail$(RESET)\n"
dev_env: .clangd tags $(MAKE_SELF)
	@$(PRINT) "$(LOG_MAJ)Creating development environment...$(RESET)\n"	&& \
	$(MAKE_SL) dbg_make													&& \
	$(PRINT) "$(OK)Success$(RESET)\n"									|| \
	$(PRINT) "$(KO)Fail$(RESET)\n"
.PHONY: all clean fclean re dbg_make
