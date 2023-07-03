/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_char_ptr.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/03 21:29:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_test.hpp"

TEST_P(VectorCharPtrTest, ft_vector_init)
{
	ASSERT_EQ(vector.size, (size_t) 0);
}

TEST_P(VectorCharPtrTest, ft_vector_get)
{
	std::vector<const char *> input = GetParam();
	setVector(input);

	for (size_t i = 0; i < vector.size; i++) {
		EXPECT_STREQ(input[i], *(char **) ft_vector_get(&vector, i));
	}
}

TEST_P(VectorCharPtrTest, ft_vector_resize)
{
	std::vector<const char *> input = GetParam();

	for (size_t i = 0; i < vector.capacity && i < input.size(); i++)
	{
		ft_vector_set(&vector, i, &input[i]);
		vector.size++;
	}
	ft_vector_resize(&vector);
	for (size_t i = 0; i < vector.size; i++)
	{
		EXPECT_STREQ(input[i], *(char **) ft_vector_get(&vector, i));
	}
}

TEST_P(VectorCharPtrTest, ft_vector_append)
{
	std::vector<const char *> input = GetParam();

	for (size_t i = 0; i < input.size(); i++)
	{
		ft_vector_append(&vector, &input[i]);
		ASSERT_EQ(vector.size, i + 1);
	}
	for (size_t i = 0; i < vector.size; i++)
	{
		EXPECT_STREQ(input[i], *(char **) ft_vector_get(&vector, i));
	}
}

TEST_P(VectorCharPtrTest, ft_vector_insert)
{
	std::vector<const char *> 			input = GetParam();
	std::vector<const char *>::iterator it = input.begin();
	size_t								i;
	size_t								previous_size;

	setVector(std::vector<const char *>{"abc", "cde", "efg", "hij", "klm", "nop", "qrs", "tuv", "wxy", "z"});
	i = 0;
	while (i < vector.size && it != input.end())
	{
		previous_size = vector.size;
		EXPECT_STREQ(*(char **) ft_vector_insert(&vector, &(*it), i), *it);
		ASSERT_EQ(vector.size, previous_size + 1);
		++it;
		i += 2;
	}
	i = 0;
	it = input.begin();
	while (i < vector.size && it != input.end())
	{
		EXPECT_STREQ(*it, *(char * *) ft_vector_get(&vector, i));
		++it;
		i += 2;
	}
}

TEST_P(VectorCharPtrTest, ft_vector_remove)
{
	size_t	i = 0;

	setVector(GetParam());
	while (i < vector.size)
	{
		ASSERT_EQ(ft_vector_remove(&vector, i), EXIT_SUCCESS);
	}
	i = 20;
	while (i > 0)
	{
		ASSERT_EQ(ft_vector_remove(&vector, i), EXIT_FAILURE);
		i--;
	}
	ASSERT_EQ(vector.size, (size_t) 0);
}

INSTANTIATE_TEST_SUITE_P(Vector, VectorCharPtrTest, testing::Values(
	std::vector<const char *>{"123"},
	std::vector<const char *>{"123", "1234567845678"},
	std::vector<const char *>{"\0\0", "1234567845678", "123678", "5234gg2"},
	std::vector<const char *>{"!@#$%^", "$%^&*()", "#$%^&*(), ", "}12412486$%^&*({&aasdsd"},
	std::vector<const char *>{}
));
