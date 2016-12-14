
#include "ft_printf.h"

static char	*parse_flags(char *str, t_flags *flags)
{
	while (ft_strchr("0-+ #", *str))
	{
		if (*str == '0')
			flags->zero = 1;
		else if (*str == '-')
			flags->minus = 1;
		else if (*str == '+')
			flags->plus = 1;
		else if (*str == ' ')
			flags->space = 1;
		else if (*str == '#')
			flags->hash = 1;
		str++;
	}
	if (*str == '\0')
		die("ft_printf: invalid format");
	return (str);
}

static char	*parse_min_width(char *str, t_conversion *conv, va_list args)
{
	if (*str == '*')
	{
		conv->min_width = va_arg(args, int);
		str++;
	}
	else
		conv->min_width = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		die("ft_printf: invalid format");
	return (str);
}

static char	*parse_precision(char *str, t_conversion *conv, va_list args)
{
	if (*str != '.')
		return (str);
	str++;
	if (*str == '*')
	{
		conv->precision = va_arg(args, int);
		conv->prec_set = 1;
		str++;
	}
	else
	{
		conv->precision = ft_atoi(str);
		conv->prec_set = 1;
	}
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		die("ft_printf: invalid format");
	return (str);
}

static char	*parse_modifier(char *str, t_conversion *conv)
{
	if (!ft_strchr("hljz", *str))
		return (str);
	if (ft_strncmp(str, "hh", 2) == 0)
	{
		conv->modif = HH;
		return (str + 2);
	}
	if (ft_strncmp(str, "ll", 2) == 0)
	{
		conv->modif = LL;
		return (str + 2);
	}
	else if (*str == 'h')
		conv->modif = H;
	else if (*str == 'l')
		conv->modif = L;
	else if (*str == 'j')
		conv->modif = J;
	else if (*str == 'z')
		conv->modif = Z;
	return (str + 1);
}

char		*parse_conversion(char *str, t_conversion *conv, va_list args)
{
	str = parse_flags(str, conv->flags);
	str = parse_min_width(str, conv, args);
	str = parse_precision(str, conv, args);
	str = parse_modifier(str, conv);
	if (*str == '\0')
		die("ft_printf: invalid format");
	if (!ft_strchr("idDoOuUxXpcCsS%", *str))
		die("ft_printf: invalid format");
	conv->speci = *str;
	return (str + 1);
}
