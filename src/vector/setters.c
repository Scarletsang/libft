/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:01:52 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/06/12 12:52:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/vector.h"

void	vector_set_char(void *buffer, void *character)
{
	*(char *) buffer = *(char *) character;
}

void	vector_set_int(void *buffer, void *integer)
{
	*(int *) buffer = *(int *) integer;
}

void	vector_set_string(void *buffer, void *string)
{
	*(char **) buffer = (char *) string;
}

void	vector_set_ptr(void *buffer, void *ptr)
{
	*(void **) buffer = ptr;
}
