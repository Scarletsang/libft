/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:42:04 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:53:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/general.h"

/**
** @brief converts a string into an int.
**
** @details When the number overflow at the long long
** level, the number will became negative, it returns 
** 0 or -1 depending on the size. Overflow on the int
** level is handled by the casting at the end.
** 
** @param str: the string that represents a number,
** multiple spaces, follow by one '-' or '+', is allowed.
** @return the int after convertion
*/
int	ft_atoi(const char *str)
{
	long long	number;
	int			sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		number = number * 10 + (*str - '0');
		if (number < 0)
		{
			if (sign == -1)
				return (0);
			if (sign == 1)
				return (-1);
		}
		str++;
	}
	return ((int) number * sign);
}
