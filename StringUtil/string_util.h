// string_util.h
#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class StringUtil
{
  public:
    /**
     * 将字符串数组用指定分隔符拼接成一个字符串
     * @param strings 字符串数组
     * @param c 分隔符
     * @return 拼接后的字符串
     */
    static string join(const vector<string> &strings, char c)
    {
        return accumulate(next(strings.begin()), strings.end(), strings[0],
                          [c](const string &a, const string &b) { return a + string(1, c) + b; });
    }

    /**
     * 将字符串按指定分隔符分割成多个子字符串
     * @param s 输入字符串
     * @param d 分隔符
     * @return 分割后的字符串数组
     */
    static vector<string> split(const string &s, char d)
    {
        vector<string> tokens;
        string         token;
        for (auto c : s) {
            if (c == d) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
            } else {
                token += c;
            }
        }

        if (!token.empty()) {
            tokens.push_back(token);
        }

        return tokens;
    }
};

#endif // STRING_UTIL_H