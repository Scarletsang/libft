/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:50:24 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 14:47:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_test.hpp"
#include <string>

TEST(ParserTest, parser_char)
{
  t_ft_str                  input = ft_str_from_cstring("abc def");
  struct s_ft_parser_atom entity = ft_parser_atom_empty(input, true);

  for (size_t i = 0; i < input.size; i++)
  {
    entity = ft_parser_char(entity, {});
    EXPECT_EQ(entity.payload.as_char, ((char *) input.content)[i]);
    if (i + 1 == input.size)
      EXPECT_STREQ((char *) entity.string.content, NULL);
    else
      EXPECT_STREQ((char *) entity.string.content, ((char *) input.content) + i + 1);
  }
}

TEST(ParserTest, parse_number)
{
  t_ft_str                  input = ft_str_from_cstring("-123090");
  struct s_ft_parser_atom entity = ft_parser_atom_empty(input, true);

  entity = ft_parser_int(entity, {});
  EXPECT_EQ(entity.payload.as_int, -123090);
  EXPECT_STREQ((char *) entity.string.content, NULL);
}

TEST(ParserTest, parse_expr)
{
  t_ft_str                  input = ft_str_from_cstring("(123)+3*(6-990)+2");
  struct s_ft_parser_atom entity = ft_parser_atom_empty(input, true);

  entity = parse_expr(entity, {});
  EXPECT_EQ(entity.payload.as_int, -2827);
  EXPECT_STREQ((char *) entity.string.content, NULL);
}

TEST(ParserTest, parse_expr2)
{
  std::string               string;
  std::getline(std::cin, string);
  t_ft_str                  input = ft_str_from_cstring(string.c_str());
  struct s_ft_parser_atom entity = ft_parser_atom_empty(input, true);

  entity = parse_expr(entity, {});
  printf("result: %d\n", entity.payload.as_int);
  printf("left  : '%s'\n", (char *) entity.string.content);
}
