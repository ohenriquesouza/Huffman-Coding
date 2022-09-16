#include "hmap.hpp"
#include "tree.hpp"

int main(){

    map <string, Record>* mapa;
    mapa = new map<string, Record>;

    configuraArquvio(mapa);

    // printMap(mapa);

    calculaHuffman(mapa);

    insereArvore(mapa);
}