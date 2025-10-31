#include <stdio.h>
#include <string.h>

typedef struct {
    char ten[100];
    int can;
    int co;
    int tien_hoa;
} Pokemon;

int main() {
    int n;
    scanf("%d", &n);
    
    Pokemon ds[n];
    int tong_tien_hoa = 0;
    int max_tien_hoa = 0;
    int chi_so_max = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", ds[i].ten);
        scanf("%d %d", &ds[i].can, &ds[i].co);
        
        // Tính s? con có th? ti?n hóa
        ds[i].tien_hoa = 0;
        int da_hien_tai = ds[i].co;
        
        while (da_hien_tai >= ds[i].can) {
            ds[i].tien_hoa++;
            da_hien_tai = da_hien_tai - ds[i].can + 2;
        }
        
        tong_tien_hoa += ds[i].tien_hoa;
        
        // Tìm lo?i pokemon ti?n hóa nhi?u nh?t
        if (ds[i].tien_hoa > max_tien_hoa) {
            max_tien_hoa = ds[i].tien_hoa;
            chi_so_max = i;
        }
    }
    
    printf("%d\n", tong_tien_hoa);
    printf("%s\n", ds[chi_so_max].ten);
    
    return 0;
}
