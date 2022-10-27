/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:02:48 by htsang            #+#    #+#             */
/*   Updated: 2022/10/27 18:01:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** @brief write a string and a new line character
** to the given file descripter.
**
** @param str:  a NULL-terminated string
** @param fd: the file descripter
*/
void	ft_putendl_fd(char *str, int fd)
{
	if (!str)
	{
		return ;
	}
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}
