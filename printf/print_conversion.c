
#include "ft_printf.h"

static void		change_equivalent_speci(t_conversion *conv)
{

	if (conv->speci == 'i')
		conv->speci = 'd';
	else if (ft_strchr("DOU", conv->speci))
	{
		conv->modif = L;
		conv->speci = ft_tolower(conv->speci);
	}
	else if (conv->speci == 'p')
	{
		conv->modif = L;
		conv->flags->hash = 1;
	}
}

static void		print_num_conv(t_conversion *conv, va_list args)
{
	intmax_t	num;

	change_equivalent_speci(conv);
	if (conv->speci == 'd')
	{
		num = get_conv_signed(conv, args);
		if (num < 0 && (num *= -1))
			conv->sign = '-';
		else if (conv->flags->plus)
			conv->sign = '+';
		else if (conv->flags->space)
			conv->sign = ' ';
	}
	else
		num = get_conv_unsigned(conv, args);
	if (ft_strchr("du", conv->speci))
		print_unsigned(conv, (uintmax_t)num);
	else if (conv->speci == 'o')
		print_octal(conv, (uintmax_t)num);
	else if (ft_strchr("xp", conv->speci))
		print_hex_low(conv, (uintmax_t)num);
	else if (conv->speci == 'X')
		print_hex_up(conv, (uintmax_t)num);
}

static void		print_str_conv(t_conversion *conv, va_list args)
{
	if (ft_strchr("CS", conv->speci))
	{
		conv->modif = L;
		conv->speci = ft_tolower(conv->speci);
	}
	if (conv->modif == L)
	{
		if (conv->speci == 'c')
			print_wchar(conv, va_arg(args, wint_t));
		else if (conv->speci == 's')
			print_wstr(conv, va_arg(args, wchar_t*));
		else
			print_char(conv, conv->speci);
	}
	else
	{
		if (conv->speci == 'c')
			print_char(conv, va_arg(args, int));
		else if (conv->speci == 's')
			print_str(conv, va_arg(args, char*));
		else
			print_char(conv, conv->speci);
	}
}

t_conversion	*conv_factory(void)
{
	t_conversion	*conv;

	if (!(conv = ft_memalloc(sizeof(t_conversion))))
		die("ft_printf: allocation failed");
	if (!(conv->flags = ft_memalloc(sizeof(t_flags))))
		die("ft_printf: allocation failed");
	conv->modif = NONE;
	return (conv);
}

char			*print_conversion(char *str, va_list args)
{
	t_conversion	*conv;

	conv = conv_factory();
	str = parse_conversion(str, conv, args);
	if (ft_strchr("idDoOuUxXp", conv->speci))
		print_num_conv(conv, args);
	else
		print_str_conv(conv, args);
	free(conv->flags);
	free(conv);
	return (str);
}
