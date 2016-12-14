#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>
# include "libft.h"

typedef struct			s_flags
{
	int					zero;
	int					minus;
	int					plus;
	int					space;
	int					hash;
}						t_flags;

typedef enum			e_modifier
{
	NONE, HH, H, LL, L, J, Z
}						t_modifier;

typedef struct			s_conversion
{
	t_flags				*flags;
	int					min_width;
	int					precision;
	int					prec_set;
	t_modifier			modif;
	char				speci;
	char				sign;
}						t_conversion;

int						ft_printf(const char *format, ...);
void					die(char *str);

t_conversion			*conv_factory();
char					*print_conversion(char *str, va_list args);
char					*parse_conversion(char *str, t_conversion *conv, va_list args);
void					del_conversion(t_conversion *conv);

intmax_t				get_conv_signed(t_conversion *conv, va_list args);
uintmax_t				get_conv_unsigned(t_conversion *conv, va_list args);

void					print_unsigned(t_conversion *conv, uintmax_t num);
void					print_octal(t_conversion *conv, uintmax_t num);
void					print_hex_low(t_conversion *conv, uintmax_t num);
void					print_hex_up(t_conversion *conv, uintmax_t num);

void					print_wint(wint_t wint);
void					print_char(t_conversion *conv, char c);
void					print_wchar(t_conversion *conv, wint_t wint);
void					print_str(t_conversion *conv, char *str);
void					print_wstr(t_conversion *conv, wchar_t *wstr);

int						get_total(int size, int is_end);
int						pf_print(void *mem, int size);
void					print_padding(int len, int min, char c);
void					print_num_spaced(t_conversion *conv, char *str);

#endif
