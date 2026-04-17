#include "AnaliseCarteiras.h"

AnaliseCarteiras::AnaliseCarteiras(unsigned wcotacoes)
{
}

AnaliseCarteiras::~AnaliseCarteiras()
{
}

void AnaliseCarteiras::AdicionarAcao(unsigned IDAcao)
{
}

void AnaliseCarteiras::AdicionarCliente(unsigned IDCliente)
{
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