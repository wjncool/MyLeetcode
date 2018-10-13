#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution{
    public:
    int reverse(int x){
        int flag = 0;
        if(x < 0){
            flag = 1;
            x = -x;
        }
        int n = 10;
        int left = 0;
        vector<int> save;
        while( (left = (x / n)) >= 1){
            int right = x % n;
            save.push_back(right);
            x = x - right * n;
            n *= 10;
        }
        int m = save.size();
        int sum = 0;
        for(int i = 0; i < m; ++i)
            sum += save[i] * pow(10, m-i);
        if(flag == 1)
            sum = -sum;
        return sum;
    }
};