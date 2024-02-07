#include <gtest/gtest.h>

#include <bintree/bintree.h>

using namespace std;

 TEST(Node, NodeDefault) {
	Node first = Node();
	//cout << first.data << endl;
	//cout << first.left << endl;
	//cout << first.right << endl;
	EXPECT_TRUE(first.data == 0);
	EXPECT_TRUE(first.left == nullptr);
	EXPECT_TRUE(first.right == nullptr);
}

 TEST(Node, NodeValue) {
	 Node first = Node(5);
	 //cout << first.data << endl;
	 //cout << first.left << endl;
	 //cout << first.right << endl;
	 EXPECT_TRUE(first.data == 5);
	 EXPECT_TRUE(first.left == nullptr);
	 EXPECT_TRUE(first.right == nullptr);
 }

 TEST(Binary_tree, Binary_tree_test) {
	 Binary_tree tree_one = Binary_tree(0);
	 cout << "Value: " << tree_one.get_root()->data << endl;
	 cout << "Left pointer: " << tree_one.get_root()->left << endl;
	 cout << "Right pointer: " << tree_one.get_root()->right << endl;
	 cout << "Size of tree: " << tree_one.get_size() << endl;
 }

 TEST(Binary_tree, Binary_tree_value_test) {
	 Binary_tree tree_one = Binary_tree(7);
	 cout << "Value: " << tree_one.get_root()->data << endl;
	 cout << "Left pointer: " << tree_one.get_root()->left << endl;
	 cout << "Right pointer: " << tree_one.get_root()->right << endl;
	 cout << "Size of tree: " << tree_one.get_size() << endl;
 }

 TEST(Binary_tree, destructor) {
	 Binary_tree tree_one = Binary_tree(7);
	 tree_one.~Binary_tree();
	 cout << "Root: " << tree_one.get_root() << endl;
 }

