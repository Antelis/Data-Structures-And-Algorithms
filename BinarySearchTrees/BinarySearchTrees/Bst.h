#pragma once
#include<iostream>
struct Node{
	int data;
	Node* left, * right;

	Node(int d):data(d),left(nullptr),right(nullptr){}
};

class Bst
{
private:
	Node* Root;
	//int lvl = 0;
	//Functions
	void insert(int&, Node*&);
	void InOrder(Node*);
	void PreOrder(Node*);
	void PostOrder(Node*);
	//void DeleteNode(int&, Node*&);
	//int Height(Node*);
	//int Height(Node*);
	void Ancestors(Node*,int);
	//bool Search(Node*, int);
	//Node* Search(Node*, int);
	int Level(Node*, int, int);
public:
	Bst():Root(nullptr){}
	~Bst()
	{
		DeleteBst(Root);
		std::cout << "\nDestructor: Bst has been deleted \n" << std::endl;
	}
	//functions
	void insert(int& value) { insert(value, Root); }
	void InOrder() { InOrder(Root); }
	void PreOrder() { PreOrder(Root); }
	void PostOrder() { PostOrder(Root); }
	void Bft();

	int Height(Node*);
	void Ancestors(int);
	//bool Search(int);
	//Node* Search(int);
	int Level(int);
	Node* getRoot();
	bool Search(Node*, int);


	//void SubstituteToMin(Node*&, Node*&);
	//void DeleteNode(int& value) { DeleteNode(value, Root); }
	void DeleteBst(Node*&);
};

