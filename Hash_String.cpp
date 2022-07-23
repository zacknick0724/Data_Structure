#include <iostream>
#include <vector>
#include <string>
using namespace std;
using LL = long long int;

/*Create hash formula function*/
LL roll_hash(const string &str,const vector<LL> &power,const LL &p){
	int ans = 0;
  	for(int i = 0; i < str.size(); i++){
      	LL ci = str[i] - 'a' + 1;
      	ans = (ans + power[str.size()-i-1] *ci %p) %p;
    }
  	return ans;
}

/*Concate the two string for using hash method*/
LL concate(const LL hash_i, const LL hash_j, const LL hash_j_len,const vector<LL> &power, const LL &p){
	LL result = ((hash_j) + (hash_i* power[hash_j_len] %p)) %p; 
    return result;
}


int main(){
	LL a = 31;
  	LL p = 1e9 + 7;
  	/*Caculate the hash power a*/
  	vector<LL> power(5001,1);
  	for(int i = 1; i <= 5000; i++){
      	power[i] = power[i-1] * a % p;
    }
  	int n,q;
    cin >> n >> q;
  	/*Create the hash */
  	vector<LL> hash(n);
  	vector<LL> hash_length(n);
  	for(int i = 0; i < n; i++){
		    string str;
      		cin >> str;
      		hash[i] = roll_hash(str,power,p);
      		hash_length[i] = str.length();
    }
	while(q--){
    	string cmd;
      	cin >> cmd;
      	int i, j;
      	cin >> i >> j;
      	i -= 1; j -= 1;
      	// 1-index to 0-index 
      	if(cmd == "E"){
			if(hash[i] == hash[j]){
              	cout << "Y" << "\n";
            }else{
            	cout << "N" << "\n";
            }
        }else{
          	hash[i] = concate(hash[i],hash[j],hash_length[j],power,p);
			hash_length[i] = hash_length[i] + hash_length[j];
        }
    }
  	
}