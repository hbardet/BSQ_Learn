/*
** EPITECH PROJECT, 2022
** all my lib
** File description:
** lib.h
*/
#include <stdarg.h>
#ifndef my_lib_
    #define my_lib_
void my_putchar(char c);
char my_str_continue(char *str, char const *to_find,int i);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int compare_ascii(char const *s1, char const *s2);
int my_strcmp(char const *s1, char const *s2);
void my_print_int(int nb);
int my_put_nbr(int nb);
int compare_ascii_n(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
void my_putchar_nonprintable(char str);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_put_hex_without_null(int nb);
void my_put_adress(int adress);
int my_put_hexchar(char const *str, int j);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_isalphanumeric(char str);
void loop(char const *str, char **string);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char const *str);
char *my_strdup ( char const *src );
/* MY_PRINTF_H */
int my_printf(const char *format , ...);
/* MY_PRINTF_H*/
#endif
