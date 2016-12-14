
#include "ft_printf.h"

intmax_t	get_conv_signed(t_conversion *conv, va_list args)
{
	if (conv->modif == HH)
		return ((char)va_arg(args, int));
	if (conv->modif == H)
		return ((short)va_arg(args, int));
	if (conv->modif == L)
		return (va_arg(args, long));
	if (conv->modif == LL)
		return (va_arg(args, long long));
	if (conv->modif == J)
		return (va_arg(args, intmax_t));
	if (conv->modif == Z)
		return (va_arg(args, ssize_t));
	return (va_arg(args, int));
}

uintmax_t	get_conv_unsigned(t_conversion *conv, va_list args)
{
	if (conv->modif == HH)
		return ((unsigned char)va_arg(args, unsigned int));
	if (conv->modif == H)
		return ((unsigned short)va_arg(args, unsigned int));
	if (conv->modif == L)
		return (va_arg(args, unsigned long));
	if (conv->modif == LL)
		return (va_arg(args, unsigned long long));
	if (conv->modif == J)
		return (va_arg(args, uintmax_t));
	if (conv->modif == Z)
		return (va_arg(args, size_t));
	return (va_arg(args, unsigned int));
}
