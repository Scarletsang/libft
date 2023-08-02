/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:49:31 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 23:21:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TEST_HPP
# define PARSER_TEST_HPP

# include <gtest/gtest.h>

extern "C"
{
  #include "LIBFT/parser.h"
  #include <limits.h>
  #include <ctype.h>
}  // extern "C"

struct s_ft_parser_entity parse_expr(struct s_ft_parser_entity input, \
union u_ft_tobject option);

struct s_ft_parser_entity parse_term(struct s_ft_parser_entity input, \
union u_ft_tobject option);

struct s_ft_parser_entity parse_factor(struct s_ft_parser_entity input, \
union u_ft_tobject option);

struct s_ft_parser_entity parse_scalar_sentence(struct s_ft_parser_entity input, \
union u_ft_tobject option);

struct s_ft_parser_entity parse_vector_sentence(struct s_ft_parser_entity input, \
union u_ft_tobject option);

struct s_ft_parser_entity parse_parantesis(struct s_ft_parser_entity input, \
union u_ft_tobject option);

struct s_ft_parser_entity parse_int(struct s_ft_parser_entity entity, \
union u_ft_tobject is_negative);

struct s_ft_parser_entity parse_number(struct s_ft_parser_entity entity, \
union u_ft_tobject option);

#endif
