/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:24:36 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:46:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_printers.h"

static int	ftprintf_long_recurse(long n, int sign)
{
	struct s_ftprintf_sequencer	seq;

	if (n * sign > 0)
	{
		ftprintf_sequencer_init(&seq);
		if (ftprintf_sequence(&seq, ftprintf_long_recurse(n / 10, sign)) || \
			ftprintf_sequence(&seq, ftprintf_c(n % 10 * sign + '0')))
			return (-1);
		return (seq.sum);
	}
	return (0);
}

/*
** @brief Print a number.
**
** @param n:  the number
*/
static int	ftprintf_long(long n)
{
	struct s_ftprintf_sequencer	seq;
	int							sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
	}
	ftprintf_sequencer_init(&seq);
	if (ftprintf_sequence(&seq, ftprintf_long_recurse(n / 10, sign)) || \
		ftprintf_sequence(&seq, ftprintf_c(n % 10 * sign + '0')))
		return (-1);
	return (seq.sum);
}

int	ftprintf_di(int n)
{
	return (ftprintf_long(n));
}

int	ftprintf_u(unsigned int n)
{
	return (ftprintf_long(n));
}
