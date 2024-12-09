#include <stdio.h>

int main(){
    int m, n, wa = -1, lly;

    scanf("%d %d", &m, &n);

    char Wally[m][n];

    for (int i = 0; i < m; i++)
    {
        scanf("%s", Wally[i]);

        if (wa == -1)
        {
            for (int j = 0; j < n; j++)
            {
                if (Wally[i][j] == 'W')
                {
                    wa = i;
                    lly = j;
                    break;
                }
            }
        }
    }
    
    printf("%d %d", wa+1, lly+1);
    return(0);
}