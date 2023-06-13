/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:31:56 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:46:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_printers.h"

static int	ftprintf_hex_digit(size_t n, char alphabet_case)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if ((n & 15) > 9)
	{
		if (ftprintf_sequence(&seq, \
			ftprintf_c((n & 15) - 10 + alphabet_case)))
			return (-1);
	}
	else
	{
		if (ftprintf_sequence(&seq, \
			ftprintf_c((n & 15) + '0')))
			return (-1);
	}
	return (seq.sum);
}

static int	ftprintf_hex_recurse(size_t n, char alphabet_case)
{
	struct s_ftprintf_sequencer	seq;

	if (n)
	{
		ftprintf_sequencer_init(&seq);
		if (ftprintf_sequence(&seq, \
			ftprintf_hex_recurse(n >> 4, alphabet_case)))
			return (-1);
		if (ftprintf_sequence(&seq, \
			ftprintf_hex_digit(n, alphabet_case)))
			return (-1);
		return (seq.sum);
	}
	return (0);
}

int	ftprintf_hex(size_t n, char alphabet_case)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	if (ftprintf_sequence(&seq, \
		ftprintf_hex_recurse(n >> 4, alphabet_case)))
		return (-1);
	if (ftprintf_sequence(&seq, \
		ftprintf_hex_digit(n, alphabet_case)))
		return (-1);
	return (seq.sum);
}
