// 인수로 받은 문자열 s를 사전순으로 정렬된 문자열로 반환하는 solution() 함수 구현
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    vector<int> cnt(26);
    string answer;

    for (char c : s) {
        cnt[c - 'a']++;
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            answer += ('a' + i);
        }
    }

    return answer;
}