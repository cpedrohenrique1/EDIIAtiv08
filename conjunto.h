#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <time.h>
#include <iostream>
#include <QString>

class Conjunto
{
private:
    int *vetor;
    int *vetor_selection_sort;
    int *vetor_insertion_sort;
    int tamanho_vetor;
    int nmr_execucoes;
public:
    Conjunto(int tamanho_array);
    ~Conjunto();
    int getTamanhoVetor() const;
    int *getVetor() const;
    int* getVetorSelectionSort() const;
    int* getVetorInsertionSort() const;
    int getNmrExecucoes() const;
    void selectionSort();
    void insertionSort();
};

#endif // CONJUNTO_H
