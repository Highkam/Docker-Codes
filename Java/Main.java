import java.io.FileWriter;
import java.io.IOException;

class Main {
    public static int fibonacci(int n) {
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

    public static void main(String[] args) {
        int n = 400000; 
        long inicio = System.currentTimeMillis();
        int resultado = fibonacci(n);
        long Final = System.currentTimeMillis();
        long tiempoTranscurrido = Final - inicio;
        System.out.println("Java: "+ tiempoTranscurrido + "ms");

        try (FileWriter writer = new FileWriter("resultado_java.txt", true)) {
            writer.write(resultado);
        } catch (IOException e) {
            System.err.println("Error al escribir en el archivo: " + e.getMessage());
        }
    }
}