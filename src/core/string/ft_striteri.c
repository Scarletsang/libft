/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:23:47 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 15:07:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
** @brief Iterate on a string, apply a function on every char of
** the string. The function can change the char in the string but
** won't produce a new string like strmapi.
** 
** @param str: a NULL-terminating string
** @param f(index,char):   the function to be applied on every char,
** it takes 2 arguments: the char and its index in the string.
*/
void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!str || !f)
		return ;
	i = 0;
	while (str[i])
	{
		f(i, str + i);
		i++;
	}
}
