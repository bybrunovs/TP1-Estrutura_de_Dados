#pragma once

#include <stdexcept>
namespace TADS
{
    template <typename T>

    class Vector
    {
    private:
        T *_dados;

        unsigned _capacidade;
        unsigned _tamanho;

    public:
        Vector();

        Vector(unsigned capacidade);

        Vector(const Vector &outro);

        Vector &operator=(const Vector &outro);

        void push_back(const T &elemento);

        T &getElemento(unsigned indice);

        void setElemento(unsigned indice, const T &valor);

        void deleteElemento(unsigned indice);

        bool contains(const T &elemento) const;

        unsigned getIndice(const T &elemento) const;

        T &operator[](unsigned indice);

        const T &operator[](unsigned indice) const;

        unsigned tamanho() const;

        unsigned capacidade() const;

        ~Vector();
    };

} // namespace TADS

#include "../src/Vector.tpp"