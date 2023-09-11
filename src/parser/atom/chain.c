/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:14:08 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 00:46:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/slice.h"
#include <stdbool.h>

struct s_ft_parser_atom	ft_parser_atom_chain(\
struct s_ft_parser_atom entity, union u_ft_tobject payload, t_ft_str string)
{
	return ((struct s_ft_parser_atom){
		.payload = payload,
		.string = string,
		.is_valid = true,
		.error_traces = entity.error_traces});
}

struct s_ft_parser_atom	ft_parser_atom_unchain(struct s_ft_parser_atom entity)
{
	return ((struct s_ft_parser_atom){
		.payload = {},
		.string = entity.string,
		.is_valid = false,
		.error_traces = entity.error_traces});
}

struct s_ft_parser_atom	ft_parser_atom_payload_set(\
struct s_ft_parser_atom entity, union u_ft_tobject payload)
{
	return ((struct s_ft_parser_atom){
		.payload = payload,
		.string = entity.string,
		.is_valid = entity.is_valid,
		.error_traces = entity.error_traces});
}

struct s_ft_parser_atom	ft_parser_atom_string_set(\
struct s_ft_parser_atom entity, t_ft_str string)
{
	return ((struct s_ft_parser_atom){
		.payload = entity.payload,
		.string = string,
		.is_valid = entity.is_valid,
		.error_traces = entity.error_traces});
}

struct s_ft_parser_atom	ft_parser_atom_validity_set(\
struct s_ft_parser_atom entity, bool is_valid)
{
	return ((struct s_ft_parser_atom){
		.payload = entity.payload,
		.string = entity.string,
		.is_valid = is_valid,
		.error_traces = entity.error_traces});
}
