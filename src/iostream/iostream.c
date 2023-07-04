/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iostream.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:25:51 by htsang            #+#    #+#             */
/*   Updated: 2023/07/04 17:26:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/iostream.h"

int	ft_iostream_init(struct s_ft_iostream *iostream)
{
	if (ft_sb_init(&iostream->sb, IOSTREAM_BUFFER_SIZE))
		return (EXIT_FAILURE);
	ft_sb_iterator_begin(&iostream->iterator, &iostream->sb);
	iostream->delimiter_size = 0;
	iostream->read_size = 0;
	return (EXIT_SUCCESS);
}

void	ft_iostream_reset(struct s_ft_iostream *iostream)
{
	ft_sb_perform(&iostream->sb, \
		ft_sb_action_delete(0, \
			iostream->iterator.index + iostream->delimiter_size));
	ft_sb_iterator_begin(&iostream->iterator, &iostream->sb);
	iostream->delimiter_size = 0;
	iostream->read_size = 0;
}

void	ft_iostream_free(struct s_ft_iostream *iostream)
{
	ft_sb_free(&iostream->sb);
}
