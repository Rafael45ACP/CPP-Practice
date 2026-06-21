#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cctype>

using namespace std;

int getStart();
int getBet(int x);
int randCard();
string toLow(string txt);
string getHit();

int getTotal(const vector<int>& num);

int main()
{

    srand(time(0));

    int random = rand() % 11 + 1;

    vector<int> userc;
    vector<int> compc;

    int startM = 0;

    int bet = 0;

    startM = getStart();

    while (startM != 0)
    {

        if (bet == 0)
        {
            bet = getBet(startM);
        }

        compc.push_back(randCard());
        cout << "Dealer has " << compc.at(0) << endl;
        userc.push_back(randCard());
        cout << "Player has " << userc.at(0) << endl;
        compc.push_back(randCard());
        cout << "Dealer has ??" << endl;
        userc.push_back(randCard());
        cout << "Player has " << userc.at(1) << endl;


        cout << "\nDealer has " << compc.at(0) << ", ?? "<< endl;
        cout << "Player has " << userc.at(0) << ", " << userc.at(1) << endl;

        int uTotal = 0;
        int pcTotal = 0;

        uTotal = getTotal(userc);
        cout << "\nPlayer has a total of " << uTotal << endl;

        pcTotal = getTotal(compc);

        string choice;

        choice = getHit();

        while(choice == "h" || choice == "hit"){
            
            userc.push_back(randCard());
            cout << "Player gets: " << userc.back() << endl;
            
            uTotal = getTotal(userc);
            cout << "\nPlayer has a total of " << uTotal << endl;
            if(uTotal > 21){
                cout << "Bust! You lose! \n";
                break;
            }

            choice = getHit();
        }

        if(choice == "s" || choice == "stand"){
            if(uTotal > pcTotal){
                cout << "You win!";
                startM + (bet * 2);
            }
            else if(pcTotal > uTotal){
                cout << "You lose!";
                startM - bet;
            }
            else{
                cout << "It's a draw!";
            }
        }

        break;
    }

    return 0;
}

int getStart()
{
    int x;
    do
    {
        cout << "What is your starting money?\n";
        cin >> x;
    } while (x <= 0);
    return x;
}

int getBet(int x)
{
    int y;
    do
    {
        cout << "How much do you want to bet?\n";
        cin >> y;
    } while (y <= 0 || y > x);
    return y;
}

int randCard()
{

    int random = rand() % 10 + 1;

    return random;
}

string getHit(){
    string c;

        cout << "\nHit or Stand?\n";
        cin >> c;

        c = toLow(c);

        return c;

}

string toLow(string txt){
    for(char &c : txt){
        c = tolower(c);
    }

    return txt;
}

int getTotal(const vector<int>& num){
    int sum = 0;
    for( int t : num){
        sum += t; 
    }
    return sum;
}