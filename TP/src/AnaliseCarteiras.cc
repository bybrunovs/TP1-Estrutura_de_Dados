#include "AnaliseCarteiras.h"

AnaliseCarteiras::AnaliseCarteiras(unsigned wcotacoes)
{
}


void AnaliseCarteiras::AdicionarAcao(unsigned IDAcao)
{
    _entrouA = true;
}

void AnaliseCarteiras::AdicionarCliente(unsigned IDCliente)
{
    if (!_entrouA)
        throw std::invalid_argument("Entrada inválida: a linha de clientes deve vir após as linhas de ações");
    _entrouU = true;
}

void AnaliseCarteiras::AdicionarMetrica(const std::string &Metrica)
{

    if (Metrica.compare("RET") == 0)
    {
        _metricas.push_back(Metrica);
    }
    else if (Metrica.compare("AVGRET") == 0)
    {
        _metricas.push_back(Metrica);
    }
    else if (Metrica.compare("CONS") == 0)
    {
        _metricas.push_back(Metrica);
    }
    else if (Metrica.compare("STAB") == 0)
    {
        _metricas.push_back(Metrica);
    }
    else
        throw std::invalid_argument("Métrica inválida. As métricas válidas são: RET, AVGRET, CONS e STAB.");
}

void AnaliseCarteiras::ConsultaCarteira(unsigned IdConsulta, unsigned IDCliente, unsigned Nacoes, unsigned Nmetricas, const std::string *metricas, unsigned peso[])
{
}

void AnaliseCarteiras::VendaAcao(Cliente &cliente, Acao &acao)
{
}

void AnaliseCarteiras::CompraAcao(Cliente &cliente, Acao &acao)
{
}

void AnaliseCarteiras::CotacaoAcao(Acao &acao, double &preco)
{
}