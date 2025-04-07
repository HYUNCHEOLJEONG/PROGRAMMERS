#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
vector<string> solution(vector<string>v) {
	vector<string>answer;
	unordered_map<string, string>maps;
	for (const auto& s : v) {
		stringstream ss(s);
		string letter, userid, name;
		ss >> letter >> userid;
		if (letter != "leave") {
			ss >> name;
			maps[userid] = name;
		}

	}
	for (const auto& s : v) {
		stringstream ss2(s);
		string letter2, userid2, name2;
		ss2 >> letter2 >> userid2;
		if (letter2 == "Enter") {
			answer.push_back("\"" + maps[userid2] + "님이 입장하셨습니다.");
		}
		else if (letter2 == "Leave") {
			answer.push_back("\"" + maps[userid2] + "님이 떠나셨습니다.");
		}
	}
	return answer;
}
void print(vector<string>v) {

		copy(v.begin(), v.end(), std::ostream_iterator<string>(cout << " "));
		cout << endl;

}


int main() {
	print(solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234", "Enter uid1234 Prodo","Change uid4567 Ryan" }));



	return 0;
}