#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long int num;
int base;
int n;
long int power = 1;
int first = 1;

 int main (void) {
     printf("\n Enter NUM BASE: ");
     n = scanf("%ld %d", &num, &base); //ld - для long элементов
     if (n<2) {
         printf("\n Must be 2 arg\n");
         return 1;
     }
     else if (base == 1) {
         printf("\n Base must be >= 2\n");
         return 1;
     }

     find_power:
      if (power <= num / base) {
          power = power * base; //идея с возведением основания в н-ую степень, пока не выполняется условие выше
          goto find_power;
      }

     convert:
     if (first != 1) {
         printf(","); //ставлю запятую перед каждой цифрой, КРОМЕ ПОСЛЕДНЕЙ
     }
     first = 0;
     printf("%d", num / power);
     num = num % power;
     power = power / base;


     if (power != 0) {
         goto convert; //колхозный закос на цикл
     }
     else {
         return 1;
     }
 }