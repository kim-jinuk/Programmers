#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool sort_num1(int a, int b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    return ab > ba;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), sort_num1);
    
    for (int i : numbers) answer += to_string(i);
    
    if (answer[0] == '0') return "0";
    return answer;
}