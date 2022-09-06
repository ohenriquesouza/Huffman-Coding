#ifndef HMAP_HPP
#define HMAP_HPP

#include "tree.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

struct Record{
	int record;
	float huffman;
};

void configuraArquvio(unordered_map <string, Record>* mapa);

string string_treatment(string s);

void printMap(unordered_map <string, Record>* mapa);

void calculaHuffman();


#endif