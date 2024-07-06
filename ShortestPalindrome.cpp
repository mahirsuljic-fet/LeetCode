// https://leetcode.com/problems/shortest-palindrome/

#include <cstdio>
#include <string>

class Solution
{
  public:
    std::string shortestPalindrome(std::string s)
    {
      if (s.empty())
        return s;

      std::string r { s.rbegin(), s.rend() };
      int table[s.size() + 1];
      int i = 1;
      int j = 0;

      table[0] = -1;
      table[1] = 0;

      while (i < s.size())
      {
        if (s[i] != s[j])
        {
          j = table[j];

          if (j != -1)
            continue;

          j = 0;
        }
        else
          ++j;

        ++i;
        table[i] = j;
      }

      i = 0;
      j = 0;

      while (i < s.size())
      {
        if (r[i] == s[j])
        {
          ++i;
          ++j;
        }
        else
          j = table[j];

        if (j == -1)
        {
          ++j;
          ++i;
        }
      }

      return r + std::string { s.begin() + j, s.end() };
    }
};
