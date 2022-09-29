#include <iostream>
#include "LinkedList.h"


int main() {
     LinkedList<int> miLlista;
    Integer number1("123451234567");
    Integer number2("1111222333351233433434343434343434344567");
    Integer number3("999988877766");


     miLlista.add(number1);
     miLlista.add(number2);
     miLlista.add(number3);
     miLlista.displayAll();

    return 0;
}
