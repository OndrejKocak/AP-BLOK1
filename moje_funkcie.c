#include <stdio.h>
#include "moje_funkcie.h"

void vypisParne(int cislo){
    //funkcia vypíše všetky párne mensie alebo rovne paramentru cislo
    for(int i; i<=cislo; i++){
        if(i%2 == 0){
            printf("%d\n", i);
        }
    }
}

void vypis_binarne(int cislo){
    // funkcia vypise cislo v dvojkovej sustave
    if(cislo == 0){
        return;
    }
    else{
        vypis_binarne(cislo/2);
        if(cislo % 2 == 1){
            printf("1");
        }
        else if(cislo % 2 == 0){
            printf("0");
        }
    }
}
void uloha1_1(int cislo, char znak){
    /*Funkcia vypise parametre(cislo a znak(jeho ASCII kod)) v desiatkovej, dvojkovej a sestnaskovej sustave*/
    printf("Cislo %d v desiatkovej sustave: %d\n",cislo, cislo);
    printf("Cislo %d v dvojkovej sustave: ", cislo);
    vypis_binarne(cislo);
    printf("\nCislo %d v sestnastkovej sustave: %X\n", cislo, cislo);
    printf("ASCII kod znaku %c v desiatkovej sustave: %d\n", znak, znak);
    printf("ASCII kod znaku %c v dvojkovej sustave: ", znak);
    vypis_binarne((int)(znak));
    printf("\nASCII kod znaku %c v sestnastkovej sustave: %X\n", znak, znak);

}

void uloha1_3(){
    // funkcia vypise vsetky fibonacciho cisla mensie alebo rovne ako vstup k
    int n=1, n_1=0, x, k;
    printf("zadajte cislo:");
    scanf("%d", &k);
    while(n<=k){
        printf("%d\n", n);
        x = n;
        n = n_1 + n;
        n_1 = x;
    }
}