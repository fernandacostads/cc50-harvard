#include <stdio.h>

int main() {
    int start_size, end_size;
    
    printf("Start size: ");
    scanf("%d", &start_size);

    printf("End size: ");
    scanf("%d", &end_size);

    int years = 0;
    
    while (start_size < end_size) {
        int born = start_size / 3;
        int died = start_size / 4;
        
        start_size += (born - died);
        years++;
    }
    
    printf("Years: %d\n", years);

    return 0;
}
