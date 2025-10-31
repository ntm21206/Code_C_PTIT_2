#include <stdio.h>
#include <stdlib.h>

int soSanh(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

int soSanhGiam(const void *a, const void *b) 
{
    return (*(int*)b - *(int*)a);
}

int main() 
{
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int M, N;
        char kyTu;
        scanf("%d %d %c", &M, &N, &kyTu);
        
        int dayA[1000], dayB[1000];
        int ketQua[2000];
        
        for (int i = 0; i < M; i++) {
            scanf("%d", &dayA[i]);
        }
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &dayB[i]);
        }
        
        int chiSo = 0;
        
        if (kyTu == 'F') {
            for (int i = 0; i < M; i++) {
                ketQua[chiSo++] = dayA[i];
            }
            for (int i = 0; i < N; i++) {
                ketQua[chiSo++] = dayB[i];
            }
        }
        else if (kyTu == 'A') {
            for (int i = 0; i < N; i++) {
                ketQua[chiSo++] = dayB[i];
            }
            for (int i = 0; i < M; i++) {
                ketQua[chiSo++] = dayA[i];
            }
        }
        else if (kyTu == 'T') {
            for (int i = 0; i < M; i++) {
                ketQua[chiSo++] = dayA[i];
            }
            for (int i = 0; i < N; i++) {
                ketQua[chiSo++] = dayB[i];
            }
            qsort(ketQua, M + N, sizeof(int), soSanh);
        }
        else if (kyTu == 'G') {
            for (int i = 0; i < M; i++) {
                ketQua[chiSo++] = dayA[i];
            }
            for (int i = 0; i < N; i++) {
                ketQua[chiSo++] = dayB[i];
            }
            qsort(ketQua, M + N, sizeof(int), soSanhGiam);
        }
        
        for (int i = 0; i < M + N; i++) {
            if (i > 0) printf(" ");
            printf("%d", ketQua[i]);
        }
        printf("\n");
    }
    
    return 0;
}
