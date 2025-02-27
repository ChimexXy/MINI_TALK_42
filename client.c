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
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while(s1[i])
		ret[m++] = s1[i++];
	while(s2[j])
		ret[m++] = s2[j++];
	ret[m] = '\0';
	return(ret);
}


char *dicmal_to_bin(char c)
{
	int i = 0;
	int j = 7;
	char *ret;

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
	int i;
	int j;
	char *ret;

	i = 0;
	j = 0;
	ret = "";
	while(str[i])
	{
		
	}
}

int main(int ac, char **av)
{
	if (ac > 3)
		return;
	int i;

	i = 0;
	while(av[i])
	{

	}
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