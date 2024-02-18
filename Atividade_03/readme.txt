# I/O de Malhas

Esta atividade faz parte de uma das entregas da matéria de Computação Gráfica. O objetivo deste exercício é  classe própria para ler modelos OBJ
Foi utilizado três modelos OBJ que podem ser encontrados em https://free3d.com/ para desenvolver o projeto. Também é possível fazer o download de mais modelos para novos testes.
Para realizar os testes unitários, foi utilizado a biblioteca Google Test,sendo necessário a instalação e vinculação da lib para executar o programa (instruções abaixo)

## Pré-requisitos

Essas instruções fornecerão uma cópia do projeto em execução na sua máquina local para fins de desenvolvimento e teste.

Para instalar o Google Test basta rodar o seguinte comando no terminal Ubunto:
```
$ sudo apt-get install libgtest-dev
```

### Executando o projeto


Vincule o Google Test ao seu programa: Ao compilar seu programa com g++, é necessário vincular o Google Test. Aqui está um exemplo de como fazer isso:
```
g++ main.cpp -o main -lgtest -lgtest_main -pthread
```

Para executar o projeto, basta abrir o arquivo gerado com o seguinte comando:
```
./main
```