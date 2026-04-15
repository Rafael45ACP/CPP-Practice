#include <iostream>

using namespace std;

int moves(int n) {
	
    if (n == 1)
        return 1;
    return 2 * moves(n - 1) + 1;
    
}

int main() {
    int x;
    
    cout << "Number of disks: ";
    
    cin >> x;
    
    cout << "Number of moves: " ;
	cout << moves(x);
	
	return 0;
}

//by: Rafael D. Griego
//BSCS - 2A