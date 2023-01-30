NAME = ft_containers

SRC_PATH = src/
OBJ_PATH = obj/

SRC_NAME =	map_test.cpp				\

OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = -I inc
 
CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98
RM = @rm -rf

DEPS_NAME = $(SRC_NAME:.cpp=.d)
DEPS = $(addprefix $(OBJ_PATH),$(DEPS_NAME))

all: $(NAME)

$(NAME): Makefile $(OBJ)
		@echo "Build $(NAME)"
		@$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME) $(LIBS) -MMD

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
		mkdir -p $(@D)
		$(CC) $(FLAGS) $(INC) -MMD -o $@ -c $<

-include $(DEPS)

clean:
		$(RM) $(OBJ_PATH)

fclean:	clean
		$(RM) $(NAME)
	
re:	fclean
	make all

.PHONY: all clean fclean re