#include <iostream>
#include <vector>
#include <string>

using namespace std;
using LL = long long;

bool my_binary_search(vector<LL> &arr , LL value){
	int left = 0;
  	int right = arr.size() - 1;
  	int mid;
  	while(left <= right){
      	mid = (left + right) /2;
    	if(arr[mid] == value){
          	return true;
        }else if(arr[mid] > value){
          	left = mid + 1;
        }else{
          	right = mid - 1;
        }
    }
  	return false;
}

bool sequential_search(vector<LL> &arr, LL value){
	for(auto &out:arr){
      	if(out == value){
          	return true;
        }
    }
  	return false;
}
int main(){
	int n;
  	int m;
  	cin >> n >> m;
  	vector<LL> A(n);
  	vector<LL> Q(m);
  	for(auto &out:A){
		cin >> out;
    }
  	for(auto &out:Q){
      	cin >> out;
    }
  	for(auto &out:Q){
      	if(my_binary_search(A,out) == true){
          	cout << "Y" << " ";
        }else{
        	cout << "N" << " ";
        }
    }
  	
}