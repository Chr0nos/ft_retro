NAME=ft_retro
FLAGS=-Wall -Werror -Wextra -Weverything -Wno-padded -std=c++98
CC=clang++
OBJS=main.o Display.class.o Position.class.o Entity.class.o Obstacle.class.o \
	Game.class.o IBullet.class.o Gun.class.o Player.class.o BulletHolder.class.o
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
