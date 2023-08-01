/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:47:54 by htsang            #+#    #+#             */
/*   Updated: 2023/08/01 12:48:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

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
