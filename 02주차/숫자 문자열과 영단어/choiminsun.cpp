#include <string>
#include <iostream>

using namespace std;

class TransToNum
{
private:
	bool itsNum; //최근 word가 숫자면 true
	int num; //최근 word의 숫자 값
	int index; //현재까지 체크한 부분
	string word; //슬라이드한 단어
	bool checkNum(string word); //해당 영문이 숫자인지 확인
	bool checkArabia(char word); //해당 문자가 아라비아 숫자인지 확인

public:
	string str; //들어온 문장.
	int result; //반환할 문자열(숫자로 구성)
	TransToNum(string str); //생성자
	int transform(); //변환(이게 원래 메인에 와야하는데 어쩌구 저쩌구)
};

TransToNum::TransToNum(string str) //변수 초기화 해주고
{
	itsNum = false;
	result = 0;
	word = "";
	index = 0;

	this->str = str;
}

bool TransToNum::checkNum(string word) //if문으로 파라미터의 영단어가 숫자인지 확인. 해당 여부는 멤버 변수에 저장. 
{
	if (word == "zero")
	{
		itsNum = true;
		num = 0;
	}
	else if (word == "one")
	{
		itsNum = true;
		num = 1;
	}
	else if (word == "two")
	{
		itsNum = true;
		num = 2;
	}
	else if (word == "three")
	{
		itsNum = true;
		num = 3;
	}
	else if (word == "four")
	{
		itsNum = true;
		num = 4;
	}
	else if (word == "five")
	{
		itsNum = true;
		num = 5;
	}
	else if (word == "six")
	{
		itsNum = true;
		num = 6;
	}
	else if (word == "seven")
	{
		itsNum = true;
		num = 7;
	}
	else if (word == "eight")
	{
		itsNum = true;
		num = 8;
	}
	else if (word == "nine")
	{
		itsNum = true;
		num = 9;
	}
	else
	{
		itsNum = false;
	}

	return itsNum;
}

bool TransToNum::checkArabia(char word) //아라비아 숫자인지 확인.
{
	int c = (int)(word - '0');
	if (c == 0 || c == 1 || c == 2 || c == 3 || c == 4 || c == 5 || c == 6 || c == 7 || c == 8 || c == 9)
	{
		this->num = c;
		return true;
	}
	else
	{
		return false;
	}
}

int TransToNum::transform()
{
	for (int i = 0; index < str.size(); index = i) //검출된 단어는 추가 후 인덱스 업데이트를 통해 제외
	{
		if (checkArabia(str[index]) == true) //아라비아 숫자이면 바로 추가
			;
		else //아라비아 숫자가 아닌 경우 항상 영문 숫자.
			do {
				i++;
				word = str.substr(index, i - index + 1);
				checkNum(word);
			} while (itsNum == false); //숫자랑 매치될 때까지

			result = result * 10 + num; //검출된 숫자 추가.
			//reset
			word = "";
			itsNum = false;
			i++;
	}

	return this->result; //숫자를 반환.
}

int solution(string s) { //원래 여기에 transform이 어쩌구 저쩌구
	int answer = 0;

	TransToNum t = TransToNum(s);

	answer = t.transform();

	return answer;
}

/*
int main(void)
{
	string test = "one";
	char c = test[0];

	cout << solution("one4seveneight");
}
*/