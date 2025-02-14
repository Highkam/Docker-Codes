#include <iostream>
#include <chrono>
#include <fstream>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
}

int main() {
    int n = 400000;  
    auto inicio = std::chrono::high_resolution_clock::now();
    int resultado = fibonacci(n);
    auto Final = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(Final - inicio).count();
    std::cout <<"C++: " << dur << " ms" << std::endl; 
    std::ofstream archivo("resultado_c++.txt");
    if (archivo.is_open()) {
        archivo << resultado;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir el resultado." << std::endl;
    }

    return 0;
}