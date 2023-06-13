/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_precision_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:30:14 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:49:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_sequence.h"

static int	ftprintf_sequence_with_precision_minus(char format, \
struct s_ftprintf_parser *states, va_list *subs)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if (ftprintf_sequence(&seq, ftprintf_prefix(format, states, subs)) || \
		ftprintf_sequence(&seq, ftprintf_zeros(states->precision)) || \
		ftprintf_sequence(&seq, \
			ftprintf_num_sub(format, states->strlen, subs)) || \
		ftprintf_sequence(&seq, ftprintf_spaces(states->width)))
		return (-1);
	return (seq.sum);
}

static int	ftprintf_sequence_with_precision_default(char format, \
struct s_ftprintf_parser *states, va_list *subs)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if (ftprintf_sequence(&seq, ftprintf_spaces(states->width)) || \
		ftprintf_sequence(&seq, ftprintf_prefix(format, states, subs)) || \
		ftprintf_sequence(&seq, ftprintf_zeros(states->precision)) || \
		ftprintf_sequence(&seq, ftprintf_num_sub(format, states->strlen, subs)))
		return (-1);
	return (seq.sum);
}

int	ftprintf_sequence_num_with_precision(char format, \
struct s_ftprintf_parser *states, va_list *subs)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if (ftprintf_has_flag(states, '-'))
	{
		return (ftprintf_sequence_with_precision_minus(format, states, subs));
	}
	else
	{
		return (ftprintf_sequence_with_precision_default(format, states, subs));
	}
}
