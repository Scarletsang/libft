/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder_identity.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/03 12:52:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringbuilder_test.hpp"

TEST_P(SbTest, ft_sb_delete)
{
	setSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(0, 0));
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_P(SbTest, ft_sb_delete_FromAfterLastChar)
{
	setSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(sb.size, 0));
	ASSERT_EQ(ret, EXIT_FAILURE);
}

TEST_P(SbTest, ft_sb_delete_OfOutboundSize)
{
	setSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(0, sb.size + 1));
	ASSERT_EQ(sb.size, (size_t) 1);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_P(SbTest, ft_sb_delete_FromAfterLastCharOfOutboundSize)
{
	setSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(sb.size, sb.size + 1));
	ASSERT_EQ(ret, EXIT_FAILURE);
}

TEST_P(SbTest, ft_sb_delete_FromLastCharOf0Size)
{
	setSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(sb.size - 1, 0));
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_P(SbTest, ft_sb_delete_FromLastCharOfOutboundSize)
{
	setSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(sb.size - 1, 1));
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

INSTANTIATE_TEST_SUITE_P(Sb, SbTest, testing::Values(
	"",
	"Hello World",
	"1\02\0",
	"qwertyuiopasdfghjklzxcvbnm",
	"\t\n\v\f\r"
));
