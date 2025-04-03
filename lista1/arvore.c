#include "arvore.h"


Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 2 - pré-ordem ====
void pre_ordem(Arvore *a)
{
    if (a != NULL)
    { 
      printf("%c ", a->info);
      pre_ordem(a->esq);
      pre_ordem(a->dir);
    }
}

//======_=== Exercício 2 - in-ordem ====
void in_ordem(Arvore *a)
{
  if (a != NULL)
  {
    in_ordem(a->esq);
    printf("%c ", a->info);
    in_ordem(a->dir);
  }
}

//========= Exercício 2 - pós-ordem ====
void pos_ordem(Arvore *a)
{
  if (a != NULL)
  {
    pos_ordem(a->esq);
    pos_ordem(a->dir);
    printf("%c ", a->info);
  }
}

//========= Exercício 3 - pertence ====
int pertence_arv (Arvore *a, char c)
{
  if (a == NULL)
    return 0;

  if (a->info == c)
    return 1;
  
  return pertence_arv(a->esq, c) || pertence_arv(a->dir, c);
}

//========= Exercício 4 - conta nós ====
int conta_nos (Arvore *a)
{

  if (a == NULL)
    return 0;

  return 1 + conta_nos(a->esq) + conta_nos(a->dir);
} 

//========= Exercício 5 - calcula altura ====
int calcula_altura_arvore (Arvore *a)
{
  if (a == NULL)
    return -1;
  
  int altura_esq = calcula_altura_arvore(a->esq);
  int altura_dir = calcula_altura_arvore(a->dir);
  
  if (altura_esq > altura_dir)
    return 1 + altura_esq;

  return 1 + altura_dir;
}

//========= Exercício 6 - conta folhas ====
int conta_nos_folha (Arvore *a)
{
  if (a == NULL)
    return 0;

  if (a->esq == NULL && a->dir == NULL)
    return 1;

  int nos_esq = conta_nos_folha(a->esq);
  int nos_dir = conta_nos_folha(a->dir);

  return nos_esq + nos_dir;
}


int main (int argc, char *argv[]) {
  char carac;
  int b = 0;

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );
  
  /*
  pre_ordem(a);
  printf("\n");

  in_ordem(a);
  printf("\n");

  pos_ordem(a);
  printf("\n");

  scanf("%c", &carac);
  if (pertence_arv(a, carac))
    printf("o caractere esta presente\n");
  else
    printf("o caractere NAO esta presente\n");

  b = conta_nos(a);
  printf("%d\n", b);

  b = calcula_altura_arvore(a);
  printf("%d\n", b); 

  b = conta_nos_folha(a);
  printf("%d\n", b);
  */

   arv_libera (a);

   return 0;
}

