/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder_identity.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/02 14:28:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringbuilder_test.hpp"

TEST_P(SbTest, ft_sb_delete)
{
	appendToSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(0, 0));
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_P(SbTest, ft_sb_delete_FromAfterLastChar)
{
	appendToSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(sb.size, 0));
	ASSERT_EQ(ret, EXIT_FAILURE);
}

TEST_P(SbTest, ft_sb_delete_OfOutboundSize)
{
	appendToSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(0, sb.size + 1));
	ASSERT_EQ(sb.size, (size_t) 1);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_P(SbTest, ft_sb_delete_FromAfterLastCharOfOutboundSize)
{
	appendToSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(sb.size, sb.size + 1));
	ASSERT_EQ(ret, EXIT_FAILURE);
}

TEST_P(SbTest, ft_sb_delete_FromLastCharOf0Size)
{
	appendToSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(sb.size - 1, 0));
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_P(SbTest, ft_sb_delete_FromLastCharOfOutboundSize)
{
	appendToSb(GetParam());
	int ret = ft_sb_perform(&sb, ft_sb_action_delete(sb.size - 1, 1));
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

INSTANTIATE_TEST_SUITE_P(SbIdentity, SbTest, testing::Values(
	"",
	"Hello World",
	"1\02\0",
	"qwertyuiopasdfghjklzxcvbnm",
	"\t\n\v\f\r"
));
