#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> totalToppings;
    map<int, int> brotherToppings;

    for (int i = 0;i < topping.size();i++) { totalToppings[topping[i]] += 1; }

    for (int i = 0;i < topping.size();i++) {
        brotherToppings[topping[i]] += 1;
        if (totalToppings.find(topping[i]) != totalToppings.end()) {
            totalToppings[topping[i]] -= 1;
            if (totalToppings[topping[i]] == 0) totalToppings.erase(topping[i]);
        }
        if (totalToppings.size() == brotherToppings.size()) answer++;
    }
    cout << answer;
    return answer;
}

int main() {
    solution({ 1, 2, 1, 3, 1, 4, 1, 2 });
}