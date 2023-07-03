/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_int.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/03 13:18:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_test.hpp"

TEST_P(VectorIntTest, ft_vector_init)
{
	ASSERT_EQ(vector.size, (size_t) 0);
}

TEST_P(VectorIntTest, ft_vector_get)
{
	std::vector<int> input = GetParam();
	setVector(input);

	for (size_t i = 0; i < vector.size; i++) {
		ASSERT_EQ(input[i], *(int *) ft_vector_get(&vector, i));
	}
}

TEST_P(VectorIntTest, ft_vector_resize)
{
	std::vector<int> input = GetParam();

	for (size_t i = 0; i < vector.capacity && i < input.size(); i++)
	{
		ft_vector_set(&vector, i, &input[i]);
		vector.size++;
	}
	ft_vector_resize(&vector);
	for (size_t i = 0; i < vector.size; i++)
	{
		ASSERT_EQ(input[i], *(int *) ft_vector_get(&vector, i));
	}
}

TEST_P(VectorIntTest, ft_vector_append)
{
	std::vector<int> input = GetParam();

	for (size_t i = 0; i < input.size(); i++)
	{
		ft_vector_append(&vector, &input[i]);
		ASSERT_EQ(vector.size, i + 1);
	}
	for (size_t i = 0; i < vector.size; i++)
	{
		ASSERT_EQ(input[i], *(int *) ft_vector_get(&vector, i));
	}
}

TEST_P(VectorIntTest, ft_vector_insert)
{
	std::vector<int> 			input = GetParam();
	std::vector<int>::iterator	it = input.begin();
	size_t						i;
	size_t						previous_size;

	setVector(std::vector<int>{999, 998, 997, 996, 995, 994});
	i = 0;
	while (i < vector.size && it != input.end())
	{
		previous_size = vector.size;
		ASSERT_EQ(*(int *) ft_vector_insert(&vector, &(*it), i), *it);
		ASSERT_EQ(vector.size, previous_size + 1);
		++it;
		i += 2;
	}
	i = 0;
	it = input.begin();
	while (i < vector.size && it != input.end())
	{
		ASSERT_EQ(*it, *(int *) ft_vector_get(&vector, i));
		++it;
		i += 2;
	}
}

TEST_P(VectorIntTest, ft_vector_remove)
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

INSTANTIATE_TEST_SUITE_P(Vector, VectorIntTest, testing::Values(
	std::vector<int>{1},
	std::vector<int>{1, 2},
	std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
	std::vector<int>{234234, -234, 982734, 0, -29078, 2346, -5367},
	std::vector<int>{}
));
