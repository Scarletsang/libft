/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iostream.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:25:51 by htsang            #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2023/06/26 02:23:24 by htsang           ###   ########.fr       */
=======
/*   Updated: 2023/06/26 23:07:34 by htsang           ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "LIBFT/iostream.h"

int	ft_iostream_init(struct s_ft_iostream *iostream)
{
	if (ft_sb_init(&iostream->sb, IOSTREAM_BUFFER_SIZE))
		return (EXIT_FAILURE);
	ft_sb_iterator_init(&iostream->iterator, &iostream->sb);
	iostream->delimiter_size = 0;
	iostream->read_size = 0;
	return (EXIT_SUCCESS);
}

void	ft_iostream_reset(struct s_ft_iostream *iostream)
{
<<<<<<< Updated upstream
	ft_sb_perform(&iostream->sb, \
		ft_sb_action_delete(0, \
			iostream->iterator.index + iostream->delimiter_size));
=======
	if (iostream->sb.size > 1)
		ft_sb_perform(&iostream->sb, \
			ft_sb_action_delete(0, \
				iostream->iterator.index + iostream->delimiter_size));
>>>>>>> Stashed changes
	ft_sb_iterator_init(&iostream->iterator, &iostream->sb);
	iostream->delimiter_size = 0;
	iostream->read_size = 0;
}

void	ft_iostream_free(struct s_ft_iostream *iostream)
{
	ft_sb_free(&iostream->sb);
}
