package main
import (
	"fmt"
	"os"
	"time"
)

// Función para calcular el n-ésimo número de Fibonacci de manera eficiente
func fibonacci(n int) int64 {
	if n <= 1 {
		return int64(n)
	}

	a, b := int64(0), int64(1)
	for i := 2; i <= n; i++ {
		a, b = b, a+b
	}
	return b
}

func main() {

	start := time.Now()


	n := 400000
	result := fibonacci(n)

	
	elapsed := time.Since(start).Milliseconds()
    fmt.Println("Go:", elapsed, "ms")

	file, err := os.OpenFile("resultado_go.txt", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		fmt.Println("Error al abrir el archivo:", err)
		return
	}
	defer file.Close()

	_, err = file.WriteString(fmt.Sprintf("%d",result))
	if err != nil {
		fmt.Println("Error al escribir en el archivo:", err)
		return
	}
}