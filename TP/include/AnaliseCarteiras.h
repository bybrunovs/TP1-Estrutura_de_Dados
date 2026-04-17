#include "Acao.h"
#include "Cliente.h"
#include "Vector.h"
#include <string>

class AnaliseCarteiras
{
private:
    TADS::Vector<Acao> _acoes;
    TADS::Vector<Cliente> _clientes;
    TADS::Vector<std::string> _metricas;
    TADS::Vector<TADS::Vector<Acao *>> _OrdenacaoMetricas;

    unsigned _wcotacoes = 0;
    bool _entrouA = false;
    bool _entrouU = false;

public:
    AnaliseCarteiras(unsigned wcotacoes);
    ~AnaliseCarteiras() = default;

    void AdicionarAcao(unsigned IDAcao);
    void AdicionarCliente(unsigned IDCliente);
    void AdicionarMetrica(const std::string &Metrica);
    void ConsultaCarteira(unsigned IdConsulta, unsigned IDCliente, unsigned Nacoes, unsigned Nmetricas, const std::string *metricas, unsigned peso[]);
    void VendaAcao(Cliente &cliente, Acao &acao);
    void CompraAcao(Cliente &cliente, Acao &acao);
    void CotacaoAcao(Acao &acao, double &preco);
};