#include "ft_printf.h"
#include "libft.h"

int		main()
{

	ft_printf("%12d\n", 45);
	ft_printf("%12d\n", -45);
	ft_printf("%012d\n", 45);
	ft_printf("%012d\n", -45);
	ft_printf("% 012d\n", 45);
	ft_printf("% 012d\n", -45);
	ft_printf("%+12d\n", 45);
	ft_printf("%+12d\n", -45);
	ft_printf("%-12d\n", 45);
	ft_printf("%-12d\n", -45);
	ft_printf("%- 12d\n", 45);
	ft_printf("%- 12d\n", -45);
	ft_printf("%-+12d\n", 45);
	ft_printf("%-+12d\n", -45);
	ft_printf("%12.4d\n", 45);
	ft_printf("%12.4d\n", -45);
	ft_printf("%-12.4d\n", 45);
	ft_printf("%-12.4d\n", -45);

	int len = ft_printf("%S", L"ابتثجحخدذرزسشصضطظعغفقكلمنهوي");
	printf("\nlen = %d\n", len);
	len = printf("%S", L"ابتثجحخدذرزسشصضطظعغفقكلمنهوي");
	printf("\nlen = %d\n", len);
	ft_printf("un pourcent: %%\n", "BOnjour");

	return 0;
}


