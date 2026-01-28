#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT 121


typedef struct Pilha{
    int * S;
    int topo;
    int tamanho;
}Pilha;

void imprimir_pilha(Pilha * pilha){
    printf("\n");
    for(int i=pilha->topo; i > -1; i = i -1){
        printf("\t🧇 %d\n",pilha->S[i]);
    }
    printf("\n");
}
Pilha * criar_pilha(int tam){
    Pilha * nova = malloc(sizeof(Pilha));
    nova->S = malloc(tam * sizeof(int));
    nova->topo = -1;
    nova->tamanho = tam;
    return nova;
}

// opção 1
bool tem_espaco(Pilha * pilha){
    if(pilha->topo == pilha->tamanho -1){
        return false;
    }
    else{
        return true;
    }
}
//opção 2
bool tem_espaco_v2(Pilha * pilha){
    return !(pilha->topo == pilha->tamanho-1);
}


void empurrar(Pilha * pilha, int x){
    if(tem_espaco(pilha)){
        pilha->topo = pilha->topo +1;// pilha->topo++;
        pilha->S[pilha->topo] = x;
    }
    else{
        printf("Sem espaço na pilha 🌝\n");
    }
}

bool esta_vazia(Pilha * pilha){
    if(pilha->topo==-1) return true;
    else return false;
}

int pocar(Pilha * pilha){
    if(!esta_vazia(pilha)){
        pilha->topo = pilha->topo-1;
        return pilha->S[pilha->topo+1];
    }
    else{
        printf("Pilha vazia! 🪹");
    }
}

int main () {
    Pilha * operators = criar_pilha(120);
    char inputStr [MAX_INPUT] = "";
    int num, op1, op2, result;
    int i = 0;

    fgets (inputStr, MAX_INPUT, stdin);
    inputStr[strcspn(inputStr, "\n")] = '\0';

    while (inputStr[i] != '\0') {
        if (inputStr[i] == ' ') {
            i++;
            continue;
        }
        
        if (inputStr[i] >= '0' && inputStr[i] <= '9') {
            num = atoi(inputStr[i]);
            empurrar(operators, num);
        } else {
            op2 = pocar(operators);
            op1 = pocar(operators);

            switch (inputStr[i])
            {
            case '+':
                result = op1 + op2;
                empurrar(operators, result);
                break;

            case '-':
                result = op1 - op2;
                empurrar(operators, result);
                break;
            
            case '*':
                result = op1 * op2;
                empurrar(operators, result);
                break;
            
            case '/':
                result = op1 / op2;
                empurrar(operators, result);
                break;

            default:
                break;
            }
        }
        i++;
    }
    
    return 0;
}
