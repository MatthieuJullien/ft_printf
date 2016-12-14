
#include "ft_printf.h"

static void		print_chars(t_conversion *conv, char *str, int size)
{
	if (conv->prec_set && conv->speci == 's')
		size = (size < conv->precision ? size : conv->precision);
	if (conv->flags->minus)
	{
		pf_print(str, size);
		print_padding(size, conv->min_width, ' ');
		return ;
	}
	if (conv->flags->zero)
		print_padding(size, conv->min_width, '0');
	else
		print_padding(size, conv->min_width, ' ');
	pf_print(str, size);
}

void			print_char(t_conversion *conv, char c)
{
	print_chars(conv, &c, 1);
}

void			print_str(t_conversion *conv, char *str)
{
	if (!str)
		str = "(null)";
	print_chars(conv, str, ft_strlen(str));
}
