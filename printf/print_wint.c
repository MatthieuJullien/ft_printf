
//#include "ft_printf.h"
#include <unistd.h>
#include <wchar.h>
int		pf_printmem(void *mem, int size)
{
	char	*str;

	str = mem;
		write(1, str, size);
	return (1);
}
void		print_wint(wint_t wint)
{
	char	str[4];

	if (wint <= 0x7F)
		pf_print(&wint, 1);							//0.......
	else if (wint <= 0x7FF)
	{
		str[0] = (((wint & 0x07C0) >> 6) + 0xC0);	//110.....
		str[1] = ((wint & 0x003F) + 0x80);			//10......
		pf_print(str, 2);
	}
	else if (wint <= 0xFFFF)
	{
		str[0] = (((wint & 0xF000) >> 12) + 0xE0);	//1110....
		str[1] = (((wint & 0x0FC0) >> 6) + 0x80);	//10......
		str[2] = ((wint & 0x003F) + 0x80);			//10......
		pf_print(str, 3);
	}
	else if (wint <= 0x10FFFF)
	{
		str[0] = (((wint & 0x1C0000) >> 18) + 0xF0);//11110...
		str[1] = (((wint & 0x03F000) >> 12) + 0x80);//10......
		str[2] = (((wint & 0x0FC0) >> 6) + 0x80);	//10......
		str[3] = ((wint & 0x003F) + 0x80);			//10......
		pf_print(str, 4);
	}
}



int		main()
{
	print_wint((wint_t)L'€');
	return 0;
}
