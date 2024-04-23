#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

template <int Degree>
class Polynomial {
private:
    std::vector<double> coefficients; // Wspó³czynniki wielomianu

public:
    Polynomial(const std::vector<double>& arr) : coefficients(arr) {};

    // Dodajemy publiczn¹ funkcjê do pobierania wspó³czynników
    const std::vector<double>& getCoefficients() const {
        return coefficients;
    }
  

    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= Degree; ++i) {
            result += coefficients[i] * pow(x, Degree-i);  
            //Musze takie zrobiæ ¿eby obliczenie dzia³a³o dobrze a nie od koñca
        }
        return result;
    }

};


template <int Degree>
void printPolynomial(const Polynomial<Degree>& poly) {
    std::cout << "Wielomian jest postaci: ";
    int i = Degree;
    for (const auto& elem : poly.getCoefficients()) { // U¿ywamy nowej funkcji
        
        if (i != 0) {
            if (elem !=0)
                std::cout << elem << "x^" << i << " + ";
            i--;
        }
        else
        {
            if (elem!=0)
            std::cout << elem;
        }
    }
    std::cout << std::endl;
}



template <int Degree1, int Degree2>
auto operator+(const Polynomial<Degree1>& p1, const Polynomial<Degree2>& p2) {
    constexpr int maxDegree = Degree1 > Degree2 ? Degree1 : Degree2;
    std::vector<double> coefficients(maxDegree + 1, 0.0);

    const auto& coeffs1 = p1.getCoefficients();
    const auto& coeffs2 = p2.getCoefficients();

    for (int i = 0; i <= Degree1; ++i) {
        coefficients[coefficients.size()-coeffs1.size()+i] += coeffs1[i];
    }

    for (int i = 0; i <= Degree2; ++i) {
        coefficients[coefficients.size() - coeffs2.size() + i] += coeffs2[i];
    }

    return Polynomial<maxDegree>(coefficients);
}


template <int Degree1, int Degree2>
auto operator-(const Polynomial<Degree1>& p1, const Polynomial<Degree2>& p2) {
    constexpr int maxDegree = Degree1 > Degree2 ? Degree1 : Degree2;
    std::vector<double> coefficients(maxDegree + 1, 0.0);

    const auto& coeffs1 = p1.getCoefficients();
    const auto& coeffs2 = p2.getCoefficients();

    for (int i = 0; i <= Degree1; ++i) {
        coefficients[coefficients.size() - coeffs1.size() + i] += coeffs1[i];
    }

    for (int i = 0; i <= Degree2; ++i) {
        coefficients[coefficients.size() - coeffs2.size() + i] -= coeffs2[i];
    }

    return Polynomial<maxDegree>(coefficients);
}


template <int Degree>
Polynomial<Degree> operator*(const Polynomial<Degree>& p, double scalar) {
    std::vector<double> coefficients = p.getCoefficients();

    for (int i = 0; i <= Degree; ++i) {
        coefficients[i] *= scalar;
    }

    return Polynomial<Degree>(coefficients);
}

#endif
