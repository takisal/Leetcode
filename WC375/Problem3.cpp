#include <vector>
using namespace std;

class Solution
{

public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        vector<int> r = {};
        int c = 0;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == maxi)
            {
                c++;
            }
            r.push_back(c);
        }
        long long res = 0;
        int lp = 0;
        for (int i = 0; i < r.size(); i++)
        {
            while ((lp == 0) ? (r[i] >= k) : (r[i] - r[lp - 1] >= k))
            {
                lp++;
            }
            int diff = (i - lp) + 1;
            res += (i - (diff)) + 1;
        }
        return res;
    }
};
