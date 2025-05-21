import random

class Node:
    def __init__(self, valor):
        self.valor = valor
        self.anterior = None
        self.proximo = None

class ListaCircularDuplamenteEncadeada:
    def __init__(self):
        self.inicio = None
        self.tamanho = 0

    def inserir(self, valor):
        novo = Node(valor)
        if not self.inicio:
            self.inicio = novo
            novo.proximo = novo
            novo.anterior = novo
        else:
            fim = self.inicio.anterior
            fim.proximo = novo
            novo.anterior = fim
            novo.proximo = self.inicio
            self.inicio.anterior = novo
        self.tamanho += 1

    def get_node_at(self, pos):
        if pos < 0 or pos >= self.tamanho:
            return None
        atual = self.inicio
        for _ in range(pos):
            atual = atual.proximo
        return atual

    def buscar_muro_infinito(self, s, alvo):
        if s < 0 or s >= self.tamanho:
            return -1  # posição inicial inválida

        if self.get_node_at(s).valor == alvo:
            return s

        k = 1
        while k < self.tamanho:
            pos_esq = (s - k) % self.tamanho
            pos_dir = (s + k) % self.tamanho

            if self.get_node_at(pos_esq).valor == alvo:
                return pos_esq
            if self.get_node_at(pos_dir).valor == alvo:
                return pos_dir

            k += 1

        return -1  # não encontrado

# Exemplo de uso
muro = ListaCircularDuplamenteEncadeada()
qtd_valores = 10  # tamanho da lista
valores = random.sample(range(1, 101), qtd_valores)

print(f"Valores da lista: {valores}")

for v in valores:
    muro.inserir(v)

s = random.randint(0, len(valores) - 1)
alvo = random.choice(valores)

print(f"Posição inicial aleatória: {s}")
print(f"Alvo aleatório: {alvo}")

posicao = muro.buscar_muro_infinito(s, alvo)
if posicao != -1:
    print(f"Valor {alvo} encontrado na posição {posicao}.")
else:
    print(f"Valor {alvo} não encontrado.")