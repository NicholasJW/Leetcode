#include "LeetCode.h"

struct person{
    int age;
    person* lover;
    person(int x) : age(x), lover(NULL) {}
};

void testPointer(){
    person* a = new person(0);
    a->age = 10;
    person* b = a;
    cout << a->age << endl;
    delete a;
}

int main(int argc, char* argv[]){
    testPointer();
    // cout << "hello" << endl;

    return 0;
}