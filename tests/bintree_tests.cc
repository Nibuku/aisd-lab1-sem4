#include <gtest/gtest.h>

#include <bintree/bintree.h>
using namespace std;

 TEST(Node, NodeConstDefault) {
	Node first = Node();

	EXPECT_TRUE(first.data == 0);
	EXPECT_TRUE(first.left == nullptr);
	EXPECT_TRUE(first.right == nullptr);
}

 TEST(Node, NodeConstValue) {
	 Node first = Node(5);

	 EXPECT_TRUE(first.data == 5);
	 EXPECT_TRUE(first.left == nullptr);
	 EXPECT_TRUE(first.right == nullptr);
 }



