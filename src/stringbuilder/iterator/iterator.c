/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:38:55 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/13 15:28:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder/sb_iterator.h"

void	ft_sb_iterator_init(t_ft_sb_iterator *iterator, \
const t_ft_sb *sb)
{
	ft_vector_iterator_init(iterator, sb);
}

int	ft_sb_iterator_next(t_ft_sb_iterator *iterator)
{
	return (ft_vector_iterator_next(iterator));
}

int	ft_sb_iterator_prev(t_ft_sb_iterator *iterator)
{
	return (ft_vector_iterator_prev(iterator));
}

char	ft_sb_iterator_current(t_ft_sb_iterator *iterator)
{
	return (*(char *) ft_vector_iterator_current(iterator));
}

bool	ft_sb_iterator_is_end(t_ft_sb_iterator *iterator)
{
	return (ft_vector_iterator_is_end(iterator));
}
