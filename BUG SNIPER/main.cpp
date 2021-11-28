#include <bits/stdc++.h>
#include<conio.h>
#define FAST_IO ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;

class Brute_Force
{
public:

    ifstream in;
    ofstream out;

    Brute_Force()
    {
        in.open("input.txt");
        out.open("BRUTEFORCE.txt",ofstream::out | ofstream::trunc);
    }

    /*
        Declare Variables
    */


//    main function of the code
    void run()
    {
        int t;
        in>>t;
        while(t--)
        {
            int n;
            in>>n;
            long long a[n],ans=0;
            for(int i=0;i<n;i++)
                in>>a[i];
            for(int i=0;i<n-1;i++)
                if(a[i]>a[i+1])
                    ans+=a[i]-a[i+1];
            out<<ans<<"\n";
        }

        in.close();
        out.close();
    }
};


class MY_Code
{
public:

    ifstream in;
    ofstream out;

    MY_Code()
    {
        in.open("input.txt");
        out.open("MYCODE.txt",ofstream::out | ofstream::trunc);
    }

    /*
        Declare Variables
    */


//    main function of the code
    void run()
    {
        int t;
        in>>t;
        while(t--)
        {
            int n;
            in>>n;
            n++;
            long long a[n];
            for(int i=0;i<n-1;i++)
                in>>a[i];
            a[n-1]=1e9+5;
            long long mx=0,mxd=0,ans=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]>=mx)
                {
                    mx=a[i];
                    ans+=mxd;
                    mxd=0;
                }
                else
                {
                    mxd=max(mxd,mx-a[i]);
                }
            }
            out<<ans<<"\n";
        }

        in.close();
        out.close();
    }
};

bool check_AC()
{

    ifstream bf,mc;
    bf.open("BRUTEFORCE.txt");
    mc.open("MYCODE.txt");

    string AC,WA;

    bool yes=1;

    while( getline(bf,AC) )
    {
        getline(mc,WA);

        if(AC != WA)
        {
            yes=0;
            break;
        }
    }
    while(getline(mc,WA))
    {
        if(WA!=" " && WA.size()!=0)
            yes=0;
    }

    bf.clear();
    mc.clear();
    bf.close();
    mc.close();

    return yes;
}

template<typename T> get_random(T _begin,T _end,int negative_lvl=0)
{
    /*
        negative_lvl == 0 ? all positive
        negative_lvl == 1 ? half positive & half negative
        negative_lvl == 2 ? all negative
    */

    T x;
    x = T((double)(_end+1 - _begin)*((double)(rand()%rand())/RAND_MAX)) + _begin;
    if((negative_lvl==2) || (negative_lvl==1 && rand()%2==0))
        x*=-1;
    return x;
}


int main()
{

   // FAST_IO


    srand(time(0));

    remove("BRUTEFORCE.txt");
    remove("MYCODE.txt");

    while(check_AC())
    {
        ofstream input("input.txt",ofstream::out | ofstream::trunc);

        /*
            Declare Variables with random values

            use this equation <3

            (end - begin) * (rand()/(double)RAND_MAX)
        */




        //Prepare the test file

        input<<"1\n";
        int n=get_random<int>(1,10);
        input<<n<<"\n";
        for(int i=0;i<n;i++)
        {long long x=get_random<long long>(1,10);input<<x<<" ";}
        input<<"\n";


        input.close();

        Brute_Force bf;
        bf.run();

        MY_Code mc;
        mc.run();

        if(check_AC()==0)
        {
            // BUG arrested successfully :)
            // print the test

            ifstream inpt("input.txt");
            string s;
            ofstream bug;
            bug.open("BUGGY TEST.txt", ofstream::out | ofstream::trunc);
            while(getline(inpt,s))
                cout<<s<<"\n",bug<<s<<"\n";
            bug.close();

            break;
        }


    }

    return 0;
}
