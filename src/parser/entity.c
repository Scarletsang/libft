/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:39:19 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 13:55:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/slice.h"
#include <stdbool.h>

struct s_ft_parser_entity	ft_parser_entity(\
union u_ft_parser_payload payload, t_ft_str input)
{
	return ((struct s_ft_parser_entity){
		.payload = payload,
		.input = input,
		.is_ok = true});
}

struct s_ft_parser_entity	ft_parser_entity_empty(t_ft_str input, bool is_ok)
{
	return ((struct s_ft_parser_entity){
		.payload = {},
		.input = input,
		.is_ok = is_ok});
}

struct s_ft_parser_entity	ft_parser_entity_compose(\
struct s_ft_parser_entity entity, union u_ft_parser_payload payload)
{
	return ((struct s_ft_parser_entity){
		.payload = payload,
		.input = entity.input,
		.is_ok = entity.is_ok});
}

bool	ft_parser_entity_is_ok(struct s_ft_parser_entity entity)
{
	return (entity.is_ok && !ft_slice_is_empty(entity.input));
}
