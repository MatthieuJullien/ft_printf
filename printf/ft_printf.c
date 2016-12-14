
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list			args;
	char			*str;

	if (format == NULL)
		die("ft_printf: format null where non-null required");
	va_start(args, format);
	str = (char *)format;
	while (*str != '\0')
	{

		//mettre dans un tableau de 1024 jusque 1024, \0 ou %
		//alors imprimer, clear la chaine, repartir du debut
		while (*str != '\0' && *str != '%')
			pf_print(str++, 1);
		if (*str == '%')
			str++;
		if (*str != '\0')
			str = print_conversion(str, args);
	}
	va_end(args);
	return (get_total(0, 1));	//true
}

void	die(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EOF);
}



int		get_total(int size, int is_end)
{
	static int	total = 0;

	if (is_end)
	{
		size = total;
		total = 0;
		return (size);
	}
	total += size;
	return (total);
}

int		pf_print(void *mem, int size)
{
	int		i;
	char	*str;

	str = mem;
	i = 0;
	while (i < size)
	{
		if (write(1, str + i, 1) == -1)
			die("ft_printf: write error");
		else
			get_total(1, 0);//false
		i++;
	}
	return (1);
}
