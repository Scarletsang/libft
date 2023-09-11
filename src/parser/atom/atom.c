/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:39:19 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 07:01:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"
#include "LIBFT/parser/error_trace.h"
#include "LIBFT/slice.h"
#include <stdbool.h>
#include <stdlib.h>

struct s_ft_parser_atom	ft_parser_atom(union u_ft_tobject payload, \
t_ft_str input)
{
	return ((struct s_ft_parser_atom){
		.payload = payload,
		.string = input,
		.is_valid = true,
		.error_traces = NULL});
}

struct s_ft_parser_atom	ft_parser_atom_empty(t_ft_str input, \
bool is_valid)
{
	return ((struct s_ft_parser_atom){
		.payload = {},
		.string = input,
		.is_valid = is_valid,
		.error_traces = NULL});
}

struct s_ft_parser_atom	ft_parser_atom_with_trace(\
union u_ft_tobject payload, t_ft_str input, struct s_ft_error_traces *traces)
{
	return ((struct s_ft_parser_atom){
		.payload = payload,
		.string = input,
		.is_valid = true,
		.error_traces = traces});
}

int	ft_parser_atom_add_error_trace(struct s_ft_parser_atom entity, \
int expected_code, int error_code)
{
	struct s_ft_error_trace	trace;

	trace = ft_error_trace(entity, expected_code, error_code);
	if (ft_error_trace_is_empty(&trace))
		return (EXIT_FAILURE);
	return (ft_error_traces_add(entity.error_traces, trace));
}
