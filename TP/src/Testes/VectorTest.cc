#include "Vector.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    TADS::Vector<int> vetor;

    vetor.push_back(5);

    vetor.push_back(10);

    // vetor.push_back(15);

    std::cout << "Tamanho do vetor: " << vetor.tamanho() << std::endl;

    for (unsigned i = 0; i < vetor.tamanho(); i++)
    {
        std::cout << vetor[i] << std::endl;
    }

    std::cout << "Elemento na posição 0: " << vetor[0] << std::endl;
    std::cout << "Elemento na posição 0(get): " << vetor.getElemento(0) << std::endl;

    vetor.deleteElemento(0);

    std::cout << "Tamanho do vetor após exclusão: " << vetor.tamanho() << std::endl;
    std::cout << "Elemento na posição 0 após exclusão: " << vetor[0] << std::endl;
    std::cout << "Elemento na posição 0(get) após exclusão: " << vetor.getElemento(0) << std::endl;

    vetor.setElemento(0, 15);

    std::cout << "Elemento na posição 0 após set: " << vetor.getElemento(0) << std::endl;

    TADS::Vector<int> vetorduplicado = vetor;

    for (unsigned i = 0; i < vetorduplicado.tamanho(); i++)
    {
        std::cout << vetorduplicado[i] << std::endl;
    }

    vetor.push_back(3);
    vetor.push_back(4);
    vetor.push_back(6);

        for (unsigned i = 0; i < vetor.tamanho(); i++)
    {
        std::cout << vetor[i] << std::endl;
    }
    return 0;
}
