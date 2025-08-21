#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> temp;
    double fail_people, try_people;

    for (int i = 1; i < N + 1; ++i) {
        fail_people = 0;
        try_people = 0;
        for (int j = 0; j < stages.size(); ++j) {
            if (i <= stages[j]) {
                try_people++;
                if (i == stages[j]) fail_people++;
            }
        }
        if (try_people == 0) {
            temp.push_back(make_pair(0, i));
            continue;
        } 
        temp.push_back(make_pair(fail_people / try_people, i));
    }

    sort(temp.begin(), temp.end(), compare);

    for (pair<double, int> num : temp) {
        answer.push_back(num.second);
    }

    return answer;
}