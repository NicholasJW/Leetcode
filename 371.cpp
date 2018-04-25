#include "LeetCode.h"


int getSum(int a, int b){
    while (b != 0) {
		int carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}
    return a;
}

int main(){
    // Bit manipulation testing
    int x=3;
    int minusx = ~x+1;
    cout << x << endl;
    cout << minusx << endl;
}