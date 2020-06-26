#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> people, vector<int> tshirts) {
    int answer = 0;
    int j = 0;
    sort(people.begin(), people.end(), greater<int>());
    sort(tshirts.begin(), tshirts.end(), greater<int>());
    if(people.size() <= tshirts.size()) {
        for(int i = 0; i<tshirts.size(); i++) {
        
            if(people[j] <= tshirts[i]) {
                answer++;
                j++;
            }
            if(j == people.size())
                break;
        }
    }
    else {
        for(int i = 0; i<people.size(); i++) {
            j = tshirts.size()-1;
            if(people[i] <= tshirts[j]) {
                answer++;
                j--;
            }
            if(j == 0)
                break;
        }
    }
    return answer;
}