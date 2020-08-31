#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n = 3, k=10;
    vector<int> coin = {1, 2, 5};
    int temp;
    int dp[1001] = {0,};
    
    
	dp[0] = 1;
	
    for(auto c: coin){
        //금액
        for(int j=1; j<=k; j++){
            if(j -c >=0) 
                dp[j] = dp[j] + dp[j-c];
        }
    }
    cout << dp[k] << endl;
}