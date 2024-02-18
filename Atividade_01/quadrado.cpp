/*! 
    @file quadrado.cpp
    @brief Essa classe realiza a criação de uma imagem com 3 quadrados 
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

        Image image(Geometry(200, 200), Color("white"));

        // Quadrado externo
        image.fillColor("black");
        image.draw(DrawableRectangle(10, 10, 190, 190));

        // Quadrado intermediário
        image.fillColor("blue");
        image.draw(DrawableRectangle(30, 30, 170, 170));

        // Quadrado interno
        image.fillColor("red");
        image.draw(DrawableRectangle(50, 50, 150, 150));

        image.write("quadrados_sobrepostos.png");


        return 1;  
    }
    catch (exception &error_) {
        cerr << "Caught exception: " << error_.what() << endl;
        return 1;
    }
}
