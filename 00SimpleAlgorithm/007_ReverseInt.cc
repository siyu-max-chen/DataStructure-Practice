#include <iostream>

using namespace std;
/*
    0 ms 100.0%
    LC 50 power(x, n) x is double from -100 to 100
    n is integer from INT32_MIN to INT32_MAX
    重点：
        【界定】边界条件，通过所有的test cases !!!
        防止【overflow】，需要其他类型的【int -> long】
        学习如何自主【选择】 test cases
        数据类型会影响速度，例如用long时为0 ms，用long long 为 4ms
    难度：简单
*/

int x = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    int reverse(int x) {
        bool a = (x > 0);
        long x_long = (a)? x: -x;
        long ans = 0;
        while( x_long > 0){
            if(ans > INT32_MAX/10 || ans < INT32_MIN/10)
                return 0;
            ans =  ans * 10 + x_long % 10;
            x_long = x_long /10;
        }
        return (a)? ans: -ans;
    }
};

int main(){
    Solution a;
    cout << a.reverse(145633) << '\n';
    cout << a.reverse(INT32_MAX) << '\n';
    cout << a.reverse(INT32_MIN) << '\n';
}