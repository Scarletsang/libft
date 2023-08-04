/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:35:21 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 04:09:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

struct s_ft_parser_atom	ft_parser_evaluate(\
t_ft_parser_curried parser, struct s_ft_parser_atom input)
{
	return (parser.parser(input, parser.option));
}

struct s_ft_parser_atom	ft_parser_decorator_evaluate(\
t_ft_parser_decorator_curried decorator, struct s_ft_parser_atom input)
{
	return (decorator.decorator(*decorator.entity, input));
}

struct s_ft_parser_atom	ft_parser_combinator_evaluate(\
t_ft_parser_combinator_curried combinator, struct s_ft_parser_atom input)
{
	return (combinator.combinator(combinator.entities, \
		combinator.amount, input));
}
