#include "Metrica.h"

class Metrica
{
protected:
    unsigned _WCOTACOES;

    double retornoElementar(const double cotacaoAtual, const double cotacaoAnterior)
    {
        return (cotacaoAtual / cotacaoAnterior) - 1;
    }

public:
    Metrica() : _WCOTACOES(0) {}
    Metrica(unsigned WCOTACOES) : _WCOTACOES(WCOTACOES) {}
    ~Metrica() = default;

    double RET(Acao &acao, unsigned indiceMetrica)
    {

        acao.setPontosMetrica(indiceMetrica, retornoElementar(acao.getCotacao(_WCOTACOES - 1), acao.getCotacao(0)));
    }

    double AVGRET(Acao &acao, unsigned indiceMetrica)
    {

        // media dos retornos elementares

        double somaRetornoElementar = 0.0;
        for (int i = 1; i < _WCOTACOES; i++)
        {
            somaRetornoElementar += retornoElementar(acao.getCotacao(i), acao.getCotacao(i - 1));
        }
        double mediaRetornoElementar = somaRetornoElementar / (_WCOTACOES - 1);
        acao.setPontosMetrica(indiceMetrica, mediaRetornoElementar);
    }

    double CONS(Acao &acao, unsigned indiceMetrica)
    {

        // função indicadora do evento ri > 0
        double retornoElementares = 0;
        for (int i = 1; i < _WCOTACOES - 1; i++)
        {
            double retornoElementar = this->retornoElementar(acao.getCotacao(i), acao.getCotacao(i - 1));
            if (retornoElementar > 0)
            {
                retornoElementares++;
            }
        }

        double consistencia = retornoElementares / (_WCOTACOES - 1);
        acao.setPontosMetrica(indiceMetrica, consistencia);
    }

    double STAB(Acao &acao, unsigned indiceMetrica)
    {

        // media dos retornos elementares
        double somaRetornoElementar = 0.0;
        for (int i = 1; i < _WCOTACOES; i++)
        {
            somaRetornoElementar += (acao.getCotacao(i) / acao.getCotacao(i - 1)) - 1;
        }
        double mediaRetornoElementar = somaRetornoElementar / (_WCOTACOES - 1);

        // somatorio dos quadrados das diferenças entre os retornos elementares e a média
        double somaQuadradosDiferencas = 0.0;
        for (int i = 1; i < _WCOTACOES; i++)
        {
            double diferenca = (acao.getCotacao(i) / acao.getCotacao(i - 1)) - 1 - mediaRetornoElementar;
            somaQuadradosDiferencas += diferenca * diferenca;
        }
        double volatilidade = sqrt(somaQuadradosDiferencas / (_WCOTACOES - 1));
        double estabilidade = 1 / (1 + volatilidade);
        acao.setPontosMetrica(indiceMetrica, estabilidade);
    }
};