// TareaPlantillasLiss.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cmath>
#include <iostream>

template<typename T>
class Vector3 {
public:
    T x, y, z;

    Vector3(T x = 0, T y = 0, T z = 0)
        : x(x), y(y), z(z) {}

    Vector3<T> operator+(const Vector3<T>& other) const {
        return Vector3<T>(x + other.x, y + other.y, z + other.z);
    }

    T operator*(const Vector3<T>& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3<T> operator^(const Vector3<T>& other) const {
        return Vector3<T>(y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x);
    }

    T sqrMagnitude() const {
        return x * x + y * y + z * z;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << "(" << x << "," << y << "," << z << ")";
        return ss.str();
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector3<T>& v) {
    os << v.toString();
    return os;
}

int main() {
    Vector3<double> v1(1, 2, 3);
    Vector3<double> v2(4, 5, 6);

    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;

    Vector3<double> v3 = v1 + v2;
    std::cout << "v3 = v1 + v2 = " << v3 << std::endl;

    double dot = v1 * v2;
    std::cout << "Dot product of v1 and v2: " << dot << std::endl;

    Vector3<double> cross = v1 ^ v2;
    std::cout << "Cross product of v1 and v2: " << cross << std::endl;

    double sqrMag = v1.sqrMagnitude();
    std::cout << "SqrMagnitude of v1: " << sqrMag << std::endl;

    return 0;
}


