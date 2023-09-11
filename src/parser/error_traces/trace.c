/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:31:42 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 09:31:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser/error_trace.h"
#include "LIBFT/parser.h"
#include <assert.h>

struct s_ft_error_trace	ft_error_trace(struct s_ft_parser_atom entity, \
int expected_code, int error_code)
{
	if (!entity.error_traces)
		return (ft_error_trace_empty());
	assert(entity.error_traces->line_start.content != NULL);
	return ((struct s_ft_error_trace){\
		.line = entity.error_traces->line_index, \
		.column_index = (char *) entity.string.content - \
			(char *) entity.error_traces->line_start.content, \
		.received = entity.string, \
		.expected_code = expected_code, \
		.error_code = error_code, \
	});
}

struct s_ft_error_trace	ft_error_trace_empty(void)
{
	return ((struct s_ft_error_trace){\
		.line = 0, \
		.column_index = 0, \
		.received = ft_slice_empty(), \
		.expected_code = 0, \
		.error_code = 0, \
	});
}

bool	ft_error_trace_is_empty(struct s_ft_error_trace *trace)
{
	return (ft_slice_is_empty(trace->received));
}
