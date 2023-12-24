#include <vector>
using namespace std;


class Solution
{
public:
    int countTestedDevices(vector<int> batteryPercentages)
    {
        int tested = 0;
        for (int i = 0; i < batteryPercentages.size(); i++)
        {
            if (batteryPercentages[i] > 0)
            {
                tested++;
                for (int j = 0; j < batteryPercentages.size(); j++)
                {
                    batteryPercentages[j]--;
                }
            }
        }
        return tested;
    }
};
