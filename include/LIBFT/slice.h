/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:59:49 by htsang            #+#    #+#             */
/*   Updated: 2023/07/02 12:19:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLICE_H
# define SLICE_H

# include <stddef.h>
# include <sys/types.h>

typedef struct s_ft_slice
{
	void	*content;
	size_t	len;
}				t_ft_slice;

typedef t_ft_slice	t_ft_str;

t_ft_str	ft_str_slice(char *cstring, size_t from, size_t to);

t_ft_str	ft_str_from_cstring(const char *cstring);

char		*ft_str_to_cstring(t_ft_str slice);

char		*ft_str_as_ptr(t_ft_str *slice);

ssize_t		ft_str_print(t_ft_str slice, int fd);

#endif