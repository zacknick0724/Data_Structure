#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using LL = long long int;
int main(){
	int n;
  	cin >> n;
  	vector<LL> vec;
  	while(n--){
    	string cmd;
      	cin >> cmd;
      	if(cmd == "I"){
          	LL data;
            cin >> data;
            vec.emplace_back(data);
        }else if(cmd == "R"){
          	LL data;
          	cin >> data;
          	if(find(vec.begin(),vec.end(),data) != vec.end()){
              	vec.erase(find(vec.begin(),vec.end(),data));
            }
        }else if(cmd == "C"){
          	LL data;
          	cin >> data;
          	int count = 0;
          	vector<LL>::iterator it;
          	for(it = vec.begin(); it != vec.end(); it++){
              	if(*it == data){
                  	count++;
                }
            }
          	cout << count << "\n";
        }
    }

}