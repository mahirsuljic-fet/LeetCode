// https://leetcode.com/problems/permutation-difference-between-two-strings/description/

#include <string>

class Solution1
{
  public:
    static int findPermutationDifference(std::string s, std::string t)
    {
      constexpr static int MAX_LENGTH = 26;
      int s_map[MAX_LENGTH];
      int result = 0;

      for (int i = 0; i < s.length(); ++i)
        s_map[s[i] - 'a'] = i;

      for (int i = 0; i < t.length(); ++i)
        result += abs(i - s_map[t[i] - 'a']);

      return result;
    }
};


#include <unordered_map>

class Solution2
{
  public:
    static int findPermutationDifference(std::string s, std::string t)
    {
      int result = 0;
      std::unordered_map<int, char> hashmap;

      for (int i = 0; i < s.length(); ++i)
        hashmap[s[i]] = i;

      for (int i = 0; i < t.length(); ++i)
        result += abs(i - hashmap[t[i]]);

      return result;
    }
};
