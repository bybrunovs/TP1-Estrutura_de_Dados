#include "Acao.h"
#include "Cliente.h"
#include "Vector.h"
#include "Metrica.h"
#include "RET.h"
#include "AVGRET.h"
#include "CONS.h"
#include "STAB.h"
#include <string>

class AnaliseCarteiras
{
private:
    TADS::Vector<Acao> _acoes;
    TADS::Vector<Cliente> _clientes;
    TADS::Vector<Metricas::Metrica> _metricas;
    TADS::Vector<TADS::Vector<Acao *>> _OrdenacaoMetricas;

    unsigned _wcotacoes = 0;
    bool _entrouA = false;
    bool _entrouC = false;

public:
    AnaliseCarteiras(unsigned wcotacoes);
    ~AnaliseCarteiras();

    void AdicionarAcao(unsigned IDAcao);
    void AdicionarCliente(unsigned IDCliente);
    void AdicionarMetrica(const std::string &Metrica);
    void ConsultaCarteira(unsigned IdConsulta, unsigned IDCliente, unsigned Nacoes, unsigned Nmetricas, const std::string *metricas, unsigned peso[]);
    void VendaAcao(Cliente &cliente, Acao &acao);
    void CompraAcao(Cliente &cliente, Acao &acao);
    void CotacaoAcao(Acao &acao, double &preco);
};