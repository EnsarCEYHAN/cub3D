NAME	:= cub3D

FLAGS	:= -Wall -Wextra -Werror -g

CC		:= gcc
RM		:= rm -rf

SRC		:=	main.c\
			map_scan.c\
			utils.c

LIBFT	:= Libft/libft.a
GNL     := GNL/gnl.a
OBJ		:= $(SRC:.cpp=.o)

RED		:= \033[31m
GREEN	:= \033[32m
YELLOW	:= \033[33m
BLUE	:= \033[34m
MAGENTA	:= \033[35m
CYAN	:= \033[36m
RESET	:= \033[0m

CC_MSG		:= @printf "$(CYAN)$(CC)$(RESET) $(YELLOW)$(FLAGS)$(RESET) $(MAGENTA)$(OBJ)$(RESET) -o $(GREEN)$(NAME)$(RESET)\n"
SUCCESS_MSG	:= @printf "$(GREEN)$(NAME) has been compiled$(RESET)\n"
CLEAN_MSG 	:= printf "$(RED)Object files removed$(RESET)\n"
FCLEAN_MSG	:= printf "Executable $(RED)$(NAME)$(RESET) removed\n"
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(GNL) -o $(NAME)
	$(CC_MSG)
	$(SUCCESS_MSG)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@if [ -n "$(wildcard *.o)" ]; then \
		$(RM) $(OBJ); \
		$(CLEAN_MSG); \
	fi

fclean: clean
	@if [ -n "$(wildcard $(NAME))" ]; then \
		$(RM) $(NAME); \
		$(FCLEAN_MSG); \
	fi

re: fclean all

.PHONY: all clean fclean re