#include <string>
#include <vector>

using namespace std;

string binary_transpose(int value) {
    if (value == 1) return "1";
    return binary_transpose(value / 2) + to_string(value % 2);
}

vector<int> solution(string s) {
    vector<int> answer;
    int zero_count = 0;
    int result = 0;
    
    while (s != "1") {
        int temp_zero_count = 0;
        for (char c : s) {
            if (c == '0') temp_zero_count++;
        }
        zero_count += temp_zero_count;
        s = binary_transpose(s.length() - temp_zero_count);
        result++;
    }
    
    answer.assign({result, zero_count});
    return answer;
}