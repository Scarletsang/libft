/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/02 14:45:20 by htsang           ###   ########.fr       */
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

int	SbTest::appendToSb(const char *str)
{
	return ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring(str)));
}

TEST_F(SbTest, ft_sb_init)
{
	ASSERT_EQ(sb.capacity, (size_t) 21);
	ASSERT_EQ(sb.size, (size_t) 1);
	ASSERT_EQ(strlen((const char *) sb.buffer),  (size_t) 0);
}

TEST_F(SbTest, ft_sb_append)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello World")));
	ASSERT_EQ(sb.size, (size_t) 12);
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Hello World"), 0);
}

TEST_F(SbTest, ft_sb_append_EmptyString)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("")));
	ASSERT_EQ(strcmp((const char *) sb.buffer, ""), 0);
}

TEST_F(SbTest, ft_sb_append_Null)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring(NULL)));
	ASSERT_EQ(strcmp((const char *) sb.buffer, ""), 0);
}

TEST_F(SbTest, ft_sb_insert)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_insert(ft_str_from_cstring(" world!"), 4));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Hell world!o"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_F(SbTest, ft_sb_insert_EmptyString)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_insert(ft_str_from_cstring(""), 4));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Hello"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_F(SbTest, ft_sb_insert_Null)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_insert(ft_str_from_cstring(NULL), 4));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Hello"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_F(SbTest, ft_sb_insert_AtLastChar)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_insert(ft_str_from_cstring(" world!"), 5));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Hello world!"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_F(SbTest, ft_sb_insert_AfterLastChar)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_insert(ft_str_from_cstring(" world!"), 6));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Hello"), 0);
	ASSERT_EQ(ret, EXIT_FAILURE);
}

TEST_F(SbTest, ft_sb_replace)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_replace(ft_str_from_cstring("TARGET"), 1, 3));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "HTARGETo"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_F(SbTest, ft_sb_replace_EmptyString)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_replace(ft_str_from_cstring(""), 1, 3));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Ho"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_F(SbTest, ft_sb_replace_Null)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_replace(ft_str_from_cstring(NULL), 1, 3));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Ho"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_F(SbTest, ft_sb_replace_FromLastChar)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_replace(ft_str_from_cstring(" world!"), 5, 0));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Hello world!"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_F(SbTest, ft_sb_replace_FromLastCharOfOutboundSize)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_replace(ft_str_from_cstring(" world!"), 5, 1));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Hello world!"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_F(SbTest, ft_sb_replace_FromLastCharOfOutboundSize2)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_replace(ft_str_from_cstring(" world!"), 5, 2));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Hello world!"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_F(SbTest, ft_sb_replace_From0Of0Size)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_replace(ft_str_from_cstring(" world!"), 0, 0));
	ASSERT_EQ(strcmp((const char *) sb.buffer, " world!Hello"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}

TEST_F(SbTest, ft_sb_replace_AfterLastChar)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_replace(ft_str_from_cstring(" world!"), 6, 0));
	ASSERT_EQ(strcmp((const char *) sb.buffer, "Hello"), 0);
	ASSERT_EQ(ret, EXIT_FAILURE);
}

TEST_F(SbTest, ft_sb_replace_WholeString)
{
	ft_sb_perform(&sb, \
		ft_sb_action_append(ft_str_from_cstring("Hello")));
	int ret = ft_sb_perform(&sb, \
		ft_sb_action_replace(ft_str_from_cstring(" world!"), 0, sb.size));
	ASSERT_EQ(strcmp((const char *) sb.buffer, " world!"), 0);
	ASSERT_EQ(ret, EXIT_SUCCESS);
}
