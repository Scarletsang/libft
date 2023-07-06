/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:59:49 by htsang            #+#    #+#             */
/*   Updated: 2023/07/06 22:53:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLICE_H
# define SLICE_H

# include <stddef.h>
# include <sys/types.h>

/**
 * @brief Represents a slice of a generic object.
*/
typedef struct s_ft_slice
{
	void	*content;
	size_t	size;
}				t_ft_slice;

/**
 * @brief Represents a slice of a string, therefore it is not garanteed to be
 * null terminated.
*/
typedef t_ft_slice	t_ft_str;

t_ft_str	ft_str_slice(const char *cstring, size_t from, size_t to);

t_ft_str	ft_str_from_cstring(const char *cstring);

char		*ft_str_to_cstring(t_ft_str str);

char		*ft_str_as_ptr(t_ft_str *str);

ssize_t		ft_str_print(t_ft_str str, int fd);

/**
 * @brief Represents a generic object with its size in bytes so that it can be
 * copied.
*/
typedef t_ft_slice	t_ft_object;

/**
 * @brief Represents a null terminated string, it is mainly used to contain
 * null termianted c string in the form of an generic object.
*/
typedef t_ft_object	t_ft_str_nt;

t_ft_str_nt	ft_str_nt_from_cstring(const char *cstring);

char		*ft_str_nt_to_cstring(t_ft_str_nt str_nt);

#endif