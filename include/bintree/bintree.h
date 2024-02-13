#pragma once
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left; 
	Node* right;
	Node();
	Node(int key);
};


class Binary_tree {
	Node* _root;
	int _size;

	void clear(Node* root);
	void print_tree(Node* root);
	Node* copy_tree(Node* root);
	
public:
	Node* get_root() const;
	int get_size() const;

	Binary_tree();
	Binary_tree(int key);
	Binary_tree(const Binary_tree& other);
	~Binary_tree();

	Binary_tree& operator=(const Binary_tree& other);
	void print();
	bool contains(int key);
	bool erase(int key);
	bool insert(int key);
	
};