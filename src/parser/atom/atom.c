/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:39:19 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 02:24:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/slice.h"
#include <stdbool.h>

struct s_ft_parser_atom	ft_parser_atom(\
union u_ft_tobject payload, t_ft_str input)
{
	return ((struct s_ft_parser_atom){
		.payload = payload,
		.string = input,
		.is_valid = true});
}

struct s_ft_parser_atom	ft_parser_atom_empty(t_ft_str input, \
bool is_valid)
{
	return ((struct s_ft_parser_atom){
		.payload = {},
		.string = input,
		.is_valid = is_valid});
}

struct s_ft_parser_atom	ft_parser_atom_payload_set(\
struct s_ft_parser_atom entity, union u_ft_tobject payload)
{
	return ((struct s_ft_parser_atom){
		.payload = payload,
		.string = entity.string,
		.is_valid = entity.is_valid});
}

struct s_ft_parser_atom	ft_parser_atom_validity_set(\
struct s_ft_parser_atom entity, bool is_valid)
{
	return ((struct s_ft_parser_atom){
		.payload = entity.payload,
		.string = entity.string,
		.is_valid = is_valid});
}
