##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

LIBMY = libmy.a

SRC = mini_printf.c \
      char_star_star_len.c \
      my_compute_power_rec.c \
	  my_compute_square_root.c \
	  my_find_prime_sup.c \
	  my_getnbr.c \
	  my_isneg.c \
	  my_isprime.c \
	  my_put_nbr.c \
	  my_putchar.c \
	  my_putstr.c \
	  my_revstr.c \
	  my_showmem.c \
	  my_showstr.c \
	  my_sort_int_array.c \
	  my_str_isalpha.c \
	  my_str_islower.c \
	  my_str_isnum.c \
	  my_str_isprintable.c \
	  my_str_isupper.c \
	  my_str_to_word_array.c \
	  my_strcapitalize.c \
	  my_strcat.c \
	  my_strcmp.c \
	  my_strcpy.c \
	  my_strstr.c \
	  my_strupcase.c \
	  my_strlen.c \
	  my_strlowcase.c \
	  my_strncat.c \
	  my_strncmp.c \
	  my_strncpy.c \
	  my_swap.c \
	  print_char_star_star.c \
	  tty_check.c \
	  my_strdup.c \
	  my_put_str_error.c \
	  my_isnumber.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I../../include

all: $(LIBMY)

$(LIBMY): $(OBJ)
	ar rc $(LIBMY) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(LIBMY)

re: fclean all
