/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:50:24 by htsang            #+#    #+#             */
/*   Updated: 2023/08/01 22:28:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_test.hpp"

TEST(ParserTest, parser_char)
{
  char                      c;
  t_ft_str                  input = ft_str_from_cstring("abc def");
  struct s_ft_parser_entity entity;

  entity = ft_parser_entity(&c, input, false);
  for (size_t i = 0; i < input.size; i++)
  {
    entity = ft_parser_char(entity, NULL);
    ASSERT_EQ(*(char *) entity.payload, ((char *) input.content)[i]);
    EXPECT_STREQ((char *) entity.input.content, ((char *) input.content) + i + 1);
    entity = ft_parser_entity(&c, entity.input, false);
  }
}
