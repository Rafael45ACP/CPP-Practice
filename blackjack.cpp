#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cctype>
#include <thread>
#include <chrono>

using namespace std;

int getStart();
int getBet(int x);
int randCard();
string toLow(string txt);
string getHit();
bool playAgain();

int getTotal(const vector<int>& num);

int main()
{

    srand(time(0));

    int random = rand() % 11 + 1;

    vector<int> userc;
    vector<int> compc;

    int startM = 0;

    int bet = 0;

    char uStatus;
    char pcStatus;

    bool play = true;

    while(play == true)
    {
    this_thread::sleep_for(chrono::milliseconds(600));
    startM = getStart();

    this_thread::sleep_for(chrono::milliseconds(600));
    cout << "\nCurrent Balance: " << startM << endl;

    do
    {
        

        if (bet == 0)
        {
            bet = getBet(startM);
        }

        compc.push_back(randCard());
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\nDealer gets " << compc.at(0) << endl;
        userc.push_back(randCard());

        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\nPlayer gets " << userc.at(0) << endl;
        compc.push_back(randCard());

        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\nDealer gets ??" << endl;
        userc.push_back(randCard());

        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\nPlayer gets " << userc.at(1) << endl;

        this_thread::sleep_for(chrono::milliseconds(600));
        cout << "\nDealer has " << compc.at(0) << ", ?? "<< endl;

        this_thread::sleep_for(chrono::milliseconds(600));
        cout << "Player has " << userc.at(0) << ", " << userc.at(1) << endl;

        int uTotal = 0;
        int pcTotal = 0;

        uTotal = getTotal(userc);
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\nPlayer has a total of " << uTotal << endl;

        pcTotal = getTotal(compc);

        string choice;

        choice = getHit();

        while(choice == "h" || choice == "hit"){
            
            userc.push_back(randCard());
            this_thread::sleep_for(chrono::milliseconds(600));
            cout << "\nPlayer gets " << userc.back() << endl;
            
            uTotal = getTotal(userc);
            this_thread::sleep_for(chrono::milliseconds(600));
            cout << "\nPlayer has a total of " << uTotal << endl;

            if(uTotal > 21){
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "\nBust! You lose! \n";
                uStatus = 'b';
                choice = "s";
                break;
            }
            if (uTotal == 21){
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "\nBlackjack!\n";
                choice = "s";
                break;
                
            }
            choice = getHit();
        }

        if(choice == "s" || choice == "stand"){
        
            this_thread::sleep_for(chrono::milliseconds(400));

            cout << "\nDealer has " << compc.at(0) << ", "<< compc.at(1) << endl;
            this_thread::sleep_for(chrono::milliseconds(400));
            cout << "\nDealer has a total of " << pcTotal<< endl;

           
            while (pcTotal <= 16 && uStatus != 'b'){

                compc.push_back(randCard());
                this_thread::sleep_for(chrono::milliseconds(600));
                cout << "\nDealer gets "<<compc.back() << endl;

                pcTotal = getTotal(compc);

                this_thread::sleep_for(chrono::milliseconds(600));
                cout <<"\nDealer has a total of "<< pcTotal << endl;

                if(pcTotal > 21){
                    this_thread::sleep_for(chrono::milliseconds(800));
                    cout << "\nBust! Player Wins! \n";
                    pcStatus = 'b';
                    break;
                }
                if (pcTotal == 21){
                    this_thread::sleep_for(chrono::milliseconds(800));
                    cout << "\nDealer gets Blackjack!\n";
                    break;
                }
            }
            this_thread::sleep_for(chrono::milliseconds(400));
            if(uStatus == 'b'){
                //cout << "\nYou lose!\n";
                startM -= bet;
            }
            else if (pcStatus == 'b'){
                startM += bet;
            }
            else if(uTotal > pcTotal){
                this_thread::sleep_for(chrono::milliseconds(600));
                cout << "\nYou Win!\n";
                startM += bet;
            }
            else if(pcTotal > uTotal){
                this_thread::sleep_for(chrono::milliseconds(600));
                cout << "\nYou lose!\n";
                startM -= bet;
            }
            else{
                this_thread::sleep_for(chrono::milliseconds(600));
                cout << "\nIt's a draw!\n";
            }
        }
        userc.clear();
        compc.clear();

        bet = 0;

        cout << "\nCurrent Balance: " << startM << endl;

    }while (startM != 0);

    cout << "Game Over! \n"; 
    play = playAgain();
    
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
        cout << "\nHow much do you want to bet?\n";
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
        this_thread::sleep_for(chrono::milliseconds(700));
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

bool playAgain(){
    char choice;

    cout << "\nDo you want to play again? (y/n)\n";
    cin >> choice;

    if(choice == 'y'){
        return true;
    }
    else return false;
}