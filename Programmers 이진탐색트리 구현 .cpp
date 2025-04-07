#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Tree
class Node {
public :
	int number;
	Node* left, * right;
	Node(int value) :number(value), left(nullptr), right(nullptr) {};
};
class BST {
private :
	Node* root;
	Node* createNode(Node* node, int numbering) {
		if (!node) {
			return new Node(numbering);
		}
		if (numbering > node->number) {
			node->right = createNode(node->right, numbering);
		}
		else {
			node->left = createNode(node->left, numbering);
		}
		return node;
	}
	bool searchBST(Node* node, int new_numbering ){
		if (!node) { return false; }
		if (node->number == new_numbering) {
			return true;
		}
		else if (node->number < new_numbering) {
			return searchBST(node->right, new_numbering);
		}
		else {
			return searchBST(node->left, new_numbering);
		}
	}
public :
	BST() :root(nullptr) {};
	void insert(vector<int>array) {
		for (const auto& s : array) {
			root =createNode(root,s);
		}
	}
	vector<string>search(vector<int>array2) {
		vector<string>answer;
		for (const auto& v : array2) {
			if (searchBST(root, v) > 0) {
				answer.push_back("true");
			}
			else {
				answer.push_back("false");
			}
			
		}
		return answer;
	}

};


int main() {
	BST findname;
	vector<int>name = { 5,3,8,4,2,1,7,10 };
	vector<int>find = { 1,2,5,6 };
	findname.insert(name);
	vector<string>tull=findname.search(find);

	cout << "\"";
	for (auto it = tull.begin(); it < tull.end();++it) {
		cout << *it;
		if (it != tull.end() - 1) {
			cout << ",";
		}
	}
	cout << "\"";
	cout << endl;
	BST findname2;
	vector<int>name2 = { 1,3,5,7,9 };
	vector<int>find2 = { 2,4,6,8,10};
	findname2.insert(name2);
	vector<string>tull2 = findname2.search(find2);

	cout << "\"";
	for (auto it = tull2.begin(); it < tull2.end(); ++it) {
		cout << *it;
		if (it != tull2.end() - 1) {
			cout << ",";
		}
	}
	cout << "\"";
	return 0;

}