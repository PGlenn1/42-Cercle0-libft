void	ft_swap(char **str1, char **str2)
{
	char *tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}
