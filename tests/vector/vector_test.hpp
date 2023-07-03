/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:00:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/03 21:32:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGBUILDER_TEST_HPP
# define STRINGBUILDER_TEST_HPP

# include <gtest/gtest.h>

extern "C"
{
	#include "LIBFT/vector.h"
}

template <typename T>
class VectorTest : public ::testing::TestWithParam<std::vector<T>>
{
	protected:
		t_ft_vector vector;
		void		TearDown() override
		{
			ASSERT_GE(vector.size, (size_t) 0);
			ASSERT_GE(vector.capacity, (size_t) 0);
			ASSERT_LE(vector.size, vector.capacity);
			ft_vector_free(&vector);
		}
	
	public:
		int			setVector(std::vector<T> v)
		{
			typename std::vector<T>::iterator	it;

			for (it = v.begin(); it != v.end(); ++it) {
				if (!ft_vector_append(&vector, &(*it)))
					return (EXIT_FAILURE);
			}
			return (EXIT_SUCCESS);
		}
};

class VectorPtrTest : public VectorTest<void *>
{
	protected:
		void	SetUp() override;
};

class VectorCharPtrTest : public VectorTest<const char *>
{
	protected:
		void	SetUp() override;
};

class VectorCharTest : public VectorTest<char>
{
	protected:
		void	SetUp() override;
};

class VectorIntTest : public VectorTest<int>
{
	protected:
		void	SetUp() override;
};

#endif
