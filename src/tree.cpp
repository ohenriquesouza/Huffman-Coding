#include "tree.hpp"

Tree* CreateTree(){
	return NULL;
}

bool TVazia(Tree **t){
  return *t == NULL;
}

void insertTree(Tree **t, Vertice v){

  if(TVazia(t)){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = v; 
  
  } else {
    
    if(v.key < (*t)->reg.key){
      insertTree(&(*t)->esq, v);
    }
    
    if(v.key > (*t)->reg.key){
      insertTree(&(*t)->dir, v);
    }
  
  }

}

void pesquisa(Tree **t, Tree **aux, Vertice v){

  if(*t == NULL){
    printf("[ERROR]: Node not found!");
    return;
  }

  if((*t)->reg.key > v.key){ pesquisa(&(*t)->esq, aux, v); return;}
  if((*t)->reg.key < v.key){ pesquisa(&(*t)->dir, aux, v); return;}

  *aux = *t;
}


int isInTree(Tree *t, Vertice v) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == v.key || isInTree(t->esq, v) || isInTree(t->dir, v);
}


void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->dir != NULL){ 
		antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  free(aux);
} 


void removeTree(Tree **t, Vertice v){
	Tree *aux;
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (v.key < (*t)->reg.key){ removeTree(&(*t)->esq, v); return; }
  	if (v.key > (*t)->reg.key){ removeTree(&(*t)->dir, v); return; }

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	free(aux);
    	return;
  	}

  	if ((*t)->esq != NULL){ antecessor(&(*t)->esq, *t); return; }

  	aux = *t;  
  	*t = (*t)->dir;
  	free(aux);
}


void preordem(Tree *t)
{
  if(!(t == NULL)){
    printf("%d ", t->reg.key);
    preordem(t->esq); 
    preordem(t->dir); 
  }
}


void central(Tree *t)
{
  if(!(t == NULL)){
    central(t->esq); 
    printf("%d ", t->reg.key);
    central(t->dir); 
  }
}

void posordem(Tree *t)
{
  if(!(t == NULL)){
    posordem(t->esq); 
    posordem(t->dir); 
    printf("%d ", t->reg.key);
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
//     printf("%d ", no.p->reg.key);

//     if(no.p->esq != NULL){
//       filho.p = no.p->esq;
//       Enfileira(&q, filho);
//       //printf(" Entrei esquerda! ");
//     }

//     if(no.p->dir != NULL){
//       filho.p = no.p->dir;
//       Enfileira(&q, filho);
//       //printf(" Entrei direita! ");
//     }

//   }


// }