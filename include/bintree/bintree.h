#pragma once
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <random>


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
	void clear(Node* curr);


public:
	Node* get_root() const;
	int get_size() const;

	Binary_tree();
	Binary_tree(int key);
	Binary_tree(const Binary_tree& other);
	~Binary_tree();

	void print_tree(Node* root);
	void copy_tree(Node* root);

	Binary_tree& operator=(const Binary_tree& other);
	void print();
	bool contains(int key);
	bool insert(int key);
	bool erase(int key);
};