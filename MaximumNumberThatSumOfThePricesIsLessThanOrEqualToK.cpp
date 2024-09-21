// https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/

#include <cstdio>

class Solution
{
  public:
    long long numberValue(long long n, int x)
    {
      long long value = 0;
      long long temp = n++;
      long long i = 1;

      while (temp >>= 1LL > 0LL) ++i;
      while (i % x) --i;

      for (; i > 0LL; i -= x)
      {
        value += (n / (1LL << i) * (1LL << (i - 1LL)));
        temp = n % (1LL << i) - (1LL << (i - 1LL));
        value += temp * (temp > 0LL);
      }

      return value;
    }

    long long findMaximumNumber(long long k, int x)
    {
      long long low = 1;
      long long middle = 0;
      long long high = 1e15;

      while (low <= high)
      {
        middle = (high - low) / 2 + low;

        if (numberValue(middle, x) <= k)
          low = middle + 1;
        else
          high = middle - 1;
      }

      return high;
    }
};
