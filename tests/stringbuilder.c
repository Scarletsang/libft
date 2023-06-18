/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:32:43 by htsang            #+#    #+#             */
/*   Updated: 2023/06/18 20:19:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"

int	resource_init_stringbuilder_clipper(t_ft_sb *sb, const char *str)
{
	if (ft_sb_init(sb, 10) || \
		ft_sb_perform(sb, ft_sb_action_append(str)))
	{
		ft_sb_free(sb);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	test_ft_sb_clipper_area(const char **user_input)
{
	t_ft_sb					sb;
	struct s_ft_sb_clipper	clipper;
	char					*str;

	if (resource_init_stringbuilder_clipper(&sb, user_input[0]))
		return (EXIT_FAILURE);
	ft_sb_clipper_init(&clipper, &sb);
	if (ft_sb_clipper_area(&clipper, user_input[1], user_input[2]))
	{
		printf("ft_sb_clipper_area() cannot find [%s] inside [%s]\n", \
			user_input[1], user_input[0]);
		ft_sb_free(&sb);
		return (EXIT_FAILURE);
	}
	str = ft_sb_clipper_run(&clipper);
	if (!str)
	{
		printf("Nothing is clipped\n");
		ft_sb_free(&sb);
		return (EXIT_FAILURE);
	}
	printf("clipped result: [%s]\n", str);
	free(str);
	ft_sb_free(&sb);
	return (EXIT_SUCCESS);
}
