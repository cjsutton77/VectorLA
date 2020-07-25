#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
  int xhat;
  int yhat;
  int zhat;
} vector;

vector* scalar(int s, vector* S);
int dotprod(vector*, vector*);
vector* crossprod(vector* S, vector* T);

int main(){
  vector* A = malloc(sizeof(vector));
  vector* B = malloc(sizeof(vector));

  A->xhat = 5;
  A->yhat = 2;
  A->zhat = -3;

  B->xhat = 1;
  B->yhat = -2;
  B->zhat = -1;

  printf("A\t\ti: %d\tj: %d\tk: %d\n",A->xhat,A->yhat,A->zhat);
  printf("B\t\ti: %d\tj: %d\tk: %d\n",B->xhat,B->yhat,B->zhat);
  printf("Now calcualte dot-product\n");
  printf("%d\n",dotprod(A,B));


  vector* C = NULL;
  printf("Declared pointer *C");
  printf("--> %p\n",C);

  C = scalar(10,A);
  printf("C\t\ti: %d\tj: %d\tk: %d\n",C->xhat,C->yhat,C->zhat);
  printf("Memory location in main: %p\n",C);

  printf("A\t\ti: %d\tj: %d\tk: %d\n",A->xhat,A->yhat,A->zhat);
  printf("B\t\ti: %d\tj: %d\tk: %d\n",B->xhat,B->yhat,B->zhat);

  vector* D = NULL;
  printf("Declared pointer *D");
  printf("--> %p\n",D);
  
  printf("Dot product of A and B\n");
  D = crossprod(A,B);
  printf("D\t\ti: %d\tj: %d\tk: %d\n",D->xhat,D->yhat,D->zhat);
  printf("Memory location in main: %p\n",D);



  free(A);
  free(B);
  free(C);
  free(D);
  return 0;
}

vector* scalar(int s, vector* T){
  vector* S = malloc(sizeof(vector));
  printf("Scalar of %d\n",s);
  printf("Memory location in function: %p\n",S);
  S->xhat = s * (T->xhat);
  S->yhat = s * (T->yhat);
  S->zhat = s * (T->zhat);
  return S;
}

int dotprod(vector *S, vector *T){
  return ((S->xhat)*(T->xhat) + (S->yhat)*(T->yhat) + (S->zhat)*(T->zhat));
}

vector* crossprod(vector* S, vector* T){
  vector* U = malloc(sizeof(vector));
  printf("Memory location in function: %p\n",U);

  U->xhat = (S->yhat)*(T->zhat)-(S->zhat)*(T->yhat);
  U->yhat = (S->zhat)*(T->xhat)-(S->xhat)*(T->zhat);
  U->zhat = (S->xhat)*(T->yhat)-(S->yhat)*(T->xhat);
  return U;
}