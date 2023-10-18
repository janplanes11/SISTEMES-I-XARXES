#pragma once
#include <vector>
#include "Node.h"
#include "Vector2.h"
#include <functional>
class Map
{
public:
	typedef std::vector<Node*> NodeColumn;//columnas de nodos
	typedef std::vector<NodeColumn*>NodeGrid;//contenedor de filas y columnas
	typedef std::function<void(Node* node)> SafePick;

private:
	Vector2 _offset;
	Vector2 _size;
	NodeGrid* _grid = nullptr;
	std::mutex* _gridMutex = new std::mutex();//SIEMPRE PUNTEROS LOS MUTECS

	Node* UnsafeGetNode(Vector2 position);
public:
	Map(Vector2 size, Vector2 offset = Vector2());
	void UnSafeDraw(Vector2 offset = Vector2());//parametro x defecto: estara siempre en la funcion, no hace falta ponerlo si llamas la funcion.
	//void SafeDraw(Vector2 offset = Vector2());
	void SafePickNode(Vector2 position, SafePick safePickAction );
};

