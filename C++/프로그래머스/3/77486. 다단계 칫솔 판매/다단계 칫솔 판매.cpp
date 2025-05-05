#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, string> referral_relations;
    unordered_map<string, int> profit;
    
    for (int i = 0; i < enroll.size(); ++i) {
        referral_relations[enroll[i]] = referral[i];
    }
    
    for (int i = 0; i < seller.size(); ++i) {
        int value = amount[i] * 100;
        string s = seller[i];
        
        while (s != "-" && value > 0) {
            int value_1 = value - (value / 10);
            value /= 10;
            profit[s] += value_1;
            s = referral_relations[s];
        }
    }
    
    for (int i = 0; i < enroll.size(); ++i) {
        answer.push_back(profit[enroll[i]]);
    }
    
    return answer;
}