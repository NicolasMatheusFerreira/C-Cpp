#include "EmpresaFuncoes.h"

float MaiorSalario(Pessoa func[]) {

	int cont = 0;
	float maior = 0;
	while(cont<QtdRegistros) {
		if (func[cont].empresa.salario>maior) {
			maior = func[cont].empresa.salario;
		} else maior = maior;
		cont++;
	}
	return maior;
}

float MenorSalario(Pessoa func[]) {
	
	int cont = 0;
	float menor = 100000000000;
	while(cont<QtdRegistros) {
		if (func[cont].empresa.salario<menor) {
			menor = func[cont].empresa.salario;
		} else menor = menor;
		cont++;
	}
	return menor;
}

float MediaSalarial(Pessoa func[]) {

	float media, salario_total;

	salario_total = GastoSalarioTotal(func);
	media = salario_total/QtdRegistros;
	return media;
}

float GastoSalarioTotal(Pessoa func[]) {

	int cont = 0;
	float soma = 0;
	while(cont<QtdRegistros) {
		soma+=func[cont].empresa.salario;
		cont++;
	}
}

float PercentualReal(Pessoa func[], int codig, float percent) {

	float resto = (func[codig].empresa.salario*percent)/100;
	return resto;
}
