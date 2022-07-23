#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node{
	int data;
  	struct node* next;
  	struct node* prev;
};

using node_ptr = node*;

void insert_head(node_ptr &head, node_ptr &tail, int new_data){
	if(head == NULL){
      	node_ptr new_node = new node;
    	new_node->data = new_data;
      	new_node->next = NULL;
      	new_node->prev = NULL;
      	head = tail = new_node;
    }else{
    	node_ptr new_node = new node;
      	new_node->data = new_data;
      	new_node->next = NULL;
      	new_node->prev = NULL;
      	head->prev = new_node;
      	new_node->next = head;
      	head = new_node;
    }
}

void insert_tail(node_ptr &head, node_ptr &tail, int new_data){
  	if(head == NULL){
      	node_ptr new_node = new node;
      	new_node->data = new_data;
      	new_node->prev = NULL;
      	new_node->next = NULL;
      	head = tail = new_node;
    }else{
      	node_ptr new_node = new node;
      	new_node->data = new_data;
      	new_node->prev = NULL;
      	new_node->next = NULL;
      	tail->next = new_node;
      	new_node->prev = tail;
      	tail = new_node;
    }

}


void remove_head(node_ptr &head, node_ptr &tail){
	if(head == NULL && tail == NULL){
      	return;
    }else if(head == tail){
      	delete head;
      	head = tail = NULL;
    }else{
      	node_ptr node = head->next; // 先指向head->next
      	node_ptr temp = head; // 用來存head,要release掉的
      	node->prev = NULL; // 將現在的指向NULL
      	head = node; // head 再指向 node
      	delete temp;
    }
}

void remove_tail(node_ptr &head, node_ptr &tail){
	if(head == NULL && tail == NULL){
      	return;
    }else if(head == tail){
      	delete head;
      	head = tail = NULL;
    }else{
    	node_ptr node = tail->prev;
      	node_ptr temp = tail;
      	node->next = NULL;
      	tail = node;
      	delete temp;
    }
}

void delete_list(node_ptr &head, node_ptr &tail){
	while(head != NULL){
    	remove_head(head,tail);
    }
}

void list_search(node_ptr head, node_ptr tail, int target){
	if(head == NULL){
      	cout << "E\n";
      	return;
    }
  	bool You_found_It = false;
  	for(node_ptr temp = head; temp != NULL;temp =temp->next){
      	if(temp->data == target){
          	You_found_It = true;
        }
    }
  	if(You_found_It){
      	cout << "Y" << "\n";
    }else{
      	cout << "N" << "\n";
    }
}
void output(node_ptr head){
	if(head == NULL){
      	cout << "E\n";
      	return;
    }
  	for(node_ptr temp = head; temp != NULL; temp = temp->next){
      	cout << temp->data << " ";
    }
  	cout << "\n";
}


int main(){
	int n;
  	cin >> n;
  	node_ptr head = NULL;
  	node_ptr tail = NULL;
  	while(n--){
    	string cmd;
      	cin >> cmd;
      	if(cmd == "IH"){
          	int data;
          	cin >> data;
          	insert_head(head,tail, data);
        }else if(cmd == "IT"){
          	int data;
          	cin >> data;
          	insert_tail(head, tail,data);
        }else if(cmd == "RH"){
          	remove_head(head,tail);
        }else if(cmd == "RT"){
          	remove_tail(head,tail);
        }else if(cmd == "S"){
          	int data;
          	cin >> data;
          	list_search(head,tail,data);
        }else{
          	output(head);

        }
    }
	delete_list(head,tail);
}