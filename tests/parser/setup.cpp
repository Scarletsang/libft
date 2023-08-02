/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 23:22:24 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 13:56:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_test.hpp"

/**
 * expr := number | '(' expr ')' | expr operator expr
 * operator := '+' | '-' | '*' | '/'
*/

struct s_ft_parser_entity parse_expr(struct s_ft_parser_entity input, \
void *option)
{
	
}

struct s_ft_parser_entity parse_quote(struct s_ft_parser_entity input, \
void *option)
{
}

struct s_ft_parser_entity parse_number(struct s_ft_parser_entity input, \
void *option)
{
	struct s_ft_parser_entity	entity;
	int							sign;
	int							number;

	entity = ft_parser_char(input, "-");
	sign = 1 + (ft_parser_entity_is_ok(entity) * -2);
	
}

struct s_ft_parser_entity parse_operator(struct s_ft_parser_entity input, \
void *option)
{
	
}
