#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>
#include <vector>


using namespace std;

template <int Degree>
class Polynomial {
private:
    std::vector<double> coefficients; // Wsp�czynniki wielomianu

public:
    Polynomial(const std::vector<double>& arr) : coefficients(arr) {};

    // Dodajemy publiczn� funkcj� do pobierania wsp�czynnik�w
    const std::vector<double>& getCoefficients() const {
        return coefficients;
    }
};

template <int Degree>
void printPolynomial(const Polynomial<Degree>& poly) {
    std::cout << "Wielomian jest postaci: ";
    int i = Degree;
    for (const auto& elem : poly.getCoefficients()) { // U�ywamy nowej funkcji
        if (i != 0) {
            std::cout << elem << "x^" << i << " + ";
            i--;
        }
        else std::cout << elem;
    }
    std::cout << std::endl;
}

#endif
