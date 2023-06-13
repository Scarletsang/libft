/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xXp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:02:49 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:44:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf_printers.h"

int	ftprintf_p(size_t p)
{
	return (ftprintf_hex(p, 'a'));
}

int	ftprintf_x(unsigned int n)
{
	return (ftprintf_hex(n, 'a'));
}

int	ftprintf_x_upper(unsigned int n)
{
	return (ftprintf_hex(n, 'A'));
}
