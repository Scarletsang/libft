/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:00:29 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 17:55:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** @brief write a byte to the given file descripter.
**
** @param c:  the byte
** @param fd: the file descripter
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
