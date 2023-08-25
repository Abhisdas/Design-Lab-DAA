#include <stdio.h>

int guessingGame(int target) {
    int low = -1000;  
    int high = 1000;  
    int guess = 0;          
    
    while (1) {
        guess = low + (high - low) / 2;  
        
        if (guess == target) {
            return guess;
        } else if (guess < target) {
            printf("Try a bigger number (%d).\n", guess + 1);  
            low = guess + 1;  
        } else {
            printf("Try a smaller number (%d).\n", guess - 1); 
            high = guess - 1; 
        }
    }
}

int main() {
    int target_number ;
    printf("Enter the number : ");
    scanf("%d",&target_number);
    int result = guessingGame(target_number);
    printf("You got it: %d\n", result);
    return 0;
}
