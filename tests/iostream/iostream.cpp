/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iostream.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:11:14 by htsang            #+#    #+#             */
/*   Updated: 2023/07/07 00:32:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <fcntl.h>
#include "iostream_test.hpp"

TEST_F(IostreamTest, iostream_ReadTillNewLine)
{
	std::string		file_path = this->pwd + "/input/until_newline.test";
	std::ifstream	input_file(file_path);
	int				fd = open(file_path.c_str(), O_RDONLY);
	t_ft_slice		line_from_iostream;
	std::string		line_from_getline;
	size_t			line_count;

	if (!input_file.is_open() || fd < 0)
	{
		FAIL() << "Cannot open file " << file_path;
	}
	line_count = 0;
	while (!ft_iostream_read_until(&this->iostream, fd, ft_str_from_cstring("\n")))
	{
		std::getline(input_file, line_from_getline);
		line_from_iostream = ft_iostream_to_slice(&this->iostream);
		if (line_from_iostream.size == 0)
		{
			FAIL() << "line should include the match character";
		}
		else
		{
			EXPECT_EQ(strncmp(\
				(const char *) line_from_iostream.content, \
				line_from_getline.c_str(), line_from_iostream.size - 1), 0);
			EXPECT_EQ(((char *)line_from_iostream.content)[line_from_iostream.size - 1], '\n');
		}
		line_count++;
		ft_iostream_reset(&this->iostream);
	}
	close(fd);
	input_file.close();
	EXPECT_EQ(line_count, (size_t) 13);
}

TEST_F(IostreamTest, iostream_ReadUntilWord)
{
	std::string							file_path = this->pwd + "/input/until_ccc.test";
	int									fd = open(file_path.c_str(), O_RDONLY);
	t_ft_slice							output;
	std::vector<std::string>::iterator	answers_it;
	std::vector<std::string>			answers = {
		"fasdfgasdhfg\nasdfadfkuasydfg78otygasdhlfgasdccc",
		"asda86tccc",
		"\nasd8oa6sdo87ygccc",
		"789as6do8agsldccc",
		"ccc",
		"ccc",
		"\naso89d76ayhlgccc"
	};

	if (fd < 0)
	{
		FAIL() << "Cannot open file " << file_path;
	}
	answers_it = answers.begin();
	while (!ft_iostream_read_until(&this->iostream, fd, ft_str_from_cstring("ccc")))
	{
		output = ft_iostream_to_slice(&this->iostream);
		if (output.size == 0)
		{
			FAIL() << "line should include the match character";
		}
		else
		{
			EXPECT_EQ(strncmp(\
				(const char *) output.content, \
				(*answers_it).c_str(), output.size), 0);
		}
		answers_it++;
		ft_iostream_reset(&this->iostream);
	}
	close(fd);
	EXPECT_EQ(answers_it, answers.end());
}

TEST_F(IostreamTest, iostream_ReadUntilDelimiter)
{
	std::string							file_path = this->pwd + "/input/until_delimiter.test";
	int									fd = open(file_path.c_str(), O_RDONLY);
	t_ft_slice							output;
	std::vector<std::string>::iterator	answers_it;
	std::vector<std::string>			answers = {
		"content1\nasdasdasdasdgasg\n&%^$RTF(*&B*(AOSHDLAS))\nasdasd34tegarfasdfg\n\n",
		"content2\n897atsoydfghiasdgfli987349uhbns\nfasdfasdf\n\nsadfasdfasdfso867otyigbslakdf\n\n\n\n\nasdfasdf8o976oyuighEO\nF",
		"content3\n976aysdufhilskdjh\n\n\n978as6df7",
		"",
		"\nrest"
	};

	if (fd < 0)
	{
		FAIL() << "Cannot open file " << file_path;
	}
	answers_it = answers.begin();
	while (!ft_iostream_read_until_delimiter(&this->iostream, fd, ft_str_from_cstring("EOF")))
	{
		output = ft_iostream_to_slice(&this->iostream);
		if (output.size == 0)
		{
			EXPECT_EQ((*answers_it).size(), (size_t) 0);
		}
		else
		{
			EXPECT_EQ(strncmp(\
				(const char *) output.content, \
				(*answers_it).c_str(), output.size), 0);
		}
		answers_it++;
		ft_iostream_reset(&this->iostream);
	}
	// here test if it can get the rest of the file
	output = ft_iostream_to_slice(&this->iostream);
	if (output.size == 0)
	{
		EXPECT_EQ((*answers_it).size(), (size_t) 0);
	}
	else
	{
		EXPECT_EQ(strncmp(\
			(const char *) output.content, \
			(*answers_it).c_str(), output.size), 0);
	}
	answers_it++;
	close(fd);
	EXPECT_EQ(answers_it, answers.end());
}
