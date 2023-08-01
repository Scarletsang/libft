/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decorator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:48:21 by htsang            #+#    #+#             */
/*   Updated: 2023/08/01 12:48:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

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
