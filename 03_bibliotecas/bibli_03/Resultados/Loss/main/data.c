#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano) {
    if (dia > 0 && dia < 32 && 
        mes > 0 && mes < 13 &&
        ano >= 0) {
        if (dia <= numeroDiasMes(mes, ano)) return 1;
    } 
    return 0;
}

void imprimeMesExtenso(int mes) {
    switch (mes)
    {
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Março");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
    return;
}

int verificaBissexto(int ano) {
    if(!(ano%100)) {
        if(!(ano%400)) {
            return 1;
        }
        return 0;
    } else if(!(ano%4)) {
        return 1;
    }
    return 0;
}

int numeroDiasMes(int mes, int ano) {
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        return 31;
    } else if(mes == 2) {
        if(verificaBissexto(ano)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 30;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if (ano1 > ano2) return -1;
    if (ano1 < ano2) return 1;
    
    // Se os anos forem iguais, compare os meses
    if (mes1 > mes2) return -1;
    if (mes1 < mes2) return 1;
    
    // Se os meses também forem iguais, compare os dias
    if (dia1 > dia2) return -1;
    if (dia1 < dia2) return 1;
    
    // Se chegamos até aqui, as datas são iguais
    return 0;
}

int calculaDiasAteMes(int mes, int ano) {
    int somaDias = 0, mesAtual = 1;
    while( !(mesAtual == mes) ) { // quando chegar no 1, é pq. chegou no mes
        somaDias += numeroDiasMes(mesAtual, ano);
        mesAtual++;
    }
    return somaDias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    int anoAux = 0, mesAux = 0, diferenca = 0, i = 0, subtracaoDias = 0;
    if (dia1 == dia2 && mes1 == mes2 && ano1 == ano2) return 0;
    
    // organiza o ano do menor pro maior
    if (ano1 > ano2) {
        anoAux = ano2;
        ano2 = ano1;
        ano1 = anoAux;
    }

    // retorna qnts dias no intervalo dos anos
    for (i = ano1; i <  ano2; i++) {
        if (verificaBissexto(i)) diferenca += 366;
        else diferenca += 365;
    }
 
    // organiza o ano do menor pro maior
    if (mes1 > mes2) {
        mesAux = mes2;
        mes2 = mes1;
        mes1 = mesAux;
    }

    // retorna a qtd de dias no intervalo dos meses
    for (i = mes1; i < mes2; i++) {
        diferenca += numeroDiasMes(i, ano2);
    }

    // subtrai a diferenca dos dias para corrigir os dias dos meses
    diferenca += dia2 - dia1;
    return diferenca;
}