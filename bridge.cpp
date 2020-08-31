#include <string>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<pair<int,int> > ing;
    int temp = 0;
    while(!truck_weights.empty() || !ing.empty()) {
        int f = truck_weights.front();
	
	int a = temp + f;
	cout << a << endl;
        while(!truck_weights.empty() &&temp + f <= weight) {
            temp = temp + f;
            //cout << f << endl;
	    truck_weights.erase(truck_weights.begin());
            //cout << truck_weights.front() << endl;
	    for(int i = 0 ; i < ing.size(); i++) {
                ing[i].first++;
            }
            
            if( !ing.empty() && ing.front().first == bridge_length) {
                temp = temp - ing.front().second;
		ing.erase(ing.begin());
            }
            
            ing.push_back(make_pair(1,f));
            
            answer++;
        }
        
        if( !ing.empty() && ing.front().first == bridge_length) {
            temp = temp - ing.front().second;
            ing.erase(ing.begin());
        }
        
        for(int i =0; i < ing.size(); i++) {
            ing[i].first++;
        }
        
        answer++;   
    }
    //answer++;
    return answer;
}

int main() {
    vector<int> a;
    a.push_back(7);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    int ret = solution(2, 10, a);
    cout << ret << endl;
    return 0;
}
