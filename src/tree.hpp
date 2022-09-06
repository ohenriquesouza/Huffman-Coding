#ifndef TREE_HPP 
#define TREE_HPP

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Vertice Vertice;
typedef struct Tree Tree;

struct Vertice{
	int key;
	int value;
};

struct Tree{
	Vertice reg;
	Tree *esq, *dir;
};

Tree* CreateTree();
bool TVazia(Tree **t);
void insertTree(Tree **t, Vertice v);
void pesquisa(Tree **t, Tree **aux, Vertice v);
int isInTree(Tree *t, Vertice v);

void removeTree(Tree **t, Vertice v);
void antecessor(Tree **t, Tree *aux);

void preordem(Tree *t);
void central(Tree *t);
void posordem(Tree *t);
void widthPath(Tree *t);

#endif