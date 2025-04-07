#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
void solution(vector<string>want, vector<int>number, vector<string>discount) {
    unordered_map<string, int>maps;
    int count = 0;
    for (size_t i = 0; i < want.size(); i++) {
        maps[want[i]] = number[i];
    }
    int discount_size = discount.size();
    int check_size = 10;
    //temp는 want 와 number의 pair 객체
    for (size_t i = 0; i <= discount_size - check_size; i++) {
        unordered_map<string, int>temp = maps;
        for (size_t j = 0; j < 10; j++) {
            if (temp.count(discount[i + j]) && temp[discount[i + j]] > 0) {
                temp[discount[i + j]]--;
            }
        }
        bool found = true;
        for (const auto& pair : temp) {
            if (pair.second > 0) {
                found = false;
                break;
            }
        }
        if (found == true) {
            count++;
        }
    }
    cout << count << endl;
}
int main() {
    solution({ "banana", "apple", "rice", "pork", "pot" }, { 3, 2, 2, 2, 1 },
        { "chicken", "apple", "apple", "banana", "rice", "apple", "pork",
          "banana", "pork", "rice", "pot", "banana", "apple", "banana" });
    solution({ "apple" }, { 10 },
        { "banana", "banana", "banana", "banana", "banana", "banana",
          "banana", "banana", "banana", "banana" });
    return 0;
}