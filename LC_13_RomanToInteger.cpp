#define IV 4
#define IX 9
#define XL 40
#define XC 90
#define CD 400
#define CM 900
#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using std::string;
using std::vector;
class Solution {
public:
    int romanToInt(string s) {
    int x = 0;
    vector<string> spetial;
    spetial.push_back("IV");
    spetial.push_back("IX");
    spetial.push_back("XL");
    spetial.push_back("XC");
    spetial.push_back("CD");
    spetial.push_back("CM");
    for(int i=0; i < s.size(); i++){
        if(i<s.size()-1 && find(spetial.begin(), spetial.end(), s.substr(i,2))!=spetial.end()){
            if(s.substr(i,2) == "IV") x += IV;
            else if(s.substr(i,2) == "IX") x += IX;
            else if(s.substr(i,2) == "XL") x += XL;
            else if(s.substr(i,2) == "XC") x += XC;
            else if(s.substr(i,2) == "CD") x += CD;
            else if(s.substr(i,2) == "CM") x += CM;
            i += 1;
        }
        else{
            if(s[i] == 'I') x += I;
            else if(s[i] =='V') x+= V;
            else if(s[i] =='X') x+= X;
            else if(s[i] =='L') x+= L;
            else if(s[i] =='C') x+= C;
            else if(s[i] =='D') x+= D;
            else if(s[i] =='M') x+= M;
        }
    }
        return x;
}
};
