#include "Acao.h"
#include "Cliente.h"
#include "TADS/Vector.h"
#include "Metricas.h"
#include <string>

class AnaliseCarteiras
{
private:
    TADS::Vector<Acao> _acoes;
    TADS::Vector<Cliente> _clientes;
    TADS::Vector<Metrica::Metricas> _metricas;

public:
    AnaliseCarteiras(unsigned wcotacoes, std::string metricas[], unsigned nAcoes, unsigned nClientes);
    ~AnaliseCarteiras();

    void AdicionarAcao(Acao &acao);
    void AdicionarCliente(Cliente &cliente);
    void AdicionarMetrica(Metrica::Metricas &metrica);
    void ConsultaCarteira(unsigned IdConsulta, Cliente &cliente, unsigned Nacoes, unsigned Nmetricas,  std::string metricas[],  unsigned peso[]);
    void VendaAcao(Cliente &cliente, Acao &acao);
    void COmpraAcao(Cliente &cliente, Acao &acao);
    void CotacaoAcao(Acao &acao, double &preco);
};