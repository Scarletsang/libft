/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:47:54 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 22:25:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

struct s_ft_parser_entity	ft_parser_and(t_ft_parser_curried *curried_parsers, \
size_t amount, struct s_ft_parser_entity input)
{
	struct s_ft_parser_entity	result;
	size_t						i;

	i = 0;
	result = input;
	while ((i < amount) && !ft_parser_entity_is_end(result))
	{
		result = curried_parsers[i].parser(result, curried_parsers[i].option);
		if (!result.is_valid)
			return (ft_parser_entity_validity_set(input, false));
		i++;
	}
	return (result);
}

struct s_ft_parser_entity	ft_parser_or(t_ft_parser_curried *curried_parsers, \
size_t amount, struct s_ft_parser_entity input)
{
	struct s_ft_parser_entity	result;
	size_t						i;

	i = 0;
	result = input;
	while ((i < amount) && !ft_parser_entity_is_end(result))
	{
		result = curried_parsers[i].parser(result, curried_parsers[i].option);
		if (result.is_valid)
			return (result);
		i++;
	}
	return (ft_parser_entity_validity_set(input, false));
}
