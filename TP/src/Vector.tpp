namespace TADS
{
    template <typename T>
    Vector<T>::Vector(unsigned capacidade) : _tamanho(0), _capacidade(capacidade)
    {
        this->_dados = new T[capacidade];
    }

    template <typename T>
    Vector<T>::Vector(const Vector &outro) : _capacidade(outro._capacidade), _tamanho(outro._tamanho)
    {
        this->_dados = new T[outro.tamanho()];
        for (unsigned i = 0; i < outro.tamanho(); i++)
        {
            this->_dados[i] = outro._dados[i];
        }
    }

    template <typename T>
    void Vector<T>::push_back(const T &elemento)
    {
        if (this->tamanho() + 1 <= this->_capacidade)
        {
            this->_dados[this->_tamanho] = elemento;
            this->_tamanho++;
        }
        else
            throw std::out_of_range("Capacidade máxima atingida");
    }

    template <typename T>
    T Vector<T>::getElemento(unsigned indice)
    {
        if (indice < _tamanho)
        {
            return this->_dados[indice];
        }
        else
            throw std::out_of_range("Índice fora dos limites");
    }

    template <typename T>
    void Vector<T>::setElemento(unsigned indice, const T &valor)
    {
        if (indice < _tamanho)
        {
            this->_dados[indice] = valor;
        }
        else
            throw std::out_of_range("Índice fora dos limites");
    }

    template <typename T>
    void Vector<T>::deleteElemento(unsigned indice)
    {
        if (indice < _tamanho)
        {
            for (unsigned i = indice; i < this->_tamanho - 1; i++)
            {
                this->_dados[i] = this->_dados[i + 1];
            }
            this->_tamanho--;
        }
        else
            throw std::out_of_range("Índice fora dos limites");
    }

    template <typename T>
    T &Vector<T>::operator[](int indice)
    {
        if (indice < _tamanho)
        {
            return this->_dados[indice];
        }
        throw std::out_of_range("Índice fora dos limites");
    }

    template <typename T>
    unsigned Vector<T>::tamanho() const
    {
        return this->_tamanho;
    }

    template <typename T>
    Vector<T>::~Vector()
    {
        delete[] this->_dados;
    }

} // namespace TADS