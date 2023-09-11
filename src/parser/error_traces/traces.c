/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:05:08 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 09:26:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser/error_trace.h"
#include "LIBFT/parser.h"
#include "LIBFT/vector.h"
#include <stdlib.h>

void	ft_error_traces_copier(struct s_ft_error_trace *dest, \
struct s_ft_error_trace *src)
{
	*dest = *src;
}

int	ft_error_traces_init(struct s_ft_error_traces *error_traces, \
t_ft_error_trace_printer expected_message_printer, \
t_ft_error_trace_printer error_message_printer)
{
	if (ft_vector_init(&error_traces->traces, sizeof(struct s_ft_error_trace), \
		10, (t_ft_vector_item_copier) ft_error_traces_copier))
		return (EXIT_FAILURE);
	error_traces->line_index = -1;
	error_traces->expected_message_printer = expected_message_printer;
	error_traces->error_message_printer = error_message_printer;
	return (EXIT_SUCCESS);
}

void	ft_error_traces_free(struct s_ft_error_traces *error_traces)
{
	ft_vector_free(&error_traces->traces);
}

void	ft_error_traces_new_line(struct s_ft_error_traces *error_traces, \
t_ft_str line_start)
{
	error_traces->line_index++;
	error_traces->line_start = line_start;
}

int	ft_error_traces_add(struct s_ft_error_traces *error_traces, \
struct s_ft_error_trace trace)
{
	return (!ft_vector_append(&error_traces->traces, &trace));
}
