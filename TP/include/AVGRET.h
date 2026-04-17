#include "Metrica.h"

namespace Metricas
{
    class AVGRET : public Metricas::Metrica
    {

    public:
        AVGRET(unsigned WCOTACOES);

        void calcularMetrica(Acao &acao, unsigned indiceMetrica);
    };
} // namespace Metrica 