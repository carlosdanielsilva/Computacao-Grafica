/*!  
    @file vec2.h
    @brief Essa classe realiza diversas operações matemáticas (produto escalar de vetor, comprimento de vetor, operações básicas, etc) com vetor de 2 posições
    @author Carlos Daniel da Silva Pereira
    @version 1.0
*/

#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <cmath>

using std::sqrt;

class vec2
{
public:
    double e[2];

    // Construtor padrão, inicializa um vetor com todos os elementos 0
    vec2() : e{0, 0} {};

    // Construtor parametrizado, inicializa um vetor com os elementos fornecidos
    vec2(double e0, double e1) : e{e0, e1} {};

    double x() const { return e[0]; }
    double y() const { return e[1]; }

    // Retorna o vetor negativo
    vec2 operator-() const { return vec2(-e[0], -e[1]); }
    double operator[](int i) const { return e[i]; }
    double &operator[](int i) { return e[i]; }

    // Operador de soma 
    vec2 &operator+=(const vec2 &v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        return *this;
    }

    // Operador de multiplicação 
    vec2 &operator*=(double t)
    {
        e[0] *= t;
        e[1] *= t;
        return *this;
    }

    // Operador de divisão 
    vec2 &operator/=(double t)
    {
        return *this *= 1 / t;
    }

    // Calcula o comprimento do vetor
    double length() const
    {
        return sqrt(length_squared());
    }

    // Calcula o quadrado do comprimento do vetor
    double length_squared() const
    {
        return e[0] * e[0] + e[1] * e[1];
    }
};

using point2 = vec2;

// Sobrecarrega o operador << para uma fácil saída
inline std::ostream &operator<<(std::ostream &out, const vec2 &v)
{
    return out << v.e[0] << ' ' << v.e[1];
}

// Sobrecarrega o operador + para a adição de vetores
inline vec2 operator+(const vec2 &u, const vec2 &v)
{
    return vec2(u.e[0] + v.e[0], u.e[1] + v.e[1]);
}

// Sobrecarrega o operador - para a subtração de vetores
inline vec2 operator-(const vec2 &u, const vec2 &v)
{
    return vec2(u.e[0] - v.e[0], u.e[1] - v.e[1]);
}

// Sobrecarrega o operador * para a multiplicação de vetores
inline vec2 operator*(const vec2 &u, const vec2 &v)
{
    return vec2(u.e[0] * v.e[0], u.e[1] * v.e[1]);
}

// Sobrecarrega o operador * para a multiplicação de um escalar e um vetor
inline vec2 operator*(double t, const vec2 &v)
{
    return vec2(t * v.e[0], t * v.e[1]);
}

// Sobrecarrega o operador * para a multiplicação de um vetor e um escalar
inline vec2 operator*(const vec2 &v, double t)
{
    return t * v;
}

// Sobrecarrega o operador / para a divisão de um vetor por um escalar
inline vec2 operator/(vec2 v, double t)
{
    return (1 / t) * v;
}

// Calcula o produto escalar de dois vetores
inline double dot(const vec2 &u, const vec2 &v)
{
    return u.e[0] * v.e[0] + u.e[1] * v.e[1];
}

// Calcula o vetor unitário de um vetor
inline vec2 unit_vector(vec2 v)
{
    return v / v.length();
}

#endif