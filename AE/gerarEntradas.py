import random

def gerar_entrada(n_acoes, n_clientes, n_cotacoes, n_consultas, nome_arquivo):
    with open(nome_arquivo, 'w') as f:
        # 1. Linha M: Define a janela w e as métricas [cite: 58, 62]
        w = n_cotacoes
        f.write(f"M {w} RET AVGRET STAB CONS\n")

        # 2. Linhas A: Identificadores de 0 a N-1 [cite: 67, 98]
        for i in range(n_acoes):
            f.write(f"A {i}\n")

        # 3. Linhas U: Identificadores de 0 a u-1 [cite: 69, 99]
        for i in range(n_clientes):
            f.write(f"U {i}\n")

        # 4. Operações Dinâmicas (P, B, V, Q) [cite: 83, 101]
        # Primeiro, vamos garantir que cada ação tenha cotações iniciais
        for acao in range(n_acoes):
            for _ in range(w):
                preco = round(random.uniform(10.0, 100.0), 2)
                f.write(f"P {acao} {preco}\n")

        # Vincular algumas ações aos clientes (Compras) [cite: 73]
        for cliente in range(n_clientes):
            # Cada cliente começa com algumas ações aleatórias
            acoes_iniciais = random.sample(range(n_acoes), k=min(10, n_acoes))
            for acao in acoes_iniciais:
                f.write(f"B {cliente} {acao}\n")

        # 5. Gerar Consultas e novas cotações intercaladas [cite: 83]
        for i in range(n_consultas):
            # Nova cotação aleatória
            acao_aleatoria = random.randint(0, n_acoes - 1)
            f.write(f"P {acao_aleatoria} {round(random.uniform(10.0, 100.0), 2)}\n")
            
            # Consulta Q: <id> <cliente> <n_ranking> <m_metricas> <pares metrica peso> [cite: 79, 80]
            cliente_alvo = random.randint(0, n_clientes - 1)
            f.write(f"Q {i} {cliente_alvo} 3 2 RET 1.5 STAB 0.5\n")


# for i in range(5):
#     #variando acoes
#     gerar_entrada(10 ** (i + 1), 10, 10, 10, f"AE/entradas/acoes{i}.txt")

#     #variando cliente
#     gerar_entrada(10,10 ** (i + 1), 10, 10, f"AE/entradas/cliente{i}.txt")

#     #variando cotacoes
#     gerar_entrada(10, 10,10 ** (i + 1), 10, f"AE/entradas/cotacoes{i}.txt")

#     #variando consultas
#     gerar_entrada(10, 10, 10,10 ** (i + 1), f"AE/entradas/consultas{i}.txt")

# acoes
gerar_entrada(50000, 10, 10, 10, f"AE/entradas/acoes5.txt")

# cliente
gerar_entrada(10,50000, 10, 10, f"AE/entradas/cliente5.txt")

#varando cotacoes
gerar_entrada(10, 10,50000, 10, f"AE/entradas/cotacoes5.txt")

# consultas
gerar_entrada(10, 10, 10,50000, f"AE/entradas/consultas5.txt")