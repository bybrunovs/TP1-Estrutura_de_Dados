#pragma once

#include <stdexcept>
namespace TADS
{
    template <typename T>

    class Vector
    {
    private:
        T *_dados;
        unsigned _tamanho = 0;
        unsigned _capacidade = 0;

    public:
        Vector(unsigned capacidade);

        Vector(const Vector &outro);

        void push_back(const T &elemento);

        T getElemento(unsigned indice);

        void setElemento(unsigned indice, const T &valor);

        void deleteElemento(unsigned indice);

        T &operator[](int indice);

        unsigned tamanho() const;

        ~Vector();
    };

} // namespace TADS

#include "../src/Vector.tpp"