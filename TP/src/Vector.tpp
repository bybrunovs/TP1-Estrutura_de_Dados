namespace TADS
{
    template <typename T>
    Vector<T>::Vector() : _capacidade(0), _tamanho(0)
    {
        this->_dados = nullptr;
    }

    template <typename T>
    Vector<T>::Vector(unsigned capacidade) : _capacidade(capacidade), _tamanho(0)
    {
        this->_dados = new T[capacidade];
    }

    template <typename T>
    Vector<T>::Vector(const Vector &outro) : _capacidade(outro._capacidade), _tamanho(outro._tamanho)
    {
        this->_dados = new T[outro._capacidade];
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
        {
            if (this->_capacidade == 0)
            {
                this->_capacidade = 1;
            }

            T *_novosDados = new T[this->_capacidade * 2];
            for (unsigned i = 0; i < this->_tamanho; i++)
            {
                _novosDados[i] = this->_dados[i];
            }
            delete[] this->_dados;
            this->_dados = _novosDados;
            this->_capacidade *= 2;
            this->_dados[this->_tamanho] = elemento;
            this->_tamanho++;
        }
    }

    template <typename T>
    T &Vector<T>::getElemento(unsigned indice)
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
    bool Vector<T>::contains(const T &elemento) const
    {
        for (unsigned i = 0; i < this->_tamanho; i++)
        {
            if (this->_dados[i] == elemento)
            {
                return true;
            }
        }
        return false;
    }

    template <typename T>
    unsigned Vector<T>::getIndice(const T &elemento) const
    {
        for (unsigned i = 0; i < this->_tamanho; i++)
        {
            if (this->_dados[i] == elemento)
            {
                return i;
            }
        }
        throw std::out_of_range("Elemento não encontrado");
    }

    template <typename T>
    T &Vector<T>::operator[](unsigned indice)
    {
        if (indice < _tamanho)
        {
            return this->_dados[indice];
        }
        throw std::out_of_range("Índice fora dos limites");
    }

    template <typename T>
    const T &Vector<T>::operator[](unsigned indice) const
    {
        if (indice < _tamanho)
        {
            return this->_dados[indice];
        }
        throw std::out_of_range("Índice fora dos limites");
    }

    template <typename T>
    Vector<T> &Vector<T>::operator=(const Vector<T> &outro)
    {
        if (this != &outro)
        {
            delete[] _dados;
            _capacidade = outro._capacidade;
            _tamanho = outro._tamanho;
            _dados = new T[_capacidade];
            for (unsigned i = 0; i < _tamanho; i++)
            {
                _dados[i] = outro._dados[i];
            }
        }
        return *this;
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