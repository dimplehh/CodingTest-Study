#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<int, char> bitset;

string ChangeBit(int k, int n)
{
    string tmp = "";
        do {
            tmp += bitset[k % n];
            k /= n;
        }while(k > 0);
        reverse(tmp.begin(), tmp.end());
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string ans;
    for (int i = 0; i < 16; i++) {
        if(i < 10)
            bitset[i] =  i + '0';
        else
        {
            bitset[i] = (char)(65 + i - 10);
        }
    }

    string result = "";
    int k = 0;
    while(result.length() < t*m+1){
        int tmpNum = k++;
        result += ChangeBit(tmpNum, n);
    }
    cout << result << endl;
    
    int cur = 0;
    while(cur < t){
        ans += result[p+cur++*m - 1];
    }
    return ans;
}
