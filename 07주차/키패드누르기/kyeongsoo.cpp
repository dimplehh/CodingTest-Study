#include <string>
#include <vector>
#include <cmath>

using namespace std;

int CheckDistance(int arr1[], int arr2[])
{
    return abs(arr1[0] - arr2[0]) + abs(arr1[1] - arr2[1]);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int arr[10][2];
    for (int i = 1; i < 10; i++) {
        arr[i][0] = (i-1) / 3;
        arr[i][1] = (i-1) % 3;
    }
    arr[0][0] = 3;
    arr[0][1] = 1;
    
    int leftPos[] = {3,0};
    int rightPos[] = {3,2};
    bool isLeft = (hand == "left") ? true : false;
    for(int i : numbers){
        if(i%3==1 ) 
        {   
            answer += "L"; 
            leftPos[0] = arr[i][0];
            leftPos[1] = arr[i][1];
        }
        else if(i%3==2 || i == 0)
        {
            int ld = CheckDistance(arr[i], leftPos);
            int rd = CheckDistance(arr[i], rightPos);
            if(ld == rd) 
                if(isLeft) 
                {
                    answer += "L";             
                    leftPos[0] = arr[i][0];
                    leftPos[1] = arr[i][1]; 
                }
                else
                { 
                    answer += "R";
                    rightPos[0] = arr[i][0];
                    rightPos[1] = arr[i][1];
                }
            else if (ld < rd) 
            {
                answer += "L";             
                leftPos[0] = arr[i][0];
                leftPos[1] = arr[i][1];
            }
            else 
            {
                answer += "R"; 
                rightPos[0] = arr[i][0];
                rightPos[1] = arr[i][1];
            }
        }
        else{
                answer += "R"; 
                rightPos[0] = arr[i][0];
                rightPos[1] = arr[i][1];
        }
    }
    
    return answer;
}
