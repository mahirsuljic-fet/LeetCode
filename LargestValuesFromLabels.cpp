// https://leetcode.com/problems/largest-values-from-labels/

#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

class Solution1
{
  public:
    int largestValsFromLabels(std::vector<int>& values, std::vector<int>& labels, int numWanted, int useLimit)
    {
      int max_label = *std::max_element(labels.begin(), labels.end()) + 1;
      int uses[max_label];
      int result = 0;

      std::memset(uses, 0, max_label * sizeof(int));

      std::vector<std::pair<int, int>> items;
      items.reserve(values.size());

      for (int i = 0; i < values.size(); ++i)
        items.push_back({ values[i], labels[i] });

      std::sort(items.begin(), items.end());

      for (int i = 0; i < numWanted; ++i)
      {
        while (!items.empty())
        {
          if (uses[items.back().second]++ < useLimit)
          {
            result += items.back().first;
            items.pop_back();
            break;
          }
          else
            items.pop_back();
        }
      }

      return result;
    }
};

class Solution2
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
