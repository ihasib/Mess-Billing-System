#include<bits/stdc++.h>
using namespace std;
int stringSummed(string s);

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s,s1;
    string utilityName[20],boarderName[20];
    double utilityCosts[20],roomRent[20],clothWash[20],bazarPay[20],mealPerBoarder[20][35],mealChargePerBoarder[20],garage[20];
    int noOfBoarder=0;

    //---------utility fetching--------
    int noOfUtility=0;
    cin>>utilityName[0];
    for(int i=1;i<10;i++)
    {
        cin>>utilityName[i];
        if(utilityName[i]=="END")
            break;
        cin>>utilityCosts[i];
        noOfUtility++;
        //cin>>utilityCosts[i];
    }
    /*for(int i=1;i<=noOfUtility;i++)
    {
        cout<<utilityName[i]<<"  "<<utilityCosts[i]<<"\n";
    }*/


    //----------ROOM rent fetching------
    for(int i=1;i<10;i++)
    {
        cin>>boarderName[i];
        if(boarderName[i]=="END")
            break;
        noOfBoarder++;
    }
    /*for(int i=1;i<=noOfBoarder;i++)
    {
        cout<<boarderName[i]<<"\n";
    }*/
    cin>>s>>s;
    for(int i=1;i<=noOfBoarder;i++)
    {
        cin>>roomRent[i];
    }

    //----------cloth wash fetching--------
    cin>>s>>s;
    for(int i=1;i<=noOfBoarder;i++)
    {
        cin>>clothWash[i];
    }
    cin>>s;
    for(int i=1;i<=noOfBoarder;i++)
    {
        cin>>garage[i];
    }
    cin>>s;//consume END

    //---------Bazar Payment fetching---------
    for(int i=1;i<=noOfBoarder;i++)
    {
        cin>>s>>s1;//s consumes boarder name
        //cout<<s<<" "<<s1<<endl;
        bazarPay[i]=stringSummed(s1);
    }
    /*for(int i=1;i<=noOfBoarder;i++)
    {
        cout<<bazarPay[i]<<"\n";
    }*/


    //---------meal fetching--------
    cin>>s;//consume Date
    for(int i=1;i<=noOfBoarder;i++)
    {
        cin>>s;
    }

    for(int i=1;i<=31;i++)
    {
        cin>>s;
        for(int j=1;j<=noOfBoarder;j++)
        {
            cin>>mealPerBoarder[j][i];
        }
    }

    /*for(int i=1;i<=31;i++)
    {
        cout<<mealPerBoarder[1][i]<<"\n";
    }*/



    //-------------averaging utility------------

    double totalUtility=0,avgUtility;
    for(int i=1;i<=noOfUtility;i++)
    {
        totalUtility+=utilityCosts[i];
    }
    avgUtility=totalUtility/noOfBoarder;
    //printf("--- %lf\n",totalUtility);
    //cout<<totalUtility<<"  "<<avgUtility<<"\n";

    //----------averaging meal charge-----------

    for(int i=1;i<=noOfBoarder;i++)
    {
        mealPerBoarder[i][32]=0;
    }
    for(int i=1;i<=noOfBoarder;i++)
    {
        for(int j=1;j<=31;j++)
        {
            mealPerBoarder[i][32]+=mealPerBoarder[i][j];
        }
    }

    double totalMeal=0,totalBazarPay=0;
    for(int i=1;i<=noOfBoarder;i++)
    {
        totalMeal+=mealPerBoarder[i][32];
        totalBazarPay+=bazarPay[i];
    }
    //cout<<totalMeal<<" "<<totalBazarPay<<"\n";
    double avgMlChrg=totalBazarPay/totalMeal;
    for(int i=1;i<=noOfBoarder;i++)
    {
            mealChargePerBoarder[i]=mealPerBoarder[i][32]*avgMlChrg;
    }

    double bazarPaySurplus[20];
    for(int i=1;i<=noOfBoarder;i++)
    {
        bazarPaySurplus[i]=bazarPay[i]-mealChargePerBoarder[i];
    }

    //----------------output--------------

    for(int i=1;i<=noOfBoarder;i++)
    {
        cout<<boarderName[i]<<"'s total meal = "<<mealPerBoarder[i][32]<<"\n";
    }
    cout<<"\nTotal Meal = "<<totalMeal<<"\n";
    cout<<"Total Bazar = "<<totalBazarPay<<"\n";
    cout<<"Per meal cost = "<<avgMlChrg<<"\n";

    cout<<"\n\n------------------------------------------------\n\n";
    for(int i=1;i<=noOfBoarder;i++)
    {
        cout<<boarderName[i]<<" = "<<avgMlChrg<<" x "<<mealPerBoarder[i][32]<<" = "<<mealChargePerBoarder[i]<<" - "<<bazarPay[i]<<" = "<<bazarPaySurplus[i]<<"\n\n" ;
    }
        cout<<"\n\n------------------------------------------------\n\n";
    for(int i=1;i<=noOfUtility;i++)
    {
        cout<<utilityName[i]<<" = "<<utilityCosts[i]<<"\n";
    }
    cout<<"Total utility = "<<totalUtility<<"\n";
    cout<<"Average utility ="<<avgUtility<<"\n";
    double totalDue[20];
    for(int i=1;i<=noOfBoarder;i++)
    {
        totalDue[i]=roomRent[i]+clothWash[i]+garage[i]+avgUtility-bazarPaySurplus[i];
    }

    cout<<"\n\n\n";

    cout<<"boarder "<<" room  "<<"cloth "<<"garage "<<"Utility "<<"Surplus  "<<" Due"<<"\n" ;
    cout<<"\n\n------------------------------------------------\n\n";
    for(int i=1;i<=noOfBoarder;i++)
    {
        cout<<boarderName[i]<<" = "<<roomRent[i]<<" + "<<clothWash[i]<<" + "<<garage[i]<<" + "<<avgUtility<<" - ("<<bazarPaySurplus[i]<<")"<<" = "<<totalDue[i]<<"\n\n" ;
    }
    return 0;
}


int stringSummed(string s)
{
    int total=0,no=0,len=s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='+')
        {
            total+=no;
            no=0;
        }
        else
        {
            no=no*10+(s[i]-'0');
        }
          //cout<<i<<" no="<<no<<endl;
    }
    total+=no;

    return total;
}
