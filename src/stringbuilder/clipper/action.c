/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:53:54 by htsang            #+#    #+#             */
/*   Updated: 2023/07/06 14:56:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/stringbuilder/clipper.h"

int	ft_sb_clipper_move_lbound(struct s_ft_sb_clipper *clipper)
{
	if ((clipper->lbound + 1) >= clipper->rbound)
		return (EXIT_FAILURE);
	clipper->lbound++;
	return (EXIT_SUCCESS);
}

int	ft_sb_clipper_move_rbound(struct s_ft_sb_clipper *clipper)
{
	if (clipper->rbound <= (clipper->lbound + 1))
		return (EXIT_FAILURE);
	clipper->rbound--;
	return (EXIT_SUCCESS);
}

char	*ft_sb_clipper_run(const struct s_ft_sb_clipper *clipper)
{
	return (ft_str_to_cstring(ft_sb_clipper_slice(clipper)));
}

t_ft_str	ft_sb_clipper_slice(\
const struct s_ft_sb_clipper *clipper)
{
	return ((t_ft_str){
		.content = clipper->sb->buffer + clipper->lbound,
		.size = clipper->rbound - clipper->lbound
	});
}
