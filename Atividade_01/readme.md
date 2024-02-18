# I/O de Imagens

Esta atividade faz parte de uma das entregas da matéria de Computação Gráfica. O objetivo deste exercício é gerar três imagens: Círculo, Quadrado e Losango.
Para salvar as imagens, foi utilizado a biblioteca ImageMagick, sendo necessário a instalação da lib para executar o programa (instruções abaixo)

## Pré-requisitos

Essas instruções fornecerão uma cópia do projeto em execução na sua máquina local para fins de desenvolvimento e teste.

Para instalar o ImageMgick basta rodar o seguinte comando no terminal Ubunto:
```
$ sudo apt install imagemagick
```
### Executando o projeto

Para compilar o projeto, rode o seguinte comando e substitua "arquivo.cpp" pelo arquivo que deseja compilar (circulo.cpp, losando.cpp ou quadrado.cpp):
```
g++ `Magick++-config --cxxflags --cppflags` -O2 -o exec arquivo.cpp `Magick++-config --ldflags --libs`
```

Para executar o projeto, basta abrir o arquivo gerado com o seguinte comando:
```
./exec
```

Por fim, será gerado uma imagem para visualização.