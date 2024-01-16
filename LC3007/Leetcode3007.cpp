#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <bitset>

using namespace std;

class Solution
{
public:
    bool countAccumulatedPrice(long long num, long long k, int x)
    {
        long long d = 0;
        string numString = std::bitset<64>(num).to_string();
        vector<long long> fromLeftValue = {};
        long long t = 0;
        long long n = 1;
        
        while (numString[0] == '0')
        {
            numString.erase(0, 1);
        }
        for (int i = numString.size() - 1; i >= 0; i--)
        {
            if (numString[i] == '1')
            {
                t += n;
            }
            fromLeftValue.insert(fromLeftValue.begin(), t);
            n *= 2;
        }

        for (int i = 0; i < numString.size(); i++)
        {
            if (((numString.size() - i) % x) == 0)
            {

                long long scopedNum = 0;
                if (numString[i] == '1')
                {
                    scopedNum++;
                    if ((i + 1) < fromLeftValue.size())
                    {
                        scopedNum += fromLeftValue[i + 1];
                    }
                }
                scopedNum += (num - fromLeftValue[i]) / 2;
                d += scopedNum;
            }
        }
        if (d > k)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    long long findMaximumNumber(long long k, int x)
    {
        long long max = k;
        long long max2 = pow(2, x) * k * 10;
        if (max2 > max)
        {
            max = max2;
        }
        long long min = 1;
        if (countAccumulatedPrice(max, k, x) == true)
        {
            return max;
        }
        if (countAccumulatedPrice(min + 1, k, x) == false)
        {
            return min;
        }

        map<long long, int> c;

        long long l = min;
        long long h = max;
        long long m = ((l + h) / 2);
        while (l <= h)
        {

            bool v = countAccumulatedPrice(m, k, x);
            if (v == false)
            {
                c[m] = 1;
            }
            else
            {
                c[m] = 2;
            }
            if (v == true)
            {
                if (c[m + 1] == 1)
                {
                    return m;
                }
                l = m + 1;
            }
            else if (v == false)
            {
                if (c[m - 1] == 2)
                {
                    return m - 1;
                }
                h = m - 1;
            }
            m = ((l + h) / 2);
        }
        return m;
    }
};
