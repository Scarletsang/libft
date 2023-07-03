/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/03 13:25:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_test.hpp"

template <typename T>
void	VectorTest<T>::TearDown()
{
	ASSERT_GE(vector.size, (size_t) 0);
	ASSERT_GE(vector.capacity, (size_t) 0);
	ASSERT_LE(vector.size, vector.capacity);
	ft_vector_free(&vector);
}

template <typename T>
int	VectorTest<T>::setVector(std::vector<T> v)
{
	typename std::vector<T>::iterator	it;

	static_assert(std::is_pointer<T>::value, "T must be a pointer type");
	for (it = v.begin(); it != v.end(); ++it) {
        if (!ft_vector_append(&vector, *it))
			return (EXIT_FAILURE);
    }
	return (EXIT_SUCCESS);
}

void	VectorTest<char>::SetUp()
{
	ft_vector_init(&vector, sizeof(char), 5, ft_vector_copy_char);
}

int	VectorTest<char>::setVector(std::vector<char> v)
{
	std::vector<char>::iterator	it;

	for (it = v.begin(); it != v.end(); ++it) {
        if (!ft_vector_append(&vector, &(*it)))
			return (EXIT_FAILURE);
    }
	return (EXIT_SUCCESS);
}

void	VectorTest<int>::SetUp()
{
	ft_vector_init(&vector, sizeof(int), 5, ft_vector_copy_int);
}

int	VectorTest<int>::setVector(std::vector<int> v)
{
	std::vector<int>::iterator	it;

	for (it = v.begin(); it != v.end(); ++it) {
        if (!ft_vector_append(&vector, &(*it)))
			return (EXIT_FAILURE);
    }
	return (EXIT_SUCCESS);
}

void	VectorTest<char *>::SetUp()
{
	ft_vector_init(&vector, sizeof(char *), 5, ft_vector_copy_string);
}
