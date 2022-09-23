#ifndef HMAP_HPP
#define HMAP_HPP

#include "tree.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void configuraArquvio(unordered_map <string, Record>* mapa);

string string_treatment(string s);

void printMap(unordered_map <string, Record>* mapa);

void calculaHuffman(unordered_map <string, Record>* mapa);

void insereArvore(unordered_map <string, Record>* mapa);

void codificaArvore(Tree **temp, string auxiliarConc, unordered_map <string, string>* huffman);

void escreveArquivo(unordered_map<string, string >* huffman);

bool compare(Tree* obj1, Tree* obj2);



#endif