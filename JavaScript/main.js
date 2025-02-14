const fs = require('fs');

function fibonacci(n) {
    if (n <= 0) {
        return 0;
    } else if (n === 1) {
        return 1;
    } else {
        let a = 0, b = 1;
        for (let i = 2; i <= n; i++) {
            let temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
}


let n = 400000; 
const inicio = new Date();
const resultado = fibonacci(n);
const Final = new Date();
const tiempoTranscurrido = Final - inicio;
console.log("javascript: ",tiempoTranscurrido, "ms")

fs.appendFileSync('resultado_js.txt', isFinite(resultado) ? resultado.toString() : "Infinity");