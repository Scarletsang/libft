/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:55:11 by htsang            #+#    #+#             */
/*   Updated: 2023/07/31 13:14:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include <stdbool.h>

bool	ft_parser_entity_is_ok(struct s_ft_parser_entity entity)
{
	return (entity.payload && (entity.input.size > 0));
}

struct s_ft_parser_entity	ft_parser_optional(\
struct s_ft_parser_entity input, t_ft_parser parser)
{
	struct s_ft_parser_entity	result;

	result = parser(input);
	if (result.payload)
		return (result);
	else
		return (input);
}

struct s_ft_parser_entity	ft_parser_some(\
struct s_ft_parser_entity input, t_ft_parser parser)
{
	struct s_ft_parser_entity	result;

	result = parser(input);
	while (ft_parser_entity_is_ok(result))
	{
		result = parser(result);
	}
	return (result);
}

struct s_ft_parser_entity	ft_parser_and(struct s_ft_parser_entity input, \
t_ft_parser *parsers, size_t amount)
{
	size_t	i;

	i = 0;
	while (i < amount)
	{
		input = parsers[i](input);
		if (!ft_parser_entity_is_ok(input))
			return (input);
		i++;
	}
	return (input);
}

struct s_ft_parser_entity	ft_parser_or(struct s_ft_parser_entity input, \
t_ft_parser *parsers, size_t amount)
{
	size_t	i;

	i = 0;
	while (i < amount)
	{
		input = parsers[i](input);
		if (ft_parser_entity_is_ok(input))
			return (input);
		i++;
	}
	return (input);
}
