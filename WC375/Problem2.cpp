#include <vector>
using namespace std;

class Solution
{
public:
    int moduloDivision(int a, int b, int n)
    {
        int res = 1;
        while (b)
        {
            if (b % 2)
            {
                res = (res * a) % n;
            }

            a = (a * a) % n;
            b /= 2;
        }

        return res;
    }

public:
    vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
    {
        vector<int> res = {};
        for (int i = 0; i < variables.size(); i++)
        {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            int f = moduloDivision(a, b, 10);
            int s = moduloDivision(f, c, m);
            if (s == target)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
