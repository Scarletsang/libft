/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:01:52 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/29 04:05:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/vector.h"

void	ft_vector_copy_char(void *buffer, void *character)
{
	*(char *) buffer = *(char *) character;
}

void	ft_vector_copy_int(void *buffer, void *integer)
{
	*(int *) buffer = *(int *) integer;
}

void	ft_vector_copy_string(void *buffer, void *string)
{
	if (string == NULL)
		*(char **) buffer = NULL;
	else
		*(char **) buffer = *(char **) string;
}

void	ft_vector_copy_ptr(void *buffer, void *ptr)
{
	if (ptr == NULL)
		*(char **) buffer = NULL;
	else
		*(void **) buffer = *(void **) ptr;
}
