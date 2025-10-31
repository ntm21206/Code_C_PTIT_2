#include <stdio.h>
#include <string.h>

int main() 
{
    int t;
    scanf("%d", &t);
    
    while (t--) 
	{
        char a[35], b[35], a2[35], b2[35];
        scanf("%s %s", a, b);
        
        strcpy(a2, a);
        strcpy(b2, b);
        
        int la = strlen(a), lb = strlen(b);
        
        
        char tong[35];
        int nho = 0, k = 0;
        int i = la - 1, j = lb - 1;
        
        while (i >= 0 || j >= 0 || nho) 
		{
            int s = nho;
            if (i >= 0) s += a[i--] - '0';
            if (j >= 0) s += b[j--] - '0';
            tong[k++] = s % 10 + '0';
            nho = s / 10;
        }
        tong[k] = 0;
        
        
        for (int x = 0; x < k/2; x++) 
		{
            char tmp = tong[x]; tong[x] = tong[k-1-x]; tong[k-1-x] = tmp;
        }
        
        
        char hieu[35];
        int la2 = strlen(a2), lb2 = strlen(b2);
        
        if (la2 < lb2 || (la2 == lb2 && strcmp(a2, b2) < 0)) 
		{
            strcpy(hieu, a2);
            strcpy(a2, b2);
            strcpy(b2, hieu);
            la2 = strlen(a2);
            lb2 = strlen(b2);
        }
        
        int muon = 0;
        k = 0;
        i = la2 - 1; j = lb2 - 1;
        
        while (i >= 0) 
		{
            int s = a2[i--] - '0' - muon;
            if (j >= 0) s -= b2[j--] - '0';
            if (s < 0) { s += 10; muon = 1; } else muon = 0;
            hieu[k++] = s + '0';
        }
        
        while (k > 1 && hieu[k-1] == '0') k--;
        hieu[k] = 0;
        

        for (int x = 0; x < k/2; x++) 
		{
            char tmp = hieu[x]; hieu[x] = hieu[k-1-x]; hieu[k-1-x] = tmp;
        }
        
        printf("%s %s\n", tong, hieu);
    }
    
    return 0;
}
