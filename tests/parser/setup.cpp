/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 23:22:24 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 23:15:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_test.hpp"

/**
 * expr     := term ( + | - ) expr | term
 * term     := factor ( * | / ) term | factor
 * factor   := ( expr ) | number
*/

struct s_ft_parser_entity parse_expr(struct s_ft_parser_entity input, \
union u_ft_tobject option)
{
	(void) option;
  return (ft_parser_or((t_ft_parser_curried[2]){
      ft_parser_curry(parse_scalar_sentence, {}),
      ft_parser_curry(parse_term, {}),
    }, 2, input));
}

struct s_ft_parser_entity parse_term(struct s_ft_parser_entity input, \
union u_ft_tobject option)
{
  (void) option;
  return (ft_parser_or((t_ft_parser_curried[2]){
      ft_parser_curry(parse_vector_sentence, {}),
      ft_parser_curry(parse_factor, {}),
    }, 2, input));
}

struct s_ft_parser_entity parse_factor(struct s_ft_parser_entity input, \
union u_ft_tobject option)
{
  (void) option;
  return (ft_parser_or((t_ft_parser_curried[2]){
      ft_parser_curry(parse_parantesis, {}),
      ft_parser_curry(parse_number, {}),
    }, 2, input));
}

struct s_ft_parser_entity parse_scalar_sentence(struct s_ft_parser_entity input, \
union u_ft_tobject option)
{
  struct s_ft_parser_entity entity;
  int                       number1;
  char                      op;
  int                       number2;

  entity = parse_term(input, option);
  if (!ft_parser_entity_is_ok(entity))
    return (ft_parser_entity_validity_set(input, false));
  number1 = entity.payload.as_int;
	entity = ft_parser_char(entity, ft_parser_tobject_str((char *) "+-"));
  if (!ft_parser_entity_is_ok(entity))
    return (ft_parser_entity_validity_set(input, false));
  op = entity.payload.as_char;
  entity = parse_expr(entity, option);
  if (!entity.is_valid)
    return (ft_parser_entity_validity_set(input, false));
  number2 = entity.payload.as_int;
  if (op == '+')
    number1 += number2;
  else if (op == '-')
    number1 -= number2;
  return (ft_parser_entity_payload_set(entity, ft_parser_tobject_int(number1)));
}

struct s_ft_parser_entity parse_vector_sentence(struct s_ft_parser_entity input, \
union u_ft_tobject option)
{
  struct s_ft_parser_entity entity;
  int                       number1;
  char                      op;
  int                       number2;

  entity = parse_factor(input, option);
  if (!ft_parser_entity_is_ok(entity))
    return (ft_parser_entity_validity_set(input, false));
  number1 = entity.payload.as_int;
	entity = ft_parser_char(entity, ft_parser_tobject_str((char *) "*/"));
  if (!ft_parser_entity_is_ok(entity))
    return (ft_parser_entity_validity_set(input, false));
  op = entity.payload.as_char;
  entity = parse_term(entity, option);
  if (!entity.is_valid)
    return (ft_parser_entity_validity_set(input, false));
  number2 = entity.payload.as_int;
  if (op == '*')
    number1 *= number2;
  else if (op == '/')
    number1 /= number2;
  return (ft_parser_entity_payload_set(entity, ft_parser_tobject_int(number1)));
}

struct s_ft_parser_entity parse_parantesis(struct s_ft_parser_entity input, \
union u_ft_tobject option)
{
  (void) option;
  return (ft_parser_and((t_ft_parser_curried[3]){
      ft_parser_curry(ft_parser_ignore, ft_parser_tobject_str((char *) "(")),
      ft_parser_curry(parse_expr, {}),
      ft_parser_curry(ft_parser_ignore, ft_parser_tobject_str((char *) ")"))
    }, 3, ft_parser_entity_payload_set(input, ft_parser_tobject_int(0))));
}

struct s_ft_parser_entity parse_int(struct s_ft_parser_entity entity, \
union u_ft_tobject is_negative)
{
  char  *c;

  c = ft_parser_peek(entity.input, 0);
  if (!c || !isdigit(*c))
    return (ft_parser_entity_empty(entity.input, false));
  else if (is_negative.as_bool)
  {
    if (entity.payload.as_int < (INT_MIN + (*c - '0')) / 10)
      return (ft_parser_entity_empty(entity.input, false));
    entity.payload.as_int = entity.payload.as_int * 10 - (*c - '0');
  }
  else
  {
    if (entity.payload.as_int > (INT_MAX - (*c - '0')) / 10)
      return (ft_parser_entity_empty(entity.input, false));
    entity.payload.as_int = entity.payload.as_int * 10 + (*c - '0');
  }
	return (ft_parser_entity(entity.payload, ft_parser_advance(entity.input, 1)));
}

struct s_ft_parser_entity parse_number(struct s_ft_parser_entity entity, \
union u_ft_tobject option)
{
	bool							        is_negative;

  (void) option;
	entity = ft_parser_char(entity, ft_parser_tobject_str((char *) "-"));
	is_negative = ft_parser_entity_is_ok(entity);
  entity = ft_parser_entity_payload_set(entity, ft_parser_tobject_int(0));
  entity.is_valid = true;
  return (ft_parser_accumulate(\
    ft_parser_curry(&parse_int, ft_parser_tobject_bool(is_negative)), entity));
}
