/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:59:49 by htsang            #+#    #+#             */
/*   Updated: 2023/06/21 15:03:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLICE_H
# define SLICE_H

# include <stddef.h>

typedef struct s_ft_slice
{
	void	*content;
	size_t	size;
}				t_ft_slice;

typedef t_ft_slice	t_ft_string_slice;

char	*ft_string_slice_to_cstring(t_ft_string_slice slice);

char	*ft_string_slice_content(t_ft_string_slice *slice);

ssize_t	ft_string_slice_print(t_ft_string_slice slice, int fd);

#endif