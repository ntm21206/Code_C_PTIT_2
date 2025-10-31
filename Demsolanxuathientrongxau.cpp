#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[105], b[105];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    int xa[205], xb[205];
    int na = 0, nb = 0;
    
    for (int i = 0; i < n; i++) {
        xa[na++] = a[i];
        xa[na++] = a[i] + 1;
        xb[nb++] = b[i];
        xb[nb++] = b[i] + 1;
    }
    xa[na++] = 1;
    xb[nb++] = 1;
    for (int i = 0; i < na - 1; i++) {
        for (int j = i + 1; j < na; j++) {
            if (xa[i] > xa[j]) {
                int temp = xa[i];
                xa[i] = xa[j];
                xa[j] = temp;
            }
        }
    }
    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (xb[i] > xb[j]) {
                int temp = xb[i];
                xb[i] = xb[j];
                xb[j] = temp;
            }
        }
    }
    
    int new_na = 1, new_nb = 1;
    for (int i = 1; i < na; i++) {
        if (xa[i] != xa[new_na-1]) {
            xa[new_na++] = xa[i];
        }
    }
    for (int i = 1; i < nb; i++) {
        if (xb[i] != xb[new_nb-1]) {
            xb[new_nb++] = xb[i];
        }
    }
    na = new_na;
    nb = new_nb;
    
    int max_val = 0;
    int count = 0;
    
    for (int i = 0; i < na - 1; i++) {
        for (int j = 0; j < nb - 1; j++) {
            int val = 0;
            for (int k = 0; k < n; k++) {
                if (xa[i] <= a[k] && xb[j] <= b[k]) {
                    val++;
                }
            }
            

            int area = (xa[i+1] - xa[i]) * (xb[j+1] - xb[j]);
            
            if (val > max_val) {
                max_val = val;
                count = area;
            } else if (val == max_val) {
                count += area;
            }
        }
    }
    
    printf("%d\n", count);
    return 0;
}
