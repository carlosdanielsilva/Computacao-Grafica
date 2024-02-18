/*!  
    @file circulo.cpp
    @brief Essa classe realiza a criação de uma imagem com 2 círculos 
    @author Carlos Daniel da Silva Pereira
    @version 1.0
*/

#include <string>
#include <iostream>
#include <Magick++.h>


using namespace std;
using namespace Magick;

int main(int /*argc*/, char **argv){
  try{
    InitializeMagick(*argv);

    Image image(Geometry(350, 350), Color("white"));

    // Círculo preto externo
    image.fillColor("black");
    image.draw(DrawableCircle(175, 175, 100, 100));

    // Círculo azul interno
    image.fillColor("blue");
    image.draw(DrawableCircle(175, 175, 200, 200));

    image.write("circulos.png");


    return 0;           
  }
    catch (exception &error_) {
        cerr << "Caught exception: " << error_.what() << endl;
        return 1;
    }
}
