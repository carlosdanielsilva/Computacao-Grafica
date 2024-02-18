/*!  
    @file mat2.h
    @brief Essa classe realiza diversas operações matemáticas (transpor, encontrar determinante, operações básicas, etc) com matriz 2x2
    @author Carlos Daniel da Silva Pereira
    @version 1.0
*/

#ifndef MAT2_H
#define MAT2_H

#include <iostream>
#include <cmath>

class mat2
{
public:
    double e[2][2];

    // Construtor padrão, inicializa uma matriz 2x2 com todos os elementos 0
    mat2() : e{0, 0, 0, 0} {};

    // Construtor parametrizado, inicializa uma matriz 2x2 com os elementos
    mat2(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} {};

    double x0() const { return e[0][0]; }
    double y0() const { return e[0][1]; }
    double x1() const { return e[1][0]; }
    double y1() const { return e[1][1]; }
};

//  Matriz transposta
inline mat2 const transpose(const mat2 &m)
{
    return mat2(
        m.e[0][0], m.e[1][0], m.e[0][1], m.e[1][1]);
}

// Determinante de uma matriz
inline double const determinant(const mat2 &m)
{
    return (m.e[0][0] * m.e[1][1] - m.e[1][0] * m.e[0][1]);
}

// Inversa de uma matriz
inline mat2 const inverse(const mat2 &m)
{
    const double invdet = 1 / (m.e[0][0] * m.e[1][1] - m.e[1][0] * m.e[0][1]);
    return mat2(m.e[1][1] * invdet, -m.e[0][1] * invdet, -m.e[1][0] * invdet, m.e[0][0] * invdet);
}

// Sobrecarrega o operador << para uma fácil saída
inline std::ostream &operator<<(std::ostream &out, const mat2 &m)
{
    return out << m.e[0][0] << ' ' << m.e[0][1] << '\n'
               << m.e[1][0] << ' ' << m.e[1][1];
}

// Sobrecarrega o operador + para a adição de matrizes
inline mat2 operator+(const mat2 &m, const mat2 &n)
{
    return mat2(m.e[0][0] + n.e[0][0], m.e[0][1] + n.e[0][1], m.e[1][0] + n.e[1][0], m.e[1][1] + n.e[1][1]);
}

// Sobrecarrega o operador - para a subtração de matrizes
inline mat2 operator-(const mat2 &m, const mat2 &n)
{
    return mat2(m.e[0][0] - n.e[0][0], m.e[0][1] - n.e[0][1], m.e[1][0] - n.e[1][0], m.e[1][1] - n.e[1][1]);
}

// Sobrecarrega o operador * para a multiplicação de matrizes
inline mat2 operator*(const mat2 &m, const mat2 &n)
{
    return mat2(
        m.e[0][0] * n.e[0][0] + m.e[0][1] * n.e[1][0], // novo valor de x0
        m.e[0][0] * n.e[0][1] + m.e[0][1] * n.e[1][1], // novo valor de y0
        m.e[1][0] * n.e[0][0] + m.e[1][1] * n.e[1][0], // novo valor de x1
        m.e[1][0] * n.e[0][1] + m.e[1][1] * n.e[1][1]); // novo valor de y1
}

// Sobrecarrega o operador / para a divisão de matrizes
inline mat2 operator/(const mat2 &m, const mat2 &n)
{
    return mat2(m * inverse(n));
}

#endif