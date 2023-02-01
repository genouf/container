NAME = std_test
NAME2 = ft_test

SRC_PATH = src/
OBJ_PATH = obj/

SRC_NAME =	std_test.cpp				
SRC_NAME2 =	test_mandatory.cpp					

OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ_NAME2 = $(SRC_NAME2:.cpp=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
SRC2 = $(addprefix $(SRC_PATH),$(SRC_NAME2))
OBJ2 = $(addprefix $(OBJ_PATH),$(OBJ_NAME2))
INC = -I inc
 
CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98
RM = @rm -rf

all: $(NAME) $(NAME2)

$(NAME): Makefile $(OBJ)
		@echo "Build $(NAME)"
		@$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME) $(LIBS) -MMD

$(NAME2): Makefile $(OBJ2)
		@echo "Build $(NAME2)"
		@$(CC) $(FLAGS) $(INC) $(OBJ2) -o $(NAME2) $(LIBS) -MMD

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
		mkdir -p $(@D)
		$(CC) $(FLAGS) $(INC) -MMD -o $@ -c $<

clean:
		$(RM) $(OBJ_PATH)

fclean:	clean
		$(RM) $(NAME) $(NAME2)
	
re:	fclean
	make all

.PHONY: all clean fclean re