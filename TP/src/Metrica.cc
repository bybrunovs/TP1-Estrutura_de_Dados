#include "Metrica.h"

Metrica::Metrica() {}

double Metrica::RET(Acao &acao)
{

    return retornoElementar(acao.getCotacao(acao.getQuantidadeCotacoes() - 1), acao.getCotacao(0));
}

double Metrica::AVGRET(Acao &acao)
{
 
    // media dos retornos elementares

    double somaRetornoElementar = 0.0;
    for (unsigned i = 1; i < acao.getQuantidadeCotacoes(); i++)
    {
        somaRetornoElementar += retornoElementar(acao.getCotacao(i), acao.getCotacao(i - 1));
    }
    double mediaRetornoElementar = somaRetornoElementar / (acao.getQuantidadeCotacoes() - 1);
    return mediaRetornoElementar;
}

double Metrica::CONS(Acao &acao)
{

    // função indicadora do evento ri > 0
    double retornoElementares = 0;
    for (unsigned i = 1; i < acao.getQuantidadeCotacoes(); i++)
    {
        double retornoElementar = this->retornoElementar(acao.getCotacao(i), acao.getCotacao(i - 1));
        if (retornoElementar > 0)
        {
            retornoElementares++;
        }
    }

    double consistencia = retornoElementares / (acao.getQuantidadeCotacoes() - 1);
    return consistencia;
}

double Metrica::STAB(Acao &acao)
{

    // media dos retornos elementares
    double mediaRetornoElementar = Metrica::AVGRET(acao);

    // somatorio dos quadrados das diferenças entre os retornos elementares e a média
    double somaQuadradosDiferencas = 0.0;
    for (unsigned i = 1; i < acao.getQuantidadeCotacoes(); i++)
    {
        double diferenca = retornoElementar(acao.getCotacao(i), acao.getCotacao(i - 1)) - mediaRetornoElementar;
        somaQuadradosDiferencas += diferenca * diferenca;
    }
    double volatilidade = sqrt(somaQuadradosDiferencas / (acao.getQuantidadeCotacoes() - 1));
    double estabilidade = 1 / (1 + volatilidade);
    return estabilidade;
}
