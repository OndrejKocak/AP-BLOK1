#include <stdio.h>
#include <string.h>
#include "moje_funkcie.h"

void vypisParne(int cislo){
    //funkcia vypíše všetky párne mensie alebo rovne paramentru cislo
    for(int i=0; i<=cislo; i++){
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

int uloha1_6(){
    char checksum_nacitany[2];
    int checksum_vypocet, dlzka_dat, dlzka_riadku, x, checksum, checksum_nacitany_int;
    scanf("\n:%2x", &dlzka_dat);
    dlzka_riadku = dlzka_dat +3;
    checksum_vypocet = dlzka_dat;

    for(int i=1;i<=dlzka_riadku;i++){
        scanf("%2x", &x);
        checksum_vypocet =checksum_vypocet + x;
    }

    scanf("%2s", &checksum_nacitany);
    checksum =(255-(checksum_vypocet%256)+1);
    printf("Vypocitany checksum: %X\n", checksum);
    if(strcmp(checksum_nacitany, "xx")==0 || strcmp(checksum_nacitany, "XX")==0){
        sscanf(checksum_nacitany,"%x", &checksum_nacitany_int);
        if(checksum == checksum_nacitany_int){
            printf("Nacitany checksum: %X sa zhoduje s vypocitanym checksumom: %X\n",checksum_nacitany_int, checksum);
        } else{
            printf("Nacitany checksum: %X sa nezhoduje s vypocitanym checksumom: %X\n", checksum_nacitany_int, checksum);
        }
    }
    return checksum;
}


int main() {
    //vypisParne(30);
    //uloha1_1(33777, 'X');

    uloha1_6();


    return 0;
}
