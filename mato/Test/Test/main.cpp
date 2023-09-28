#include<ios>
#include <ostream>
#include <fstream>
#include <iostream>
#include<vector>
int Binary_Read_Write_CharorInt() {
	int a[10];
	char b = 'A';
	for (int i = 0; i < 10; i++) {
		a[i] = i;

	}
	std::ofstream myFile;//archiu de escriptura
	myFile.open("save.dat", std::ios::out | std::ios::binary);
	if (!myFile.is_open()) {
		return 1;
	}
	myFile.write(reinterpret_cast<char*>(&a), sizeof(int) * 10);
	//^escric en el archiu i reinterpreto els valors com a char, per a poder escriure bye per byte, comença a char
	myFile.write(reinterpret_cast<char*>(&b), sizeof(char));//En este caso no aumento medida pork es un solo char
	myFile.close();

	std::ifstream myFileIn;//archiu de lectura
	myFileIn.open("save.dat", std::ios::in | std::ios::binary);
	if (!myFileIn.is_open()) {
		return 1;
	}
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 100;
		std::cout << a[i] << ", ";
	}
	myFileIn.read(reinterpret_cast<char*>(&a), sizeof(int) * 10);
	myFileIn.read(reinterpret_cast<char*>(&b), sizeof(char));//En este caso no aumento medida pork es un solo char

	for (int i = 0; i < 10; i++) {
		std::cout << a[i];
	}
}
int Binary_String_Write() {
	std::string s = "PROVA";
	std::ofstream myFileOut("string.dat", std::ios::out | std::ios::binary);
	if (!myFileOut.is_open()) {
		return 1;
	}
	size_t size = s.size();//size_t es un unsigned long long, ocupa 16 bytes, podria guardar un llibre, te una mida enorme
	myFileOut.write(reinterpret_cast<char*>(&size), sizeof(size));
	//write the actual string
	myFileOut.write(s.c_str(), size);//c_str es fa servir perque no pot passar de string a const char
	myFileOut.close();
	return 0;
}
int Binary_String_Read() {
	std::ifstream myFileIn("string.dat", std::ios::in | std::ios::binary);
	if (!myFileIn.is_open()) {
		return 1;
	}
	//lee tamaño string
	size_t inSize;
	myFileIn.read(reinterpret_cast<char*>(&inSize), sizeof(inSize));

	//Read string
	char* ptr = new char[inSize + 1];
	myFileIn.read(ptr, inSize);

	//añadir'\0'
	ptr[inSize] = '\0';

	//guardar como std::string
	std::string inString = ptr;
	//borro pointer, sino sem cola merda
	delete[] ptr;
	myFileIn.close();
	std::cout << inString << std::endl;
}
int Binary_Vector_Write() {
	std::vector<int> grades;
	for (int i = 0; i < 10; i++) {
		grades.push_back(i);
	}
	std::ofstream myFileOut("vector.dat", std::ios::out | std::ios::binary | std::ios::trunc);
	//escriu mida
	int size = grades.size();
	myFileOut.write(reinterpret_cast<char*>(&size), sizeof(int));

	//escric continguts
	myFileOut.write(reinterpret_cast<char*>(grades.data()), sizeof(int) * size);
	myFileOut.close();
	return 0;
}
int Binary_Vector_Read() {
	std::ifstream myFileIn("vector.dat", std::ios::in | std::ios::binary);
	if (!myFileIn.is_open()) {
		return 1;
	}

	int inSize = 0;
	myFileIn.read(reinterpret_cast<char*>(&inSize), sizeof(int));
	std::vector<int> readVector;
	readVector.resize(inSize);//IMPORTANT
	myFileIn.read(reinterpret_cast<char*>(readVector.data()), sizeof(int) * inSize);

	for (int i = 0; i < readVector.size(); i++) {
		std::cout << readVector[i] << ' ' << std::endl;
	}

	return 0;
}

int main() {
	Binary_String_Write();
	Binary_String_Read();
	Binary_Vector_Write();
	Binary_Vector_Read();
	return 0;
}
