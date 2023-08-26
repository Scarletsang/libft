/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 02:26:46 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 14:38:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/string.h"

struct s_ft_parser_atom	ft_parser_ignore(struct s_ft_parser_atom input, \
union u_ft_tobject set)
{
	char	*c;

	c = ft_parser_peek(input.string, 0);
	if (!c || (set.as_str && !ft_strchr(set.as_str, *c)))
		return (ft_parser_atom_validity_set(input, false));
	return (ft_parser_atom(input.payload, \
		ft_parser_advance(input.string, 1)));
}

struct s_ft_parser_atom	ft_parser_ignore_not(struct s_ft_parser_atom input, \
union u_ft_tobject set)
{
	char	*c;

	c = ft_parser_peek(input.string, 0);
	if (!c || (set.as_str && ft_strchr(set.as_str, *c)))
		return (ft_parser_atom_validity_set(input, false));
	return (ft_parser_atom(input.payload, \
		ft_parser_advance(input.string, 1)));
}

struct s_ft_parser_atom	ft_parser_ignore_string(struct s_ft_parser_atom input, \
union u_ft_tobject string)
{
	struct s_ft_parser_atom result;
	char					*c;
	size_t					i;

	i = 0;
	result = input;
	while (string.as_str[i])
	{
		c = ft_parser_peek(input.string, 0);
		if (*c != string.as_str[i])
			return (ft_parser_atom_validity_set(input, false));
		result.string = ft_parser_advance(input.string, 1);
		i++;
	}
	return (result);
}

struct s_ft_parser_atom	ft_parser_ignore_multiple(struct s_ft_parser_atom input, \
union u_ft_tobject set)
{
	return (ft_decorator_accumulate(ft_parser_entity(&ft_parser_ignore, set), input, \
		ft_tobject_empty()));
}
