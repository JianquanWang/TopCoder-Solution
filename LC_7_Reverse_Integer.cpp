class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        string new_s = "";
        if(x<0) s.erase(0,1);
        auto p = s.end()-1;
        while(p!=s.begin()){
            new_s += *p;
            p -= 1;
        }
        new_s += *p;
        long long y = x>0? stoll(new_s) : -stoll(new_s);
        if(y>INT_MAX || y<INT_MIN) return 0;
        return x>0? stoi(new_s) : -stoi(new_s);
    }
};

/*
这道题要注意判断是否溢出，我用的是类型转换的方法。
官网给的解法是用栈操作把数按位加起来，加的同时去判断是否溢出。
我的解法Runtime: 12 ms, faster than 97.87% of C++ online submissions for Reverse Integer. 
下面是官网的答案，参考一下。
*/

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
