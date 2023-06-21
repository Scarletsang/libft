/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:19:07 by htsang            #+#    #+#             */
/*   Updated: 2023/06/21 10:01:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder.h"
#include "stringbuilder_internal.h"

int	ft_sb_init(t_ft_sb *sb, const size_t capacity)
{
	if (ft_vector_init(sb, sizeof(char), capacity + 1, ft_vector_copy_char))
		return (EXIT_FAILURE);
	ft_vector_set(sb, 0, "\0");
	sb->size = 1;
	return (EXIT_SUCCESS);
}

void	ft_sb_reset(t_ft_sb *sb)
{
	ft_vector_set(sb, 0, "\0");
	sb->size = 1;
}

int	ft_sb_resize(t_ft_sb *sb)
{
	return (ft_vector_resize(sb));
}

char	ft_sb_get(const t_ft_sb *sb, const size_t index)
{
	return (*(char *) ft_vector_get(sb, index));
}

void	ft_sb_free(t_ft_sb *sb)
{
	ft_vector_free(sb);
}
