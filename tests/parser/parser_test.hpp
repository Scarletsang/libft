/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:49:31 by htsang            #+#    #+#             */
/*   Updated: 2023/08/01 23:22:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TEST_HPP
# define PARSER_TEST_HPP

# include <gtest/gtest.h>

extern "C"
{
  #include "LIBFT/parser.h"
}  // extern "C"

class ParserTest : public ::testing::Test
{
  protected:
	void SetUp() override{}
	void TearDown() override{}
};

#endif
