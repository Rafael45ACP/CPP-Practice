#include<iostream>
using namespace std;

int main()
{
   int num;

std::cin >> num ;

if (0 < num && num < 10){
std::cout << "red";
}
 else if (10 < num && num <20){
std::cout << "blue";
}
else if (20 < num && num < 30){
std::cout << "green" ;
}
else 
std::cout << "wrong" ;

    return 0;
}