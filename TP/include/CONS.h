#include "Metrica.h"

namespace Metricas
{
    class CONS : public Metricas::Metrica
    {

    public:
        CONS(unsigned WCOTACOES);

        void calcularMetrica(Acao &acao, unsigned indiceMetrica);
    };
} // namespace Metrica