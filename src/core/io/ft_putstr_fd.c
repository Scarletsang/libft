/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:04:42 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 15:19:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/io.h"
#include "LIBFT/string.h"

/**
** @brief Write a string to the given file descripter.
**
** @param str:  a NULL-terminated string
** @param fd: the file descripter
*/
void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
	{
		return ;
	}
	write(fd, str, ft_strlen(str));
}
