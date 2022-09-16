#ifndef HMAP_HPP
#define HMAP_HPP

#include "tree.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void configuraArquvio(map <string, Record>* mapa);

string string_treatment(string s);

void printMap(map <string, Record>* mapa);

void calculaHuffman(map <string, Record>* mapa);

void insereArvore(map <string, Record>* mapa);

void codificaArvore(Tree **temp, string auxiliarConc, map <string, string>* huffman);

void escreveArquivo(map<string, string >* huffman);

bool compare(Tree* obj1, Tree* obj2);



#endif