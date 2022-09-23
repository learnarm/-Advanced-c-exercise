#include <stdio.h>
#include <stdint.h>
#include <time.h>

uint8_t PORT_A = 0x00;

typedef enum{
    GPIO_PIN_0 = 1,
    GPIO_PIN_1 = 1 << 1,
    GPIO_PIN_2 = 1 << 2
}GPIO_PIN;

typedef enum{
    LOW = 0,
    HIGH
}GPIO_PIN_STATUS;


void digitalWrite(GPIO_PIN PIN, GPIO_PIN_STATUS STATE){
    if(STATE){
        PORT_A |= PIN;
    }else{
        PORT_A ^= PIN;
    }
}

//Hàm thay đổi trang thai
void blinkLED(GPIO_PIN PIN){
    PORT_A = PORT_A ^ PIN;
}

// Hàm đổi 10 -> 2
void decToBin(int n){
    if(n <= 1){
        printf("%d", n);
    }else{
        decToBin(n/2);
        printf("%d", n%2);
    }
}

//Hàm delay
void delay(int time){
    clock_t start, end;
    start = clock();
    while (clock() - start <= time);
    end = clock();
    //printf("%f\n", (double)(end - start));
}

int main(int argc, char const *argv[])
{
    digitalWrite(GPIO_PIN_0, HIGH);
    printf("%d\n", PORT_A);
    digitalWrite(GPIO_PIN_2, HIGH);
    printf("%d\n", PORT_A);
    blinkLED(GPIO_PIN_0);
    printf("%d\n", PORT_A);
    blinkLED(GPIO_PIN_0);
    printf("%d\n", PORT_A);
    return 0;
}
