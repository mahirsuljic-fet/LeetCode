// https://leetcode.com/problems/longest-subsequence-with-limited-sum/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

class Solution
{
  public:
    std::vector<int> answerQueries(std::vector<int>& nums, std::vector<int>& queries)
    {
      std::vector<int> result;
      result.reserve(queries.size());

      std::sort(nums.begin(), nums.end());

      int current_sum;
      for (int target : queries)
      {
        current_sum = 0;

        int i = 0;
        for (; i < nums.size(); ++i)
        {
          current_sum += nums[i];
          if (current_sum > target)
            break;
        }

        result.push_back(i);
      }

      return result;
    }
};
