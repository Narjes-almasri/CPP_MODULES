#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout <<b << std::endl;
    // std::cout<<"------------------------------\n";
    // std::cout << (b >= a) << std::endl;
    std::cout <<Fixed::max(a, b) << std::endl;
    return 0;
}
/*
#include <iostream>
#include "Fixed.hpp"
int main() {
    std::cout << "=== Constructors ===\n\n";
    Fixed a;
    Fixed const b(5);
    Fixed const c(3.5f);
    Fixed const d(b);
    std::cout << "a = " << a << "        | expected: 0\n";
    std::cout << "b = " << b << "        | expected: 5\n";
    std::cout << "c = " << c << "      | expected: 3.5\n";
    std::cout << "d = " << d << "        | expected: 5\n\n";
    std::cout << "=== Assignment ===\n";
    a = c;
    std::cout << "a = " << a << "      | expected: 3.5\n\n";
    std::cout << "=== Comparison Operators ===\n";
    std::cout << "b > c : " << (b > c ? "true " : "false") << "     | expected: true\n";
    std::cout << "b < c : " << (b < c ? "true " : "false") << "     | expected: false\n";
    std::cout << "b >= d : " << (b >= d ? "true " : "false") << "    | expected: true\n";
    std::cout << "b <= d : " << (b <= d ? "true " : "false") << "    | expected: true\n";
    std::cout << "b == d : " << (b == d ? "true " : "false") << "    | expected: true\n";
    std::cout << "b != c : " << (b != c ? "true " : "false") << "    | expected: true\n\n";
    std::cout << "=== Arithmetic Operators ===\n";
    std::cout << "b + c = " << (b + c) << "      | expected: 8.5\n";
    std::cout << "b - c = " << (b - c) << "      | expected: 1.5\n";
    std::cout << "b * c = " << (b * c) << "      | expected: 17.5\n";
    std::cout << "b / c = " << (b / c) << "   | expected: 1.42969\n\n";
    std::cout << "=== Increment / Decrement ===\n";
    Fixed e;
    std::cout << "e = " << e << "        | expected: 0\n";
    std::cout << "++e = " << ++e << " | expected: 0.00390625\n";
    std::cout << "e++ = " << e++ << " | expected: 0.00390625 (post)\n";
    std::cout << "After e++ → e = " << e << " | expected: 0.0078125\n";
    std::cout << "--e = " << --e << " | expected: 0.00390625\n";
    std::cout << "e-- = " << e-- << " | expected: 0.00390625 (post)\n";
    std::cout << "After e-- → e = " << e << " | expected: 0\n\n";
    std::cout << "=== Min / Max ===\n";
    Fixed f(10.1992f);
    Fixed g(42.6992f);
    const Fixed cf(2.19922f);
    const Fixed cg(9.89844f);
    std::cout << "min(f, g) = " << Fixed::min(f, g) << "   | expected: 10.1992\n";
    std::cout << "max(f, g) = " << Fixed::max(f, g) << "   | expected: 42.6992\n";
    std::cout << "const min(cf, cg) = " << Fixed::min(cf, cg) << " | expected: 2.19922\n";
    std::cout << "const max(cf, cg) = " << Fixed::max(cf, cg) << " | expected: 9.89844\n\n";
    std::cout << "=== Conversion ===\n";
    std::cout << "b.toInt() = " << b.toInt() << "        | expected: 5\n";
    std::cout << "c.toFloat() = " << c.toFloat() << "      | expected: 3.5\n\n";
    std::cout << "=== All tests done ===\n";
    return 0;
}*/