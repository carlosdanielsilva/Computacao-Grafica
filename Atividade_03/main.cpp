/*!  
    @file main.cpp
    @brief Esse arquivo realiza 3 testes unitários com o auxílio do Framework Google Test para verificar a leitura correta de modelos OBJ a partir da classe OBJModel.h
    @author Carlos Daniel da Silva Pereira
    @version 1.0
*/

#include "OBJModel.h"
#include <gtest/gtest.h>

TEST(OBJModelTest, LoadFile) {
    // Teste com um arquivo OBJ 1.
    {
        OBJModel model;
        EXPECT_TRUE(model.load("bugatti.obj"));
        EXPECT_FALSE(model.vertices.empty());
        EXPECT_FALSE(model.faces.empty());
    }

    // Teste com um arquivo OBJ 2.
    {
        OBJModel model;
        EXPECT_TRUE(model.load("IronMan.obj"));
        EXPECT_FALSE(model.vertices.empty());
        EXPECT_FALSE(model.faces.empty());
    }

    // Teste com um arquivo OBJ 3.
    {
        OBJModel model;
        EXPECT_TRUE(model.load("desktop.obj"));
        EXPECT_FALSE(model.vertices.empty());
        EXPECT_FALSE(model.faces.empty());
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}