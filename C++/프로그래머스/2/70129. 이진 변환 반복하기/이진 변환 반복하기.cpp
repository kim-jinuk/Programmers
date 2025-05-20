#include <string>
#include <vector>

using namespace std;

string get_binary(int x) {
    if (x == 1) return "1";
    return get_binary(x / 2) + to_string(x % 2);
}

vector<int> solution(string s) {
    vector<int> answer;
    int zero_count = 0;
    int result = 0;
    
    while (s != "1") {
        int s_length = s.length();
        int temp_zero_count = 0;
        for (char c : s) {
            if (c == '0') temp_zero_count++;
        }
        zero_count += temp_zero_count;
        s = get_binary(s_length - temp_zero_count);
        result++;
    }
    
    answer.assign({result, zero_count});
    return answer;
}