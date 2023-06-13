/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_sequence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:30:14 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:46:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_sequence.h"

static int	ftprintf_sequence_str_minus(char format, \
struct s_ftprintf_parser *states, va_list *subs)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if (ftprintf_sequence(&seq, ftprintf_str_sub(format, states, subs)) || \
		ftprintf_sequence(&seq, ftprintf_spaces(states->width)))
		return (-1);
	return (seq.sum);
}

static int	ftprintf_sequence_str_zero(char format, \
struct s_ftprintf_parser *states, va_list *subs)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if (ftprintf_sequence(&seq, ftprintf_zeros(states->width)) || \
		ftprintf_sequence(&seq, ftprintf_str_sub(format, states, subs)))
		return (-1);
	return (seq.sum);
}

static int	ftprintf_sequence_str_default(char format, \
struct s_ftprintf_parser *states, va_list *subs)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if (ftprintf_sequence(&seq, ftprintf_spaces(states->width)) || \
		ftprintf_sequence(&seq, ftprintf_str_sub(format, states, subs)))
		return (-1);
	return (seq.sum);
}

int	ftprintf_sequence_str(char format, struct s_ftprintf_parser *states, \
va_list *subs)
{
	if (ftprintf_has_flag(states, '-'))
	{
		return (ftprintf_sequence_str_minus(format, states, subs));
	}
	else if (ftprintf_has_flag(states, '0'))
	{
		return (ftprintf_sequence_str_zero(format, states, subs));
	}
	else
	{
		return (ftprintf_sequence_str_default(format, states, subs));
	}
}
