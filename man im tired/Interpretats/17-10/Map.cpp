#include "Map.h"


Map::Map(Vector2 size, Vector2 offset)
{
	_size = size;
	_offset = offset;
	_grid = new NodeGrid();
	for (int x = 0; x < _size.x; x++) {
		NodeColumn* column = new NodeColumn;
		for (int y = 0; y < _size.y; y++) {
			column->push_back(new Node(Vector2(x, y)));
		}
		_grid->push_back(column);
	}
}

void Map::UnSafeDraw(Vector2 offset)//No usamos mutex por eso no es segura
{
	Vector2 totalOffset = _offset + offset;//se pueden sumar ya q hicimos un override del operador
	for (NodeColumn* column : *_grid) {
		for (Node* node : *column) {

			node->DrawContent(totalOffset);
			//hicimos esta suma pork asi optimizamos, sino hariamos la suma _offset+offset cad iteracionLo cual no es optimo
		}
	}
}

/*void Map::SafeDraw(Vector2 offset)//safe pork uso mutex
{
	Vector2 totalOffset = _offset + offset;//se pueden sumar ya q hicimos un override del operador
	_gridMutex->lock();
	for (NodeColumn* column : *_grid) {
		for (Node* Node : *column) {
			Node->Lock();
			Node->DrawContent(totalOffset);
			//hicimos esta suma pork asi optimizamos, sino hariamos la suma _offset+offset cad iteracionLo cual no es optimo
			Node->Unlock();
		}
	}
	_gridMutex->unlock();
}*/

void Map::SafePickNode(Vector2 position, SafePick safePickAction)
{
	
	if(position.x >= _size.x || position.y >= _size.y) {
		safePickAction(nullptr);
		return;
	}
	_gridMutex->lock();

	Node* node = UnsafeGetNode(position);

	_gridMutex->unlock();
	node->Lock();
	safePickAction(node);
	node->Unlock();
}
void Map::SafePickNodes(std::list<Vector2> positions, SafeMultiPick safeMultiPickAction)
{
	std::list<Node*>* nodes = new std::list<Node*>;
	_sizeMutex->lock();
	Vector2 size = _size;
	_sizeMutex->unlock();
	for (Vector2 pos : positions) {
		if (pos.x >= size.x || pos.y >= size.y || pos.x < 0 || pos.y < 0) {
			nodes->push_back(nullptr);
			continue;
		}
		_gridMutex->lock();
		Node* node = UnsafeGetNode(pos);
		_gridMutex->unlock();
		nodes->push_back(node);
	}
	_SafeMultiPickMutex->lock();
	for (Node* node : *nodes) {
		node->Lock();            //De esta manera no bloqueo mas de un nodo a lavez

		//hasta que uno no acabe el siguiente no empieza
	}
	_SafeMultiPickMutex->unlock();
	safeMultiPickAction(nodes);
	for (Node* node : *nodes) {
		node->Unlock();            
	}
}
Vector2 Map::GetOffest()
{
	_offsetMutex->lock();
	Vector2 offset = _offset;
	_offsetMutex->unlock();
	return _offset;
}
Node* Map::UnsafeGetNode(Vector2 position)
{
	NodeColumn* column = (*_grid)[position.x];
	Node* node = (*column)[position.y];
	return node;
}

