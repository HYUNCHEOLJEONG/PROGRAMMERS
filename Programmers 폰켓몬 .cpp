#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
int solution(vector<int>v) {
	set<int>s(v.begin(), v.end());
	return min(v.size() / 2, s.size());
}

int main() {

	int a=solution({ 3,1,2,3, });
	int b=solution({ 3,3,3,2,2,4 });
	int c=solution({ 3,3,3,2,2,2 });
	cout << a << endl;
	cout << b << endl;
	cout << c;

	return 0;
}