#include "hmap.hpp"
#include "tree.hpp"

int main(){

    Tree* t = new Tree;

    unordered_map <string, Record>* mapa;
    mapa = new unordered_map<string, Record>;

    configuraArquvio(mapa);

    // printMap(mapa);

    calculaHuffman(mapa);

    insereArvore(mapa, &t);

    central(t);
    

}

