#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int arr[1002] = {0, };
    for(int i : citations){
        if(i >= 1000)
            i = 1000;
        arr[i] += 1;
    }
    for(int i = 1000; i >= 0; i--){
        arr[i] += arr[i+1];
        if(arr[i]>= i)
            return i;
    }
    return 0;
}
