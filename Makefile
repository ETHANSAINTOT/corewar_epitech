##
## EPITECH PROJECT, 2023
## myrpg
## File description:
## Makefile
##

CC = gcc

SRC		=	src/op.c\
			src/main.c\
			src/free_corewar.c\
			src/write_mem.c\
			src/read_args.c\
			src/check_dead_number.c\
			src/load_robots.c\
			src/fight.c\
			src/functions/live.c\
			src/functions/aff.c\
			src/functions/ld.c\
			src/functions/st.c\
			src/functions/add.c\
			src/functions/sub.c\
			src/functions/and.c\
			src/functions/or.c\
			src/functions/xor.c\
			src/functions/zjmp.c\
			src/functions/lld.c\
			src/functions/ldi.c\
			src/functions/sti.c\
			src/functions/lldi.c\
			src/functions/fork.c\
			src/functions/lfork.c\
			src/mini_printf.c\
			src/args.c\
			src/process_fork.c\

OBJ	=	$(SRC:src/%.c=obj/%.o)

NAME    =	corewar

CFLAGS	+=	-Wall -Wextra -I./include

LDFLAGS = -lncurses


all: 	$(NAME)

$(NAME):	 $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf obj
	rm -f vgcore*

fclean: clean
	rm -f $(NAME)

run: all running fclean

running:
	./$(NAME)

re:		clean all
