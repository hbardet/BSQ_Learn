##
## EPITECH PROJECT, 2022
## makefile
## File description:
## wow
##
SRCMY           =       ./libMy/my_compute_power_rec.c          \
                        ./libMy/my_compute_square_root.c        \
                        ./libMy/my_find_prime_sup.c             \
                        ./libMy/my_getnbr.c                     \
                        ./libMy/my_is_alpha.c                   \
                        ./libMy/my_is_alphanum.c                \
                        ./libMy/my_is_lower.c                   \
                        ./libMy/my_isneg.c                      \
                        ./libMy/my_is_prime.c                   \
                        ./libMy/my_is_upper.c                   \
                        ./libMy/my_putchar.c                    \
                        ./libMy/my_put_float.c                  \
                        ./libMy/my_put_nbr.c                    \
                        ./libMy/my_putstr.c                     \
                        ./libMy/my_revstr.c                     \
                        ./libMy/my_showmem.c                    \
                        ./libMy/my_showstr.c                    \
                        ./libMy/my_show_word_array.c            \
                        ./libMy/my_sort_int_array.c             \
                        ./libMy/my_strcapitalize.c              \
                        ./libMy/my_strcat.c                     \
                        ./libMy/my_strcmp.c                     \
                        ./libMy/my_strcpy.c                     \
                        ./libMy/my_strdup.c                     \
                        ./libMy/my_str_isalpha.c                \
                        ./libMy/my_str_islower.c                \
                        ./libMy/my_str_isnum.c                  \
                        ./libMy/my_str_isprintable.c            \
                        ./libMy/my_str_isupper.c                \
                        ./libMy/my_strlen.c                     \
                        ./libMy/my_strlowcase.c                 \
                        ./libMy/my_strncat.c                    \
                        ./libMy/my_strncmp.c                    \
                        ./libMy/my_strncpy.c                    \
                        ./libMy/my_strstr.c                     \
                        ./libMy/my_str_to_word_array.c          \
                        ./libMy/my_strupcase.c                  \
                        ./libMy/my_swap.c

SRCPRINTF       =	./my_printf/my_specifier/my_specifier_b.c	\
                        ./my_printf/my_specifier/my_specifier_b_copy.c	\
			./my_printf/my_specifier/my_specifier_c.c	\
			./my_printf/my_specifier/my_specifier_d.c	\
			./my_printf/my_specifier/my_specifier_e.c	\
			./my_printf/my_specifier/my_specifier_e_copy.c	\
			./my_printf/my_specifier/my_specifier_e_value.c	\
			./my_printf/my_specifier/my_specifier_f.c	\
			./my_printf/my_specifier/my_specifier_f_value.c	\
			./my_printf/my_specifier/my_specifier_g_value.c	\
			./my_printf/my_specifier/my_specifier_g.c	\
			./my_printf/my_specifier/my_specifier_o.c	\
			./my_printf/my_specifier/my_specifier_p.c	\
			./my_printf/my_specifier/my_specifier_percent.c \
			./my_printf/my_specifier/my_specifier_s.c	\
			./my_printf/my_specifier/my_specifier_u.c	\
			./my_printf/my_specifier/my_specifier_x.c	\
  			./my_printf/my_specifier/my_specifier_x_copy.c  \
                        ./my_printf/my_count_nbr.c                      \
			./my_printf/my_printf_flags_one.c               \
			./my_printf/my_printf.c                         \
			./my_printf/my_printf_specifiers.c              \
                        ./my_printf/my_printf_width.c                   \
                        ./my_printf/my_printf_precision.c


SRC       =     $(SRCMY)        \
                $(SRCPRINTF)

OBJ	  =	$(SRC:.c=.o)

NAME 	  =	libmy.a

all: 	libmy.a

libmy.a:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re :	fclean
	make all
