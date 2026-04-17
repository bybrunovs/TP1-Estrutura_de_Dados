#include "Metrica.h"

namespace Metricas
{
    class STAB : public Metricas::Metrica
    {

    public:
        STAB(unsigned WCOTACOES);

        void calcularMetrica(Acao &acao, unsigned indiceMetrica);
    };
} // namespace Metrica