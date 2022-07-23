#include <iostream>
#include <vector>
#include <string>

using namespace std;

int degree(vector<vector<int>> &adjacency_matrix,int u){
	int count = 0;
  	for(int i = 1; i < adjacency_matrix[u].size(); i++){
    	if(adjacency_matrix[u][i] > 0){
          	count++;
        }
    }
  	return count;
}

bool neighbor(vector<vector<int>> &adjacency_matrix, int u, int v){
	if(adjacency_matrix[u][v] > 0){
      	return true;
    }else{
    	return false;
    }
}


int main(){
	int n,m,q;
  	cin >> n >> m >> q;
  	vector<vector<int>> adjacency_matrix(n + 1, vector<int>(n + 1,0));
  	for(int i = 0; i < m; i++){
    	int u,v;
      	cin >> u >> v;
      	adjacency_matrix[u][v]++;
        adjacency_matrix[v][u]++;
    }
	while(q--){
      	string cmd;
     	cin >> cmd;
    	if(cmd == "D"){
          	int u;
          	cin >> u;
          	cout << degree(adjacency_matrix,u) << "\n";
        }else{
          	int u, v;
          	cin >> u >> v;
          	if(neighbor(adjacency_matrix,u,v)){
          		cout << "Y" << "\n";
            }else{
            	cout << "N" << "\n";
            }
        }
    }
}