/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:48:44 by htsang            #+#    #+#             */
/*   Updated: 2023/07/01 20:49:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder.h"
#include "field_validator.h"

void	ft_sb_action_set_validator_bit(struct s_ft_sb_action *action, \
enum e_ft_sb_validator_bit bit)
{
	action->field_validator |= bit;
}

void	ft_sb_action_flip_validator_bit(struct s_ft_sb_action *action, \
enum e_ft_sb_validator_bit bit)
{
	action->field_validator ^= bit;
}

bool	ft_sb_action_has_edit_start(struct s_ft_sb_action *action)
{
	return (action->field_validator & SB_EDIT_START_BIT);
}

bool	ft_sb_action_has_edit_len(struct s_ft_sb_action *action)
{
	return (action->field_validator & SB_EDIT_LEN_BIT);
}
