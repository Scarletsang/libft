/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/03 21:32:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_test.hpp"

void	VectorPtrTest::SetUp()
{
	ft_vector_init(&vector, sizeof(void *), 5, ft_vector_copy_ptr);
}

void	VectorCharPtrTest::SetUp()
{
	ft_vector_init(&vector, sizeof(char *), 5, ft_vector_copy_string);
}

void	VectorCharTest::SetUp()
{
	ft_vector_init(&vector, sizeof(char), 5, ft_vector_copy_char);
}

void	VectorIntTest::SetUp()
{
	ft_vector_init(&vector, sizeof(int), 5, ft_vector_copy_int);
}
