#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> pocket_set;
    
    for (int num : nums) pocket_set.insert(num);
    answer = min(nums.size() / 2, pocket_set.size());
    
    return answer;
}