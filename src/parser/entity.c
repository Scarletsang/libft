/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:39:19 by htsang            #+#    #+#             */
/*   Updated: 2023/08/01 13:19:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/slice.h"
#include <stdbool.h>

struct s_ft_parser_entity	ft_parser_entity(void *payload, t_ft_str input)
{
	return ((struct s_ft_parser_entity){
		.payload = payload,
		.input = input});
}

struct s_ft_parser_entity	ft_parser_entity_compose(\
struct s_ft_parser_entity entity, void *payload)
{
	return ((struct s_ft_parser_entity){
		.payload = payload,
		.input = entity.input});
}

bool	ft_parser_entity_is_ok(struct s_ft_parser_entity entity)
{
	return (entity.payload && !ft_slice_is_empty(entity.input));
}

t_ft_str	ft_parser_advance(t_ft_str input, size_t len)
{
	if (len > input.size)
		return (ft_slice_empty());
	return (ft_str_slice(input.content, len, input.size - len));
}

char	*ft_parser_peek(t_ft_str input, size_t index)
{
	if (index >= input.size)
		return (NULL);
	return ((char *) input.content + index);
}
