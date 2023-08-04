/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 23:22:24 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 04:26:34 by htsang           ###   ########.fr       */
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
  return (ft_parser_or((struct s_ft_parser_entity[2]){
      ft_parser_entity(parse_scalar_sentence, {}),
      ft_parser_entity(parse_term, {})
    }, 2, input));
}

struct s_ft_parser_atom parse_term(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
  (void) option;
  return (ft_parser_or((struct s_ft_parser_entity[2]){
      ft_parser_entity(parse_vector_sentence, {}),
      ft_parser_entity(parse_factor, {})
    }, 2, input));
}

struct s_ft_parser_atom parse_factor(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
  (void) option;
  return (ft_parser_or((struct s_ft_parser_entity[2]){
      ft_combinator_entity(ft_parser_and, (struct s_ft_parser_entity[3]) {
        ft_parser_entity(ft_parser_ignore, ft_tobject_str((char *) "(")),
        ft_parser_entity(parse_expr, {}),
        ft_parser_entity(ft_parser_ignore, ft_tobject_str((char *) ")"))
      }, 3),
      ft_parser_entity(parse_number, {})
    }, 2, input));
}

struct s_ft_parser_atom parse_parantesis(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
  (void) option;
  return (ft_parser_and((struct s_ft_parser_entity[3]) {
      ft_parser_entity(ft_parser_ignore, ft_tobject_str((char *) "(")),
      ft_parser_entity(parse_expr, {}),
      ft_parser_entity(ft_parser_ignore, ft_tobject_str((char *) ")"))
    }, 3, ft_parser_atom_payload_set(input, ft_tobject_int(0))));
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

struct s_ft_parser_atom parse_int(struct s_ft_parser_atom input, \
union u_ft_tobject is_negative)
{
  char  *c;

  c = ft_parser_peek(input.string, 0);
  if (!c || !isdigit(*c))
    return (ft_parser_atom_empty(input.string, false));
  else if (is_negative.as_bool)
  {
    if (input.payload.as_int < (INT_MIN + (*c - '0')) / 10)
      return (ft_parser_atom_empty(input.string, false));
    input.payload.as_int = input.payload.as_int * 10 - (*c - '0');
  }
  else
  {
    if (input.payload.as_int > (INT_MAX - (*c - '0')) / 10)
      return (ft_parser_atom_empty(input.string, false));
    input.payload.as_int = input.payload.as_int * 10 + (*c - '0');
  }
	return (ft_parser_atom(input.payload, ft_parser_advance(input.string, 1)));
}

struct s_ft_parser_atom parse_number(struct s_ft_parser_atom input, \
union u_ft_tobject option)
{
	bool							        is_negative;

  (void) option;
	input = ft_parser_char(input, ft_tobject_str((char *) "-"));
	is_negative = ft_parser_atom_is_ok(input);
  input = ft_parser_atom_payload_set(input, ft_tobject_int(0));
  input.is_valid = true;
  return (ft_parser_accumulate(\
    ft_parser_entity(&parse_int, ft_tobject_bool(is_negative)), input));
}
