#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> create_vector(const vector<string>& want, const vector<int>& number) {
    vector<string> arr;
    for (int i = 0; i < want.size(); ++i) {
        for (int j = 0; j < number[i]; ++j) {
            arr.push_back(want[i]);
        }
    }
    return arr;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    vector<string> want_arr = create_vector(want, number);
    int n = want_arr.size();
    
    for (int i = 0; i < discount.size() - n + 1; ++i) {
        unordered_map<string, int> discount_map;
        for (int j = 0; j < n; ++j) {
            discount_map[discount[i + j]]++;
        }
        for (int j = 0; j < n; ++j) {
            discount_map[want_arr[j]]--;
        }
        for (int j = 0; j < n; ++j) {
            if (discount_map[want_arr[j]] != 0) {
                answer--;
                break;
            }
        }
        answer++;
    }
    
    return answer;
}