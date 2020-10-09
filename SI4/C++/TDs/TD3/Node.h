//
// Created by safwane on 05/10/2020.
//
#include <iostream>
using namespace std;

#ifndef TD3_CLION_NODE_H
#define TD3_CLION_NODE_H

class Node {
private:
    int valeur = 0;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
public:
    Node(int);
    Node(Node const &node);
    int getValeur();
    void addNodeLeftChild(Node* left_child);
    void addNodeRightChild(Node* right_child);
    Node* getNodeLeftChild();
    Node* getNodeRightChild();
    bool isFeuille();
};
#endif //TD3_CLION_NODE_H
