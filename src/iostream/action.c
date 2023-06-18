/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:05:15 by htsang            #+#    #+#             */
/*   Updated: 2023/06/19 00:02:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
	if (iostream->read_size < 0)
		return (EXIT_FAILURE);
	iostream->sb.size += (size_t) iostream->read_size;
	iostream->clipper.rbound += (size_t) iostream->read_size;
	return (EXIT_SUCCESS);
}

static size_t	ft_iostream_find_end_match(struct s_ft_iostream *iostream, \
const char *end_match, const char **match, size_t lbound_reset)
{
	while (true)
	{
		while (ft_sb_clipper_at_lbound(&iostream->clipper) == **match)
		{
			(*match)++;
			if (ft_sb_clipper_move_lbound(&iostream->clipper))
				return (lbound_reset);
		}
		iostream->clipper.lbound = lbound_reset;
		lbound_reset++;
		*match = end_match;
		if (ft_sb_clipper_move_lbound(&iostream->clipper))
			break ;
	}
	return (lbound_reset);
}

int	ft_iostream_read_until(struct s_ft_iostream *iostream, int fd, \
const char *end_match)
{
	const char	*match;
	size_t		lbound_reset;

	if (ft_iostream_read(iostream, fd))
		return (-1);
	match = end_match;
	lbound_reset = iostream->clipper.lbound;
	while (true)
	{
		lbound_reset = ft_iostream_find_end_match(iostream, end_match, \
			&match, lbound_reset);
		if (!*match)
		{
			iostream->clipper.lbound = 0;
			iostream->clipper.rbound = lbound_reset;
			return (EXIT_SUCCESS);
		}
		if (ft_iostream_read(iostream, fd))
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
