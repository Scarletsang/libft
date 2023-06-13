/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:21:27 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 14:55:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include <stdlib.h>
# ifdef __linux__
#  include <stdint.h>
# endif
# include <limits.h>
# include "LIBFT/ctype.h"
# include "LIBFT/string.h"

void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

#endif