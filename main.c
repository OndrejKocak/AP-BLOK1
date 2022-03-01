#include <stdio.h>
#include "moje_funkcie.h"

int uloha1_6(){
    char checksum_nacitany[2];
    int checksum_vypocitany=0, dlzka_dat, dlzka_riadku, x=0;
    scanf(":%2x", &dlzka_dat);
    dlzka_riadku = dlzka_dat +4;
    checksum_vypocitany = dlzka_dat;

    for(int i=1;i<dlzka_riadku;i++){
        scanf("%2x", &x);
        checksum_vypocitany =checksum_vypocitany + x;
    }
    scanf("%2x", &checksum_nacitany);
    printf("---nacitane---\n");

    printf("%x\n", checksum_vypocitany);
    printf("%X", 255-(checksum_vypocitany%256)+1);
}


int main() {
    //vypisParne(30);
    //uloha1_1(33777, 'X');
    uloha1_6();
    return 0;
}
