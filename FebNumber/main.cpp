//
//  main.cpp
//  FebNumber
//
//  Created by adeeb mohammed on 02/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>

/*
    program to find the nth febonocci number
    sample input 6
    output 5 [0 1 1 2 3 5]
 */

int getNthFib(int n) {
    
    if(1 == n ){
        return 0;
    }
    
    if(2 == n || 3 == n ){
        return 1;
    }
    
    int prevNumOne = 1;
    int prevNumTwo = 1;
    int sumOfBoth  = 0;
    for(int i = 3; i < n; i++){
        sumOfBoth  = prevNumTwo + prevNumOne;
        prevNumOne = prevNumTwo;
        prevNumTwo = sumOfBoth;
    }
    return sumOfBoth;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "getNthFib(1)= " << getNthFib(1)<< std::endl;
    std::cout << "getNthFib(2)= " << getNthFib(2)<< std::endl;
    std::cout << "getNthFib(3)= " << getNthFib(3)<< std::endl;
    std::cout << "getNthFib(4)= " << getNthFib(4)<< std::endl;
    std::cout << "getNthFib(5)= " << getNthFib(5)<< std::endl;
    std::cout << "getNthFib(6)= " << getNthFib(6)<< std::endl;
    return 0;
}
