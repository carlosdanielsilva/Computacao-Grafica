/*!  
    @file main.cpp
    @brief Esse arquivo realiza testes unitários com a biblioteca assert nas classes vec2, vec4, mat2 e mat3.
    @author Carlos Daniel da Silva Pereira
    @version 1.0
*/

#include "vec2.h"
#include "vec4.h"
#include "mat2.h"
#include "mat3.h"
#include <cassert>


void test_unitary_vec2(){
    //VEC2
    std::cout << "TESTES: Iniciando os testes unitários vec2.\n";
  
    // Testar construtores
    vec2 v1;
    assert(v1.x() == 0 && v1.y() == 0);

    vec2 v2(1, 2);
    assert(v2.x() == 1 && v2.y() == 2);

    // Testar operações de vetor
    vec2 v3 = v2 + v2;
    assert(v3.x() == 2 && v3.y() == 4);

    vec2 v4 = v2 - v2;
    assert(v4.x() == 0 && v4.y() == 0);

    vec2 v5 = v2 * 2;
    assert(v5.x() == 2 && v5.y() == 4);

    vec2 v6 = v5 / 2;
    assert(v6.x() == 1 && v6.y() == 2);

    // Testar produto escalar (dot product)
    double dp = dot(v2, v2);
    assert(dp == 5); // 1*1 + 2*2 = 5

    // Testar comprimento (length) e comprimento ao quadrado (length_squared)
    assert(v2.length_squared() == 5);
    assert(v2.length() == sqrt(5));

    // Testar vetor unitário (unit vector)
    vec2 v7 = unit_vector(v2);
    double len = v7.length();
    assert(len > 0.9999999 && len < 1.0000001);
    std::cout << "SUCESSO: Todos os testes unitários vec4 passaram.\n";
}

void test_unitary_vec4(){
    //VEC4

    std::cout << "TESTES: Iniciando os testes unitários vec4.\n";
    // Testar construtores
    vec4 v1;
    assert(v1.x() == 0 && v1.y() == 0 && v1.z() == 0 && v1.w() == 0);

    vec4 v2(1, 2, 3, 4);
    assert(v2.x() == 1 && v2.y() == 2 && v2.z() == 3 && v2.w() == 4);

    // Testar operações de vetor
    vec4 v3 = v2 + v2;
    assert(v3.x() == 2 && v3.y() == 4 && v3.z() == 6 && v3.w() == 8);

    vec4 v4 = v2 - v2;
    assert(v4.x() == 0 && v4.y() == 0 && v4.z() == 0 && v4.w() == 0);

    vec4 v5 = v2 * 2;
    assert(v5.x() == 2 && v5.y() == 4 && v5.z() == 6 && v5.w() == 8);

    vec4 v6 = v5 / 2;
    assert(v6.x() == 1 && v6.y() == 2 && v6.z() == 3 && v6.w() == 4);

    // Testar produto escalar (dot product)
    double dp = dot(v2, v2);
    assert(dp == 30); // 1*1 + 2*2 + 3*3 + 4*4 = 30

    // Testar comprimento (length) e comprimento ao quadrado (length_squared)
    assert(v2.length_squared() == 30);
    assert(v2.length() == sqrt(30));


    std::cout << "SUCESSO: Todos os testes unitários vec4 passaram.\n";


}

void test_unitary_mat2(){
    //MAT2
    std::cout << "TESTES: Iniciando os testes unitários mat2.\n";

    // Testa o construtor padrão
    {
        mat2 m;
        assert(m.x0() == 0);
        assert(m.y0() == 0);
        assert(m.x1() == 0);
        assert(m.y1() == 0);
    }

    // Testa o construtor parametrizado
    {
        mat2 m(1, 2, 3, 4);
        assert(m.x0() == 1);
        assert(m.y0() == 2);
        assert(m.x1() == 3);
        assert(m.y1() == 4);
    }

    // Testa a transposição de uma matriz
    {
        mat2 m(1, 2, 3, 4);
        mat2 t = transpose(m);
        assert(t.x0() == 1);
        assert(t.y0() == 3);
        assert(t.x1() == 2);
        assert(t.y1() == 4);
    }

    // Testa o cálculo do determinante de uma matriz
    {
        mat2 m(1, 2, 3, 4);
        double det = determinant(m);
        assert(det == -2.0);
    }

    // Testa a inversão de uma matriz
    {
        mat2 m(1, 2, 3, 4);
        mat2 inv = inverse(m);
        assert(inv.x0() == -2.0);
        assert(inv.y0() == 1.0);
        assert(inv.x1() == 1.5);
        assert(inv.y1() == -0.5);
    }

    // Testa a adição de duas matrizes
    {
        mat2 m1(1, 2, 3, 4);
        mat2 m2(5, 6, 7, 8);
        mat2 m = m1 + m2;
        assert(m.x0() == 6);
        assert(m.y0() == 8);
        assert(m.x1() == 10);
        assert(m.y1() == 12);
    }

    // Testa a subtração de duas matrizes
    {
        mat2 m1(1, 2, 3, 4);
        mat2 m2(5, 6, 7, 8);
        mat2 m = m1 - m2;
        assert(m.x0() == -4);
        assert(m.y0() == -4);
        assert(m.x1() == -4);
        assert(m.y1() == -4);
    }

    // Testa a multiplicação de duas matrizes
    {
        mat2 m1(1, 2, 3, 4);
        mat2 m2(5, 6, 7, 8);
        mat2 m = m1 * m2;
        assert(m.x0() == 19);
        assert(m.y0() == 22);
        assert(m.x1() == 43);
        assert(m.y1() == 50);
    }

    // Testa a divisão de duas matrizes
    {
        mat2 m1(1, 2, 3, 4);
        mat2 m2(5, 6, 7, 8);
        mat2 m = m1 / m2;
        mat2 expected = m1 * inverse(m2);
        assert(m.x0() == expected.x0());
        assert(m.y0() == expected.y0());
        assert(m.x1() == expected.x1());
        assert(m.y1() == expected.y1());
    }

    std::cout << "SUCESSO: Todos os testes unitários mat2 passaram.\n";
}

void test_unitary_mat3(){
    //MAT3
    std::cout << "TESTES: Iniciando os testes unitários mat3.\n";

    // Teste do construtor padrão
    {
        mat3 m;   // Construtor padrão
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                assert(m.e[i][j] == 0);
            }
        }
    }

    // Teste do construtor parametrizado
    {
        mat3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);   // Construtor parametrizado
        assert(m.x0() == 1);
        assert(m.y0() == 2);
        assert(m.z0() == 3);
        assert(m.x1() == 4);
        assert(m.y1() == 5);
        assert(m.z1() == 6);
        assert(m.x2() == 7);
        assert(m.y2() == 8);
        assert(m.z2() == 9);
    }

    // Teste da transposta
    {
        mat3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);   
        mat3 transposed = transpose(m);

        assert(transposed.x0() == m.x0());
        assert(transposed.y0() == m.x1());
        assert(transposed.z0() == m.x2());
        assert(transposed.x1() == m.y0());
        assert(transposed.y1() == m.y1());
        assert(transposed.z1() == m.y2());
        assert(transposed.x2() == m.z0());
        assert(transposed.y2() == m.z1());
        assert(transposed.z2() == m.z2());
    }

    // Teste do determinante
    {
        mat3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);   
        double det = determinant(m);

        // Calcula o determinante manualmente
        double manualDet = +m.x0() * (m.y1() * m.z2() - m.z1() * m.y2()) - m.y0() * (m.x1() * m.z2() - m.z1() * m.x2()) + m.z0() * (m.x1() * m.y2() - m.y1() * m.x2());

        assert(det == manualDet);
    }

    // Teste da inversa
    {
        mat3 m(1, 2, 3, 4, 5, 6, 7, 8, 10);   
        mat3 inv = inverse(m);

        // Verifica se a matriz original, quando multiplicada pela inversa, resulta na matriz identidade
        mat3 identity = m * inv;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) {
                    assert(std::abs(identity.e[i][j] - 1) < 0.0001);
                } else {
                    assert(std::abs(identity.e[i][j]) < 0.0001);
                }
            }
        }
    }

    std::cout << "SUCESSO: Todos os testes unitários mat3 passaram.\n";
}

int main() {

    test_unitary_vec2();
    test_unitary_vec4();
    test_unitary_mat2();
    test_unitary_mat3();
    

    return 0;
}