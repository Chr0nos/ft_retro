NAME=ft_retro
FLAGS=-Wall -Werror -Wextra -Weverything -std=c++98
CC=clang++
OBJS=main.o Display.class.o
LINKER=-lncurses

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(LINKER) -o $(NAME) $(OBJS)

%.o: srcs/%.cpp
	$(CC) $(FLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)


re: fclean all
