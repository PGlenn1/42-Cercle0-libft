/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:33:05 by gpiriou           #+#    #+#             */
/*   Updated: 2021/01/06 14:33:50 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_n(int n)
{
	int len_n;
	int n_parsed;

	len_n = 1;
	n_parsed = n;
	while (n_parsed / 10 != 0)
	{
		n_parsed = n_parsed / 10;
		len_n++;
	}
	if (n < 0)
		len_n++;
	return (len_n);
}

char		*ft_itoa(int n)
{
	int		i;
	int		len_n;
	int		n_parsed;
	int		is_negative;
	char	*s;

	len_n = ft_len_n(n);
	n_parsed = n;
	is_negative = 0;
	if (!(s = malloc((len_n + 1) * sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_memcpy(s, "-2147483648",  12);
			return (s);
		}
		is_negative = 1;
		n_parsed *= -1;
	}
	i = 0;
	while (i < len_n)
	{
		s[len_n - 1 - i] = ((n_parsed % 10) + '0');
		n_parsed = n_parsed / 10;
		i++;
	}
	if (is_negative)
		s[0] = '-';
	s[i] = 0;
	return (s);
}

//int	main(int argc, char **argv)
//{
//	(void)argc;
//	(void)argv;
//	printf("result: %s\n", ft_itoa(-2147483648LL));
//	printf("result: %s\n", ft_itoa(-2147483648LL));
//}
