/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/06 23:44:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream_test.hpp"

void	IostreamTest::SetUp()
{
	std::string script_path(__FILE__);
	this->pwd = script_path.substr(0, script_path.find_last_of("/\\"));
	ft_iostream_init(&iostream);
}

void	IostreamTest::TearDown()
{
	ft_iostream_free(&iostream);
}
