#include <iostream>
#include <vector>

using namespace std;
using LL = long long int;

void merge(vector<LL> &arr, int front, int end, int mid){
  	vector<LL> temp;
  	int i = front;
  	int j = mid + 1;
  
  	while(i <= mid && j <= end){
      	if(arr[i] > arr[j]){
          	temp.push_back(arr[i]);
          	i++;
        }else{
        	temp.push_back(arr[j]);
          	j++;
        }
    }
  	while(i <= mid){
      	temp.push_back(arr[i]);
      	i++;
    }
  	while(j <= end){
    	temp.push_back(arr[j]);
      	j++;
    }
  	for(int i = 0; i < temp.size(); i++){
      	arr[front+i] = temp[i];
	}
  	
}
void merge_sort(vector<LL> &arr, int front, int end){
  if(front < end){
    	int mid = (front + end) /2;
    	merge_sort(arr,front,mid);
    	merge_sort(arr, mid+1,end);
    	merge(arr, front, end, mid);
  }
}
int main(){
	int n;
  	cin >> n;
  	vector<LL> arr(n);
  	for(auto &out:arr){
      	cin >> out;
    }
  	merge_sort(arr,0,n-1);
  	for(auto &out:arr){
      	cout << out << " ";
    }
  	cout << "\n";
}