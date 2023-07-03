/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:00:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/03 00:43:33 by htsang           ###   ########.fr       */
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
		void	SetUp() override;
		void	TearDown() override;
	
	public:
		int	setVector(std::vector<T>);
};

template <>
class VectorTest<char *> : public ::testing::TestWithParam<std::vector<char *>>
{
	protected:
		t_ft_vector vector;
		void	SetUp() override;
};

typedef VectorTest<char *> VectorCharPtrTest;

template <>
class VectorTest<char> : public ::testing::TestWithParam<std::vector<char>>
{
	protected:
		t_ft_vector vector;
		void	SetUp() override;
	
	public:
		int	setVector(std::vector<char>);
};

typedef VectorTest<char> VectorCharTest;

template <>
class VectorTest<int> : public ::testing::TestWithParam<std::vector<int>>
{
	protected:
		t_ft_vector vector;
		void	SetUp() override;
	
	public:
		int	setVector(std::vector<int>);
};

typedef VectorTest<int> VectorIntTest;

#endif
