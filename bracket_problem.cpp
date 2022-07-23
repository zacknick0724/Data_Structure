#include <bits/stdc++.h>
using namespace std;

bool bracket_problem(string str){
	stack<char> bracket_stack;
  	char temp;
  	int n = str.length();
  	for(int i = 0; i < n; i++){
        if(str[i] == '{' || str[i] == '(' || str[i] == '['){
            bracket_stack.push(str[i]);
            continue;
        }

        if(str[i] == ')'){
          	if(bracket_stack.empty()){
            	return false;
        	}else{
              temp = bracket_stack.top();
              bracket_stack.pop();
              if(temp == '{' || temp == '['){
                    return false;
              }
            }
        }
        if(str[i] == ']'){
            if(bracket_stack.empty()){
            	return false;
        	}else{
                temp = bracket_stack.top();
                bracket_stack.pop();
                if(temp == '(' || temp == '{'){
                    return false;
                }
            }
        }
      	if(str[i] == '}'){
          	if(bracket_stack.empty()){
            	return false;
        	}else{
                temp = bracket_stack.top();
                bracket_stack.pop();
                if(temp == '[' || temp == '('){
                    return false;
                }
            }
        }
    }
    if(bracket_stack.empty()){
      	return true;
    }else{
      	return false;
    }
}

int main(){
	int n;
  	cin >> n;
  	for(int i = 0; i < n; i++){
      	string str;
      	cin >> str;
      	if(bracket_problem(str)){
          	cout << "Y" << "\n";
        }else{
          	cout << "N" << "\n";
        }
    }
}