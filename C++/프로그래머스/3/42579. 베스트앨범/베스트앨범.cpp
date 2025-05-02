#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool sort_genres_play(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

bool sort_genres_songs(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genres_play;
    unordered_map<string, vector<pair<int, int>>> genres_songs;
    
    for (int i = 0; i < genres.size(); ++i) {
        genres_play[genres[i]] += plays[i];
        genres_songs[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> sorted_genres_play(genres_play.begin(), genres_play.end());
    sort(sorted_genres_play.begin(), sorted_genres_play.end(), sort_genres_play);
    
    for (const pair<string, int>& a : sorted_genres_play) {
        vector<pair<int, int>> b(genres_songs[a.first].begin(), genres_songs[a.first].end());
        sort(b.begin(), b.end(), sort_genres_songs);
        
        for (int i = 0; i < min(2, (int)b.size()); ++i) {
            answer.push_back(b[i].first);
        }
    }
    
    return answer;
}