/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:49:31 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 14:47:01 by htsang           ###   ########.fr       */
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

struct s_ft_parser_atom parse_expr(struct s_ft_parser_atom input, \
union u_ft_tobject option);

struct s_ft_parser_atom parse_term(struct s_ft_parser_atom input, \
union u_ft_tobject option);

struct s_ft_parser_atom parse_factor(struct s_ft_parser_atom input, \
union u_ft_tobject option);

struct s_ft_parser_atom parse_scalar_sentence(struct s_ft_parser_atom input, \
union u_ft_tobject option);

struct s_ft_parser_atom parse_vector_sentence(struct s_ft_parser_atom input, \
union u_ft_tobject option);

#endif
