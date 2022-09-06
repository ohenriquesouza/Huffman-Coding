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
	
//     for (itr = (*mapa).begin(); itr != (*mapa).end(); itr++)
//     {
//         cout << itr->first << "  " << itr->second.record<< endl;
//     }
// }

void calculaHuffman(unordered_map <string, Record>* mapa){

	//DESCOBRIR PALAVRA MAIS RECORRENTE E MENOS RECORRENTE
	unordered_map<string, Record>::iterator itr;

	int MAIOR = 0, MENOR = 0, AUX = 0;

	itr = (*mapa).begin();

	 while(itr != (*mapa).end())
    {
		AUX = itr->second.record;

		for (itr = (*mapa).begin(); itr != (*mapa).end(); itr++){
			
			if(itr->second.record > MAIOR){

			MAIOR = itr->second.record;

			}

			if(itr->second.record < AUX){

			MENOR = itr->second.record;

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

