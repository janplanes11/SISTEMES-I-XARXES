#include <iostream>
#include "Vector2.h"
#include "Node.h"
class Tree : InNodeContent {
public:
    Tree() {

    }
    ~Tree() {

    }
};
int main()
{
    Vector2 v1, v2;
    Node* node = new Node(Vector2());
    InNodeContent* content = node->GetContent();
    Tree* tree = node->GetContent<Tree>();
    if (node->TryGetContent<Tree>(tree)) {
        
    }
}

