#include "minitalk.h"

int bin_to_dicmal(char *str)
{
	int i;
	int j;
	int ret;

	i = 0;
	j = 128;
	ret = 0;
	while(str[i])
	{
		if(str[i] == '1')
			ret = ret + j;
		j = j / 2;
		i++;
	}
	return (ret);
}

// int main()
// {
// 	ft_printf("%d\n", bin_to_dicmal("10100110"));
// }