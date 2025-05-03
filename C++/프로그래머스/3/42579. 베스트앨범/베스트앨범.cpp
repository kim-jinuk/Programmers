#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool sort_genres_count(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

bool sort_songs(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genres_count;
    unordered_map<string, vector<pair<int, int>>> songs;
    
    for (int i = 0; i < genres.size(); ++i) {
        genres_count[genres[i]] += plays[i];
        songs[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> sorted_genres_count(genres_count.begin(), genres_count.end());
    sort(sorted_genres_count.begin(), sorted_genres_count.end(), sort_genres_count);
    
    for (pair<string, int>& a : sorted_genres_count) {
        vector<pair<int, int>> sorted_songs(songs[a.first].begin(), songs[a.first].end());
        sort(sorted_songs.begin(), sorted_songs.end(), sort_songs);
        
        for (int i = 0; i < min(2, (int)sorted_songs.size()); ++i) {
            answer.push_back(sorted_songs[i].first);
        }
    }
    
    return answer;
}