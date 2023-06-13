/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:04:42 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:57:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/io.h"

static void	ft_putnbr_recurse(int n, int fd)
{
	if (n > 0)
	{
		ft_putnbr_recurse(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

/**
** @brief Write an int to the given file descripter.
**
** @param n:  the interger to be written to the file descripter
** @param fd: the file descripter
*/
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
