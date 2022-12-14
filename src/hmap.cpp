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

				if (aux.compare("dos")&&aux.compare("das")&&aux.compare("como")&&aux.compare("que")&&aux.compare("no")&&aux.compare("não")&&aux.compare("a")&&aux.compare("à")&&aux.compare("e")&&aux.compare("é")
                &&aux.compare("ante")&&aux.compare("após")&&aux.compare("até")&&aux.compare("com")&&aux.compare("contra")
                &&aux.compare("de")&&aux.compare("desde")&&aux.compare("em")&&aux.compare("entre")
                &&aux.compare("para")&&aux.compare("trás")&&aux.compare("sob")&&aux.compare("sobre")&&aux.compare("per")
				&&aux.compare("sem")&&aux.compare("perante")&&aux.compare("por")){
					
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

		(no)->esq = vectorAux[0]; 

		(no)->dir = vectorAux[1]; 

		(no)->reg.huffman = (vectorAux[0]->reg.huffman + vectorAux[1]->reg.huffman); 

		vectorAux.erase(vectorAux.begin());
		vectorAux.erase(vectorAux.begin());

		vectorAux.push_back(no);

		sort(vectorAux.begin(), vectorAux.end(), compare);
	}
    
    //Tree* no = vectorAux[0];
    
	// cout << "CHEGOU NO FIM DA INSEREARVORE" <<endl;
	
	unordered_map <string, string>* huffman;
	
    huffman = new unordered_map<string, string>;
    
	string auxiliarConc;
	
	codificaArvore(&vectorAux[0], "", huffman);
	
	// map <string, string>::iterator it;
	
	// for(it = (*huffman).begin(); it != (*huffman).end(); it++){
	    
	//     cout<<"PALAVRA '"<<it->first<<"' CODIGO: "<<it->second<<endl;
	// }
	
	escreveArquivo(huffman);
}

void codificaArvore(Tree **temp, string auxiliarConc, unordered_map<string, string >* huffman){

	string CaminhaEsquerda, CaminhaDireita;

	if ((*temp)->dir == nullptr && (*temp)->esq == nullptr){ 
		
		(*huffman)[(*temp)->reg.palavra] = auxiliarConc;

  	}
	else{

		CaminhaEsquerda = auxiliarConc;
		CaminhaDireita = auxiliarConc;

		CaminhaEsquerda += '0';

		CaminhaDireita += '1';

		codificaArvore(&(*temp)->esq, CaminhaEsquerda ,huffman);

		codificaArvore(&(*temp)->dir, CaminhaDireita ,huffman);

	}

}

void escreveArquivo(unordered_map<string, string >* huffman){

	// cout << "ENTREI NA FUNÇÃO ESCREVEARQUIVO" <<endl;

	unordered_map <string, string>::iterator it;

	vector <string>::iterator itr;

	vector <string> token;

	string tk;

	string nline = "";

	string line;

	ofstream myFile;
	myFile.open("saida.txt");

	// cout << "ABRI O 'SAIDA' PARA ESCRITA" <<endl;

	ifstream myFile2;
	myFile2.open("texto.txt");

	// cout << "ABRI O 'TEXTO' PARA LEITURA"<<endl;

	if(!myFile2.eof()){

		while(getline(myFile2, line)){

			stringstream aux(line);

			while(getline(aux, tk, ' ')){

				token.push_back(tk);
			}

			for(itr = token.begin(); itr != token.end(); ++itr){

				it = huffman->find(*itr);

				if(it != huffman->end()){

					nline += it->second + " ";

				}
			}

			myFile<<nline;
			myFile<<endl;

			nline = "";

			token.clear();
			
		}

	}
    
	myFile2.close();

	myFile.close();
}

bool compare(Tree* obj1, Tree* obj2){

	return obj1->reg.huffman < obj2->reg.huffman;

}
