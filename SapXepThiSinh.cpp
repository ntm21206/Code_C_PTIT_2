#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int ma;
    char ten[100];
    char ngay_sinh[15];
    float diem1, diem2, diem3;
    float tong_diem;
    int thu_tu_goc;
} ThiSinh;

int compare(const void *a, const void *b) {
    ThiSinh *x = (ThiSinh*)a;
    ThiSinh *y = (ThiSinh*)b;
    
    if (x->tong_diem > y->tong_diem) return -1;
    if (x->tong_diem < y->tong_diem) return 1;
    
    return x->thu_tu_goc - y->thu_tu_goc;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    ThiSinh ds[n];
    
    for (int i = 0; i < n; i++) {
        ds[i].ma = i + 1;
        ds[i].thu_tu_goc = i;
        
        fgets(ds[i].ten, sizeof(ds[i].ten), stdin);
        ds[i].ten[strcspn(ds[i].ten, "\n")] = '\0';
        
        fgets(ds[i].ngay_sinh, sizeof(ds[i].ngay_sinh), stdin);
        ds[i].ngay_sinh[strcspn(ds[i].ngay_sinh, "\n")] = '\0';
        
        scanf("%f", &ds[i].diem1);
        scanf("%f", &ds[i].diem2);
        scanf("%f", &ds[i].diem3);
        getchar();
        
        ds[i].tong_diem = ds[i].diem1 + ds[i].diem2 + ds[i].diem3;
    }
    
    qsort(ds, n, sizeof(ThiSinh), compare);
    
    for (int i = 0; i < n; i++) {
        printf("%d %s %s %.1f\n", ds[i].ma, ds[i].ten, ds[i].ngay_sinh, ds[i].tong_diem);
    }
    
    return 0;
}
