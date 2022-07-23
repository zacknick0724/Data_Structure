#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
  	int n;
  	cin >> n;
	vector<int> vec(1000000);
  	while(n--){
    	string cmd;
      	cin >> cmd;
      	if(cmd == "I"){
          	int index;
          	cin >> index;
          	vec[index]++;
        }else if(cmd == "R"){
          	int index;
          	cin >> index;
          	if(vec[index] > 0){
            	vec[index]--;
            }
        }else if(cmd == "C"){
          	int index;
          	cin >> index;
			cout << vec[index] << "\n";
        }
    }
}