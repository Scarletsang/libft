/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuilder_test.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:00:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/02 14:28:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGBUILDER_TEST_HPP
# define STRINGBUILDER_TEST_HPP

# include <gtest/gtest.h>

extern "C"
{
	#include "LIBFT/stringbuilder.h"
	#include "LIBFT/stringbuilder/clipper.h"
	#include "LIBFT/stringbuilder/sb_iterator.h"
}

class SbTest : public ::testing::TestWithParam<const char *>
{
	protected:
		t_ft_sb	sb;
		void	SetUp() override;
		void	TearDown() override;
	
	public:
		int	appendToSb(const char *str);
};

#endif
