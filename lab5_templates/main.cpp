#include <iostream>
#include "Polynomial.hpp"

int main() {




    
    // Utw�rz kilka wielomian�w i przetestuj operacje na nich
    Polynomial<3> poly1({ 1, 2, 3, 4 });
    printPolynomial(poly1);// x^3 + 2x^2 + 3x + 4
    Polynomial<2> poly2({ -1, 0, 1}); // -x^2 + 1
    printPolynomial(poly2);
    
    // Dodaj dwa wielomiany
    auto sum = poly1 + poly2;
    std::cout << "Suma wielomianow: ";
    printPolynomial(sum);
   
    
    
    // Odejmij jeden wielomian od drugiego
    auto diff = poly1 - poly2;
    std::cout << "Roznica wielomianow: ";
    printPolynomial(diff);

    // Pomn� wielomian przez sta��
    auto scaled = poly1 * 2;
    std::cout << "Wielomian pomno�ony przez 2: ";
    printPolynomial(scaled);
    
    // Oblicz warto�� wielomianu dla x = 2
    double x = 2;
    std::cout << "Wartosc wielomianu poly1 dla x = " << x << ": " << poly1.evaluate(x)<< std::endl;
    

    return 0;
}
