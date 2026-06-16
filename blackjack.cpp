#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getStart();
int getBet(int x);

int main()
{

    srand(time(0));

    int random = rand() % 11 + 1;

    int userc;
    int compc;

    int startM = 0;

    int bet = 0;

    startM = getStart();
    bet = getBet(startM);
    

    userc = random + random;

    cout << userc;



    return 0;
}

int getStart(){
    int x;
    do {
        cout << "What is your starting money?\n";
        cin >> x;
    } while(x <= 0);
    return x;
}

int getBet(int x){
    int y;
    do {
        cout << "How much do you want to bet?\n";
        cin >> y;
    } while(y <= 0 || y > x);
    return y;
}