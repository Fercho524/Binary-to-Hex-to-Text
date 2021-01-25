#include "Lib.h"

//Las siguientes 2 funciones imprimen las listas, principalmente usadas para el desarrollo
void printNumberList(int list[], int size){
    printf("[ ");
    for (int i = 0; i < size; i++){
        printf(" %d, ", list[i]);
    }
    printf(" ]\n");
}
void printStingList(int size, char list[size][maxTextLengh]){
    printf("[ ");
    for (int i = 0; i < size; i++){
        printf(" %s, ", list[i]);
    }
    printf(" ]\n");
}
//FOR LIST OF NUMBERS
//mix and short 2 list of ints
void mergeInt(int arrSize, int arr[arrSize], int size1, int L[size1], int size2, int R[size2]){
    int i = 0; // Indice del primer array
    int j = 0; // Indice del segundo array
    int k = 0; // Indice del array final
    //Aqui se hace el recorrido
    while (i < size1 && j < size2){
        //Si el elemento del arreglo izquierdo es menor el elemento del final sera el de la izquierda
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        //Si no el elemento final sera de la derecha dado que es mayor
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //Copia el resto de palabras del arreglo derecho al arreglo final
    while (i < size1){
        arr[k] = L[i];
        i++;
        k++;
    }
    //Copia el resto de palabras del arreglo izquierdo al arreglo final
    while (j < size2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
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
//separa en 2 partes una lista de enteros
void separeIntList(int bigListSize, int bigList[bigListSize], int list1Size, int list1[list1Size], int list2Size, int list2[list2Size]){
    for (int i = 0; i < bigListSize; i++){
        if (i < list1Size){
            list1[i] = bigList[i];
        }
        else{
            list2[i - list1Size] = bigList[i];
        }
    }
}
//mix a list of Strings
void mergeStr(int arrSize, char arr[arrSize][maxTextLengh], int size1, char L[size1][maxTextLengh], int size2, char R[size2][maxTextLengh]){
    int i = 0; // Indice del primer array
    int j = 0; // Indice del segundo array
    int k = 0; // Indice del array final
    //Aqui se hace el recorrido para ordenar los elementos
    while (i < size1 && j < size2){
        //Si el elemento del arreglo izquierdo es menor el elemento del final sera el de la izquierda
        if (L[i][0] <= R[j][0]){
            strcpy(arr[k], L[i]);
            i++;
        }
        //Si no el elemento final sera de la derecha dado que es mayor
        else{
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }
    //Copia el resto de palabras del arreglo derecho al arreglo final
    while (i < size1){
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }
    //Copia el resto de palabras del arreglo izquierdo al arreglo final
    while (j < size2){
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}
// Este divide 2 listas de palabras segun el tamaño de las listas contenedoras que le pasemos
void separeStrList(int bigListSize, char bigList[bigListSize][maxTextLengh], int list1Size, char list1[list1Size][maxTextLengh], int list2Size, char list2[list2Size][maxTextLengh]){
    for (int i = 0; i < bigListSize; i++){
        if (i < list1Size){
            strcpy(list1[i], bigList[i]);
        }
        else{
            strcpy(list2[i - list1Size], bigList[i]);
        }
    }
}
//---------------------------Algoritmos de ordenamiento para enteros y cadenas------------------------------------------------------------------
void mergeShortInt(int arrSize, int arr[arrSize]){
    if (arrSize > 1){
        int size1 = arrSize / 2;
        int size2 = arrSize - size1;
        int left[size1];
        int rigth[size2];
        separeIntList(arrSize, arr, size1, left, size2, rigth);
        mergeShortInt(size1, left);
        mergeShortInt(size2, rigth);
        mergeInt(arrSize, arr, size1, left, size2, rigth);
    }
}
void mergeShortStr(int arrSize, char arr[arrSize][maxTextLengh]){
    if (arrSize > 1){
        int size1 = arrSize / 2;
        int size2 = arrSize - size1;
        char left[size1][maxTextLengh];
        char rigth[size2][maxTextLengh];
        separeStrList(arrSize, arr, size1, left, size2, rigth);
        mergeShortStr(size1, left);
        mergeShortStr(size2, rigth);
        mergeStr(arrSize, arr, size1, left, size2, rigth);
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