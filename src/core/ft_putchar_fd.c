/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:00:29 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 15:08:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
** @brief Write a byte to the given file descripter.
**
** @param c:  the byte
** @param fd: the file descripter
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
