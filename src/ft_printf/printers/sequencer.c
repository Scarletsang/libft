/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequencer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:50:25 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:46:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_printers.h"

void	ftprintf_sequencer_init(struct s_ftprintf_sequencer *seq)
{
	seq->sum = 0;
}

int	ftprintf_sequence(struct s_ftprintf_sequencer *seq, int ret)
{
	if (ret < 0)
		return (EXIT_FAILURE);
	seq->sum += ret;
	return (EXIT_SUCCESS);
}
