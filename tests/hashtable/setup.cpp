/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/06 22:10:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable_test.hpp"

void	HtTest::SetUp()
{
	ft_ht_init(&ht, 4);
}

void	HtTest::TearDown()
{
	ft_ht_free(&ht);
}
