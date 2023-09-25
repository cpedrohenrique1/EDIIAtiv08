#include "conjunto.h"

Conjunto::Conjunto(int tamanho_array):
    vetor(0),
    vetor_selection_sort(0),
    vetor_insertion_sort(0),
    vetor_bubble_sort(0),
    tamanho_vetor(0),
    nmr_execucoes(0)
{
    if (tamanho_array <= 0){
        throw QString("Erro: tamanho invalido");
    }
    tamanho_vetor = tamanho_array;
    try{
        vetor = new int[tamanho_vetor];
        vetor_selection_sort = new int[tamanho_vetor];
        vetor_insertion_sort = new int[tamanho_vetor];
        vetor_bubble_sort = new int[tamanho_vetor];
        srand(time(0));
        for (int i = 0; i < tamanho_vetor; ++i){
            ++nmr_execucoes;
            vetor_bubble_sort[i] = vetor_insertion_sort[i] = vetor_selection_sort[i] = vetor[i] = rand() % 1001;
        }
    }catch(std::bad_alloc &e){
        throw QString("Erro: memoria insuficiente");
    }
}

int Conjunto::getTamanhoVetor() const{
    return tamanho_vetor;
}

int* Conjunto::getVetor() const{
    return vetor;
}

int* Conjunto::getVetorSelectionSort() const{
    return vetor_selection_sort;
}

int* Conjunto::getVetorInsertionSort() const{
    return vetor_insertion_sort;
}

int* Conjunto::getVetorBubbleSort() const{
    return vetor_bubble_sort;
}

int Conjunto::getNmrExecucoes() const{
    return nmr_execucoes;
}

void Conjunto::selectionSort(){
    if (tamanho_vetor <= 0 || !vetor_selection_sort){
        throw QString("Erro: vetor vazio ou tamanho invalido");
    }
    if (nmr_execucoes){
        nmr_execucoes = 0;
    }
    for (int indice = 0; indice < tamanho_vetor - 1; ++indice){
        int min_idc = indice;
        for (int i = indice + 1; i < tamanho_vetor; ++i){
            if (vetor_selection_sort[i] < vetor_selection_sort[min_idc]){
                min_idc = i;
            }
            ++nmr_execucoes;
        }
        int temp = vetor_selection_sort[indice];
        vetor_selection_sort[indice] = vetor_selection_sort[min_idc];
        vetor_selection_sort[min_idc] = temp;
    }
}

void Conjunto::insertionSort(){
    if (tamanho_vetor <= 0 || !vetor_insertion_sort){
        throw QString("Erro: vetor vazio ou tamanho invalido");
    }
    if (nmr_execucoes){
        nmr_execucoes = 0;
    }
    for (int step = 1; step < tamanho_vetor; ++step){
        int key = vetor_insertion_sort[step];
        int j = step - 1;
        while (key < vetor_insertion_sort[j] && j >= 0){
            vetor_insertion_sort[j + 1] = vetor_insertion_sort[j];
            --j;
            ++nmr_execucoes;
        }
        vetor_insertion_sort[j + 1] = key;
    }
}

void Conjunto::bubbleSort(){
    if (tamanho_vetor <= 0 || !vetor_bubble_sort){
        throw QString("Erro: vetor vazio ou tamanho invalido");
    }
    if (nmr_execucoes){
        nmr_execucoes = 0;
    }
    bool swapped = false;
    for (int i = 0; i < tamanho_vetor - 1; ++i){
        swapped = true;
        for (int j = 0; j < tamanho_vetor - i - 1; ++j){
            if (vetor_bubble_sort[j] > vetor_bubble_sort[j + 1]){
                int temp = vetor_bubble_sort[j];
                vetor_bubble_sort[j] = vetor_bubble_sort[j + 1];
                vetor_bubble_sort[j + 1] = temp;
                swapped = true;
            }
            ++nmr_execucoes;
        }
        if (!swapped){
            return;
        }
    }
}

Conjunto::~Conjunto()
{
    if (vetor){
        delete[] vetor;
        vetor = 0;
    }
    if (vetor_selection_sort){
        delete[] vetor_selection_sort;
        vetor_selection_sort = 0;
    }
    if (vetor_insertion_sort){
        delete[] vetor_insertion_sort;
        vetor_insertion_sort = 0;
    }
    if (vetor_bubble_sort){
        delete[] vetor_bubble_sort;
        vetor_bubble_sort = 0;
    }
}
