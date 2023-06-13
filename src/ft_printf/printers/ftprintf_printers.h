/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_printers.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:26:22 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:46:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_PRINTERS_H
# define FTPRINTF_PRINTERS_H

# include <stdlib.h>
# include <unistd.h>

////////////////////////
//////    Core    //////
////////////////////////

struct s_ftprintf_sequencer
{
	int	sum;
};

void	ftprintf_sequencer_init(struct s_ftprintf_sequencer *seq);

int		ftprintf_sequence(struct s_ftprintf_sequencer *seq, int ret);

//////////////////////////
//////    Prefix    //////
//////////////////////////

int		ftprintf_zeros(unsigned int len);

int		ftprintf_spaces(unsigned int len);

int		ftprintf_plus(void);

int		ftprintf_minus(void);

int		ftprintf_0x(char is_upper);

//////////////////////////
//////    Format    //////
//////////////////////////

int		ftprintf_c(char c);

int		ftprintf_s(char *str, unsigned int len);

int		ftprintf_null(unsigned int len);

int		ftprintf_di(int n);

int		ftprintf_u(unsigned int n);

int		ftprintf_x(unsigned int n);

int		ftprintf_x_upper(unsigned int n);

int		ftprintf_p(size_t p);

//////////////////////////
//////   Private	//////
//////////////////////////

int		ftprintf_hex(size_t n, char alphabet_case);

#endif