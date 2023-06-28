#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int length = numbers.size();
    int* temp_arr = numbers.data();
    set<int> result;
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            if(i==j) continue;
            result.insert(temp_arr[i] + temp_arr[j]);
        }
    }
    vector<int> answer;
    
    int k = 0;
    for(int i : result){
        answer.push_back(i);
    }
    return answer;
}
