
#include "ft_printf.h"

void		print_unsigned(t_conversion *conv, uintmax_t num)
{
	char	str[100];
	int		i;

	i = 99;
	str[i] = '\0';
	if (num > 0 || !conv->prec_set)
		str[--i] = '0' + (num % 10);
	while ((num /= 10) > 0)
		str[--i] = '0' + (num % 10);
	if (conv->precision > 99 - i)
		conv->flags->zero = 0;
	while (conv->precision > 99 - i)
		str[--i] = '0';
	if (conv->flags->zero && conv->sign)
	{
		pf_print(&(conv->sign), 1);
		conv->min_width--;
	}
	else if (conv->sign)
		str[--i] = conv->sign;
	print_num_spaced(conv, str + i);
}

void		print_octal(t_conversion *conv, uintmax_t num)
{
	char	str[100];
	int		i;

	i = 99;
	str[i] = '\0';
	if (num > 0 || !conv->prec_set)
		str[--i] = '0' + (num % 8);
	while ((num /= 8) > 0)
		str[--i] = '0' + (num % 8);
	if (conv->flags->hash && str[i] != '0')
		str[--i] = '0';
	while (conv->precision > 99 - i)
		str[--i] = '0';
	print_num_spaced(conv, str + i);
}

void		print_hex_low(t_conversion *conv, uintmax_t num)
{
	char	str[100];
	int		i;

	i = 99;
	str[i] = '\0';
	if (num > 0 || !conv->prec_set)
		str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16))
			: ('0' + (num % 16) + 39));
	while ((num /= 16) > 0)
		str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16))
			: ('0' + (num % 16) + 39));
	while (conv->precision > 99 - i)
		str[--i] = '0';
	if (conv->flags->zero && ((conv->flags->hash && i < 99 && str[98] != '0')
		|| conv->speci == 'p') && pf_print("0x", 2))
		conv->min_width -= 2;
	else if ((conv->flags->hash && i < 99 && str[98] != '0')
		|| conv->speci == 'p')
	{
		str[--i] = 'x';
		str[--i] = '0';
	}
	print_num_spaced(conv, str + i);
}

void		print_hex_up(t_conversion *conv, uintmax_t num)
{
	char	str[100];
	int		i;

	i = 99;
	str[i] = '\0';
	if (num > 0 || !conv->prec_set)
		str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16))
			: ('0' + (num % 16) + 7));
	while ((num /= 16) > 0)
		str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16))
			: ('0' + (num % 16) + 7));
	while (conv->precision > 99 - i)
		str[--i] = '0';
	if (conv->flags->zero && conv->flags->hash && str[i] != '0')
	{
		pf_print("0X", 2);
		conv->min_width -= 2;
	}
	if (conv->flags->hash && str[i] != '0')
	{
		str[--i] = 'X';
		str[--i] = '0';
	}
	print_num_spaced(conv, str + i);
}
