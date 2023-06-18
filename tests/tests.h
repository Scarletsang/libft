/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:00:58 by htsang            #+#    #+#             */
/*   Updated: 2023/06/18 20:26:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

#include "LIBFT/stringbuilder/clipper.h"
#include "LIBFT/iostream.h"

int	resource_init_stringbuilder_clipper(t_ft_sb *sb, const char *str);

int	test_ft_sb_clipper_area(const char **user_input);

int	test_ft_iostream_read_until(const char **user_input);

#endif
