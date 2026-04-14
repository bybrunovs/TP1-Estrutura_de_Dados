#pragma once
class Acao
{
private:
    unsigned id;
    unsigned* cotacoes;
    
public:
    Acao(unsigned id, unsigned WCotacoes);
    ~Acao();
};

