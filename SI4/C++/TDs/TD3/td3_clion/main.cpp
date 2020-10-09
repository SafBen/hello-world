#include "Node.h"
#include "Tree.h"

int main() {
    Node node = Node(5);
    cout << node.getValeur();
    Node droit = Node(7);
    node.addNodeLeftChild(&droit);
    cout << node.getNodeLeftChild().getValeur();

    Node n1=node;
    cout << n1.getNodeLeftChild().getValeur();

    cout << droit.isFeuille() << endl;

    cout << node;

//    Node* n2 = node.getPtrLeftChild()->getPtrLeftChild();
//    cout << n2->getValeur();
//
//    Node n3 = node.getNodeLeftChild().getNodeLeftChild();
//    cout << n3.getValeur();
    return 0;
}
