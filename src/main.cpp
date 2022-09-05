#include "fila.hpp"
#include "tree.hpp"

int main(){

    //CRIAÇÃO DA ARVORE//
    Tree *raiz = CreateTree();
    Tree *aux = CreateTree();
    Record r;
    //VECTOR DE CONTAR AS PALAVRAS//
    string palavra;
    vector <vector<int> > palavras;
    vector <int> count;

    ifstream texto;
    texto.open("texto.txt");
    if(texto.is_open()){
        while(getline(texto, palavra, ' ')){
           for ( int i = 0; i < palavras.size(); i++){
                if(palavra == palavras[i]){
                    palavras[i].count += 1;
                }else{
                    palavras.push_back(palavra);
                }
           }
        }
    }else
        cout<<"Unable to open file.";
    texto.close();
    for(int i = 0; i < palavras.size(); i++){
        cout << "A palavra '"<<palavras[i] << "' apareceu '"<<palavras[i].count << "' vezes no texto."<<endl;
    }


}

