/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_test.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:00:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/06 22:21:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGBUILDER_TEST_HPP
# define STRINGBUILDER_TEST_HPP

# include <gtest/gtest.h>

extern "C"
{
	#include "LIBFT/hashtable.h"
}

typedef std::vector<std::tuple<std::string, std::string>> StringTupleVector;

class HtTest : public ::testing::TestWithParam<StringTupleVector>
{
	protected:
		t_ft_ht	ht;
		void	SetUp() override;
		void	TearDown() override;
};

#endif
