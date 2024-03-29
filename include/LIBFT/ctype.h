/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:21:27 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 02:11:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTYPE_H
# define CTYPE_H

int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isspace(int c);

#endif