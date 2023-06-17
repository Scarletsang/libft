/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:05:15 by htsang            #+#    #+#             */
/*   Updated: 2023/06/17 16:54:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "LIBFT/iostream.h"

int	ft_iostream_read(struct s_ft_iostream *iostream, int fd)
{
	while (iostream->sb.capacity - iostream->sb.size < IOSTREAM_BUFFER_SIZE)
	{
		if (ft_sb_resize(&iostream->sb))
			return (EXIT_FAILURE);
	}
	iostream->read_size = read(fd, \
		ft_vector_get(&iostream->sb, iostream->sb.size - 1), \
			IOSTREAM_BUFFER_SIZE);
	iostream->sb.size += (size_t) iostream->read_size;
	if (iostream->read_size < 0)
		return (EXIT_FAILURE);
	iostream->clipper.rbound += (size_t) iostream->read_size;
	return (EXIT_SUCCESS);
}

static int	ft_iostream_find_end_match(struct s_ft_iostream *iostream, \
const char **match, const char *end_match)
{
	size_t	lbound_reset;

	while (true)
	{
		*match = end_match;
		lbound_reset = iostream->clipper.lbound;
		while (ft_sb_clipper_at_lbound(&iostream->clipper) == **match)
		{
			(*match)++;
			if (ft_sb_clipper_move_lbound(&iostream->clipper))
				break ;
		}
		if (ft_sb_clipper_move_lbound(&iostream->clipper))
			break ;
	}
	if (!**match)
	{
		iostream->clipper.lbound = 0;
		iostream->clipper.rbound = lbound_reset - 1;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	ft_iostream_read_until(struct s_ft_iostream *iostream, int fd, \
const char *end_match)
{
	const char	*match;

	if (ft_iostream_read(iostream, fd))
		return (-1);
	match = end_match;
	while (true)
	{
		if (!ft_iostream_find_end_match(iostream, &match, end_match))
			return (EXIT_SUCCESS);
		if (match == end_match && ft_iostream_read(iostream, fd))
			return (-1);
		if (ft_sb_clipper_move_lbound(&iostream->clipper))
			break ;
	}
	return (EXIT_FAILURE);
}

t_ft_string_slice	ft_iostream_to_slice(struct s_ft_iostream *iostream)
{
	return (ft_sb_clipper_slice(&iostream->clipper));
}
