/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:20 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:58:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals.h"

static int	ftprintf_control_print(char **str, \
struct s_ftprintf_parser *states, va_list *subs, char *reset_str)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if (ft_strchr("cs%", **str))
	{
		ftprintf_calc_states_str(**str, states, subs);
		if (ftprintf_sequence(&seq, ftprintf_sequence_str(**str, states, subs)))
			return (-1);
	}
	else if (ft_strchr("diuxXp", **str))
	{
		ftprintf_calc_states_num(**str, states, subs);
		if (ftprintf_sequence(&seq, ftprintf_sequence_num(**str, states, subs)))
			return (-1);
	}
	else
	{
		*str = reset_str;
		return (0);
	}
	(*str)++;
	return (seq.sum);
}

static int	ftprintf_control_parse(char **str, \
struct s_ftprintf_parser *states, va_list *subs)
{
	char						*reset_str;
	struct s_ftprintf_sequencer	seq;

	reset_str = *str;
	ftprintf_sequencer_init(&seq);
	ftprintf_parser_run(str, states, &ftprintf_parse_flags);
	ftprintf_parser_run(str, states, &ftprintf_parse_width);
	if (**str == '.')
	{
		states->precision = 0;
		(*str)++;
		ftprintf_parser_run(str, states, &ftprintf_parse_precision);
	}
	if (ftprintf_sequence(&seq, ftprintf_control_print(str, states, subs, \
		reset_str)))
		return (-1);
	return (seq.sum);
}

int	ftprintf_control(const char *str, va_list *subs)
{
	struct s_ftprintf_parser	states;
	struct s_ftprintf_sequencer	seq;
	unsigned int				text_count;

	ftprintf_sequencer_init(&seq);
	text_count = 0;
	while (str[text_count])
	{
		if (str[text_count] == '%')
		{
			if (ftprintf_sequence(&seq, write(STDOUT_FILENO, str, text_count)))
				return (-1);
			str += text_count + 1;
			text_count = 0;
			ftprintf_parser_init(&states);
			if (ftprintf_sequence(&seq, ftprintf_control_parse((char **) &str, \
				&states, subs)))
				return (-1);
			continue ;
		}
		text_count++;
	}
	if (ftprintf_sequence(&seq, write(STDOUT_FILENO, str, text_count)))
		return (-1);
	return (seq.sum);
}
