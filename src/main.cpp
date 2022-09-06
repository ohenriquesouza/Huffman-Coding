#include "hmap.hpp"
#include "tree.hpp"

int main(){

    Tree* raiz = CreateTree();
    Tree* aux = CreateTree();
    Vertice v;

    unordered_map <string, Record>* mapa;
    mapa = new unordered_map<string, Record>;

    configuraArquvio(mapa);

    // printMap(mapa);

    calculaHuffman(mapa);
    

}

