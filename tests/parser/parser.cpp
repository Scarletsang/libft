/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:50:24 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 23:02:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_test.hpp"

TEST(ParserTest, parser_char)
{
  t_ft_str                  input = ft_str_from_cstring("abc def");
  struct s_ft_parser_entity entity = ft_parser_entity_empty(input, true);

  for (size_t i = 0; i < input.size; i++)
  {
    entity = ft_parser_char(entity, {});
    EXPECT_EQ(entity.payload.as_char, ((char *) input.content)[i]);
    if (i + 1 == input.size)
      EXPECT_STREQ((char *) entity.input.content, NULL);
    else
      EXPECT_STREQ((char *) entity.input.content, ((char *) input.content) + i + 1);
  }
}

TEST(ParserTest, parse_number)
{
  t_ft_str                  input = ft_str_from_cstring("-123090");
  struct s_ft_parser_entity entity = ft_parser_entity_empty(input, true);

  entity = parse_number(entity, {});
  EXPECT_EQ(entity.payload.as_int, -123090);
  EXPECT_STREQ((char *) entity.input.content, NULL);
}

TEST(ParserTest, parse_expr)
{
  t_ft_str                  input = ft_str_from_cstring("(123)+3*(6-990)+2");
  struct s_ft_parser_entity entity = ft_parser_entity_empty(input, true);

  entity = parse_expr(entity, {});
  EXPECT_EQ(entity.payload.as_int, -2827);
  EXPECT_STREQ((char *) entity.input.content, NULL);
}
