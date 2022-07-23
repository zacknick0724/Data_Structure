#include <iostream>
#include <vector>
#include <string>

using namespace std;

int degree(vector<vector<int>> &adjacency_list, int u){
	return adjacency_list[u].size();
}

bool neighbor(vector<vector<int>> &adjacency_list, int u, int v){
	for(int i = 0; i < adjacency_list[u].size(); i++){
    	if(adjacency_list[u][i] == v){
          	return true;
        }
    }
  	return false;
}



int main(){
	int n,m,q;
  	cin >> n >> m >> q;
  	vector<vector<int>> adjacency_list(n+1);
  	for(int i = 0; i < m; i++){
      	int u,v;
      	cin >> u >> v;
      	adjacency_list[u].emplace_back(v);
      	adjacency_list[v].emplace_back(u);
    	}
  	while(q--){
		string cmd;
      	cin >> cmd;
      	if(cmd == "D"){
        	int u;
          	cin >> u;
          	cout << degree(adjacency_list,u) << "\n";
        }else{
			int u,v;
          	cin >> u >> v;
          	if(neighbor(adjacency_list,u,v)){
              	cout << "Y" << "\n";
            }else{
            	cout << "N" << "\n";
            }
        }
    }

}