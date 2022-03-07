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

int uloha1_6(){ //funkcia vypocita checksum zadaneho intelhex riadku
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

    checksum =(255-(checksum_vypocet%256)+1);// FF - sucet mod 256 + 1
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
void uloha1_2(){ //funkcia vypise zadane cislo rimskymi cislicami
    int cislo;
    printf("Zadajte cislo v rozsahu 1-100:\n");
    scanf("%d", &cislo);
    if(cislo > 100 || cislo <= 0){
        printf("cislo je mimo rozsah 1-100");
    }
    else if(cislo == 100){
        printf("C");
    }
    else{
        if(cislo >= 90){
            cislo = cislo - 90;
            printf("XC");
        }
        if(cislo >= 50){
            cislo = cislo - 50;
            printf("L");
        }
        if(cislo >= 40){
            cislo = cislo - 40;
            printf("XL");
        }

        while(cislo>=10){
            cislo = cislo - 10;
            printf("X");
        }

        if(cislo == 9){
            printf("IX");
            return;
        }
        if(cislo >= 5){
            cislo = cislo - 5;
            printf("V");
        }
        if(cislo == 4){
            printf("IV");
            return;
        }
        while(cislo > 0){
            cislo = cislo -1;
            printf("I");
        }

    }
}

int main() {
    //vypisParne(30);
    //uloha1_1(33777, 'X');

    uloha1_6();


    return 0;
}
