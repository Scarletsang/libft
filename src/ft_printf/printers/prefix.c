/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:22:54 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:46:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_printers.h"

int	ftprintf_zeros(unsigned int len)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	while (len)
	{
		if (ftprintf_sequence(&seq, write(STDOUT_FILENO, "0", 1)))
			return (-1);
		len--;
	}
	return (seq.sum);
}

int	ftprintf_spaces(unsigned int len)
{
	struct s_ftprintf_sequencer	seq;

	ftprintf_sequencer_init(&seq);
	while (len)
	{
		if (ftprintf_sequence(&seq, write(STDOUT_FILENO, " ", 1)))
			return (-1);
		len--;
	}
	return (seq.sum);
}

int	ftprintf_plus(void)
{
	return (write(STDOUT_FILENO, "+", 1));
}

int	ftprintf_minus(void)
{
	return (write(STDOUT_FILENO, "-", 1));
}

int	ftprintf_0x(char is_upper)
{
	if (is_upper)
	{
		return (write(STDOUT_FILENO, "0X", 2));
	}
	else
	{
		return (write(STDOUT_FILENO, "0x", 2));
	}
}
