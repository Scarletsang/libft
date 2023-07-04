/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:38:55 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/07/04 17:32:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder/sb_iterator.h"

void	ft_sb_iterator_begin(t_ft_sb_iterator *iterator, \
const t_ft_sb *sb)
{
	ft_vector_iterator_begin(iterator, sb);
}

void	ft_sb_iterator_end(t_ft_sb_iterator *iterator, \
const t_ft_sb *sb)
{
	ft_vector_iterator_end(iterator, sb);
}

char	ft_sb_iterator_current(t_ft_sb_iterator *iterator)
{
	return (*(char *) ft_vector_iterator_current(iterator));
}
