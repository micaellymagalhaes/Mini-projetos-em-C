#include <stdio.h> 

int main() {
double num1, num2, resultado; 
char operacao; 

printf("Calculadora Simples em C\n");
printf("Digite o primeiro número: "); 
scanf("%lf", &num1); 
printf("Escolha a operação (+, -, *, /): ");
scanf(" %c", &operacao); 
printf("Digite o segundo número: ");
scanf("%lf", &num2); if (operacao == '+') { 
resultado = num1 + num2; 
} 
else if (operacao == '-')
{ resultado = num1 - num2;
} else if (operacao == '*') { 
resultado = num1 * num2;
} else if (operacao == '/') {
if (num2 != 0) resultado = num1 / num2; 
else { 
printf("Erro: divisão por zero!\n"); return 1; }
} else { 
printf("Operação inválida!\n"); return 1;
} 
printf("Resultado: %.2lf %c %.2lf = %.2lf\n", num1, operacao, num2, resultado); return 0; 
}