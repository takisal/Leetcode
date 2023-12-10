#include <map>
#include <vector>
using namespace std;

class Solution
{

public:
    int numberOfGoodPartitions(vector<int> &nums)
    {
        int mod = 1000000007;
        int res = 1;
        map<int, int> obj = {};
        for (int i = 0; i < nums.size(); i++)
        {
            obj[nums[i]] = i;
        }
        int s = -1;
        int e = 0;
        vector<int> p = {};
        for (int i = 0; i < nums.size(); i++)
        {
            if (obj[nums[i]] != i)
            {
                if (s == -1)
                {
                    s = i;
                }
                e = max(e, obj[nums[i]]);
            }
            if (i >= e)
            {
                p.push_back(i);
            }
        }
        for (int i = 0; i < p.size() - 1; i++)
        {
            res = (res * 2) % mod;
        }
        return res;
    }
};
