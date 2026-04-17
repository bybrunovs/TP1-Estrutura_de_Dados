#pragma once

#include <string>
#include "Acao.h"

namespace Metricas
{

    class Metrica
    {
    protected:
        unsigned _WCOTACOES;
        std::string _nomeMetrica;

    public:
        Metrica() : _WCOTACOES(0), _nomeMetrica("") {}
        Metrica(unsigned WCOTACOES) : _WCOTACOES(WCOTACOES) {}
        ~Metrica() = default;
        virtual void calcularMetrica(Acao &acao, unsigned indiceMetrica) {};
    };

} // namespace Metrica