#include <bintree/bintree.h>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

vector<int> duplication(vector<int> base) {
	if (base.empty())
		throw runtime_error("Invalid argument");
	vector<int> unique;
	vector<int> duplicate;
	Binary_tree search_tree = Binary_tree(base.back());
	base.pop_back();
	while (!base.empty()) {
		if (search_tree.insert(base.back()))
			unique.push_back(base.back());
		else
			duplicate.push_back(base.back());
		base.pop_back();
	}
	return 	duplicate;
	//return 	unique;
}


int main() {

	vector<int> base{ 6,5,9,6,2,8,1,0,2,4,3,7,4 };
	vector<int> new_vector = duplication(base);
	for (int i = 0; i < new_vector.size(); ++i)
		cout << new_vector[i]<< " ";
	cout << endl;

}