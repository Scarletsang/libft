/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iostream.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:25:51 by htsang            #+#    #+#             */
/*   Updated: 2023/06/21 10:05:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/iostream.h"

int	ft_iostream_init(struct s_ft_iostream *iostream)
{
	if (ft_sb_init(&iostream->sb, IOSTREAM_BUFFER_SIZE))
		return (EXIT_FAILURE);
	ft_sb_clipper_init(&iostream->clipper, &iostream->sb);
	return (EXIT_SUCCESS);
}

void	ft_iostream_reset(struct s_ft_iostream *iostream)
{
	ft_sb_reset(&iostream->sb);
	ft_sb_clipper_init(&iostream->clipper, &iostream->sb);
}

void	ft_iostream_free(struct s_ft_iostream *iostream)
{
	ft_sb_free(&iostream->sb);
}
