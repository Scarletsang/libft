/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:24:36 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:44:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_printers.h"

int	ftprintf_c(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	ftprintf_s(char *str, unsigned int len)
{
	return (write(STDOUT_FILENO, str, len));
}

int	ftprintf_null(unsigned int len)
{
	return (write(STDOUT_FILENO, "(null)", len));
}
