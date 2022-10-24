/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:04:42 by htsang            #+#    #+#             */
/*   Updated: 2022/10/24 13:26:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static void	ft_putnbr_recurse(int n, int fd)
{
	if (n > 0)
	{
		ft_putnbr_recurse(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

/* write int */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	ft_putnbr_recurse(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
