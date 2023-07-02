/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_validator.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:14:01 by htsang            #+#    #+#             */
/*   Updated: 2023/07/01 20:53:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_VALIDATOR_H
# define FIELD_VALIDATOR_H

# include "LIBFT/stringbuilder.h"

/////////////////////////////////////////////
////////     Private interface     //////////
/////////////////////////////////////////////

/**
 * @brief A bit field that indicates which fields are valid. It is needed
 * because the action functions will not fill in all the fields, the unfilled
 * fields will wither be filled when ft_sb_perform is called, or if the action
 * does not require the field, it will be ignored.
*/
enum e_ft_sb_validator_bit
{
	SB_EDIT_START_BIT = 0b1,
	SB_EDIT_LEN_BIT = 0b10
};

void					ft_sb_action_set_validator_bit(\
struct s_ft_sb_action *action, enum e_ft_sb_validator_bit bit);

void					ft_sb_action_flip_validator_bit(\
struct s_ft_sb_action *action, enum e_ft_sb_validator_bit bit);

bool					ft_sb_action_has_edit_start(\
struct s_ft_sb_action *action);

bool					ft_sb_action_has_edit_len(\
struct s_ft_sb_action *action);

#endif