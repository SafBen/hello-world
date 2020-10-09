//
// Created by safwane on 05/10/2020.
//

#include "Node.h"

Node::Node(int valeur):valeur(valeur) {}

int Node::getValeur() {
    return this->valeur;
}

void Node::addNodeLeftChild(Node* left_child) {
    if (left_child== nullptr){
        exit(-1);
    }
    this->left_child=left_child;
}

void Node::addNodeRightChild(Node *right_child) {
    if (right_child== nullptr){
        exit(-1);
    }
    this->right_child=right_child;
}

Node Node::getNodeRightChild() {
    if (this->right_child==nullptr){
        exit(-1);
    }
    return (*this->right_child);
}

Node Node::getNodeLeftChild() {
    if (this->left_child==nullptr){
        exit(-1);
    }
    return (*this->left_child);
}

// Constructeur
//Node::Node(const Node &node):valeur(node.valeur)
//,left_child(node.left_child),right_child(node.right_child) {}

bool Node::isFeuille() {
    return this->left_child== nullptr && this->right_child== nullptr;
}

Node *Node::getPtrLeftChild() {
    return this->left_child;
}

Node *Node::getPtrRightChild() {
    return this->right_child;
}

ostream &operator<<(ostream &os, const Node &node) {
    if (!node.right_child->isFeuille()){
        os << node.valeur << "-" << node.right_child;
    }
    if (!node.left_child->isFeuille()){
        os << node.valeur << "|"<<node.left_child;
    }
    return os;
}

