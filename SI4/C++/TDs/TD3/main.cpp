#include "Node.h"
#include "Tree.h"

int main() {
    Node node = Node(5);
    cout << node.getValeur();
    Node droit = Node(7);
    node.addNodeLeftChild(&droit);
    cout << node.getNodeLeftChild()->getValeur();

    Node n1=node;
    cout << n1.getNodeLeftChild()->getValeur();

    cout << droit.isFeuille();
    return 0;
}
