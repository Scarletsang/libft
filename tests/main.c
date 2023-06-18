/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:00:44 by htsang            #+#    #+#             */
/*   Updated: 2023/06/18 22:48:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "tests.h"

int main(int argc, const char **argv)
{
	if (argc < 2)
		return (EXIT_FAILURE);
	printf("test: [%s]\n", argv[1]);
	// return (test_ft_sb_clipper_area(argv + 1));
	return (test_ft_iostream_read_until(argv + 1));
}
