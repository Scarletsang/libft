/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:29:12 by htsang            #+#    #+#             */
/*   Updated: 2023/07/04 17:30:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder/sb_iterator.h"

bool	ft_sb_iterator_has_next(const t_ft_sb_iterator *iterator)
{
	return (ft_vector_iterator_has_next(iterator));
}

bool	ft_sb_iterator_has_prev(const t_ft_sb_iterator *iterator)
{
	return (ft_vector_iterator_has_prev(iterator));
}

int	ft_sb_iterator_next(t_ft_sb_iterator *iterator)
{
	return (ft_vector_iterator_next(iterator));
}

int	ft_sb_iterator_prev(t_ft_sb_iterator *iterator)
{
	return (ft_vector_iterator_prev(iterator));
}
