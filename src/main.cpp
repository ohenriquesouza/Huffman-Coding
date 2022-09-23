#include "hmap.hpp"
#include "tree.hpp"

int main(){

    unordered_map <string, Record>* mapa;
    mapa = new unordered_map<string, Record>;

    configuraArquvio(mapa);

    // printMap(mapa);

    calculaHuffman(mapa);

    insereArvore(mapa);
}