/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:10:42 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/17 15:13:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder/clipper.h"
#include "LIBFT/stringbuilder/sb_iterator.h"
#include "../stringbuilder_internal.h"

void	ft_sb_clipper_init(struct s_ft_sb_clipper *clipper, const t_ft_sb *sb)
{
	clipper->sb = sb;
	clipper->lbound = 0;
	clipper->rbound = sb->size - 1;
}

char	ft_sb_clipper_at_lbound(const struct s_ft_sb_clipper *clipper)
{
	return (ft_sb_get(clipper->sb, clipper->lbound));
}

char	ft_sb_clipper_at_rbound(const struct s_ft_sb_clipper *clipper)
{
	return (ft_sb_get(clipper->sb, clipper->rbound));
}
