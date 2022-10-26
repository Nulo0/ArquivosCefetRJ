## Busca Binária

Arquivo Principal: `BuscaCEP.c`.

### Objetivo
Encontrar, a partir do cep digitado, informações de:
* Logradouro
* Bairro
* Cidade
* Uf
* Sigla

### Utilização
Dentro da pasta "BuscaCep", deve haver um arquivo contendo os ceps ordenados, que será usado para realizar a busca.


Exemplo de utilização:
```C
./buscaCep [cep]
```

### Compilação

```C
gcc -o buscaCep buscaCEP.c
```

+ gcc -> Conjunto de compiladores.
+ -o --> Flag de controle do nível de otimização.
+ buscaCep --> Nome do executável a ser gerado, mude-o conforme sua necessidade.
+ buscaCep.c --> Nome do código em C responsável por gerar o executável.