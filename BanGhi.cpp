#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int a, b, c;
} tamgiac;

void nhapTamGiac(tamgiac *tg) {
    scanf("%d %d %d", &tg->a, &tg->b, &tg->c);
}

double tinhDienTich(tamgiac tg) {
    double p = (tg.a + tg.b + tg.c) / 2.0;
    return sqrt(p * (p - tg.a) * (p - tg.b) * (p - tg.c));
}

void inTamGiac(tamgiac tg) {
    printf("%d %d %d\n", tg.a, tg.b, tg.c);
}

void ghiFile(tamgiac *dsTamGiac, int n) {
    FILE *f = fopen("FPLSP22GxxmsvTG.fpl", "wb");
    if (f != NULL) {
        fwrite(&n, sizeof(int), 1, f);
        fwrite(dsTamGiac, sizeof(tamgiac), n, f);
        fclose(f);
    }
}

void sapXepTheoDienTich(tamgiac *dsTamGiac, int n) {
    int i, j;
    tamgiac temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (tinhDienTich(dsTamGiac[i]) > tinhDienTich(dsTamGiac[j])) {
                temp = dsTamGiac[i];
                dsTamGiac[i] = dsTamGiac[j];
                dsTamGiac[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    
    tamgiac *dsTamGiac = (tamgiac*)malloc(n * sizeof(tamgiac));
    
    for (i = 0; i < n; i++) {
        nhapTamGiac(&dsTamGiac[i]);
    }
    
    sapXepTheoDienTich(dsTamGiac, n);
    ghiFile(dsTamGiac, n);
    
    for (i = 0; i < n; i++) {
        inTamGiac(dsTamGiac[i]);
    }
    
    free(dsTamGiac);
    return 0;
}
