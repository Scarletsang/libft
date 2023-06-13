/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:58:54 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 15:09:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
** @brief Check if the character is between 32 and 126.
** Printable characters include the space (32).
*/
int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
	{
		return (1);
	}
	return (0);
}
