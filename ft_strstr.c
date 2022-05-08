/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:36:37 by htsang            #+#    #+#             */
/*   Updated: 2022/05/08 16:08:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	p = 0;
	if (*to_find == 0)
		return ((char *) str);
	while (str[i] && to_find[j])
	{
		if (str[i++] == to_find[j])
		{
			if (p == 0)
				p = (char *) &str[i - 1];
			j++;
			continue ;
		}
		p = 0;
		j = 0;
	}
	if (to_find[j] == 0)
		return (p);
	return (0);
}
