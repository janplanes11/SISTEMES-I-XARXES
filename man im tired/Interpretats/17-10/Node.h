#pragma once
#include "Vector2.h"
#include "InNodeContent.h"
#include <mutex>
class Node
{
private:
	Vector2 _position;
	InNodeContent* _content = nullptr;
	std::mutex* _classMutex = new std::mutex();

public:
	
	Node(Vector2 position);
	InNodeContent* GetContent();
	template<typename T, typename = typename std::enable_if<std::is_base_of<InNodeContent, T>::value>::type>
	//se define SOLO si cumple la condicion de que tiene que estar basado en un InNodeContent
	T* GetContent() {
		T* contentCasted = dynamic_cast<T*>(_content);
		return contentCasted;
	}
	template<typename T, typename = typename std::enable_if<std::is_base_of<InNodeContent, T>::value>::type>
	bool TryGetContent(T*& outContent) { //qiere el mismo puntero de memoria
		T* contentCasted = dynamic_cast<T*>(_content);
		if (contentCasted != nullptr) {
			outContent = contentCasted;
			return true;
		}
		return false;
	}
	void SetContent(InNodeContent* newContent);
	void DrawContent(Vector2 offset);
	void Lock();
	void Unlock();
};

