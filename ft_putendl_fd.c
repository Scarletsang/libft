/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:02:48 by htsang            #+#    #+#             */
/*   Updated: 2022/10/24 13:26:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/* write string + new line */
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
	{
		return ;
	}
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
