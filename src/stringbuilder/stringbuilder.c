/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:19:07 by htsang            #+#    #+#             */
/*   Updated: 2023/06/12 12:52:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder.h"

int	sb_init(t_sb *sb, const size_t capacity)
{
	if (vector_init(sb, sizeof(char), capacity + 1, vector_set_char))
		return (EXIT_FAILURE);
	vector_set(sb, 0, "\0");
	sb->size = 1;
	return (EXIT_SUCCESS);
}

int	sb_resize(t_sb *sb)
{
	return (vector_resize(sb));
}

char	sb_get(const t_sb *sb, const size_t index)
{
	return (*(char *) vector_get(sb, index));
}

void	sb_free(t_sb *sb)
{
	vector_free(sb);
}
