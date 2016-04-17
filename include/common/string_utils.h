#pragma once


namespace utils
{
    template <typename T> struct string_traits;
    template <> struct string_traits<char>    { typedef std::string  type; };
    template <> struct string_traits<wchar_t> { typedef std::wstring type; };

    //
    // Tokenizer
    //

    template <typename T> struct string_tokens_traits;
    template <> struct string_tokens_traits<char>    { typedef string_traits<char>::type    string_type; typedef std::deque<string_type> type; };
    template <> struct string_tokens_traits<wchar_t> { typedef string_traits<wchar_t>::type string_type; typedef std::deque<string_type> type; };

    template <typename T>
        typename string_tokens_traits<T>::type get_string_tokens(const typename string_tokens_traits<T>::string_type& str, const T* separators)
    {
        typename string_tokens_traits<T>::type string_tokens;
        get_string_tokens(str, separators, string_tokens);

        return string_tokens;
    }

    template <typename T>
        void get_string_tokens(const typename string_tokens_traits<T>::string_type& str, const T* separators, typename string_tokens_traits<T>::type& string_tokens)
    {
        // TODO(zhord): use boost::tokenizer instead of this shit
        for (auto start_pos = str.find_first_not_of(separators, 0), pos = str.find_first_of(separators, start_pos);
             pos != string_tokens_traits<T>::string_type::npos || start_pos != string_tokens_traits<T>::string_type::npos;
             start_pos = str.find_first_not_of(separators, pos), pos = str.find_first_of(separators, start_pos))
        {
            string_tokens.push_back(str.substr(start_pos, pos - start_pos));
        }
    }

    typedef string_tokens_traits<char>::type    string_tokens_t;
    typedef string_tokens_traits<wchar_t>::type wstring_tokens_t;
}
