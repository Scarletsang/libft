/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:37:13 by htsang            #+#    #+#             */
/*   Updated: 2022/10/22 16:04:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_count_itoa_size(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static unsigned int	ft_abs(int n)
{
	if (n >= 0)
	{
		return ((unsigned int) n);
	}
	return ((unsigned int) -n);
}

/* Allocate memory for a string that represents the given int. */
char	*ft_itoa(int n)
{
	size_t	count;
	char	*str;

	count = ft_count_itoa_size(ft_abs(n));
	if (n < 0)
		count++;
	str = (char *) malloc(count + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		*str = '-';
	str[count--] = 0;
	if (n == INT32_MIN)
	{
		str[count--] = '8';
		n /= 10;
	}
	n = ft_abs(n);
	while (n / 10 > 0)
	{
		str[count--] = n % 10 + '0';
		n /= 10;
	}
	str[count] = n % 10 + '0';
	return (str);
}