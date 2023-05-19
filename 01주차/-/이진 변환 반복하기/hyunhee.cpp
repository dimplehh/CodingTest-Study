    vector<int> temp;
    int ans1 = 0;
    int ans2 = 0;
    int len = 0;
    for (int i = 0; i< s.length(); i++)
    {
        if(s[i] == '1') len++;
        else ans2++;
    }
    while (1)
    {
        temp.clear();
        while(len != 0)
        {
            temp.push_back(len % 2);
            len = len / 2;
        }
        len = 0;
        for (int i = 0; i< temp.size(); i++)
        {
            if(temp[i] == 1) len++;
            else ans2++;
        }
        ans1++;
        if(temp.size() == 1 && temp[0] == 1)
            break;
    }
    answer.push_back(ans1);
    answer.push_back(ans2);
    return answer;
}
