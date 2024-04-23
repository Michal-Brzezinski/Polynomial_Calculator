#include "Polynomial.hpp"





template<int Degree>
Polynomial<Degree>::Polynomial(const std::vector<double>& arr) : coefficients(arr) {
    std::cout << "Wielomian jest postaci: ";
    int i = Degree;
    for (const auto& elem : arr) {

        if (i != 0) {
            std::cout << elem << "x^" << i << " + ";
            i--;
        }
        else std::cout << elem;
    }
    std::cout << std::endl;

}

/*
template<int Degree>
Polynomial<Degree> Polynomial<Degree>:: operator+(const Polynomial& other) const {
    Polynomial result({ 0 }); // Tworzymy wynikowy wielomian z zerowymi wspó³czynnikami
    for (int i = 0; i <= Degree; ++i) {
        result.coefficients[i] = coefficients[i] + other.coefficients[i];
    }
    return result;
}

// Metoda odejmowania wielomianów
template<int Degree>
Polynomial<Degree> Polynomial<Degree>::operator-(const Polynomial& other) const {
    Polynomial result({ 0 });
    for (int i = 0; i <= Degree; ++i) {
        result.coefficients[i] = coefficients[i] - other.coefficients[i];
    }
    return result;
}

// Metoda mno¿enia wielomianu przez sta³¹
template<int Degree>
Polynomial<Degree> Polynomial<Degree>:: operator*(double scalar) const {
    Polynomial result({ 0 });
    for (int i = 0; i <= Degree; ++i) {
        result.coefficients[i] = coefficients[i] * scalar;
    }
    return result;
}

template<int Degree>
double Polynomial<Degree>::calculate(double x) const {
    double result = 0;
    double x_power = 1;
    for (int i = 0; i <= Degree; ++i) {
        result += coefficients[i] * x_power;
        x_power *= x;
    }
    return result;
}*/