/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iostream.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:20:31 by htsang            #+#    #+#             */
/*   Updated: 2023/06/18 20:59:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"

int	test_ft_iostream_read_until(const char **user_input)
{
	struct s_ft_iostream	iostream;
	char					*str;
	int						read_status;

	if (ft_iostream_init(&iostream))
		return (EXIT_FAILURE);
	read_status = ft_iostream_read_until(\
		&iostream, STDIN_FILENO, user_input[0]);
	if (read_status == -1)
	{
		printf("internal error, mostly from read()\n");
		ft_iostream_free(&iostream);
		return (EXIT_FAILURE);
	}
	else if (read_status == EXIT_FAILURE)
	{
		printf("ft_iostream_read_until() cannot find [%s]\n", user_input[0]);
		ft_iostream_free(&iostream);
		return (EXIT_FAILURE);
	}
	str = ft_string_slice_to_cstring(ft_iostream_to_slice(&iostream));
	if (!str)
	{
		printf("Nothing is read\n");
		ft_iostream_free(&iostream);
		return (EXIT_FAILURE);
	}
	printf("read result: [%s]\n", str);
	ft_iostream_free(&iostream);
	return (EXIT_SUCCESS);
}
