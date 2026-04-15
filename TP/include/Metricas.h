#pragma once

#include <string.h>
#include "Acao.h"

namespace Metrica
{

    unsigned _WCOTACOES;

    class Metricas
    {
    private:
        unsigned _id;

    public:
        Metricas();
        virtual ~Metricas() = default;
        virtual double calcularMetrica(Acao& acao, unsigned peso) const = 0;
    };

} // namespace Metrica