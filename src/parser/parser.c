/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:55:11 by htsang            #+#    #+#             */
/*   Updated: 2023/07/31 22:00:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include <stdbool.h>

bool	ft_parser_entity_is_ok(struct s_ft_parser_entity entity)
{
	return (entity.payload && (entity.input.size > 0));
}

struct s_ft_parser_entity	ft_parser_optional(\
t_ft_parser parser, struct s_ft_parser_entity input, void *option)
{
	struct s_ft_parser_entity	result;

	result = parser(input, option);
	if (result.payload)
		return (result);
	else
		return (input);
}

struct s_ft_parser_entity	ft_parser_some(\
t_ft_parser parser, struct s_ft_parser_entity input, void *option)
{
	struct s_ft_parser_entity	result;

	result = parser(input, option);
	while (ft_parser_entity_is_ok(result))
	{
		result = parser(result, option);
	}
	return (result);
}

struct s_ft_parser_entity	ft_parser_and(t_ft_parser *parsers, size_t amount, \
struct s_ft_parser_entity input, void *option)
{
	size_t	i;

	i = 0;
	while (i < amount)
	{
		input = parsers[i](input, option);
		if (!ft_parser_entity_is_ok(input))
			return (input);
		i++;
	}
	return (input);
}

struct s_ft_parser_entity	ft_parser_or(t_ft_parser *parsers, size_t amount, \
struct s_ft_parser_entity input, void *option)
{
	size_t	i;

	i = 0;
	while (i < amount)
	{
		input = parsers[i](input, option);
		if (ft_parser_entity_is_ok(input))
			return (input);
		i++;
	}
	return (input);
}
