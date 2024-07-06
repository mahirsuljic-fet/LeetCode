// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <vector>

class Solution
{
  public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k)
    {
      int sum = std::accumulate(nums.begin(), nums.end(), 0);

      if (sum % k != 0)
        return false;

      int target_sum = sum / k;
      std::sort(nums.begin(), nums.end());

      if (nums.back() > target_sum)
        return false;

      std::vector<int> buckets(k);
      return fill_subsets(nums, buckets, target_sum, nums.size() - 1, k);
    }

    bool fill_subsets(const std::vector<int>& nums, std::vector<int>& buckets, int target_sum, int current_index, int k)
    {
      if (current_index < 0)
      {
        for (int n : buckets)
          if (n != target_sum)
            return false;
        return true;
      }

      for (int i = 0; i < k; ++i)
      {
        if (buckets[i] + nums[current_index] > target_sum || buckets[i] + nums[0] > target_sum)
          continue;

        buckets[i] += nums[current_index];

        if (fill_subsets(nums, buckets, target_sum, current_index - 1, k))
          return true;

        buckets[i] -= nums[current_index];

        if (buckets[i] == 0)
          break;
      }

      return false;
    }
};
