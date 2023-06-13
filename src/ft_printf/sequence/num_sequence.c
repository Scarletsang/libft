/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_sequence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:30:14 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:46:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_sequence.h"

static int	ftprintf_sequence_num_minus(char format, \
struct s_ftprintf_parser *states, va_list *subs)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if (ftprintf_sequence(&seq, ftprintf_prefix(format, states, subs)) || \
		ftprintf_sequence(&seq, ftprintf_num_sub(format, 1, subs)) || \
		ftprintf_sequence(&seq, ftprintf_spaces(states->width)))
		return (-1);
	return (seq.sum);
}

static int	ftprintf_sequence_num_zero(char format, \
struct s_ftprintf_parser *states, va_list *subs)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if (ftprintf_sequence(&seq, ftprintf_prefix(format, states, subs)) || \
		ftprintf_sequence(&seq, ftprintf_zeros(states->width)) || \
		ftprintf_sequence(&seq, ftprintf_num_sub(format, 1, subs)))
		return (-1);
	return (seq.sum);
}

static int	ftprintf_sequence_num_default(char format, \
struct s_ftprintf_parser *states, va_list *subs)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if (ftprintf_sequence(&seq, ftprintf_spaces(states->width)) || \
		ftprintf_sequence(&seq, ftprintf_prefix(format, states, subs)) || \
		ftprintf_sequence(&seq, ftprintf_num_sub(format, 1, subs)))
		return (-1);
	return (seq.sum);
}

int	ftprintf_sequence_num(char format, struct s_ftprintf_parser *states, \
va_list *subs)
{
	if (ftprintf_has_precision(states))
	{
		return (ftprintf_sequence_num_with_precision(format, states, subs));
	}
	if (ftprintf_has_flag(states, '-'))
	{
		return (ftprintf_sequence_num_minus(format, states, subs));
	}
	else if (ftprintf_has_flag(states, '0'))
	{
		return (ftprintf_sequence_num_zero(format, states, subs));
	}
	else
	{
		return (ftprintf_sequence_num_default(format, states, subs));
	}
}
