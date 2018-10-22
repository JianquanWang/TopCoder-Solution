#include <vector>
#include <string>

using namespace std;

class AB{
    public:
    string createString(int N, int K){
        string s(N, 'A');
		
        if (K == 0) return "";
        if (N % 2 == 0){
        	if (K > N*N/4) return "";}
        else{
            if (K > (N*N-1)/4) return "";}
    	for(int i=1; i<=(N-1)/2; i++){
            string res(i,'B');
            s.replace(N-i, i+1, res);
            if (((N-i+1)*(i-1) < K) && (K<= (N-i)*i)){
           		int tempK = K - (N-i+1)*(i-1);
                s[N-i] = 'A';
                s[tempK] = 'B';
            }    
         
    	}
        return s;
   }
};
