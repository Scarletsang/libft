/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:48:44 by htsang            #+#    #+#             */
/*   Updated: 2023/06/12 12:52:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/stringbuilder.h"

void	sb_action_set_validator_bit(struct s_sb_action *action, \
enum e_sb_validator_bit bit)
{
	action->field_validator |= bit;
}

void	sb_action_flip_validator_bit(struct s_sb_action *action, \
enum e_sb_validator_bit bit)
{
	action->field_validator ^= bit;
}

bool	sb_action_has_entry_str_len(struct s_sb_action *action)
{
	return (action->field_validator & SB_ENTRY_STR_LEN_BIT);
}

bool	sb_action_has_edit_start(struct s_sb_action *action)
{
	return (action->field_validator & SB_EDIT_START_BIT);
}

bool	sb_action_has_edit_len(struct s_sb_action *action)
{
	return (action->field_validator & SB_EDIT_LEN_BIT);
}
