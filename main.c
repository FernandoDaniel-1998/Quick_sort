#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2);
int partition(int* vet, int ini, int fim);
void quick_sort(int *vet, int ini, int fim, int posicao);

int main(void) {

  int posicao, tam;

  scanf("%d",&posicao);
  scanf("%d",&tam);

  int* vet;
  vet = (int*) malloc(tam*sizeof(int)); // Alocando dinamicamente o vetor de inteiros

  for(int i = 0; i < tam; i++){ // Leitura dos elementos do vetor
    scanf("%d",&vet[i]);
  }

  quick_sort(vet, 0, tam-1, posicao); // Chamada da função com parametro de posicao

  printf("%do menor elemento eh o %d\n",posicao,vet[posicao-1]); // Apenas printará na forma que a saída deve ser inserida

  for(int i = 0; i < tam; i++){ // Laço para printar os elementos do vetor
    printf("%d ",vet[i]);
  }
  
  printf("\n");

  free(vet); // Liberando o vetor alocado dinamicamente
  
  return 0;
}

void swap(int *num1, int *num2){ // FUNÇÃO QUE FAZ A TROCA DOS ELEMENTOS NUM VETOR
  
  int aux;
  aux = *num1; // "aux" APENAS ARMAZENA O VALOR DO PRIMEIRO ELEMENTO
  *num1 = *num2;
  *num2 = aux;
  
}

int partition(int* vet, int ini, int fim){

  int x = vet[fim]; // Obtendo o pivô
  int i = ini-1; // "i" está percorrendo o vetor para fazer a troca dos elementos posteriormente
  

  for(int j = ini; j <= fim - 1; j++){ // Essa laço de repetição percorrira todo vetor
    
    if(vet[j] <= x){ // Quando o elemento do indice percorrido for menor ou igual que o pivô, o elemento com índice i será trocado com o elemento de índice j
      
      i = i + 1; // Incrementando em i para percorrer o vetor caso ocorra do elemento analisado ser menor ou igual ao pivô
      swap(&vet[i],&vet[j]);
      
    }
    
  }

  swap(&vet[i+1],&vet[fim]); // Nesta parte, o pivô será mudado
  
  return (i+1); // Esse retorno se trata do índice do pivô no vetor
}

void quick_sort(int *vet, int ini, int fim, int posicao){

  if (ini < fim){ // Essa condição de parada apenas irá interromper a recursão quando o "q" (pivô) estiver a "esquerda" no vetor. Esquerda que eu cito se trata do pivô ser o elemento unico
    
    int q = partition(vet,ini,fim); // "q" receberá o índice do pivô no vetor

    // Essas duas condições de "if", se tratam de que o elemento na posição analisada esteja ainda na recursão. Ou seja, se o menor elemento que eu quero pegar está ja ordenado ou não. Se não, se entra na recursao novamente, e se sim, a recursao sessa, pois posicao = q+1(pivô).
    if(posicao < q+1){
      quick_sort(vet, ini, q-1,posicao);
    }
      else if(posicao > q+1){
        quick_sort(vet, q+1, fim,posicao);
      }
    
  }
  
}