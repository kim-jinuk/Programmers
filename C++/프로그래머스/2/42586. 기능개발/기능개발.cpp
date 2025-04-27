#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> dev_day;
    queue<int> speeds_q;
    
    for (int i = 0; i < progresses.size(); ++i) {
        dev_day.push(progresses[i]);
        speeds_q.push(speeds[i]);
    }
    
    while (!dev_day.empty()) {
        if (dev_day.front() >= 100) {
            int n = 0;
            while (!dev_day.empty() && dev_day.front() >= 100) {
                n++;
                dev_day.pop();
                speeds_q.pop();
            }
            answer.push_back(n);
        }
        for (int i = 0; i < dev_day.size(); ++i) {
            dev_day.push(dev_day.front() + speeds_q.front());
            speeds_q.push(speeds_q.front());
            speeds_q.pop();
            dev_day.pop();
        }
    }
    
    return answer;
}