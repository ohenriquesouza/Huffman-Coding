#ifndef HMAP_HPP
#define HMAP_HPP

#include "tree.hpp"
#include "lista.hpp"
#include <iostream>
#include <string>
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

void codificaArvore(Tree **t, Lista l, string auxiliarConc);

void escreveArquivo(Lista *l, vector <Tree*> vectorAux);

bool compare(Tree* obj1, Tree* obj2);



#endif