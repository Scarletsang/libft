/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:18:56 by htsang            #+#    #+#             */
/*   Updated: 2023/08/02 18:19:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

bool	ft_parser_entity_is_end(struct s_ft_parser_entity entity)
{
	return (ft_slice_is_empty(entity.input));
}

bool	ft_parser_entity_is_ok(struct s_ft_parser_entity entity)
{
	return (entity.is_valid && !ft_parser_entity_is_end(entity));
}
