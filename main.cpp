#include <iostream>
#include <list>
using namespace std;

list <string> li;
char table[9] = {'1','2','3','4','5','6','7','8','9'};

void line_table()
{
    cout<<endl;
    for(int i=0; i<=8; i++)
    {
        cout<<"| "<<table[i]<< " | ";

        if(i == 2 )
        {
            cout<<"\n-----------------\n";
        }
        else if(i == 5)
        {
            cout<<"\n-----------------\n";
        }
    }
}

void put_num(int step)
{
    int num;

    while(true)
    {
        auto it = li.begin();
        advance(it, step);
        cout<<"\n___________________________________";
        cout<<"\n\nNow it's your turn " << *it <<" !";

        loop: cout<<"\nPut the desired house number : ";
        cin>>num;

        if(table[num-1] == 'x' || table[num-1] == 'o')
        {
            cout<<"This house is full !!!!!\n\n";
            line_table();
            cout<<endl;
            goto loop;
        }

        if(step % 2 == 0)
        {
            //palyer1
            int x=120;
            table[num-1]=(char)x;
            break;
        }
        else if(step % 2 != 0)
        {
            //player2
            int o=111;
            table[num-1]=(char)o;
            break;
        }
    }
}

int winner_loser()
{
    int j, c;
    int step = 0;
    bool is_end=false;
    while(true)
    {
        put_num(step);
        for(int i=0; i<=8; i+=3)
        {
            if(table[i] == 'x' && table[i+1] == 'x' && table[i+2] == 'x'
               || table[i] == 'o' && table[i+1] == 'o' && table[i+2] == 'o')
            {
                if(table[i] == 'x')
                {
                    auto it = li.begin();
                    advance(it, 0);
                    cout<<"\n\n* " <<*it <<" is winner *";
                    return 0;
                }
                else if(table[i] == 'o')
                {
                    auto it = li.begin();
                    advance(it, 1);
                    cout<<"\n\n* " <<*it <<" is winner *";
                    return 0;
                }
            }
        }

        for(int k=0; k<=2; k++)
        {
            if(table[k] == 'x' && table[k+3] == 'x' && table[k+6] == 'x'
               || table[k] == 'o' && table[k+3] == 'o' && table[k+6] == 'o')
            {
                if(table[k] == 'x')
                {
                    auto it = li.begin();
                    advance(it, 0);
                    cout<<"\n\n* " <<*it <<" is winner *";
                    return 0;
                }
                else if(table[k] == 'o')
                {
                    auto it = li.begin();
                    advance(it, 1);
                    cout<<"\n\n* " <<*it <<" is winner *";
                    return 0;
                }
            }
        }

        if(table[j] == 'x' && table[j+4] == 'x' && table[j+8] == 'x'
           || table[j] == 'o' && table[j+4] == 'o' && table[j+8] == 'o')
        {
            if(table[j] == 'x')
            {
                auto it = li.begin();
                advance(it, 0);
                cout<<"\n\n* " <<*it <<" is winner *";
                return 0;
            }
            else if(table[j] == 'o')
            {
                auto it = li.begin();
                advance(it, 1);
                cout<<"\n\n* " <<*it <<" is winner *";
                return 0;
            }
        }
        else if(table[j+2] == 'x' && table[j+4] == 'x' && table[j+6] == 'x'
                || table[j+2] == 'o' && table[j+4] == 'o' && table[j+6] == 'o')
        {
            if(table[j+2] == 'x')
            {
                auto it = li.begin();
                advance(it, 0);
                cout<<"\n\n* " <<*it <<" is winner *";
                return 0;
            }
            else if(table[j+2] == 'o')
            {
                auto it = li.begin();
                advance(it, 1);
                cout<<"\n\n* " <<*it <<" is winner *";
                return 0;
            }
        }

        c = 0;

        for (int i = 0 ; i <= 8 ; i++)
        {
            if (table[i] != 'o' && table[i] != 'x')
            {
                c++;
                break;
            }
        }

        if (c == 0)
        {
            cout << "\nThis game not have a winner !!!" << endl;
            return 0;
        }

        line_table();
        if (step == 1)
        {
            step = 0;
        }
        else
        {
            step = 1;
        }
    }
    return 0;
}


int main()
{
    string player;
    for(int i=1; i<=2; i++)
    {
        cout<<"Put your name player "<< i << ": ";
        cin>>player;
        li.push_back(player);
    }
    line_table();
    winner_loser();
    line_table();
    cout<<endl;

    return 0;
}