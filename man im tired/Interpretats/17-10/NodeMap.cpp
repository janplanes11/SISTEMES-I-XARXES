#include <iostream>
#include "Vector2.h"
#include "Map.h"
#include "Node.h"
#include "ConsoleControl.h"
class Tree : public InNodeContent {//se pone por default en privado, no podriamos acceder a tree
public:
    Tree() {

    }
    ~Tree() {

    }
    void Draw(Vector2 offset)override {
        Vector2 pos = offset;
        ConsoleControl::LockMutex();
        ConsoleControl::SetPosition(pos.x, pos.y);
        ConsoleControl::SetColor(ConsoleControl::GREEN);
        std::cout << "T";
        ConsoleControl::UnlockMutex();
    }
};
class Coin : public InNodeContent {
public:
    Coin() {

    }
    ~Coin() {

    }
    void Draw(Vector2 offset)override {
        Vector2 pos = offset;
        ConsoleControl::LockMutex();
        ConsoleControl::SetPosition(pos.x, pos.y);
        ConsoleControl::SetColor(ConsoleControl::YELLOW);
        std::cout << "C";
        ConsoleControl::UnlockMutex();
    }
};
int main()
{
   /* Vector2 v1, v2;
    Node* node = new Node(Vector2());
    InNodeContent* content = node->GetContent();
    Tree* tree = node->GetContent<Tree>();
    if (node->TryGetContent<Tree>(tree)) {
        

    }
    Coin* coin = node->GetContent<Coin>();
    if (node->TryGetContent<Coin>(coin)) {

    }*/
    
    Map* map = new Map(Vector2(10, 10), Vector2(2, 2));
    
   
    std::list<Vector2>treesPositions =  std::list<Vector2>();
    treesPositions.push_back(Vector2(3,4));
    treesPositions.push_back(Vector2(9,2));
    treesPositions.push_back(Vector2(6,9));
    treesPositions.push_back(Vector2(7,0));
    treesPositions.push_back(Vector2(3,3));
    
    map->SafePickNodes(treesPositions, [map](std::list<Node*>* nodes) {
        for (Node* node : *nodes) {
            if (node != nullptr) {
                node->SetContent(new Tree());
                node->DrawContent(map->GetOffest());
            }
        }
        });

    while (true)
    {

    }
    return 0;
}

