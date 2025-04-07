#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
//노드의 정의
class Node {
public :
	int number; // Node안에 값
	Node* next; // Node안에 next 다음 노드를 가르킬 준비
	Node(int value) :number(value), next(nullptr) {}; //Node 선안과 동시에 초기화
};
//Class Tree 만들기 
class Tree {
private://private으로 maps 접근 불가
	map<int, Node*>maps;
public:
	void CreateNode(int parent,int child) {
		Node* newNode = new Node(child);//자식을 이용한 노드 생성 그 자식 노드는 newNode가 가르킨다
		// maps의 key값 parent 값이 없다면
		if (maps.find(parent)==maps.end()){
			maps[parent] = newNode;
		}
		// 부모 키가 있다면
		else {
			Node* current = maps[parent];
			while (current->next) {
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void print() {
		for (auto& pair : maps) {
			cout << pair.first << " :" << " ";
			Node* childname = pair.second;
			while (childname) {
				cout << childname->number << " ";
				childname = childname->next;
			}
			cout << endl;
		}
	}


};

int main() {
	int number; // 5
	cin >> number;
	Tree tree;
	// 1 1 2 3
	for (size_t i = 2; i <=number; i++) {
		int parent;
		cin >> parent;
		tree.CreateNode(parent, i);
	}
	tree.print();

	return 0;
}