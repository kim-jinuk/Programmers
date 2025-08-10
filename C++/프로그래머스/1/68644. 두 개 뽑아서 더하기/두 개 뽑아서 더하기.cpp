#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> tmp;
    vector<int> answer;
    int size = numbers.size();
    
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            tmp.insert(numbers[i] + numbers[j]);
        }
    }
    
    for (const auto& v : tmp) {
        answer.push_back(v);
    }
    
    return answer;
}