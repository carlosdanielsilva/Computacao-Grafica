/*!  
    @file losango.cpp
    @brief Essa classe realiza a criação de uma imagem com um losango
    @author Carlos Daniel da Silva Pereira
    @version 1.0
*/
#include <string>
#include <iostream>
#include <Magick++.h>

using namespace std;
using namespace Magick;

int main(int /*argc*/, char **argv) {
    try {
        InitializeMagick(*argv);

        Image image(Geometry(400, 400), Color("white"));

        // Define as coordenadas para o losango
        std::list<Coordinate> coordinates;
        coordinates.push_back(Coordinate(200, 50));   // Topo
        coordinates.push_back(Coordinate(350, 200)); // Direita
        coordinates.push_back(Coordinate(200, 350)); // Baixo
        coordinates.push_back(Coordinate(50, 200));  // Esquerda

        // Desenha um losango verde
        image.fillColor("green");
        image.draw(DrawablePolygon(coordinates));

        image.write("losango.png");

        return 0;
    }
    catch (exception &error_) {
        cerr << "Caught exception: " << error_.what() << endl;
        return 1;
    }
}