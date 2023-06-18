/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:28:52 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/18 19:35:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder/clipper.h"
#include "../stringbuilder_internal.h"

static int	sb_clipper_area_left(struct s_ft_sb_clipper *clipper, \
const char *start_match)
{
	size_t	i;
	size_t	j;

	i = clipper->lbound;
	while (i < clipper->rbound)
	{
		j = 0;
		while (start_match[j] && (i + j < clipper->rbound))
		{
			if (ft_sb_get(clipper->sb, i + j) != start_match[j])
				break ;
			j++;
		}
		if (!start_match[j])
		{
			clipper->lbound = i;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

static int	sb_clipper_area_right(struct s_ft_sb_clipper *clipper, \
const char *end_match)
{
	char	*end;

	end = ft_strnstr((const char *)clipper->sb->buffer + clipper->lbound, \
		end_match, clipper->rbound - clipper->lbound);
	if (!end)
		return (EXIT_FAILURE);
	clipper->rbound = end - (const char *)clipper->sb->buffer;
	return (EXIT_SUCCESS);
}

int	ft_sb_clipper_area(struct s_ft_sb_clipper *clipper, \
const char *start_match, const char *end_match)
{
	size_t	lbound;
	size_t	rbound;

	lbound = clipper->lbound;
	rbound = clipper->rbound;
	if (start_match)
	{
		if (sb_clipper_area_left(clipper, start_match))
		{
			clipper->lbound = lbound;
			return (EXIT_FAILURE);
		}
	}
	if (end_match)
	{
		if (sb_clipper_area_right(clipper, end_match))
		{
			clipper->lbound = lbound;
			clipper->rbound = rbound;
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
