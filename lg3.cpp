#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
bool comp()
vector<vector<int>> copyitem;
vector<int> solution(vector<int> healths, vector<vector<int>> items) {
    vector<int> answer;
    vector<int> temp;
    vector<int> temp2;
    
    copyitem = items;
    int j = 0;
    sort(items.begin(), items.end(), greater<vector<int>>());
    sort(healths.begin(), healths.end(), greater<int>());

    if(items.size() >= healths.size()) {
        for(int i =0; i < items.size(); i++) {
            if(items[i][1] <= healths[j]-100) {
                temp.push_back(items[i][0]);
                j++;
            }
            if(j==healths.size())
                break;
        }

    }
    else {
        for(int i =0; i < healths.size(); i++) {
            if(items[j][1] <= healths[i]-100) {
                temp.push_back(items[j][0]);
                j++;
            }
            if(j==items.size())
                break;
        }
    }

    for(int i = 0; i < temp.size(); i++) {
        for(int j = 0; j < copyitem.size(); j++) {
            if(temp[i] == copyitem[j][0])
                answer.push_back(j+1);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}