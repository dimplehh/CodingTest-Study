#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

vector<bool> FindSosu(int n) {
    int maxValue = int(stod(string(n,'9')));
    vector<bool> isPrime(maxValue + 1, true);
    fill_n(isPrime.begin(), 2, false);
    
    for (int i = 2; i * i <= maxValue; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxValue; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int solution(string numbers) {
    vector<bool> isPrime = FindSosu(numbers.size());
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int tmp = stoi(numbers.substr(0, i));
            if (isPrime[tmp]) { answer++; isPrime[tmp] = false; }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));



    return answer;
}
