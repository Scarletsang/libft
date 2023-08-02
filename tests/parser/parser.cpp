/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:50:24 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 13:56:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_test.hpp"

TEST(ParserTest, parser_char)
{
  t_ft_str                  input = ft_str_from_cstring("abc def");
  struct s_ft_parser_entity entity;

  entity = ft_parser_entity_empty(input, true);
  for (size_t i = 0; i < input.size; i++)
  {
    entity = ft_parser_char(entity, NULL);
    ASSERT_EQ(entity.payload.as_char, ((char *) input.content)[i]);
    EXPECT_STREQ((char *) entity.input.content, ((char *) input.content) + i + 1);
  }
}
