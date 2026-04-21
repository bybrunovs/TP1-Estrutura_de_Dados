#include "AnaliseCarteiras.h"

AnaliseCarteiras::AnaliseCarteiras(unsigned wcotacoes) : _wcotacoes(wcotacoes)
{
    _metrica = Metrica(wcotacoes);
}

void AnaliseCarteiras::iniciarMetricas()
{
    for (unsigned i = 0; i < _nomesMetricas.tamanho(); i++)
    {
        TADS::Vector<unsigned> ordenacaoMetrica;
        for (unsigned j = 0; j < _acoes.tamanho(); j++)
        {
            ordenacaoMetrica.push_back(j);
        }
        _OrdenacaoMetricas.push_back(ordenacaoMetrica);
    }

    for (unsigned j = 0; j < _acoes.tamanho(); j++)
    {
        _ordenacaoGlobalAcoes.push_back(j);
    }
}

unsigned AnaliseCarteiras::getIndiceMetrica(const std::string &Metrica)
{
    for (unsigned i = 0; i < _nomesMetricas.tamanho(); i++)
    {
        if (_nomesMetricas.getElemento(i).compare(Metrica) == 0)
        {
            return i;
        }
    }
    throw std::invalid_argument("Métrica inválida");
}

void AnaliseCarteiras::AdicionarAcao(unsigned IDAcao)
{
    _entrouA = true;
    this->_acoes.push_back(Acao(IDAcao, this->_wcotacoes, this->_nomesMetricas.tamanho()));
}

void AnaliseCarteiras::AdicionarCliente(unsigned IDCliente)
{
    if (!_entrouA)
    {
        throw std::invalid_argument("Entrada inválida: a linha de clientes deve vir após as linhas de ações");
    }
    if (!_entrouUmetricas)
    {
        this->iniciarMetricas();
        _entrouUmetricas = true;
    }

    _entrouU = true;

    this->_clientes.push_back(Cliente(IDCliente));
}

void AnaliseCarteiras::AdicionarMetrica(const std::string &Metrica)
{

    if (Metrica.compare("RET") == 0)
    {
        _nomesMetricas.push_back(Metrica);
    }
    else if (Metrica.compare("AVGRET") == 0)
    {
        _nomesMetricas.push_back(Metrica);
    }
    else if (Metrica.compare("CONS") == 0)
    {
        _nomesMetricas.push_back(Metrica);
    }
    else if (Metrica.compare("STAB") == 0)
    {
        _nomesMetricas.push_back(Metrica);
    }
    else
        throw std::invalid_argument("Métrica inválida. As métricas válidas são: RET, AVGRET, CONS e STAB.");
}

void AnaliseCarteiras::ConsultaCarteira(unsigned IdConsulta, unsigned IDCliente, unsigned Nacoes, unsigned Nmetricas, const std::string *metricas, double peso[])
{
    if (!_entrouA || !_entrouU)
        throw std::invalid_argument("Entrada inválida: a linha de consulta deve vir após as linhas de ações e clientes");

    // calcular as metricas para as ações
    for (unsigned i = 0; i < Nmetricas; i++)
    {
        // verificar se a métrica é válida
        if (!_nomesMetricas.contains(metricas[i]))
            throw std::invalid_argument("Métrica inválida");

        // verificar qual
        unsigned k = getIndiceMetrica(metricas[i]);

        // calcular os pontos para cada ação de acordo com a métrica
        if (metricas[i].compare("RET") == 0)
        {
            for (unsigned j = 0; j < _acoes.tamanho(); j++)
            {
                Acao &acao = _acoes.getElemento(j);
                acao.setPontosMetrica(k, _metrica.RET(acao));
            }
        }
        else if (metricas[i].compare("AVGRET") == 0)
        {
            for (unsigned j = 0; j < _acoes.tamanho(); j++)
            {
                Acao &acao = _acoes.getElemento(j);
                acao.setPontosMetrica(k, _metrica.AVGRET(acao));
            }
        }
        else if (metricas[i].compare("CONS") == 0)
        {
            for (unsigned j = 0; j < _acoes.tamanho(); j++)
            {
                Acao &acao = _acoes.getElemento(j);
                acao.setPontosMetrica(k, _metrica.CONS(acao));
            }
        }
        else if (metricas[i].compare("STAB") == 0)
        {
            for (unsigned j = 0; j < _acoes.tamanho(); j++)
            {
                Acao &acao = _acoes.getElemento(j);
                acao.setPontosMetrica(k, _metrica.STAB(acao));
            }
        }
        else
            throw std::invalid_argument("Métrica inválida. As métricas válidas são: RET, AVGRET, CONS e STAB.");
    }

    // ordenar as ações de acordo com as métricas
    for (unsigned i = 0; i < Nmetricas; i++)
    {
        unsigned k = getIndiceMetrica(metricas[i]);
        ordenarMetrica(k);
    }

    // calcular a ordenação global das ações de acordo com as métricas e os pesos
    for (unsigned i = 0; i < _acoes.tamanho(); i++)
    {
        double pontuacaoGlobal = 0.0;
        for (unsigned j = 0; j < Nmetricas; j++)
        {
            unsigned k = getIndiceMetrica(metricas[j]);

            pontuacaoGlobal += (_acoes.tamanho() - _OrdenacaoMetricas.getElemento(k).getIndice(i)) * peso[j];
        }

        _acoes.getElemento(i).setPontosGlobal(pontuacaoGlobal);
    }

    // ordenar as ações de acordo com a ordenação global
    ordenarAcoes();

    // ordenar as ações da carteira do cliente de acordo com a ordenação global
    ordenarCliente(IDCliente, true);

    // imprimir as N ações da carteira do cliente com melhor e pior pontuação de acordo com as métricas
    Cliente &cliente = _clientes.getElemento(IDCliente);
    // Melores ações da carteira do cliente
    for (size_t i = 0; i < Nacoes && i < cliente.getNumeroAcoes(); i++)
    {
        if (i != 0 || _entrouQ == true)
        {
            std::cout << std::endl;
        }

        std::cout << "R " << IdConsulta << " M " << i << " " << cliente.getCarteira().getElemento(i)->getId() << " "
                  << cliente.getCarteira().getElemento(i)->getPontosGlobal();
    }

    // reordenar para ordem crescente para as piores
    ordenarCliente(IDCliente, false);

    // piores ações da carteira do cliente
    for (size_t i = 0; i < Nacoes && i < cliente.getNumeroAcoes(); i++)
    {
        std::cout << std::endl;
        std::cout << "R " << IdConsulta << " P " << i << " " << cliente.getCarteira().getElemento(i)->getId() << " "
                  << cliente.getCarteira().getElemento(i)->getPontosGlobal();
    }

    _entrouQ = true;
}

void AnaliseCarteiras::VendaAcao(unsigned IDCliente, unsigned IDAcao)
{
    Acao acao(IDAcao, this->_wcotacoes, this->_nomesMetricas.tamanho());
    if (!_acoes.contains(acao))
        throw std::invalid_argument("A ação com o ID especificado não existe");
    this->_clientes.getElemento(IDCliente).removerAcao(IDAcao);
}

void AnaliseCarteiras::CompraAcao(unsigned IDCliente, unsigned IDAcao)
{
    Acao acao(IDAcao, this->_wcotacoes, this->_nomesMetricas.tamanho());
    if (!_acoes.contains(acao))
        throw std::invalid_argument("A ação com o ID especificado não existe");

    if (this->_clientes.getElemento(IDCliente).possuiAcao(IDAcao))
        throw std::invalid_argument("O cliente já possui a ação com o ID especificado na carteira");
    this->_clientes.getElemento(IDCliente).adicionarAcao(this->_acoes.getElemento(IDAcao));
}

void AnaliseCarteiras::AdicionarCotacaoAcao(unsigned IDAcao, double &preco)
{
    this->_acoes.getElemento(IDAcao).adicionarCotacao(preco);
}

void AnaliseCarteiras::ordenarMetrica(unsigned indiceMetrica)
{
    quicksort(_OrdenacaoMetricas[indiceMetrica], 0, this->_acoes.tamanho() - 1, indiceMetrica);
}

void AnaliseCarteiras::ordenarAcoes()
{

    quicksort(_ordenacaoGlobalAcoes, 0, this->_acoes.tamanho() - 1);
}

void AnaliseCarteiras::ordenarCliente(unsigned IDCliente, bool isDecrescente)
{
    quicksort(_clientes.getElemento(IDCliente).getCarteira(), 0, this->_clientes.getElemento(IDCliente).getNumeroAcoes() - 1, isDecrescente);
}

// ordenacao metricas
void AnaliseCarteiras::quicksort(TADS::Vector<unsigned> &metrica, unsigned low, unsigned high, unsigned indiceMetrica)
{
    if (low < high)
    {
        unsigned pi = partition(metrica, low, high, indiceMetrica);

        if (pi > low)
            quicksort(metrica, low, pi - 1, indiceMetrica);
        if (pi < high)
            quicksort(metrica, pi + 1, high, indiceMetrica);
    }
}

void AnaliseCarteiras::quicksort(TADS::Vector<unsigned> &ordenacaoGlobalAcoes, unsigned low, unsigned high)
{
    if (low < high)
    {
        unsigned pi = partition(ordenacaoGlobalAcoes, low, high);

        if (pi > low)
            quicksort(ordenacaoGlobalAcoes, low, pi - 1);
        if (pi < high)
            quicksort(ordenacaoGlobalAcoes, pi + 1, high);
    }
}

void AnaliseCarteiras::quicksort(TADS::Vector<Acao *> &ordenacaoCarteiraCliente, unsigned low, unsigned high, bool isDecrescente)
{
    if (low < high)
    {
        unsigned pi = partition(ordenacaoCarteiraCliente, low, high, isDecrescente);

        if (pi > low)
            quicksort(ordenacaoCarteiraCliente, low, pi - 1, isDecrescente);
        if (pi < high)
            quicksort(ordenacaoCarteiraCliente, pi + 1, high, isDecrescente);
    }
}

double AnaliseCarteiras::partition(TADS::Vector<unsigned> &metrica, unsigned low, unsigned high, unsigned indiceMetrica)
{
    unsigned indexPivot = encontrarMediana(metrica.getElemento(low), low, metrica.getElemento(high / 2), high / 2, metrica.getElemento(high), high);
    double pivot = _acoes.getElemento(indexPivot).getPontosMetrica(indiceMetrica);
    unsigned i = low - 1;
    for (unsigned j = low; j < high; j++)
    {
        unsigned indexAtual = metrica.getElemento(j);
        double Atual = _acoes.getElemento(indexAtual).getPontosMetrica(indiceMetrica);
        if (Atual > pivot || (doubleEquals(Atual, pivot) && indexAtual < indexPivot))
        {
            i++;
            swap(metrica.getElemento(i), metrica.getElemento(j));
        }
    }
    swap(metrica.getElemento(i + 1), metrica.getElemento(high));
    return i + 1;
}

double AnaliseCarteiras::partition(TADS::Vector<unsigned> &ordenacaoGlobalAcoes, unsigned low, unsigned high)
{
    unsigned indexPivot = encontrarMediana(ordenacaoGlobalAcoes.getElemento(low), low, ordenacaoGlobalAcoes.getElemento(high / 2), high / 2, ordenacaoGlobalAcoes.getElemento(high), high);
    double pivot = _acoes.getElemento(indexPivot).getPontosGlobal();
    unsigned i = low - 1;

    for (unsigned j = low; j < high; j++)
    {
        unsigned indexAtual = ordenacaoGlobalAcoes.getElemento(j);
        double Atual = _acoes.getElemento(indexAtual).getPontosGlobal();
        if (Atual > pivot || (doubleEquals(Atual, pivot) && indexAtual < indexPivot))
        {
            i++;
            swap(ordenacaoGlobalAcoes.getElemento(i), ordenacaoGlobalAcoes.getElemento(j));
        }
    }
    swap(ordenacaoGlobalAcoes.getElemento(i + 1), ordenacaoGlobalAcoes.getElemento(high));
    return i + 1;
}

double AnaliseCarteiras::partition(TADS::Vector<Acao *> &ordenacaoCarteiraCliente, unsigned low, unsigned high, bool isDecrescente)
{
    unsigned indexPivot = encontrarMediana(ordenacaoCarteiraCliente.getElemento(low)->getPontosGlobal(), low, ordenacaoCarteiraCliente.getElemento(high / 2)->getPontosGlobal(), high / 2, ordenacaoCarteiraCliente.getElemento(high)->getPontosGlobal(), high);
    Acao *acaoPivot = ordenacaoCarteiraCliente.getElemento(indexPivot);
    double pivot = acaoPivot->getPontosGlobal();
    unsigned pivotId = acaoPivot->getId();
    unsigned i = low - 1;

    for (unsigned j = low; j < high; j++)
    {
        Acao *acaoAtual = ordenacaoCarteiraCliente.getElemento(j);
        double atual = acaoAtual->getPontosGlobal();
        unsigned idAtual = acaoAtual->getId();
        bool condicao;
        if (isDecrescente)
        {
            condicao = (atual > pivot) || (doubleEquals(atual, pivot) && idAtual < pivotId);
        }
        else
        {
            condicao = (atual < pivot) || (doubleEquals(atual, pivot) && idAtual < pivotId);
        }
        if (condicao)
        {
            i++;
            swap(ordenacaoCarteiraCliente.getElemento(i), ordenacaoCarteiraCliente.getElemento(j));
        }
    }
    swap(ordenacaoCarteiraCliente.getElemento(i + 1), ordenacaoCarteiraCliente.getElemento(high));
    return i + 1;
}

template <typename T>
void AnaliseCarteiras::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

unsigned AnaliseCarteiras::encontrarMediana(double a, unsigned indicea, double b, unsigned indiceb, double c, unsigned indicec)
{
    // Verifica se 'a' é a mediana
    if ((a >= b && a <= c) || (a >= c && a <= b))
        return indicea;
    // Verifica se 'b' é a mediana
    else if ((b >= a && b <= c) || (b >= c && b <= a))
        return indiceb;
    // Se não for 'a' ou 'b', então é 'c'
    else
        return indicec;
}

bool AnaliseCarteiras::doubleEquals(double a, double b)
{
    const double epsilon = 1e-3;
    return std::abs(a - b) < epsilon;
}