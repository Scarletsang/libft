/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:05:15 by htsang            #+#    #+#             */
/*   Updated: 2023/07/07 06:33:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/iostream.h"
#include "LIBFT/string.h"

ssize_t	ft_iostream_read(struct s_ft_iostream *iostream, int fd)
{
	char	buffer[IOSTREAM_BUFFER_SIZE];

	iostream->read_size = read(fd, buffer, IOSTREAM_BUFFER_SIZE);
	if (iostream->read_size <= 0)
		return (iostream->read_size);
	if (ft_sb_perform(&iostream->sb, ft_sb_action_append(\
		ft_str_slice(buffer, 0, (size_t) iostream->read_size))))
		return (-1);
	return (iostream->read_size);
}

static int	ft_iostream_lookahead_delimiter(struct s_ft_iostream *iostream, \
int fd, t_ft_str delimiter)
{
	size_t	lookahead;
	size_t	delimiter_index;

	delimiter_index = 0;
	lookahead = iostream->iterator.index;
	while (ft_sb_get(&iostream->sb, lookahead) == \
		ft_str_as_ptr(&delimiter)[delimiter_index])
	{
		if ((delimiter_index + 1) == delimiter.size)
			return (EXIT_SUCCESS);
		if ((lookahead + 1) == iostream->sb.size)
		{
			if (ft_iostream_read(iostream, fd) <= 0)
				return (-1);
		}
		delimiter_index++;
		lookahead++;
	}
	return (EXIT_FAILURE);
}

int	ft_iostream_read_until_delimiter(struct s_ft_iostream *iostream, int fd, \
t_ft_str delimiter)
{
	int	lookahead_result;

	iostream->delimiter_size = delimiter.size;
	while (true)
	{
		while (iostream->iterator.is_end != VECTOR_ITERATOR_RIGHT_END)
		{
			lookahead_result = ft_iostream_lookahead_delimiter(iostream, fd, \
				delimiter);
			if (lookahead_result == EXIT_SUCCESS)
				return (EXIT_SUCCESS);
			else if (lookahead_result == -1)
				return (EXIT_FAILURE);
			ft_sb_iterator_next(&iostream->iterator);
		}
		if (ft_iostream_read(iostream, fd) <= 0)
			return (EXIT_FAILURE);
		ft_sb_iterator_prev(&iostream->iterator);
	}
}

int	ft_iostream_read_until(struct s_ft_iostream *iostream, int fd, \
t_ft_str match)
{
	int	return_value;

	return_value = ft_iostream_read_until_delimiter(iostream, fd, match);
	iostream->delimiter_size = 0;
	iostream->iterator.index += match.size;
	iostream->iterator.current = NULL;
	return (return_value);
}

t_ft_str	ft_iostream_to_slice(struct s_ft_iostream *iostream)
{
	if (iostream->iterator.index == 0)
		return ((t_ft_str){.content = NULL, .size = 0});
	return ((t_ft_str){\
		.content = iostream->sb.buffer, \
		.size = iostream->iterator.index});
}
