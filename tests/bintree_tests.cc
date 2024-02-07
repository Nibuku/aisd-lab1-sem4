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

 TEST(Binary_tree, insertion_and_print) {
	 Binary_tree tree_one = Binary_tree(13);
	 tree_one.insert(2);
	 tree_one.insert(10);
	 tree_one.insert(5);
	 tree_one.insert(5);
	 tree_one.insert(13);
	 tree_one.insert(20);
	 tree_one.insert(-1);
	 cout << "Size: " << tree_one.get_size() << endl;;
	 tree_one.print();
	 
 }

 TEST(Binary_tree, Copy_constructor) {
	 Binary_tree tree_one = Binary_tree(13);
	 tree_one.insert(2);
	 tree_one.insert(10);
	 tree_one.insert(5);
	 tree_one.insert(5);
	 tree_one.insert(13);
	 tree_one.insert(20);
	 tree_one.insert(-1);
	 cout << "Size: " << tree_one.get_size() << endl;
	 cout << "original tree: ";
	 tree_one.print();
	 cout << endl;
	 Binary_tree second_tree(tree_one);
	 cout << "copy tree: ";
	 second_tree.print();

 }

 TEST(Binary_tree, operator_test) {
	 Binary_tree tree_one = Binary_tree(13);
	 tree_one.insert(4);
	 tree_one.insert(16);
	 tree_one.insert(12);
	 tree_one.insert(0);
	 tree_one.insert(13);
	 tree_one.insert(20);
	 tree_one.insert(-70);
	 cout << "Size: " << tree_one.get_size() << endl;
	 cout << "original tree: ";
	 tree_one.print();
	 cout << endl;
	 Binary_tree second_tree = tree_one;
	 cout << "operator's tree: ";
	 second_tree.print();
	 
 }

 TEST(Binary_tree, contains_test) {
	 Binary_tree tree_one = Binary_tree(16);
	 tree_one.insert(1);
	 tree_one.insert(16);
	 tree_one.insert(2);
	 tree_one.insert(0);
	 tree_one.insert(13);
	 tree_one.insert(100);
	 tree_one.insert(-7);
	 cout << "Size: " << tree_one.get_size() << endl;
	 cout << "original tree: ";
	 tree_one.print();
	 cout << endl;
	 cout<<"Contains 5?: "<<tree_one.contains(5)<<endl;
	 cout << "Contains 13?: " << tree_one.contains(13) << endl;
 }
