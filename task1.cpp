#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    srand(time(0));
    int target=rand()%100+1;
    int guess;
    int tries=0;
    cout<<"Guess any number between 1 and 100"<< endl;
    while(true) 
    {
        cout<<"Enter the number you guessed:";
        cin>>guess;
        tries++;
        if (guess>target) 
        {
             cout<<"Your Guess is too high,try again"<<endl;
        }
        else if (guess < target) 
        {
            cout<<"Your guess is too low,try again"<<endl;
        }
        else 
        {
            cout<<"Nice work! You got it"<<target<<endl;
            cout <<"It took"<<tries<<"tries for you"<<endl;
            break;
        }
    }
    return 0;
}