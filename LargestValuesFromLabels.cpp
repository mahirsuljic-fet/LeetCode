// https://leetcode.com/problems/largest-values-from-labels/

#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

class Solution
{
  public:
    struct Item
    {
        int value;
        int label;

        bool operator<(const Item& other) const
        {
          return this->value < other.value;
        }
    };

    int largestValsFromLabels(std::vector<int>& values, std::vector<int>& labels, int numWanted, int useLimit)
    {
      int max_label = *std::max_element(labels.begin(), labels.end()) + 1;
      int uses[max_label];
      int result = 0;

      std::memset(uses, 0, max_label * sizeof(int));

      std::priority_queue<Item> items;

      for (int i = 0; i < values.size(); ++i)
        items.push(Item { values[i], labels[i] });

      for (int i = 0; i < numWanted; ++i)
      {
        while (!items.empty())
        {
          if (uses[items.top().label]++ < useLimit)
          {
            result += items.top().value;
            items.pop();
            break;
          }
          else
            items.pop();
        }
      }

      return result;
    }
};
