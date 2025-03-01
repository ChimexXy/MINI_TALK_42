#include "minitalk.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	int m;
	char *ret;

	i = 0;
	j = 0;
	m = 0;
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	while(s1[i])
		ret[m++] = s1[i++];
	while(s2[j])
		ret[m++] = s2[j++];
	ret[m++] = ' ';
	ret[m] = '\0';
	return(ret);
}


char *dicmal_to_bin(char c)
{
	int i;
	int j;
	char *ret;

	i = 0;
	j = 7;
	ret = malloc(8 * sizeof(char) + 1);
	while(j >= 0)
	{
		if(((c >> j) & 1) == 1)
			ret[i] = '1';
		else
			ret[i] = '0';
	j--;
	i++;
	}
	ret[i] = '\0';
	return(ret);
}

char **encrypte_via_bit(char *av)
{
	// printf("%s\n", av);
	if (!av)
		exit(1);
	int i;
	int j;
	char **ret;

	i = 0;
	j = 0;
	ret = malloc(ft_strlen(av) * sizeof(char *) + 1);
	while(av[i])
	{
		ret[j] = dicmal_to_bin(av[i]);
		j++;
		i++;
	}
	return (ret);
}

char *join_bits(char **str)
{
	if(!str)
		exit(1);
	int i;
	int j;
	char *ret;

	i = 0;
	j = 0;
	ret = "";
	while(str[i])
	{
		ret = ft_strjoin(ret, str[i]);
		i++;
	}
	return (ret);
}

int main(int ac, char **av)
{
	if (ac > 3)
		exit(1);
	char **str = encrypte_via_bit(av[2]);
	char *str1 = join_bits(str);

	ft_printf("%s\n", str1);
	// int i;
	// char **res;

	// i = 0;
	// while(av[i])
	// {
	// 	res[i] = join_bits()
	// }
}




// int main()
// {
// 	printf("%s\n", dicmal_to_bin(97));

// }


// int main()
// {
// 	char *s1 = "hello";
// 	char *s2 = "world";
// 	printf("%s", ft_strjoin(s1, s2));
// }