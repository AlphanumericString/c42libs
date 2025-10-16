# no name as theres currently nothing needing to be compiled
# only templated code
NAME	= cpp42lib
TNAME	= cpp42lib_test
SRCS	=
TSRCS	=	tests.cpp
BUILD_DIR	=	build
TEST_DIR	=	tests_modules
.DEFAULT_GOAL	=	all

OBJS	= $(addprefix $(BUILD_DIR)/, $(patsubst %.cpp, %.o, $(SRCS)))
TOBJS	= $(addprefix $(BUILD_DIR)/$(TEST_DIR)/, $(patsubst %.cpp, %.o, $(TSRCS)))
REQS	=	$(patsubst %.o, %.d, $(TOBJ))	\
			$(patsubst %.o, %.d, $(OBJ))

CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -I./include -MMD -g3
RM		= $(shell which rm) -rf --

all:	lib$(NAME).a

-include: $(REQS)

$(BUILD_DIR)/%.o:%.cpp
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TEST_DIR)/%.o:$(TEST_DIR)/%.cpp
	@echo "Compiling test file: $<"
	@mkdir -p "$(BUILD_DIR)/$(TEST_DIR)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@


lib$(NAME).a:
	@echo -ne "no target to build\tcurrent lib only has templated code\n"

$(TNAME): $(TOBJS) $(REQS)
	@$(CXX) -o $@ $(CXXFLAGS) -std=c++98	$(TOBJS)
	@$(CXX) -o $@_11 $(CXXFLAGS) -std=c++11	$(TOBJS)
	@$(CXX) -o $@_17 $(CXXFLAGS) -std=c++17	$(TOBJS)

clean:
	@$(RM) $(BUILD_DIR)/*.o
fclean:	clean
	@$(RM) $(NAME) $(TNAME) $(TNAME)_11 $(TNAME)_17
	@$(RM) -- $(BUILD_DIR)
re:		fclean all

.PHONY:	all clean fclean re
