//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> answers) {
//    vector<int> answer;
//    vector<int> o = {1, 2, 3, 4, 5 };
//    vector<int> t = {2, 1, 2, 3, 2, 4, 2, 5 };
//    vector<int> th = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
//
//    int one = 0; int two = 0; int three = 0;
//
//    for (int i = 0; i < answers.size(); i++) //맞은 수 체크
//    {
//        if (o[i % o.size()] == answers[i])
//            one++;
//        if (t[i % t.size()] == answers[i])
//            two++;
//        if (th[i % th.size()] == answers[i])
//            three++;
//    }
//
//    vector<int> s = { one, two, three };
//    sort(s.begin(), s.end(), greater<>());
//    int i = 0;
//    
//    if (s[0] > s[1])
//    {
//        if (s[0] == one)
//            answer.push_back(1);
//        else if (s[0] == two)
//            answer.push_back(2);
//        else
//            answer.push_back(3);
//    }
//    else if (s[1] > s[2])
//    {
//        if (s[2] == one)
//        {
//            answer.push_back(2); answer.push_back(3);
//        }
//        else if (s[2] == two)
//        {
//            answer.push_back(1); answer.push_back(3);
//        }
//        else
//        {
//            answer.push_back(1); answer.push_back(2);
//        }
//    }
//    else
//    {
//        answer.push_back(1); answer.push_back(2); answer.push_back(3);
//    }
//
//    return answer;
//}