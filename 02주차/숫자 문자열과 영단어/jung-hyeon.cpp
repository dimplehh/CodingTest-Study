#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    string AnswerString = "";
    string FindString = "";
    vector<string> stringNumbers = { "zero", "one","two","three","four","five",
                                    "six","seven","eight","nine" };

    for (auto& ch : s) {
        FindString += ch;
        if (FindString >= "0" && FindString <= "9") {
            AnswerString += FindString;
            FindString = "";
            continue;
        }

        else if (FindString.length() >= 3) {
            for (int idx = 0; idx < stringNumbers.size(); idx++) {
                if (FindString.compare(stringNumbers[idx]) == 0) {
                    AnswerString += to_string(idx);
                    FindString = "";
                    break;
                }
            }
        }
    }

    answer = stoi(AnswerString);
    return answer;
}
