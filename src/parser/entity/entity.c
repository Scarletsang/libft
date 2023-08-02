/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:39:19 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 18:19:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/slice.h"
#include <stdbool.h>

struct s_ft_parser_entity	ft_parser_entity(\
union u_ft_tobject payload, t_ft_str input)
{
	return ((struct s_ft_parser_entity){
		.payload = payload,
		.input = input,
		.is_valid = true});
}

struct s_ft_parser_entity	ft_parser_entity_empty(t_ft_str input, \
bool is_valid)
{
	return ((struct s_ft_parser_entity){
		.payload = {},
		.input = input,
		.is_valid = is_valid});
}

struct s_ft_parser_entity	ft_parser_entity_payload_set(\
struct s_ft_parser_entity entity, union u_ft_tobject payload)
{
	return ((struct s_ft_parser_entity){
		.payload = payload,
		.input = entity.input,
		.is_valid = entity.is_valid});
}

struct s_ft_parser_entity	ft_parser_entity_validity_set(\
struct s_ft_parser_entity entity, bool is_valid)
{
	return ((struct s_ft_parser_entity){
		.payload = entity.payload,
		.input = entity.input,
		.is_valid = is_valid});
}
