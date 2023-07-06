/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:32:25 by htsang            #+#    #+#             */
/*   Updated: 2023/07/07 01:43:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable_test.hpp"

TEST_F(HtTest, ft_ht_set)
{
	ft_ht_set(&ht, ft_str_nt_from_cstring("hello"), ft_str_nt_from_cstring("world"), free);
}

TEST_F(HtTest, ft_ht_get_UsingEmptyKey)
{
	ft_ht_set(&ht, ft_str_nt_from_cstring(""), ft_str_nt_from_cstring("world"), free);
	EXPECT_STREQ(\
		(char *) ft_ht_get(&ht, ft_str_nt_from_cstring("")).content, "world");
}

TEST_P(HtTest, ft_ht_get)
{
	StringTupleVector			entries = GetParam();
	StringTupleVector::iterator	vec_it;
	const char					*key;
	const char					*value;
	const s_ft_ht_entry 		*entry;
	size_t						added;

	vec_it = entries.begin();
	added = 0;
	while (vec_it != entries.end())
	{
		key = std::get<0>(*vec_it).c_str();
		value = std::get<1>(*vec_it).c_str();
		entry = ft_ht_set(&ht, \
			ft_str_nt_from_cstring(key), \
			ft_str_nt_from_cstring(value), \
			free);
		if (entry)
		{
			EXPECT_STREQ(\
				(char *) ft_ht_get(&ht, ft_str_nt_from_cstring(key)).content, value);
			added++;
		}
		vec_it++;
	}
	EXPECT_EQ(added, ht.size);
}

TEST_P(HtTest, ft_ht_update)
{
	StringTupleVector			entries = GetParam();
	StringTupleVector::iterator	vec_it;
	const char					*key;
	const char					*value;
	const s_ft_ht_entry 		*entry;

	vec_it = entries.begin();
	while (vec_it != entries.end())
	{
		key = std::get<0>(*vec_it).c_str();
		value = std::get<1>(*vec_it).c_str();
		entry = ft_ht_update(&ht, \
			ft_str_nt_from_cstring(key), \
			ft_str_nt_from_cstring(value), \
			free);
		if (!entry)
		{
			FAIL() << "ft_update failed on key: " << key << " value: " << value;
		}
		EXPECT_STREQ(\
			(char *) ft_ht_get(&ht, ft_str_nt_from_cstring(key)).content, value);
		vec_it++;
	}
}

TEST_P(HtTest, ft_ht_delete)
{
	StringTupleVector					entries = GetParam();
	StringTupleVector::iterator			vec_it;
	StringTupleVector::reverse_iterator	vec_rit;
	const char							*key;
	const char							*value;
	size_t								deleted;
	size_t								size_before_deleted;

	vec_it = entries.begin();
	while (vec_it != entries.end())
	{
		key = std::get<0>(*vec_it).c_str();
		value = std::get<1>(*vec_it).c_str();
		ft_ht_update(&ht, \
			ft_str_nt_from_cstring(key), \
			ft_str_nt_from_cstring(value), \
			free);
		vec_it++;
	}
	size_before_deleted = ht.size;
	deleted = 0;
	vec_rit = entries.rbegin();
	while (vec_rit != entries.rend())
	{
		key = std::get<0>(*vec_rit).c_str();
		value = std::get<1>(*vec_rit).c_str();
		if (!ft_ht_delete(&ht, ft_str_nt_from_cstring(key)))
		{
			deleted++;
		}
		vec_rit++;
	}
	ASSERT_EQ(deleted, size_before_deleted);
	ASSERT_EQ(ht.size, (size_t) 0);
}

INSTANTIATE_TEST_SUITE_P(Ht, HtTest, testing::Values(
	std::vector<std::tuple<std::string, std::string>>{
		std::make_tuple("a", "b"),
		std::make_tuple("b", "a")
	},
	std::vector<std::tuple<std::string, std::string>>{
		std::make_tuple("key1", "value1"),
		std::make_tuple("key2", "value2"),
		std::make_tuple("key3", "value3"),
		std::make_tuple("key4", "value4")
	},
	std::vector<std::tuple<std::string, std::string>>{
		std::make_tuple("wtf", "akjsghd96826t3re"),
		std::make_tuple("as8df6g", "$@*H"),
		std::make_tuple("", "(*Hsas)as"),
		std::make_tuple("23rsadf", "")
	},
	std::vector<std::tuple<std::string, std::string>>{
		std::make_tuple("a", "hi"),
		std::make_tuple("a", "bye"),
		std::make_tuple("b", "hi"),
		std::make_tuple("b", "bye")
	},
	std::vector<std::tuple<std::string, std::string>>{
		std::make_tuple("", "hi"),
		std::make_tuple("", "bye"),
		std::make_tuple("", "hi"),
		std::make_tuple("", "bye")
	},
	std::vector<std::tuple<std::string, std::string>>{
		std::make_tuple("", ""),
		std::make_tuple("", ""),
		std::make_tuple("", ""),
		std::make_tuple("", "")
	},
	std::vector<std::tuple<std::string, std::string>>{
		std::make_tuple("key1", "value1"),
		std::make_tuple("key2", "value2"),
		std::make_tuple("key3", "value3"),
		std::make_tuple("key4", "value4"),
		std::make_tuple("key5", "value5"),
		std::make_tuple("key6", "value6"),
		std::make_tuple("key7", "value7"),
		std::make_tuple("key8", "value8"),
		std::make_tuple("key9", "value9"),
		std::make_tuple("key10", "value10")
	}
));