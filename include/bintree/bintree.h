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
	Node* root;
	int m_size;
	void print_tree(Node*);
	void delete_tree(Node*);
	void copy_tree(Node*);

public:
	Binary_tree();
	Binary_tree(int key);
	Binary_tree(const Binary_tree& other);
	~Binary_tree();
	Binary_tree& operator=(const Binary_tree& other);
	void print();
	bool contains(int key);
	void insert(int key);
	void erase(int key);
	int size();
};