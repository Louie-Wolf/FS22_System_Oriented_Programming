#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 8

int main(){
    double conversionRate;
    double currency_chf = 200;
    
    printf("Enter conversion rate (1.00 BTC -> CHF):");
    scanf("%lf", &conversionRate);
    
    
    for(int i = 0; i < NUM_ROWS; i++){
        printf("%6.0lf CHF\t<-->\t%9.5lf BTC\n", currency_chf, (currency_chf / conversionRate));
        currency_chf += 200;
    }
    
    return EXIT_SUCCESS;
}
