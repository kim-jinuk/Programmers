#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), [](int a, int b){ return a < b;});
    int left = 0, right = people.size() - 1;
    
    while (left <= right) {
        if (left == right) return ++answer;
        if (people[left] + people[right] <= limit) left++;
        right--;
        answer++;
    }
    
    return answer;
}