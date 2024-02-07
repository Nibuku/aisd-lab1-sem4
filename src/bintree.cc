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

void Binary_tree::clear(Node* root){ 
	if (!root) {
		return;
	}
	if (root->left && root->right) {
		clear(root->left);
		clear(root->right);
		delete root;
		root=nullptr;
	}
	
}

Binary_tree::Binary_tree(int key) {
	_root = new Node(key);
	_size = 1;
}


Binary_tree::~Binary_tree() {
	if (_root != nullptr) {
		clear(_root);
	}
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

Node* Binary_tree::copy_tree(Node* root) {
	insert(root->data);
	if (root->left)
		copy_tree(root->left);
	if (root->right)
		copy_tree(root->right);
	return this->_root;
}

Binary_tree& Binary_tree::operator=(const Binary_tree& other) {
	if (this != &other) {
		// очищаем текущее дерево
		clear(other._root);
		// копируем корень дерева
		if (other._root != nullptr)
			_root = new Node(*other._root);
		// копируем остальные узлы дерева
		copy_tree(other._root);
	}
	return *this;
}

void Binary_tree::print_tree(Node* root) {
	if (!root)
		return;
		//cout << root->data;
	print_tree(root->left);
	cout << root->data<<" ";
	print_tree(root->right);
}

void Binary_tree::print() {
	if (!_root)
		return;
	print_tree(_root);

}

Binary_tree::Binary_tree(const Binary_tree& other) {
	_root = nullptr;
	_root=copy_tree(other.get_root());
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


bool _erase(Node* current, int key) {
	if (!current) {
		return false;
	}
	if (current->data == key) {
		if (!current->left) {
			Node* right_node = current->right;
			delete current;
			current = right_node;
			return true;
		}
		if (!current->right) {
			Node* left_node = current->left;
			delete current;
			current = left_node;
			return true;
		}
		else {
			Node* min_element = current->right;
			while (min_element->left) {
				min_element = min_element->left;
			}
			current->data = min_element->data;
			return _erase(current->right, min_element->data);
		}
	}
	if (current->data > key) {
		return _erase(current->left, key);
	}
	if (current->data < key) {
		return _erase(current->right, key);
	}
	return false;
}
