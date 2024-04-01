#include <bintree/bintree.h>


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

Binary_tree::Binary_tree(): _root(nullptr), _size(0) {}

void Binary_tree::clear(Node* root){ 
	if (!root) {
		return;
	}
	clear(root->left);
	clear(root->right);
	delete root;
	root=nullptr;	
}

Binary_tree::Binary_tree(int key) {
	_root = new Node(key);
	_size = 1;
}

Binary_tree::~Binary_tree() {
		clear(_root);
		_root = nullptr;
		_size = 0;
}

bool Binary_tree::insert(int key) {
	if (!_root) {
		_root = new Node(key);
		return true;
	}

	Node* tmp = _root;
	while (tmp && tmp->data != key) {
		
		if (tmp->data > key) {
			if (tmp->left)
				tmp = tmp->left;
			else {
				tmp->left = new Node(key);
				++_size;
				return true;
			}
		}
		else {
			if (tmp->right)
				tmp = tmp->right;
			else {
				tmp->right = new Node(key);
				++_size;
				return true;
			}
		}
	}
	return false;
}

Node* Binary_tree::copy_tree(Node* root, Node* other) {
	if (!other)
		return nullptr;

	root = new Node(other->data);
	root->left = copy_tree(root->left, other->left);
	root->right = copy_tree(root->right, other->right);
	return root;
}

Binary_tree& Binary_tree::operator=(const Binary_tree& other) {
	if (this != &other) {
		clear(other._root);
		copy_tree(_root, other._root);
	}
	return *this;
}

void Binary_tree::print_tree(Node* root) {
	if (!root)
		return;
	cout << root->data << " ";
	print_tree(root->left);
	
	print_tree(root->right);

}

void Binary_tree::print() {
	if (!_root)
		return;
	print_tree(_root);
}

Binary_tree::Binary_tree(const Binary_tree& other) {
	_root = nullptr;
	_root=copy_tree(_root, other.get_root());
}

bool Binary_tree::contains(int key) {
	Node* tmp = _root;
	while (tmp)
	{
		if (tmp->data == key)
			return true;
		if (tmp->data > key)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	return false;
}

bool Binary_tree::erase( int key) {
	Node* tmp = _root;
	Node* parent = nullptr;
	while (tmp && tmp->data != key)
	{
		parent = tmp;
		if (tmp->data > key)
		{
			tmp = tmp->left;
		}
		else
		{
			tmp = tmp->right;
		}
	}
	if (!tmp)
		return false;
	if (!tmp->left)
	{
			
		if (parent && parent->left == tmp)
			parent->left = tmp->right;
		if (parent && parent->right == tmp)
			parent->right = tmp->right;
		--_size;
		delete tmp;
		return true;
	}
	if (!tmp->right)
	{
			
		if (parent && parent->left == tmp)
			parent->left = tmp->left;
		if (parent && parent->right == tmp)
			parent->right = tmp->left;
		--_size;
		delete tmp;
		return true;
	}

	Node* replace = tmp->right;
	while (replace->left)
		replace = replace->left;
	int replace_value = replace->data;
	erase(replace_value);
	tmp->data = replace_value;
	return true;
}
