#include <stdio.h>
#include <string.h>

void cong_chuoi(char* so1, char* so2, char* ketqua) {
    int dai1 = strlen(so1);
    int dai2 = strlen(so2);
    int dai_max = dai1 > dai2 ? dai1 : dai2;
    int nho = 0;
    int vitri = 0;
    
    for (int i = 0; i < dai_max || nho > 0; i++) {
        int chu_so1 = (i < dai1) ? so1[dai1 - 1 - i] - '0' : 0;
        int chu_so2 = (i < dai2) ? so2[dai2 - 1 - i] - '0' : 0;
        int tong = chu_so1 + chu_so2 + nho;
        ketqua[vitri++] = (tong % 10) + '0';
        nho = tong / 10;
    }
    
    ketqua[vitri] = '\0';
    
    for (int i = 0; i < vitri / 2; i++) {
        char tam = ketqua[i];
        ketqua[i] = ketqua[vitri - 1 - i];
        ketqua[vitri - 1 - i] = tam;
    }
}

int main() {
    char so[201];
    char nua_dau[201];
    char nua_sau[201];
    char ketqua[202];
    
    scanf("%s", so);
    
    while (strlen(so) > 1) {
        int dai = strlen(so);
        int vi_tri_chia = dai / 2;
        
        strncpy(nua_dau, so, vi_tri_chia);
        nua_dau[vi_tri_chia] = '\0';
        
        strcpy(nua_sau, so + vi_tri_chia);
        
        cong_chuoi(nua_dau, nua_sau, ketqua);
        strcpy(so, ketqua);
        printf("%s\n", so);
    }
    
    return 0;
}
