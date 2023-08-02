/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:55:11 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 19:41:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/string.h"
#include "LIBFT/ctype.h"

t_ft_parser_curried	ft_parser_curry(t_ft_parser parser, \
union u_ft_tobject option)
{
	return ((t_ft_parser_curried){parser, option});
}

t_ft_parser_char_entity	ft_parser_char(t_ft_parser_char_entity input, \
union u_ft_tobject set)
{
	char	*c;

	c = ft_parser_peek(input.input, 0);
	if (!c || (set.as_str && !ft_strchr(set.as_str, *c)))
		return (ft_parser_entity_empty(input.input, false));
	input.payload.as_char = *c;
	return (ft_parser_entity(input.payload, \
		ft_parser_advance(input.input, 1)));
}

t_ft_parser_char_entity	ft_parser_digit(t_ft_parser_char_entity input, \
union u_ft_tobject option)
{
	char	*digit;

	(void) option;
	digit = ft_parser_peek(input.input, 0);
	if (!digit || !ft_isdigit(*digit))
		return (ft_parser_entity_empty(input.input, false));
	input.payload.as_char = *digit;
	return (ft_parser_entity(input.payload, \
		ft_parser_advance(input.input, 1)));
}

struct s_ft_parser_entity	ft_parser_ignore(struct s_ft_parser_entity input, \
union u_ft_tobject set)
{
	char	*c;

	c = ft_parser_peek(input.input, 0);
	if (!c || (set.as_str && !ft_strchr(set.as_str, *c)))
		return (ft_parser_entity_empty(input.input, false));
	return (ft_parser_entity(input.payload, \
		ft_parser_advance(input.input, 1)));
}
