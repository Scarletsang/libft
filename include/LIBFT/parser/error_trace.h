/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_trace.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:02:08 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 10:10:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_TRACE_H
# define ERROR_TRACE_H

# include "LIBFT/vector.h"
# include "LIBFT/slice.h"

# define TEXT_BLUE "\e[34m"
# define TEXT_RED "\e[31m"
# define TEXT_RESET "\e[0m"
# define TEXT_BOLD "\e[1m"

//////////////////////////////////////////
////////////   error traces   ////////////
//////////////////////////////////////////

struct s_ft_error_trace
{
	size_t		line;
	size_t		column_index;
	t_ft_str	received;
	int			expected_code;
	int			error_code;
};

typedef void	(*t_ft_error_trace_printer)(int code);

struct			s_ft_parser_atom;

struct s_ft_error_trace	ft_error_trace(struct s_ft_parser_atom entity, \
int expected_code, int error_code);

struct s_ft_error_trace	ft_error_trace_empty(void);

bool					ft_error_trace_is_empty(struct s_ft_error_trace *trace);

////////////////////////////////////
////////////   traces   ////////////
////////////////////////////////////

struct s_ft_error_traces
{
	t_ft_vector					traces;
	size_t						line_index;
	t_ft_str					line_start;
	t_ft_error_trace_printer	expected_message_printer;
	t_ft_error_trace_printer	error_message_printer;
};

int						ft_error_traces_init(\
struct s_ft_error_traces *error_traces, \
t_ft_error_trace_printer expected_message_printer, \
t_ft_error_trace_printer error_message_printer);

void					ft_error_traces_free(\
struct s_ft_error_traces *error_traces);

void					ft_error_traces_new_line(\
struct s_ft_error_traces *error_traces, t_ft_str line_start);

int						ft_error_traces_add(\
struct s_ft_error_traces *error_traces, struct s_ft_error_trace trace);

void					ft_error_traces_print(\
struct s_ft_error_traces *error_traces);

void					ft_error_trace_print(struct s_ft_error_trace *trace, \
struct s_ft_error_traces *error_traces);

#endif