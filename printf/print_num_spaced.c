
#include "ft_printf.h"

void	print_padding(int len, int min, char c)
{
	while (min-- > len)
		pf_print(&c, 1);
}

static void	print_left(t_conversion *conv, char *str)
{
	pf_print(str, ft_strlen(str));
	print_padding(ft_strlen(str), conv->min_width, ' ');
}

void		print_num_spaced(t_conversion *conv, char *str)
{
	if (conv->flags->minus)
		return (print_left(conv, str));
	if (conv->flags->zero)
		print_padding(ft_strlen(str), conv->min_width, '0');
	else
		print_padding(ft_strlen(str), conv->min_width, ' ');
	pf_print(str, ft_strlen(str));
}
