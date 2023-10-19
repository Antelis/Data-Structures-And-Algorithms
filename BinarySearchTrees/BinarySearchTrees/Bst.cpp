#include "Bst.h"
#include <queue>
#include <algorithm>
// Private member function for inserting a value in the BST
void Bst::insert(int& value, Node*& currentNode) {
    if (currentNode == nullptr) {
        currentNode = new Node(value);
        return;
    }

    if (value < currentNode->data) {
        insert(value, currentNode->left);
    }
    else if (value > currentNode->data) {
        insert(value, currentNode->right);
    } else { std::cout << "Repeted element\n"<<std::endl; }
}
void Bst::PreOrder(Node* currentNode) {
    if (currentNode == nullptr) {
        return;
    }
    std::cout << currentNode->data << " ";
    PreOrder(currentNode->left);
    PreOrder(currentNode->right);
}
void Bst::InOrder(Node* currentNode) {
    if (currentNode == nullptr) {
        return;
    }
    InOrder(currentNode->left);
    std::cout << currentNode->data << " ";
    InOrder(currentNode->right);
}
void Bst::PostOrder(Node* currentNode) {
    if (currentNode == nullptr) {
        return;
    }
    PostOrder(currentNode->left);
    PostOrder(currentNode->right);
    std::cout << currentNode->data << " ";

}
void Bst::Bft() {
    if (Root == nullptr) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    std::queue<Node*> levelQueue;
    levelQueue.push(Root);

    while (!levelQueue.empty()) {
        Node* currentNode = levelQueue.front();
        levelQueue.pop();

        std::cout << currentNode->data << " ";

        if (currentNode->left != nullptr)
            levelQueue.push(currentNode->left);

        if (currentNode->right != nullptr)
            levelQueue.push(currentNode->right);
    }
    std::cout << std::endl;
}

//int Bst::Height() { //Altura que accede el usuario, regresa el integer que calcule la verdadera
   // return Height(Root); //Funcion de altura
//}
int Bst::Height(Node* currentNode) { 
    if (currentNode == nullptr) {
        return -1;
    }

    int leftHeight = Height(currentNode->left);
    int rightHeight = Height(currentNode->right);

    return std::max(leftHeight, rightHeight) + 1;
}

void Bst::Ancestors(Node* currentNode, int target) {
    if (currentNode == nullptr) {
        return;
    }

    if (currentNode->data == target) {
        return;
    }

    if (currentNode->data > target) {
        std::cout << currentNode->data << " ";
        Ancestors(currentNode->left, target);
    }
    else {
        std::cout << currentNode->data << " ";
        Ancestors(currentNode->right, target);
    }
}
void Bst::Ancestors(int target) {
    if (!this->Search(this->getRoot(), target)) { 
        std::cout << "Target not found in tree ):" << std::endl;
        return; 
    }
   Ancestors(Root, target);
}

int Bst::Level(int target) {
    return Level(Root, target, 0);
}
int Bst::Level(Node* currentNode, int target, int lvl) {

    if (currentNode == nullptr) { return -1; }

    if (currentNode->data == target) { return lvl; }

    int leftLevel = -1;
    int rightLevel = -1;

    if (target > currentNode->data) {
        rightLevel = Level(currentNode->right, target, lvl + 1);
    }
    else if (target < currentNode->data) {
        leftLevel = Level(currentNode->left, target, lvl + 1);
    }
    if (leftLevel != -1) {
        return leftLevel;
    }

    return rightLevel;
}


Node* Bst::getRoot() {
    return Root;
}


void Bst::DeleteBst(Node*& node) {
    if (node == nullptr) {
        return;
    }

    DeleteBst(node->left);
    DeleteBst(node->right);

    delete node;
    node = nullptr;
}

bool Bst::Search(Node* currentNode, int target) {
    if (currentNode == nullptr) {
        return false;
    }

    if (currentNode->data == target) {
        return true;
    }

    if (target > currentNode->data) {
        return Search(currentNode->right, target);
    }
    else {
        return Search(currentNode->left, target);
    }
}

