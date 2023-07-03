/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/03 00:05:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringbuilder_test.hpp"

void	SbTest::SetUp()
{
	ft_sb_init(&sb, 20);
}

void	SbTest::TearDown()
{
	ASSERT_EQ(((char *) sb.buffer)[sb.size - 1], '\0');
	ASSERT_GE(sb.size, (size_t) 1);
	ASSERT_GE(sb.capacity, (size_t) 1);
	ASSERT_LE(sb.size, sb.capacity);
	ft_sb_free(&sb);
}

int	SbTest::setSb(const char *str)
{
	return ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring(str)));
}
