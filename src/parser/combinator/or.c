/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:41:21 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 10:09:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

static struct s_ft_parser_atom	ft_combinator_or_without_trace(\
struct s_ft_parser_entity *entities, size_t amount, \
struct s_ft_parser_atom input, union u_ft_tobject option)
{
	struct s_ft_parser_atom	result;
	size_t					i;

	(void) option;
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

// static size_t	ft_size_to_index(size_t size)
// {
// 	if (size == 0)
// 		return (size);
// 	return (size - 1);
// }

// if current bigger than last trace size, then move the last trace forward
// else set the size to the last trace size
void	ft_combinator_or_select_trace(struct s_ft_error_traces *error_traces, \
size_t original_traces_size, size_t last_traces_size)
{
	struct s_ft_error_trace	*current_deepest_trace;
	struct s_ft_error_trace	*last_deepest_trace;

	last_deepest_trace = ft_vector_get(&error_traces->traces, \
		original_traces_size);
	current_deepest_trace = ft_vector_get(&error_traces->traces, \
		last_traces_size);
	if (last_deepest_trace->column_index > current_deepest_trace->column_index)
		error_traces->traces.size = last_traces_size;
	else
	{
		ft_vector_buffer_shift(&error_traces->traces, \
			original_traces_size, \
			last_traces_size);
		error_traces->traces.size -= last_traces_size - original_traces_size;
	}
}

static struct s_ft_parser_atom	ft_combinator_or_with_trace(\
struct s_ft_parser_entity *entities, size_t amount, \
struct s_ft_parser_atom input, union u_ft_tobject option)
{
	struct s_ft_parser_atom	result;
	size_t					original_traces_size;
	size_t					last_traces_size;
	size_t					i;

	(void) option;
	i = 0;
	result = input;
	original_traces_size = result.error_traces->traces.size;
	while ((i < amount) && !ft_parser_atom_is_end(result))
	{
		last_traces_size = result.error_traces->traces.size;
		result = ft_parser_entity_evaluate(entities + i, result);
		if (result.is_valid)
		{
			result.error_traces->traces.size = original_traces_size;
			return (ft_parser_atom_validity_set(result, true));
		}
		ft_combinator_or_select_trace(result.error_traces, \
			original_traces_size, last_traces_size);
		i++;
	}
	return (ft_parser_atom_validity_set(input, false));
}

struct s_ft_parser_atom	ft_combinator_or(struct s_ft_parser_entity *entities, \
size_t amount, struct s_ft_parser_atom input, union u_ft_tobject option)
{
	if (input.error_traces)
		return (ft_combinator_or_with_trace(entities, amount, input, option));
	return (ft_combinator_or_without_trace(entities, amount, input, option));
}
