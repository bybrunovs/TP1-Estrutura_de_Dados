namespace TADS
{
    template <typename T>
    Vector<T>::Vector() : _capacidade(0), _tamanho(0)
    {
        // Inicia sem alocar memória, o primeiro push_back criará a capacidade.
        this->_dados = nullptr;
    }

    template <typename T>
    Vector<T>::Vector(unsigned capacidade) : _capacidade(capacidade), _tamanho(0)
    {
        // Aloca o buffer inicial com a capacidade especificada.
        this->_dados = new T[capacidade];
    }

    template <typename T>
    Vector<T>::Vector(const Vector &outro) : _capacidade(outro._capacidade), _tamanho(outro._tamanho)
    {
        // copia os dados do vetor original para um novo buffer.
        this->_dados = new T[outro._capacidade];
        for (unsigned i = 0; i < outro.tamanho(); i++)
        {
            this->_dados[i] = outro._dados[i];
        }
    }

    template <typename T>
    void Vector<T>::push_back(const T &elemento)
    {
        // Insere no fim sempre que houver espaço disponível.
        if (this->tamanho() + 1 <= this->_capacidade)
        {
            this->_dados[this->_tamanho] = elemento;
            this->_tamanho++;
        }
        else
        {
            // Se não houver capacidade, multiplica por 2.
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
            // Desloca os elementos subsequentes para preencher o espaço vazio.
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
    int Vector<T>::getIndice(const T &elemento) const
    {
        for (unsigned i = 0; i < this->_tamanho; i++)
        {
            if (this->_dados[i] == elemento)
            {
                return i;
            }
        }
        return -1; // Retorna -1 se o elemento não for encontrado.
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
            // Remove o buffer anterior e copia o conteúdo do outro vetor.
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
    unsigned Vector<T>::capacidade() const
    {
        return this->_capacidade;
    }

    template <typename T>
    Vector<T>::~Vector()
    {
        // Libera a memória dinâmica usada pelo vetor.
        delete[] this->_dados;
    }

} // namespace TADS