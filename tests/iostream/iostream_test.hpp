/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iostream_test.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:00:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/06 23:43:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGBUILDER_TEST_HPP
# define STRINGBUILDER_TEST_HPP

# include <gtest/gtest.h>

extern "C"
{
	#include "LIBFT/iostream.h"
}

class IostreamTest : public ::testing::Test
{
	protected:
		struct s_ft_iostream	iostream;
		std::string				pwd;
		void	SetUp() override;
		void	TearDown() override;
};

#endif
