#include <vector>
#include <string>

using namespace std;

class AB{
    public:
    string createString(int N, int K){
        string s(N, 'A');                                   // 创建一个全是‘A’的串
        if (K==0) return s;                                 // 极限条件直接返回
        if (N % 2 == 0){
        	if (K > N*N/4) return "";}                   // N为偶数的极限条件，如果K大于AB能出现的最多的pair数，直接返回空串
        else{
            if (K > (N*N-1)/4) return "";}                  // N为奇数的极限条件
        // 开始考虑有AB pair出现的情况
    	for(int i=1; i<=int((N+1)/2); i++){                  // 最多有int(N+1)/2个B在串里
            string res(i,'B');                              // 对于有i个B的情况，先建一个有i个B的串
            s.replace(N-i, i+1, res);                       // 将上面的串放进s里替代最后的i个A
            if (((N-(i-1))*(i-1) < K) && (K <= (N-i)*i)){   // 根据K的值判断串里有多少个B，如果等于i，进if
           		int tempK = K - (N-(i-1))*(i-1)+(i-1);      // 寻找串中最前面的B应该替换的A的index
                if (tempK!=0){                              // 第一个A不用替换，替换了会破坏上面公式
                	s[N-i] = 'A';                        // 将最前面的B替换成A
                	s[tempK] = 'B';                      //将算好的index的A替换成B
               		break;                       //已经不需要B进串了
                }
            }
    	}
        return s;
   }
};
/*
第一道topcoder的题，花了一下午的时间，一开始拿到题有点懵，愣了一会儿开始推公式找规律，
找到之后开始编码，暂时还不知道这道题有没有快速一点的解法思路，所以我现在的水平以后遇到这类题还是会慢慢推公式。
其实直觉这应该是道DP的题，但是还没有具体思路。
希望能学习大牛们的解体思路。
*/

/*
github 的代码预览为什么和编辑模式的对齐不一样呢
*/
