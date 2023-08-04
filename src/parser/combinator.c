/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:47:54 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 13:52:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

struct s_ft_parser_atom	ft_parser_and(struct s_ft_parser_entity *entities, \
size_t amount, struct s_ft_parser_atom input)
{
	struct s_ft_parser_atom	result;
	size_t					i;

	i = 0;
	result = input;
	while ((i < amount) && !ft_parser_atom_is_end(result))
	{
		result = ft_parser_entity_evaluate(entities + i, result);
		if (!result.is_valid)
			return (ft_parser_atom_validity_set(input, false));
		i++;
	}
	return (ft_parser_atom_validity_set(result, true));
}

struct s_ft_parser_atom	ft_parser_or(struct s_ft_parser_entity *entities, \
size_t amount, struct s_ft_parser_atom input)
{
	struct s_ft_parser_atom	result;
	size_t					i;

	i = 0;
	result = input;
	while ((i < amount) && !ft_parser_atom_is_end(result))
	{
		result = ft_parser_entity_evaluate(entities + i, result);
		if (result.is_valid)
			return (ft_parser_atom_validity_set(result, true));
		i++;
	}
	return (ft_parser_atom_validity_set(input, false));
}
