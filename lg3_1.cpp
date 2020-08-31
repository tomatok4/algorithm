#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool compare(const pair<int, int>&a, const pair<int, int>& b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<int> healths, vector<vector<int>> items) {
    vector<int> answer;
    vector<pair<int,int>> tmp_ans;
    int h_size=healths.size();
    int i_size=items.size();
    vector<pair<int,int>> ite;
    
    for(auto it : items){
        ite.push_back({it.front(),it.back()});
    }
    sort(healths.begin(),healths.end(),greater<int>());
    sort(ite.begin(),ite.end(),compare);
    
    for(int i=0; i<i_size; i++){
        for(auto it : healths){
            if(ite[i].second<it){
                tmp_ans.push_back({ite[i].first,ite[i].second});
                ite[i].second=10000001;
            }
        }
    }
    
    for(int i=0; i<i_size; i++){    
        for(auto it : tmp_ans){
            if(items[i].front() == it.first && items[i].back() == it.second){
                answer.push_back(i+1);
            }
        }
    }
    
    return answer;
}