#include "tree.hpp"

Tree* CreateTree(){
	return nullptr;
}

bool TVazia(Tree **t){
  return *t == nullptr;
}

void insertTree(Tree **t, Record r){

  if(TVazia(t)){
    *t = new Tree;
    (*t)->esq = nullptr; 
    (*t)->dir = nullptr; 
    (*t)->reg.huffman = r.huffman; 
    (*t)->reg.record = r.record;
  
  } else {
    
    if(r.huffman < (*t)->reg.huffman){
      insertTree(&(*t)->esq, r);
    }
    
    if(r.huffman > (*t)->reg.huffman){
      insertTree(&(*t)->dir, r);
    }
  
  }

}

void pesquisa(Tree **t, Tree **aux, Record r){

  if(*t == nullptr){
    printf("[ERROR]: Node not found!");
    return;
  }

  if((*t)->reg.huffman > r.huffman){ pesquisa(&(*t)->esq, aux, r); return;}
  if((*t)->reg.huffman < r.huffman){ pesquisa(&(*t)->dir, aux, r); return;}

  *aux = *t;
}


int isInTree(Tree *t, Record r) {
  
  if(t == nullptr){ 
    return 0;
  }
  
  return t->reg.huffman == r.huffman || isInTree(t->esq, r) || isInTree(t->dir, r);
}


void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->dir != nullptr){ 
		antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  free(aux);
} 


void removeTree(Tree **t, Record r){
	Tree *aux;
  	
  	if (*t == nullptr){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (r.huffman < (*t)->reg.huffman){ removeTree(&(*t)->esq, r); return; }
  	if (r.huffman > (*t)->reg.huffman){ removeTree(&(*t)->dir, r); return; }

  	if ((*t)->dir == nullptr){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	free(aux);
    	return;
  	}

  	if ((*t)->esq != nullptr){ antecessor(&(*t)->esq, *t); return; }

  	aux = *t;  
  	*t = (*t)->dir;
  	free(aux);
}


void preordem(Tree *t)
{
  if(!(t == nullptr)){
    printf("%f ", t->reg.huffman);
    preordem(t->esq); 
    preordem(t->dir); 
  }
}


void central(Tree *t)
{
  if(!(t == nullptr)){
    central(t->esq); 
    printf("%f ", t->reg.huffman);
    central(t->dir); 
  }
}

void posordem(Tree *t)
{
  if(!(t == nullptr)){
    posordem(t->esq); 
    posordem(t->dir); 
    printf("%f ", t->reg.huffman);
  }
}

// void widthPath(Tree *t){
//   Fila q;
//   Item no, filho;
  
//   FFVazia(&q);
//   no.p = t;
//   Enfileira(&q, no);

//   while (!isVazia(&q)){

//     Desenfileira(&q, &no);
//     printf("%d ", no.p->reg.huffman);

//     if(no.p->esq != nullptr){
//       filho.p = no.p->esq;
//       Enfileira(&q, filho);
//       //printf(" Entrei esquerda! ");
//     }

//     if(no.p->dir != nullptr){
//       filho.p = no.p->dir;
//       Enfileira(&q, filho);
//       //printf(" Entrei direita! ");
//     }

//   }


// }