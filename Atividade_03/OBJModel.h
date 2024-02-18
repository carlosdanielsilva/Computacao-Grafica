/*!  
    @file OBJModel.h
    @brief Essa classe a leitura de modelos OBJ
    @author Carlos Daniel da Silva Pereira
    @version 1.0
*/

#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Vertex {
    float x, y, z;
};

struct Face {
    int v1, v2, v3;
};

class OBJModel {
public:
    std::vector<Vertex> vertices;
    std::vector<Face> faces;

    bool load(const std::string& filename) {
        std::ifstream in(filename, std::ios::in);
        if (!in) {
            return false;
        }

        std::string line;
        while (std::getline(in, line)) {
            if (line.substr(0, 2) == "v ") {
                std::istringstream s(line.substr(2));
                Vertex v;
                s >> v.x; 
                s >> v.y; 
                s >> v.z;
                vertices.push_back(v);
            } else if (line.substr(0, 2) == "f ") {
                std::istringstream s(line.substr(2));
                Face f;
                s >> f.v1; 
                s >> f.v2; 
                s >> f.v3;
                faces.push_back(f);
            }
        }

        return true;
    }
};