/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:42:04 by htsang            #+#    #+#             */
/*   Updated: 2022/05/09 21:30:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	number;
	int			sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		number = number * 10 + (*str - '0');
		if (sign == -1 && number < 0)
			return (0);
		if (sign == 1 && number < 0)
			return (-1);
		str++;
	}
	return ((int) number * sign);
}
