#include <stdio.h>

int main(){


    for (int i = 0; i < 10; i++)
    {
        printf("%d ", Matriz[i]);
    }
    printf("\n");

    for(int step = 0 ; step < 10-1; ++step)
        for(int i = 0; i < 10-step-1; ++i)
        {
            if(Matriz[i] > Matriz[i+1])  
            {
                int aux;

                aux = Matriz[i];
                Matriz[i] = Matriz[i+1];
                Matriz[i+1] = aux;
            }

        }
            
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", Matriz[i]);
    }
    

    return 0;
}