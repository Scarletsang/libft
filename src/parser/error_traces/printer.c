/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:02:34 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 09:50:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser/error_trace.h"
#include <stdio.h>

void	ft_error_trace_print(struct s_ft_error_trace *trace, \
struct s_ft_error_traces *error_traces)
{
	printf(TEXT_BOLD"line %zu(column %zu): "TEXT_RESET, \
		trace->line + 1, trace->column_index + 1);
	if (error_traces->error_message_printer)
		error_traces->error_message_printer(trace->error_code);
	printf("\n");
	printf(TEXT_BLUE"  expected: "TEXT_RESET);
	if (error_traces->expected_message_printer)
		error_traces->expected_message_printer(trace->expected_code);
	printf("\n");
	printf(TEXT_BLUE"  received"TEXT_RESET": \"%.*s\"\n", \
		(int) error_traces->line_start.size, \
		(char *) error_traces->line_start.content);
	printf("             "TEXT_RED"%*s\n"TEXT_RESET, \
		(int) trace->column_index + 1, "^");
}

void	ft_error_traces_print(struct s_ft_error_traces *error_traces)
{
	t_ft_vector_iterator	iterator;

	if (error_traces->traces.size == 0)
		return ;
	printf("Error trace:\n");
	ft_vector_iterator_begin(&iterator, &error_traces->traces);
	while (!iterator.is_end)
	{
		ft_error_trace_print(ft_vector_iterator_current(&iterator), \
			error_traces);
		ft_vector_iterator_next(&iterator);
	}
}
