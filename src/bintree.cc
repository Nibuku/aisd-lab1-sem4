#include <bintree/bintree.h>


Node::Node() {
	data = 0;
	left = nullptr;
	right = nullptr;
}

Node::Node(int key) {
	data = key;
	left = nullptr;
	right = nullptr;
}


Node* Binary_tree::get_root() const
{
	return _root;
}

int Binary_tree::get_size() const
{
	return _size;
}

Binary_tree::Binary_tree() {
	_root = new Node();
	_size = 1;
}

void Binary_tree::clear(Node* curr)
{
	if (!curr)
	{
		return;
	}

	if (curr->left)
	{
		clear(curr->left);
		curr->left = nullptr;  
	}
	if (curr->right)
	{
		clear(curr->right);
		curr->right = nullptr; 
	}

	delete curr;
	curr = nullptr; 
}

Binary_tree::Binary_tree(int key) {
	_root = new Node(key);
	_size = 1;
}


Binary_tree::~Binary_tree() {
	if (_root != nullptr) {
		clear(_root);
		 
	}
	_root=nullptr;
	_size = 0;
}

bool Binary_tree::insert(int key) {
	if (!_root) {
		_root = new Node(key);
		return true;
	}

	Node* tmp = _root;
	while (tmp && tmp->data != key) {
		
		if (tmp->data > key ) {
			if (tmp->left)
				tmp = tmp->left;
			else
				tmp->left = new Node(key);
			++_size;
			return true;
		}
		else{
			if (tmp->right)
				tmp = tmp->right;
			else
				tmp->right = new Node(key);
			++_size;
			return true;
		}

	}
	return false;
}

void Binary_tree::copy_tree(Node* root) {
	insert(root->data);
	if (root->left)
		copy_tree(root->left);
	if (root->right)
		copy_tree(root->right);
}

Binary_tree& Binary_tree::operator=(const Binary_tree& other) {
	if (_root == other.get_root())
		return *this;
	clear(_root);
	copy_tree(other.get_root());
	return *this;
}


void Binary_tree::print_tree(Node* root) {
	if (!root)
		return;
	cout << root->data;
	print_tree(root->left);
	print_tree(root->right);
}

void Binary_tree::print() {
	if (!_root)
		return;
	print_tree(_root);
}

Binary_tree::Binary_tree(const Binary_tree& other) {
	clear(_root);
	copy_tree(other.get_root());
}