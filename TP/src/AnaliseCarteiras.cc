#include "AnaliseCarteiras.h"

AnaliseCarteiras::AnaliseCarteiras(unsigned wcotacoes){

}

AnaliseCarteiras::~AnaliseCarteiras(){

}

void AnaliseCarteiras::AdicionarAcao(unsigned IDAcao){

}

void AnaliseCarteiras::AdicionarCliente(unsigned IDCliente)
{

}

void AnaliseCarteiras::AdicionarMetrica(const std::string &Metrica){

    if (Metrica.compare("RET") == 0)
        {
            _metricas.push_back(Metricas::RET(_wcotacoes));
        }
        else if (Metrica.compare("AVGRET") == 0)
        {
            _metricas.push_back(Metricas::AVGRET(_wcotacoes));
        }
        else if (Metrica.compare("CONS") == 0)
        {
            _metricas.push_back(Metricas::CONS(_wcotacoes));
        }
        else if (Metrica.compare("STAB") == 0)
        {
            _metricas.push_back(Metricas::STAB(_wcotacoes));
        }
}

void AnaliseCarteiras::ConsultaCarteira(unsigned IdConsulta, unsigned IDCliente, unsigned Nacoes, unsigned Nmetricas, const std::string *metricas, unsigned peso[]){

}

void AnaliseCarteiras::VendaAcao(Cliente &cliente, Acao &acao){

}

void AnaliseCarteiras::CompraAcao(Cliente &cliente, Acao &acao){

}

void AnaliseCarteiras::CotacaoAcao(Acao &acao, double &preco){

}