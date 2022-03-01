#include <stdio.h>
#include "moje_funkcie.h"

int uloha1_6(){
    char checksum_nacitany[2];
    int checksum_vypocitany=0, dlzka_dat, dlzka_riadku;
    scanf(":%2x", &dlzka_dat);
    dlzka_riadku = dlzka_dat +4;

    int hex_line[dlzka_riadku];
    hex_line[0] = dlzka_dat;
    for(int i=1;i<=dlzka_riadku;i++){
        scanf("%2x", &hex_line[i]);
    }
    scanf("%2x", &checksum_nacitany);
    printf("---nacitane---");
    for(int i=0;i<=dlzka_riadku;i++){
        checksum_vypocitany = checksum_vypocitany + hex_line[i];
        printf("%x\n", checksum_vypocitany);
    }
}


int main() {
    //vypisParne(30);
    //uloha1_1(33777, 'X');
    uloha1_6();
    return 0;
}
