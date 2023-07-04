/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_int.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/04 21:04:50 by htsang           ###   ########.fr       */
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

TEST_P(VectorIntTest, ft_vector_remove_EntireVector)
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

TEST_P(VectorIntTest, ft_vector_remove_FirstElement)
{
	std::vector<int> 	input = GetParam();
	int					ret;

	setVector(input);
	ASSERT_EQ(vector.size, input.size());
	ret = ft_vector_remove(&vector, 0);
	if (input.size() > 0)
	{
		ASSERT_EQ(ret, EXIT_SUCCESS);
		ASSERT_EQ(vector.size, input.size() - 1);
		if (input.size() > 1)
		{
			ASSERT_EQ(*(int *) ft_vector_get(&vector, 0), input[1]);
		}
	}
	else
	{
		ASSERT_EQ(ret, EXIT_FAILURE);
		ASSERT_EQ(vector.size, (size_t) 0);
	}
}

TEST_P(VectorIntTest, ft_vector_remove_SecondElement)
{
	std::vector<int> 	input = GetParam();
	int					ret;

	setVector(input);
	ASSERT_EQ(vector.size, input.size());
	ret = ft_vector_remove(&vector, 1);
	if (input.size() > 1)
	{
		ASSERT_EQ(ret, EXIT_SUCCESS);
		ASSERT_EQ(vector.size, input.size() - 1);
		if (input.size() > 2)
		{
			ASSERT_EQ(*(int *) ft_vector_get(&vector, 1), input[2]);
		}
	}
	else
	{
		ASSERT_EQ(ret, EXIT_FAILURE);
	}
}

TEST_P(VectorIntTest, ft_vector_iterator_MoveForwards)
{
	std::vector<int>			input = GetParam();
	std::vector<int>::iterator	input_it;
	t_ft_vector_iterator		it;

	setVector(input);
	ft_vector_iterator_begin(&it, &vector);
	input_it = input.begin();
	while (!it.is_end)
	{
		ASSERT_EQ(*input_it, *(int *) ft_vector_iterator_current(&it));
		input_it++;
		ft_vector_iterator_next(&it);
	}
	ASSERT_TRUE(input_it == input.end());
}

TEST_P(VectorIntTest, ft_vector_iterator_MoveForwardsAfterIsEnd)
{
	std::vector<int>			input = GetParam();
	std::vector<int>::iterator	input_it;
	t_ft_vector_iterator		it;
	size_t						iteration_amount = 100;

	setVector(input);
	ft_vector_iterator_begin(&it, &vector);
	input_it = input.begin();
	while (!it.is_end)
	{
		ASSERT_EQ(*input_it, *(int *) ft_vector_iterator_current(&it));
		input_it++;
		ft_vector_iterator_next(&it);
	}
	while (iteration_amount > 0)
	{
		ft_vector_iterator_next(&it);
		iteration_amount--;
	}
	ASSERT_TRUE(ft_vector_iterator_current(&it) == NULL);
}

TEST_P(VectorIntTest, ft_vector_iterator_MoveBackwards)
{
	std::vector<int>					input = GetParam();
	std::vector<int>::reverse_iterator	input_it;
	t_ft_vector_iterator				it;

	setVector(input);
	ft_vector_iterator_end(&it, &vector);
	input_it = input.rbegin();
	while (!it.is_end)
	{
		ASSERT_EQ(*input_it, *(int *) ft_vector_iterator_current(&it));
		ft_vector_iterator_prev(&it);
		input_it++;
	}
	ASSERT_TRUE(input_it == input.rend());
}

TEST_P(VectorIntTest, ft_vector_iterator_MoveBackwardsAfterIsEnd)
{
	std::vector<int>					input = GetParam();
	std::vector<int>::reverse_iterator	input_it;
	t_ft_vector_iterator				it;
	size_t								iteration_amount = 100;

	setVector(input);
	ft_vector_iterator_end(&it, &vector);
	input_it = input.rbegin();
	while (!it.is_end)
	{
		ASSERT_EQ(*input_it, *(int *) ft_vector_iterator_current(&it));
		ft_vector_iterator_prev(&it);
		input_it++;
	}
	while (iteration_amount > 0)
	{
		ft_vector_iterator_prev(&it);
		iteration_amount--;
	}
	ASSERT_TRUE(ft_vector_iterator_current(&it) == NULL);
}

TEST_P(VectorIntTest, ft_vector_iterator_MoveForwardsThenBackwards)
{
	std::vector<int>					input = GetParam();
	std::vector<int>::iterator			input_it;
	std::vector<int>::reverse_iterator	reverse_input_it;
	t_ft_vector_iterator				it;
	size_t								iteration_amount = 100;

	setVector(input);
	ft_vector_iterator_begin(&it, &vector);
	input_it = input.begin();
	while (!it.is_end)
	{
		ASSERT_EQ(*input_it, *(int *) ft_vector_iterator_current(&it));
		input_it++;
		ft_vector_iterator_next(&it);
	}
	ASSERT_TRUE(input_it == input.end());
	while (iteration_amount > 0)
	{
		ft_vector_iterator_next(&it);
		iteration_amount--;
	}
	ASSERT_TRUE(ft_vector_iterator_current(&it) == NULL);
	ft_vector_iterator_end(&it, &vector);
	reverse_input_it = input.rbegin();
	while (!it.is_end)
	{
		ASSERT_EQ(*reverse_input_it, *(int *) ft_vector_iterator_current(&it));
		ft_vector_iterator_prev(&it);
		reverse_input_it++;
	}
	ASSERT_TRUE(reverse_input_it == input.rend());
	iteration_amount = 100;
	while (iteration_amount > 0)
	{
		ft_vector_iterator_prev(&it);
		iteration_amount--;
	}
	ASSERT_TRUE(ft_vector_iterator_current(&it) == NULL);
}


TEST_P(VectorIntTest, ft_vector_iterator_MoveForwardsThenBackwardsAtLastElement)
{
	std::vector<int>					input = GetParam();
	std::vector<int>::iterator			input_it;
	std::vector<int>::reverse_iterator	reverse_input_it;
	t_ft_vector_iterator				it;
	size_t								iteration_count = 10;

	setVector(input);
	ft_vector_iterator_begin(&it, &vector);
	input_it = input.begin();
	while (!it.is_end)
	{
		ASSERT_EQ(*input_it, *(int *) ft_vector_iterator_current(&it));
		if (!ft_vector_iterator_has_next(&it))
		{
			if (iteration_count > 0)
			{
				iteration_count--;
				reverse_input_it = input.rbegin();
				while (!it.is_end)
				{
					ASSERT_EQ(*reverse_input_it, *(int *) ft_vector_iterator_current(&it));
					reverse_input_it++;
					ft_vector_iterator_prev(&it);
				}
				ASSERT_TRUE(reverse_input_it == input.rend());
				input_it = input.begin();
			}
		}
		input_it++;
		ft_vector_iterator_next(&it);
	}
	if (input.size() == 0)
		// When it is an empty vector, it should not iterate at all.
		ASSERT_EQ(iteration_count, (size_t) 10);
	else if (input.size() == 1)
		// When it is a vector with only one element, it should iterate once,
		// the concept of stepping forward and backward does not make sense.
		ASSERT_EQ(iteration_count, (size_t) 9);
	else
		ASSERT_EQ(iteration_count, (size_t) 0);
	ASSERT_TRUE(input_it == input.end());
}

INSTANTIATE_TEST_SUITE_P(Vector, VectorIntTest, testing::Values(
	std::vector<int>{1},
	std::vector<int>{1, 2},
	std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
	std::vector<int>{234234, -234, 982734, 0, -29078, 2346, -5367},
	std::vector<int>{}
));
