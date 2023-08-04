/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:18:56 by htsang            #+#    #+#             */
/*   Updated: 2023/08/04 02:10:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser.h"

bool	ft_parser_atom_is_end(struct s_ft_parser_atom entity)
{
	return (ft_slice_is_empty(entity.string));
}

bool	ft_parser_atom_is_ok(struct s_ft_parser_atom entity)
{
	return (entity.is_valid && !ft_parser_atom_is_end(entity));
}
