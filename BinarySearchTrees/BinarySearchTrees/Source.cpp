#include <iostream>
#include "Bst.h"
int main() {
    Bst tree;

    int values[] = { 7, 3, 9, 2, 5, 8, 10, 1, 4, 6 };

    for (int value : values) {
        tree.insert(value);
    }

    std::cout << "Preorder Traversal: ";
    tree.PreOrder();
    std::cout << std::endl;

    std::cout << "Inorder Traversal: ";
    tree.InOrder();
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    tree.PostOrder();
    std::cout << std::endl;
    std::cout << "Level by level: ";
    tree.Bft();


    int height = tree.Height(tree.getRoot());
    std::cout << "Height of the tree is: " << height << std::endl;

    int num = 4;
    std::cout << "Ancestors of " << num << ": ";
    tree.Ancestors(num);
    std::cout << std::endl;
    num = 11;
    int level = tree.Level(num);
    if (level != -1) {
        std::cout << "Level of node with value " << num << " is: " << level << std::endl;
    }
    else {
        std::cout << "Node with value " << num << " not found in the tree ):" << std::endl;
    }
    return 0;
}