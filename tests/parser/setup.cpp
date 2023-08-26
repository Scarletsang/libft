/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 23:22:24 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 14:38:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_test.hpp"

/**
 * expr     := term ( + | - ) expr | term
 * term     := factor ( * | / ) term | factor
 * factor   := ( expr ) | number
*/

struct s_ft_parser_atom parse_expr(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	(void) option;
  return (ft_combinator_or((struct s_ft_parser_entity[2]){
      ft_parser_entity(parse_scalar_sentence, ft_tobject_empty()),
      ft_parser_entity(parse_term, ft_tobject_empty())
    }, 2, input, ft_tobject_empty()));
}

struct s_ft_parser_atom parse_term(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
  (void) option;
  return (ft_combinator_or((struct s_ft_parser_entity[2]){
      ft_parser_entity(parse_vector_sentence, ft_tobject_empty()),
      ft_parser_entity(parse_factor, ft_tobject_empty())
    }, 2, input, ft_tobject_empty()));
}

struct s_ft_parser_atom parse_factor(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
  (void) option;
  return (ft_combinator_or((struct s_ft_parser_entity[2]){
      ft_combinator_entity(ft_combinator_and, (struct s_ft_parser_entity[3]) {
        ft_parser_entity(ft_parser_ignore, ft_tobject_str((char *) "(")),
        ft_parser_entity(parse_expr, ft_tobject_empty()),
        ft_parser_entity(ft_parser_ignore, ft_tobject_str((char *) ")"))
      }, 3, ft_tobject_empty()),
      ft_parser_entity(ft_parser_int, ft_tobject_empty())
    }, 2, input, ft_tobject_empty()));
}

struct s_ft_parser_atom parse_scalar_sentence(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
  struct s_ft_parser_atom entity;
  int                       number1;
  char                      op;
  int                       number2;

  entity = parse_term(input, option);
  if (!ft_parser_atom_is_ok(entity))
    return (ft_parser_atom_validity_set(input, false));
  number1 = entity.payload.as_int;
	entity = ft_parser_char(entity, ft_tobject_str((char *) "+-"));
  if (!ft_parser_atom_is_ok(entity))
    return (ft_parser_atom_validity_set(input, false));
  op = entity.payload.as_char;
  entity = parse_expr(entity, option);
  if (!entity.is_valid)
    return (ft_parser_atom_validity_set(input, false));
  number2 = entity.payload.as_int;
  if (op == '+')
    number1 += number2;
  else if (op == '-')
    number1 -= number2;
  return (ft_parser_atom_payload_set(entity, ft_tobject_int(number1)));
}

struct s_ft_parser_atom parse_vector_sentence(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
  struct s_ft_parser_atom entity;
  int                       number1;
  char                      op;
  int                       number2;

  entity = parse_factor(input, option);
  if (!ft_parser_atom_is_ok(entity))
    return (ft_parser_atom_validity_set(input, false));
  number1 = entity.payload.as_int;
	entity = ft_parser_char(entity, ft_tobject_str((char *) "*/"));
  if (!ft_parser_atom_is_ok(entity))
    return (ft_parser_atom_validity_set(input, false));
  op = entity.payload.as_char;
  entity = parse_term(entity, option);
  if (!entity.is_valid)
    return (ft_parser_atom_validity_set(input, false));
  number2 = entity.payload.as_int;
  if (op == '*')
    number1 *= number2;
  else if (op == '/')
    number1 /= number2;
  return (ft_parser_atom_payload_set(entity, ft_tobject_int(number1)));
}
