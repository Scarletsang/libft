/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder_identity.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/06 14:48:04 by htsang           ###   ########.fr       */
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

TEST_P(SbTest, ft_sb_iterator_Forwards)
{
	const char				*input = GetParam();
	t_ft_sb_iterator		it;

	setSb(input);
	ft_sb_iterator_begin(&it, &sb);
	while (!it.is_end)
	{
		ASSERT_EQ(ft_sb_iterator_current(&it), *input);
		ft_sb_iterator_next(&it);
		input++;
	}
	ASSERT_EQ(ft_sb_iterator_current(&it), *input);
}

TEST_P(SbTest, ft_sb_iterator_Backwards)
{
	const char				*input = GetParam();
	size_t					input_size = strlen(input);
	t_ft_sb_iterator		it;

	setSb(input);
	ft_sb_iterator_end(&it, &sb);
	while (!it.is_end)
	{
		ASSERT_EQ(ft_sb_iterator_current(&it), input[input_size - 1]);
		ft_sb_iterator_prev(&it);
		if (!it.is_end)
			input_size--;
	}
	ASSERT_EQ(ft_sb_iterator_current(&it), input[input_size - 1]);
}

TEST_P(SbTest, ft_sb_iterator_ForwardsThenBackwards)
{
	const char				*input = GetParam();
	size_t					i;
	t_ft_sb_iterator		it;

	setSb(input);
	ft_sb_iterator_begin(&it, &sb);
	i = 0;
	while (!it.is_end)
	{
		ASSERT_EQ(ft_sb_iterator_current(&it), input[i]);
		ft_sb_iterator_next(&it);
		i++;
	}
	ASSERT_EQ(ft_sb_iterator_current(&it), input[i]);
	ft_sb_iterator_prev(&it);
	if (i > 0)
		i--;
	while (!it.is_end)
	{
		ASSERT_EQ(ft_sb_iterator_current(&it), input[i]);
		ft_sb_iterator_prev(&it);
		if (!it.is_end)
			i--;
	}
	ASSERT_EQ(ft_sb_iterator_current(&it), input[i]);
}

TEST_P(SbTest, ft_sb_iterator_mut_insert)
{
	const char				*input = GetParam();
	t_ft_sb_iterator		it;

	setSb(input);
	ft_sb_iterator_begin(&it, &sb);
	if (sb.size <= 1)
	{
		ft_sb_iterator_mut_insert(&it, ft_str_from_cstring("789"));
		ASSERT_EQ(ft_sb_iterator_current(&it), '7');
		ft_sb_iterator_next(&it);
		ASSERT_EQ(ft_sb_iterator_current(&it), '8');
		ft_sb_iterator_next(&it);
		ASSERT_EQ(ft_sb_iterator_current(&it), '9');
		ft_sb_iterator_next(&it);
	}
	while (!it.is_end)
	{
		ASSERT_EQ(ft_sb_iterator_current(&it), *input);
		ft_sb_iterator_mut_insert(&it, ft_str_from_cstring("789"));
		ft_sb_iterator_next(&it);
		ft_sb_iterator_next(&it);
		ft_sb_iterator_next(&it);
		ft_sb_iterator_next(&it);
		input++;
	}
	ASSERT_EQ(ft_sb_iterator_current(&it), *input);
}

TEST_P(SbTest, ft_sb_iterator_mut_delete)
{
	const char				*input = GetParam();
	t_ft_sb_iterator		it;

	setSb(input);
	ft_sb_iterator_begin(&it, &sb);
	while (!it.is_end)
	{
		ASSERT_EQ(ft_sb_iterator_current(&it), *input);
		ft_sb_iterator_mut_delete(&it, 1);
		input++;
	}
	ASSERT_EQ(ft_sb_iterator_current(&it), '\0');
}

TEST_P(SbTest, ft_sb_iterator_mut_replace)
{
	const char				*input = GetParam();
	t_ft_sb_iterator		it;

	setSb(input);
	ft_sb_iterator_begin(&it, &sb);
	if (sb.size <= 1)
	{
		ft_sb_iterator_mut_replace(&it, ft_str_from_cstring("abc"), 2);
		ft_sb_iterator_next(&it);
		ft_sb_iterator_next(&it);
		ASSERT_EQ(ft_sb_iterator_current(&it), 'c');
		ft_sb_iterator_next(&it);
	}
	while (it.is_end != SB_RIGHT_END)
	{
		ft_sb_iterator_mut_replace(&it, ft_str_from_cstring("abc"), 2);
		ft_sb_iterator_next(&it);
		ft_sb_iterator_next(&it);
		ASSERT_EQ(ft_sb_iterator_current(&it), 'c');
		ft_sb_iterator_next(&it);
		input++;
	}
	ASSERT_EQ(ft_sb_iterator_current(&it), '\0');
}

INSTANTIATE_TEST_SUITE_P(Sb, SbTest, testing::Values(
	"",
	"1",
	"Hello World",
	"1\02\0",
	"qwertyuiopasdfghjklzxcvbnm",
	"wertyuiopasdfghjklz",
	"\t\n\v\f\r"
));
