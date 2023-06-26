/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:05:15 by htsang            #+#    #+#             */
/*   Updated: 2023/06/26 02:24:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/iostream.h"
#include "LIBFT/string.h"
#include <stdio.h>

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
	return (EXIT_SUCCESS);
}

static bool	ft_iostream_find_match(struct s_ft_iostream *iostream, \
t_ft_string_slice match, size_t *current_match, size_t *current_index)
{
	while (*current_match < match.size)
	{
		while (ft_sb_iterator_current(&iostream->iterator) == \
			ft_string_slice_content(&match)[*current_match])
		{
			(*current_match)++;
			if ((*current_match >= match.size) || \
				ft_sb_iterator_next(&iostream->iterator))
				return (true);
		}
		iostream->iterator.index = *current_index;
		iostream->iterator.current = NULL;
		(*current_index)++;
		*current_match = 0;
		if (ft_sb_iterator_next(&iostream->iterator))
			return (false);
	}
	return (true);
}

int	ft_iostream_read_until_delimiter(struct s_ft_iostream *iostream, int fd, \
t_ft_string_slice delimiter)
{
	size_t	current_match;
	size_t	current_index;
	int		return_value;

	current_match = 0;
	current_index = 0;
	return_value = EXIT_SUCCESS;
	while (!ft_iostream_find_match(iostream, delimiter, \
		&current_match, &current_index))
	{
		if ((ft_iostream_read(iostream, fd) == EXIT_FAILURE) || \
			ft_sb_iterator_next(&iostream->iterator))
		{
			return_value = EXIT_FAILURE;
			break ;
		}
	}
	iostream->delimiter_size = delimiter.size;
	iostream->iterator.index = current_index;
	iostream->iterator.current = NULL;
	return (return_value);
}

int	ft_iostream_read_until(struct s_ft_iostream *iostream, int fd, \
t_ft_string_slice match)
{
	int	return_value;

	return_value = ft_iostream_read_until_delimiter(iostream, fd, match);
	iostream->delimiter_size = 0;
	iostream->iterator.index += match.size;
	iostream->iterator.current = NULL;
	return (return_value);
}

t_ft_string_slice	ft_iostream_to_slice(struct s_ft_iostream *iostream)
{
	return ((t_ft_string_slice){\
		.content = iostream->sb.buffer, \
		.size = iostream->iterator.index});
}
