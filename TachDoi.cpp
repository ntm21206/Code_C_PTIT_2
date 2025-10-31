#include <stdio.h>
#include <string.h>

long long ucln(long long a, long long b) 
{
    if (b == 0) return a;
    return ucln(b, a % b);
}

long long bcnn(long long a, long long b) 
{
    return (a * b) / ucln(a, b);
}

long long chuyenChuoiThanhSo(char chuoi[], int batDau, int ketThuc) 
{
    long long ketQua = 0;
    for (int i = batDau; i <= ketThuc; i++) 
	{
        ketQua = ketQua * 10 + (chuoi[i] - '0');
    }
    return ketQua;
}

int main() 
{
    int soBoTest;
    scanf("%d", &soBoTest);
    
    while (soBoTest--) 
	{
        char N[20];
        scanf("%s", N);
        
        int doDai = strlen(N);
        
        if (doDai % 2 == 1) {
            printf("INVALID\n");
        } 
		else 
		{
            int giua = doDai / 2;
            
            long long nuaTrai = chuyenChuoiThanhSo(N, 0, giua - 1);
            long long nuaPhai = chuyenChuoiThanhSo(N, giua, doDai - 1);
            
            long long ketQua = bcnn(nuaTrai, nuaPhai);
            printf("%lld\n", ketQua);
        }
    }
    
    return 0;
}
