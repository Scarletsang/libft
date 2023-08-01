/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:42:14 by htsang            #+#    #+#             */
/*   Updated: 2023/08/01 21:26:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include <stdlib.h>

int	ft_parser_entities_init(struct s_ft_parser_entities *entities, \
size_t item_size, t_ft_vector_item_copier copier, t_ft_str input)
{
	if (ft_vector_init(&entities->payloads, item_size, \
		FT_PARSER_ENTITIES_SIZE, copier))
		return (EXIT_FAILURE);
	entities->input = input;
	return (EXIT_SUCCESS);
}

void	ft_parser_entities_free(\
struct s_ft_parser_entities *entities)
{
	ft_vector_free(&entities->payloads);
}

bool	ft_parser_entities_is_ok(struct s_ft_parser_entities entities)
{
	return ((entities.payloads.size > 0) && !ft_slice_is_empty(entities.input));
}

struct s_ft_parser_entities	ft_parser_entities_empty(void)
{
	return ((struct s_ft_parser_entities){
		.payloads = {},
		.input = ft_slice_empty()
	});
}
