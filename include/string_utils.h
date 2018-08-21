#pragma once

#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

namespace utils
{

template <class gg_char_t>
using tstring =
	std::basic_string<gg_char_t, std::char_traits<gg_char_t>, std::allocator<gg_char_t>>;


template <class gg_char_t>
using tstringstream =
	std::basic_stringstream<gg_char_t, std::char_traits<gg_char_t>, std::allocator<gg_char_t>>;

template <class gg_char_t>
inline tstring<gg_char_t> to_upper(tstring<gg_char_t> text)
{
	std::transform(std::begin(text), std::end(text),
				   std::begin(text), toupper);

	return text;
}

template <class gg_char_t>
inline tstring<gg_char_t> to_lower(tstring<gg_char_t> text)
{
	std::transform(std::begin(text), std::end(text),
				   std::begin(text), tolower);

	return text;
}

template <class gg_char_t>
inline tstring<gg_char_t> reverse(tstring<gg_char_t> text)
{
	std::reverse(std::begin(text), std::end(text));
	return text;
}

template <class gg_char_t>
inline tstring<gg_char_t> trim(tstring<gg_char_t> const &text)
{
	auto first{text.find_first_not_of(' ')};
	auto last{text.find_last_not_of(' ')};

	return text.substr(first, last - first + 1);
}

template <class gg_char_t>
inline tstring<gg_char_t> trim(tstring<gg_char_t> const &text,
							   tstring<gg_char_t> const &chars)
{
	auto first{text.find_first_not_of(chars)};
	auto last{text.find_last_not_of(chars)};

	return text.substr(first, last - first + 1);
}

template <class gg_char_t>
inline tstring<gg_char_t> trim_left(tstring<gg_char_t> const &text)
{
	auto first{text.find_first_not_of(' ')};

	return text.substr(first, text.size() - first);
}

template <class gg_char_t>
inline tstring<gg_char_t> trim_right(tstring<gg_char_t> const &text)
{
	auto last{text.find_last_not_of(' ')};
	return text.substr(0, last + 1);
}

template <class gg_char_t>
inline tstring<gg_char_t> remove(tstring<gg_char_t> text,
								 gg_char_t const ch)
{
	auto start = std::remove_if(
		std::begin(text), std::end(text),
		[=](gg_char_t const c) { return c == ch; });
	text.erase(start, std::end(text));

	return text;
}

template <class gg_char_t>
inline std::vector<tstring<gg_char_t>> split(tstring<gg_char_t> text,
											 gg_char_t const delimiter)
{
	auto sstr = tstringstream<gg_char_t>{text};
	auto tokens = std::vector<tstring<gg_char_t>>{};
	auto token = tstring<gg_char_t>{};
	while (std::getline(sstr, token, delimiter))
	{
		if (!token.empty())
			tokens.push_back(token);
	}

	return tokens;
}

} // namespace utils