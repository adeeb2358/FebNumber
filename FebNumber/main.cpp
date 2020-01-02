//
//  main.cpp
//  FebNumber
//
//  Created by adeeb mohammed on 02/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <unordered_map>

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

// febenocci numbers using recursion
// the time o(n2) and space complexity o(n)
int getNthFibRecur(int n){
    int sumOfBoth = 0;
    if(1 == n || n < 1){
        return 0;
    }
    if(2 == n){
        return 1;
    }
    sumOfBoth  = getNthFibRecur(n-1) + getNthFibRecur(n-2);
    return sumOfBoth;
}

// febenocci numbers using dynamic programming
// it simply means repeated steps can be stored in some
// hash table and access this in constant time

int findFib(int n, std::unordered_map<int, int> memoize){
    if(memoize.find(n) != memoize.end()){
        return memoize[n];
    }else{
        memoize[n] = findFib(n-1,memoize) + findFib(n-2,memoize);
        return memoize[n];
    }
}

int getNthFibDyn(int n){
    int resultNumber = 0;
    std::unordered_map<int, int> memoize;
    memoize[1] = 0;
    memoize[2] = 1;
    resultNumber = findFib(n,memoize);
    memoize.clear();
    return resultNumber;
}

int main(int argc, const char * argv[]) {
    // optismal solution output
    std::cout << "getNthFib(1)= " << getNthFib(1)<< std::endl;
    std::cout << "getNthFib(2)= " << getNthFib(2)<< std::endl;
    std::cout << "getNthFib(3)= " << getNthFib(3)<< std::endl;
    std::cout << "getNthFib(4)= " << getNthFib(4)<< std::endl;
    std::cout << "getNthFib(5)= " << getNthFib(5)<< std::endl;
    std::cout << "getNthFib(6)= " << getNthFib(6)<< std::endl;
    // recursion very slow soluton output
    std::cout << "getNthFibRecur(1)= " << getNthFibRecur(1)<< std::endl;
    std::cout << "getNthFibRecur(2)= " << getNthFibRecur(2)<< std::endl;
    std::cout << "getNthFibRecur(3)= " << getNthFibRecur(3)<< std::endl;
    std::cout << "getNthFibRecur(4)= " << getNthFibRecur(4)<< std::endl;
    std::cout << "getNthFibRecur(5)= " << getNthFibRecur(5)<< std::endl;
    std::cout << "getNthFibRecur(6)= " << getNthFibRecur(6)<< std::endl;
    
    
    return 0;
}
