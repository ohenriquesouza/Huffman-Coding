#include "hmap.hpp"

void configuraArquvio(unordered_map <string, Record>* mapa){

	string line, auxiliar, auxiliar_2, delimiter = " ", aux;
	size_t pos = 0;

    ifstream myfile;
	myfile.open("texto.txt");

	//LEITURA, REMOÇÃO STOPWOPRD E CONTADOR DE PALAVRA
    if (myfile.is_open()) {

		while(!myfile.eof()) {

			getline(myfile, line);

			aux = line;

			while ((pos = line.find(delimiter)) != string::npos) {

				aux = (line.substr(0, pos));

				line.erase(0, pos + delimiter.size());

				auxiliar = aux;

				auxiliar_2 = string_treatment(auxiliar);

				aux = auxiliar_2;

				if (aux.compare("a")&&aux.compare("nos")&&aux.compare("à")&&aux.compare("e")&&aux.compare("ser")&&aux.compare("é")
                &&aux.compare("uma")&&aux.compare("em")&&aux.compare("como")&&aux.compare("por")&&aux.compare("da")&&aux.compare("das")
                &&aux.compare("dos")&&aux.compare("um")&&aux.compare("com")&&aux.compare("o")&&aux.compare("de")&&aux.compare("do")&&aux.compare("no")
                &&aux.compare("na")&&aux.compare("que")&&aux.compare("se")&&aux.compare("ao")&&aux.compare("as")&&aux.compare("não")){
					
                    if((*mapa).find(aux) == (*mapa).end()){

                        (*mapa)[aux].record = 1;

                    } else {

                        (*mapa)[aux].record += 1;

                    }

				} 
			}
		}
	}

}


string string_treatment(string s) {

	int size = s.size();

	string aux;

	for (int i = 0; i < size; i++) {

		if (s[i] != '.' && s[i]!= ',' && s[i] != ':' && s[i] != ';' && s[i] != '?' && s[i] != '!' && s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']' && s[i] != '{'
			&& s[i] != '}' && s[i] != '+'&& s[i] != '=' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '%' && !isdigit(s[i])) {

			s[i] = tolower(s[i]);

            aux += s[i];
		}
	}
 
	return aux;
}

// void printMap(unordered_map <string, Record>* mapa){

//     unordered_map<string, Record>::iterator itr;
	
//     for (itr = (*mapa).begin(); itr != (*mapa).end(); itr++){

//         cout << itr->first << "  " << itr->second.record<< endl;
//     }
// }

void calculaHuffman(unordered_map <string, Record>* mapa){

	//DESCOBRIR PALAVRA MAIS RECORRENTE E MENOS RECORRENTE
	unordered_map<string, Record>::iterator itr;

	unordered_map<string, Record>::iterator itr2;

	int MAIOR = 0, MENOR = 0, AUX = 0;

	for (itr2 = (*mapa).begin(); itr2 != (*mapa).end(); itr2++){

		AUX = itr2->second.record;

		for (itr = (*mapa).begin(); itr != (*mapa).end(); itr++){
			
			if(itr->second.record > MAIOR){

				MAIOR = itr->second.record;

				// cout << "NOVO MAIOR: "<<MAIOR<<endl;

			}

			if(itr->second.record < AUX){

				MENOR = itr->second.record;

				// cout << "NOVO MENOR: "<<MENOR<<endl;

			}

		}
       
    }

	// cout << "A MAIOR RECORRENCIA FOI: " << MAIOR << endl;

	// cout << "A MENOR RECORRENCIA FOI: " << MENOR << endl;

	//NORMALIZAÇÃO PALAVRA
	 for (itr = (*mapa).begin(); itr != (*mapa).end(); itr++)
    {

		itr->second.huffman = (((float)itr->second.record) / (MAIOR - MENOR));

		// cout <<"A PALAVRA "<< itr->first << " TEM O VALOR HUFFMAN = " << itr->second.huffman<< endl;
		
    }
}

void insereArvore(unordered_map <string, Record>* mapa){

	unordered_map<string, Record>::iterator itr;

	vector <Tree*> vectorAux;

	Tree *temp;

	for (itr = (*mapa).begin(); itr != (*mapa).end(); itr++){

		temp = new Tree;

		temp->reg.palavra = itr->first;

		temp->reg.huffman = itr->second.huffman;

		temp->esq = nullptr;

		temp->dir = nullptr;

		vectorAux.push_back(temp);

	}

	sort(vectorAux.begin(), vectorAux.end(), compare);

	while(vectorAux.size() != 1){

		Tree* no = new Tree;

		vectorAux[0]->reg.bin = 0;

		(no)->esq = vectorAux[0]; 

		vectorAux[1]->reg.bin = 1;

		(no)->dir = vectorAux[1]; 

		(no)->reg.huffman = (vectorAux[0]->reg.huffman + vectorAux[1]->reg.huffman); 

		vectorAux.erase(vectorAux.begin());
		vectorAux.erase(vectorAux.begin());

		vectorAux.push_back(no);

		sort(vectorAux.begin(), vectorAux.end(), compare);
	}

	widthPath(vectorAux[0]);

}

void escreveArquivo(unordered_map <string, Record>* mapa, vector <Tree*> vectorAux){

	Block *temp;
	vector <Bool> traducao;
	ostream binaryFile;
	binaryFile.open("saida.bin");

	if(!binaryFile){

		cout << "Unable to open file" << endl;
		exit(1);

	}

	for (long unsigned int i = 0; i < vectorAux.size()){

		temp = vectorAux->first->prox;

		while(temp != nullptr){

			if(vectorAux[i]->reg.palavra == temp->data.palavra){

				for(size_t j = 0; j < temp->data.vectorAux.size(); j++){

					if(temp->data.vectorAux[j]->reg.bin == '0'){
						
						traducao.push_back(false);

					}

					if(temp->data.vectorAux[j]->reg.bin == '1'){
						
						traducao.push_back(true);

					}
				}

				for(size_t k = 0; k < traducao.size(); k++){

					binaryFile << traducao[k];

				}

				binaryFile << " ";
				traducao.clear();
			}

			temp = temp->prox;
		}

	}

}


bool compare(Tree* obj1, Tree* obj2){

	return obj1->reg.huffman < obj2->reg.huffman;

}
