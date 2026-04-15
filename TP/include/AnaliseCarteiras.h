#include "Acao.h"
#include "Cliente.h"
#include "TADS/Vector.h"
#include "Metricas/Metricas.h"
#include <string>

class AnaliseCarteiras
{
private:
    TADS::Vector<Acao> _acoes;
    TADS::Vector<Cliente> _clientes;
    TADS::Vector<Metrica::Metricas> _metricas;

public:
    AnaliseCarteiras(unsigned wcotacoes, unsigned nAcoes, unsigned nClientes);
    ~AnaliseCarteiras();

    void AdicionarAcao(unsigned IDAcao);
    void AdicionarCliente(unsigned IDCliente);
    void AdicionarMetrica(const std::string& Metrica);
    void ConsultaCarteira(unsigned IdConsulta, unsigned IDCliente, unsigned Nacoes, unsigned Nmetricas,  const std::string* metricas,  unsigned peso[]);
    void VendaAcao(Cliente &cliente, Acao &acao);
    void COmpraAcao(Cliente &cliente, Acao &acao);
    void CotacaoAcao(Acao &acao, double &preco);
};