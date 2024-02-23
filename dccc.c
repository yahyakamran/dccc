#include <stdio.h>
void get_array(long cc_number ,long * cc_array , int len){
    while (len > 0) {
        int last_digit = cc_number % 10;
        cc_number /= 10;
        --len;
        cc_array[len] = last_digit;
    }
}
int get_length(long number){
    int i = 0;
    while (number > 0) {
        number /= 10;
        ++i;
    }
    return i;
}

int get_sum_two (long * cc_array , int len){
    int sum = 0;
    for(int i = len - 1 ; i >= 0 ; i-=2){
        int temp = cc_array[i];
        sum += temp;
    }
    return sum;
}

int get_sum_one(long * cc_array , int len){
    int sum = 0;
    for(int i = len - 2 ; i >= 0 ; i-=2){
        long temp = cc_array[i] * 2;
        if(temp > 9){
            sum += (temp % 10) + 1;
        }else sum += temp;
    }
    return sum;
}
int main(void){
    long cc_number;
    printf("Enter your Credit Card Number : ");
    scanf("%ld",&cc_number);
    int len = get_length(cc_number);
    long cc_array[len];
    get_array(cc_number,cc_array,len);
    int sum_one = get_sum_one(cc_array , len);
    int sum_two = get_sum_two(cc_array, len);
    int sum = sum_one + sum_two;
    if(sum % 10 == 0){
        printf("IT IS A VALID CARD\n");
    }else {
        printf("CARD IS NOT VALID\n");
    }
    if(cc_array[0] == 5 && (cc_array[1] > 0 && cc_array[1] < 6)){
        printf("This is a Master card\n");
    }else if (cc_array[0] == 3 && (cc_array[1] == 4 || cc_array[1] ==7)) {
        printf("This is an AMEX card\n");
    }else if (cc_array[0] == 4) {
        printf("This is a Visa card\n");
    }else {
        printf("This is an INVALID card\n");
    }
}
