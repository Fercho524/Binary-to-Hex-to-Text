#include "Lib.h"

typedef struct
{
    char* text,
    int length;
} pointer;


void mergePairs(int arrSize, pairCountSpeaks arr[arrSize], int size1, pairCountSpeaks L[size1], int size2, pairCountSpeaks R[size2]){
    int i = 0; // Indice del primer array
    int j = 0; // Indice del segundo array
    int k = 0; // Indice del array final
    //Aqui se hace el recorrido
    while (i < size1 && j < size2){
        //Si el elemento del arreglo izquierdo es menor el elemento del final sera el de la izquierda
        if (L[i].speakers <= R[j].speakers){
            strcpy(arr[k].name,L[i].name);
            arr[k].speakers = L[i].speakers;
            i++;
        }
        //Si no el elemento final sera de la derecha dado que es mayor
        else{
            strcpy(arr[k].name,R[j].name);
            arr[k].speakers = R[j].speakers;
            j++;
        }
        k++;
    }
    //Copia el resto de palabras del arreglo derecho al arreglo final
    while (i < size1){
        strcpy(arr[k].name,L[i].name);
        arr[k].speakers = L[i].speakers;
        i++;
        k++;
    }
    //Copia el resto de palabras del arreglo izquierdo al arreglo final
    while (j < size2){
        strcpy(arr[k].name,R[j].name);
        arr[k].speakers = R[j].speakers;
        j++;
        k++;
    }
}
void separePairsList(int bigListSize, pairCountSpeaks bigList[bigListSize], int list1Size, pairCountSpeaks list1[list1Size], int list2Size,pairCountSpeaks list2[list2Size]){
    for (int i = 0; i < bigListSize; i++){
        if (i < list1Size){
            list1[i].speakers = bigList[i].speakers;
            strcpy(list1[i].name,bigList[i].name);
        }
        else{
            strcpy((list2[i-list1Size].name),bigList[i].name);
            list2[i - list1Size].speakers = bigList[i].speakers;
        }
    }
}

void mergeShortPairs(int arrSize, pairCountSpeaks arr[arrSize]){
    if (arrSize > 1){
        int size1 = arrSize / 2;
        int size2 = arrSize - size1;
        pairCountSpeaks left[size1];
        pairCountSpeaks rigth[size2];
        separePairsList(arrSize, arr, size1, left, size2, rigth);
        mergeShortPairs(size1, left);
        mergeShortPairs(size2, rigth);
        mergePairs(arrSize, arr, size1, left, size2, rigth);
    }
}