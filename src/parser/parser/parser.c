/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:55:11 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 00:34:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/string.h"

t_ft_parser_atom_char	ft_parser_char(t_ft_parser_atom_char input, \
union u_ft_tobject set)
{
	char	*c;

	c = ft_parser_peek(input.string, 0);
	if (!c || (set.as_str && !ft_strchr(set.as_str, *c)))
		return (ft_parser_atom_empty(input.string, false));
	input.payload.as_char = *c;
	return (ft_parser_atom_chain(input, input.payload, \
		ft_parser_advance(input.string, 1)));
}

struct s_ft_parser_atom	ft_parser_expect(struct s_ft_parser_atom input, \
union u_ft_tobject set)
{
	char	*c;

	c = ft_parser_peek(input.string, 0);
	if (!c || (set.as_str && !ft_strchr(set.as_str, *c)))
		return (ft_parser_atom_validity_set(input, false));
	return (ft_parser_atom_validity_set(input, true));
}

struct s_ft_parser_atom	ft_parser_expect_not(struct s_ft_parser_atom input, \
union u_ft_tobject set)
{
	char	*c;

	c = ft_parser_peek(input.string, 0);
	if (!c || (set.as_str && ft_strchr(set.as_str, *c)))
		return (ft_parser_atom_validity_set(input, false));
	return (ft_parser_atom_validity_set(input, true));
}
