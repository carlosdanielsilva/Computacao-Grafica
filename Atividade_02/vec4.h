/*!  
    @file vec4.h
    @brief Essa classe realiza diversas operações matemáticas (produto escalar de vetor, comprimento de vetor, operações básicas, etc) com vetor de 4 posições
    @author Carlos Daniel da Silva Pereira
    @version 1.0
*/

#ifndef VEC4_H
#define VEC4_H

#include <iostream>
#include <cmath>

using std::sqrt;

class vec4
{
public:
    double e[4];

    // Construtor padrão: inicializa um vetor com todos elementos sendo zero.
    vec4() : e{0, 0, 0, 0} {};

    // Construtor que inicializa um vetor com os valores passados como parâmetro.
    vec4(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} {};

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }
    double w() const { return e[3]; }

    vec4 operator-() const { return vec4(-e[0], -e[1], -e[2], -e[3]); }
    double operator[](int i) const { return e[i]; }
    double &operator[](int i) { return e[i]; }

    // Adiciona um vetor ao atual
    vec4 &operator+=(const vec4 &v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        e[3] += v.e[3];
        return *this;
    }
    // Multiplica o vetor atual por um escalar
    vec4 &operator*=(double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        e[3] *= t;
        return *this;
    }

    // Divide o vetor atual por um escalar
    vec4 &operator/=(double t)
    {
        return *this *= 1 / t;
    }

    // Retorna o comprimento (magnitude) do vetor
    double length() const
    {
        return sqrt(length_squared());
    }

    // Retorna o quadrado do comprimento (magnitude) do vetor
    double length_squared() const
    {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3];
    }
};

using point4 = vec4;

// Sobrecarga do operador de saída para exibição de vetores
inline std::ostream &operator<<(std::ostream &out, const vec4 &v)
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2] << ' ' << v.e[3];
}

// Retorna a soma de dois vetores.
inline vec4 operator+(const vec4 &u, const vec4 &v)
{
    return vec4(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2], u.e[3] + v.e[3]);
}

// Retorna a diferença entre dois vetores.
inline vec4 operator-(const vec4 &u, const vec4 &v)
{
    return vec4(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2], u.e[3] - v.e[3]);
}

// Retorna o produto elemento-a-elemento de dois vetores.
inline vec4 operator*(const vec4 &u, const vec4 &v)
{
    return vec4(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2], u.e[3] * v.e[3]);
}

// Retorna um vetor multiplicado por um escalar.

inline vec4 operator*(double t, const vec4 &v)
{
    return vec4(t * v.e[0], t * v.e[1], t * v.e[2], t * v.e[3]);
}

// Retorna um vetor multiplicado por um escalar.
inline vec4 operator*(const vec4 &v, double t)
{
    return t * v;
}

// Retorna um vetor dividido por um escalar.
inline vec4 operator/(vec4 v, double t)
{
    return (1 / t) * v;
}

// Calcula o produto escalar de dois vetores.
inline double dot(const vec4& u, const vec4& v) 
{
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2] + u.e[3] * v.e[3];
}

// Calcula o vetor unitário de um vetor
inline vec4 unit_vector(vec4 v)
{
    return v / v.length();
}

#endif