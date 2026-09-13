#include<stdio.h>
#include<time.h>                // header file for time and date.
#include<string.h>
int account_type ;
long int accountno;
char pinn[5] ;
int  menu;
int d ,w ,i;
int accountcount=0;
int loggedInAccount;
int accountexist;
struct transaction
{
    int type;
    int amount;
    char datetime[30];
};

void main()
{
    time_t currenttime;
    time(&currenttime);
    struct tm *localTime;
    localTime = localtime(&currenttime);
    printf(" current date and time :%s", ctime(&currenttime));

    int choise ;
    struct details 
    {
    char name [30];
    long int account ;
    char pin[5] ;
    char tempPin[20];
    int balance ;
    struct transaction arr [20];
    int transactionCount;
    };
    struct details s1[20];
    printf("===========================");
    printf("\n          MY BANK          ");
    printf("\n===========================");
do
{

    printf("\n\n*****    Welcome    *****");
    printf("\n\nprees the following to proceed :");
    printf("\n1 . Create account \n2 . Login \n3 . Exit\n");
    
    scanf("%d",&choise);
   

    switch(choise)
    {
        case 1 : 
                printf("\n\ncreat account type you want to create :");
                printf("\n\nPress :\n 1 . savings account \n 2 . current account .\n");
                scanf("%d",&account_type);
                switch(account_type)
                {
                case 1 : 
                    if(accountcount < 20)
                    {
                         printf("Enter name of coustumer :\n");
                         scanf("%s",s1[accountcount].name);
                         printf("Enter account number you want :\n");
                         scanf("%ld",&s1[accountcount].account);
                         accountexist = 0;
                         for(i = 0; i < accountcount; i++)
                            {
                                if(s1[i].account == s1[accountcount].account)
                                {
                                    accountexist = 1;
                                    
                                break;
                                }
                            }
                                if(accountexist == 1)
                                {
                                    printf("\nAccount number already exists. Please choose another account number.\n");
                                }
                                    else
                                {
                                    
                                    do
                                    {
                                        printf("Enter a 4 digit PIN for your account:\n");
                                        scanf("%4s", s1[accountcount].pin);
                                            if(strlen(s1[accountcount].pin) != 4 ||
                                            s1[accountcount].pin[0] < '0' || s1[accountcount].pin[0] > '9' ||
                                            s1[accountcount].pin[1] < '0' || s1[accountcount].pin[1] > '9' ||
                                            s1[accountcount].pin[2] < '0' || s1[accountcount].pin[2] > '9' ||
                                            s1[accountcount].pin[3] < '0' || s1[accountcount].pin[3] > '9')
                                        {
                                            printf("Invalid PIN! Please enter exactly 4 numbers.\n");
                                        }

                                    }while(strlen(s1[accountcount].pin) != 4 ||s1[accountcount].pin[0] < '0' || s1[accountcount].pin[0] > '9' || s1[accountcount].pin[1] < '0' || s1[accountcount].pin[1] > '9' ||s1[accountcount].pin[2] < '0' || s1[accountcount].pin[2] > '9' ||s1[accountcount].pin[3] < '0' || s1[accountcount].pin[3] > '9');
                                    printf("Enter the amount you want to credit now :\n");
                                    scanf("%d",&s1[accountcount].balance);
                                    s1[accountcount].transactionCount = 0;
                                    printf("\n\nDetails :");
                                    printf("\nName           : %s",s1[accountcount].name);
                                    printf("\nAccount number : %ld",s1[accountcount].account);
                                    printf("\npin            : %s ",s1[accountcount].pin);
                                    printf("\nbalance        : %d",s1[accountcount].balance);

                                    accountcount++;
                                }
                    }
                    else
                    {
                        printf("\n\nMaximum number of account reach ");
                    }
                break;
                case 2 :
                    if(accountcount < 20)
                    {
                         printf("Enter name of coustumer :\n");
                         scanf("%s",s1[accountcount].name);
                         printf("Enter account number you want :\n");
                         scanf("%ld",&s1[accountcount].account);
                         
                        accountexist = 0;

                        for(i = 0; i < accountcount; i++)
                        {
                            if(s1[i].account == s1[accountcount].account)
                            {
                                accountexist = 1;
                                break;
                            }
                        }

                        if(accountexist == 1)
                        {
                            printf("\nAccount number already exists. Please choose another account number.\n");
                        }
                        else
                        {

                         do
                            {
                                printf("Enter a 4 digit PIN for your account:\n");
                                scanf("%4s", s1[accountcount].pin);

                                if(strlen(s1[accountcount].pin) != 4 ||
                                    s1[accountcount].pin[0] < '0' || s1[accountcount].pin[0] > '9' ||
                                    s1[accountcount].pin[1] < '0' || s1[accountcount].pin[1] > '9' ||
                                    s1[accountcount].pin[2] < '0' || s1[accountcount].pin[2] > '9' ||
                                    s1[accountcount].pin[3] < '0' || s1[accountcount].pin[3] > '9')
                                    {
                                        printf("Invalid PIN! Please enter exactly 4 numbers.\n");
                                    }

                                    }while(strlen(s1[accountcount].pin) != 4 ||
                                        s1[accountcount].pin[0] < '0' || s1[accountcount].pin[0] > '9' ||
                                        s1[accountcount].pin[1] < '0' || s1[accountcount].pin[1] > '9' ||
                                        s1[accountcount].pin[2] < '0' || s1[accountcount].pin[2] > '9' ||
                                        s1[accountcount].pin[3] < '0' || s1[accountcount].pin[3] > '9');
                         printf("Enter the amount you want to credit now :\n");
                         scanf("%d",&s1[accountcount].balance);
                         s1[accountcount].transactionCount = 0;
                         printf("\n\nDetails :");
                         printf("\nName           : %s",s1[accountcount].name);
                         printf("\nAccount number : %ld",s1[accountcount].account);
                         printf("\npin            : %s ",s1[accountcount].pin);
                         printf("\nbalance        : %d",s1[accountcount].balance);
                         accountcount++;
                        }
                    }
                    else
                    {
                        printf("\n\nMaximum number of account reach ");
                    }
                 break;
                default :
                            printf("\n\nWrong input :\n please press 1 or 2");
                break;
            }

        break;
        case 2 :
                printf("\n\nEnter your account number : \n");
                scanf("%ld",&accountno);
                                
                loggedInAccount = -1;

                for(i = 0; i < accountcount; i++)
                {
                    if(accountno == s1[i].account)
                    {
                        loggedInAccount = i;
                    }
                }
                if(loggedInAccount != -1)
                {
                    printf("\nNow enter your pin\n");
                    scanf("%4s",pinn);
                    if(strcmp(pinn ,s1[loggedInAccount].pin)==0)
                    {
                        printf("\nLogin suceesfull .");
                        do
                        {
                            printf("\n\nMENU :\n");
                            printf("press :\n1 . check balance \n 2. deposit money \n 3. withdraw money \n 4 change pin \n 5 transation history \n 6 logout  ");
                            scanf("%d",&menu);
                            switch(menu)
                            {
                                case 1:
                                    printf("account number : \n %ld",s1[loggedInAccount].account);
                                    printf("\n\nBalance : %d",s1[loggedInAccount].balance);
                                break;
                                case 2:
                                    
                                    printf("\nDEPOSIT MONEY :\n");
                                    printf("Enter amount to be deposit : \n");
                                    scanf("%d",&d);
                                    if(d > 0 && s1[loggedInAccount].transactionCount < 20)
                                    {
                                        printf("\n\nold balance    : %d",s1[loggedInAccount].balance);
                                        printf("\namount deposit : %d",d);
                                        s1[loggedInAccount].balance=s1[loggedInAccount].balance+d;
                                        printf("\n\nCurrent balance : %d",s1[loggedInAccount].balance);
                                        s1[loggedInAccount].arr[s1[loggedInAccount].transactionCount].type = 1;   // 1 = Deposit
                                        s1[loggedInAccount].arr[s1[loggedInAccount].transactionCount].amount = d;
                                        time_t currenttime;
                                        time(&currenttime);

                                        strcpy(s1[loggedInAccount].arr[s1[loggedInAccount].transactionCount].datetime, ctime(&currenttime));

                                        s1[loggedInAccount].transactionCount++;
                                    }
                                    else if(d <= 0)
                                        {
                                            printf("\n\nDeposit amount must be greater than 0.");
                                        }
                                        else
                                        {
                                            printf("\n\nTransaction history is full. Maximum 20 transactions allowed.");
                                        }
                                break;
                                case 3 :

                                    printf("\nWITHDRAW MONEY :\n");
                                    printf("Enter amount you want to withdraw :\n");
                                    scanf("%d",&w);
                                    if(w > 0 && s1[loggedInAccount].transactionCount < 20)
                                    {
                                        if(w<=s1[loggedInAccount].balance)
                                        {
                                            printf("Enter pin : \n");
                                            scanf("%4s", pinn);
                                            if(strcmp(pinn, s1[loggedInAccount].pin) == 0)
                                            {
                                                printf("\n\nold balance      : %d",s1[loggedInAccount].balance);
                                                printf("\namount withdrawl : %d",w);
                                                s1[loggedInAccount].balance=s1[loggedInAccount].balance-w;
                                                printf("\n\nCurrent balance : %d",s1[loggedInAccount].balance);
                                                s1[loggedInAccount].arr[s1[loggedInAccount].transactionCount].type = 2;   // 2 = withdrawl
                                                s1[loggedInAccount].arr[s1[loggedInAccount].transactionCount].amount = w;
                                                time_t currenttime;
                                                time(&currenttime);
                                                strcpy(s1[loggedInAccount].arr[s1[loggedInAccount].transactionCount].datetime, ctime(&currenttime));
                                                s1[loggedInAccount].transactionCount++;
                                            }
                                            else
                                            {
                                                printf("incorrect pin :");
                                            }
                                        }
                                        else
                                        {
                                            printf("insufficent balance .");
                                        }
                                    }
                                    else if(w <= 0)
                                        {
                                            printf("\n\nWithdraw amount must be greater than 0.");
                                        }
                                        else
                                        {
                                            printf("\n\nTransaction history is full. Maximum 20 transactions allowed.");
                                        }
                                break ;
                                case 4:
                                        printf("\n\nChange pin :");
                                        printf("\n\nEnter old pin :\n");
                                        scanf("%4s",pinn);
                                        if(strcmp(pinn,s1[loggedInAccount].pin)==0)
                                        {
                                            
                                                
                                            do
                                                {
                                                    printf("Enter new 4 digit PIN :\n");
                                                    scanf("%4s", s1[loggedInAccount].pin);
                                                    if(strlen(s1[loggedInAccount].pin) != 4 ||
                                                    s1[loggedInAccount].pin[0] < '0' || s1[loggedInAccount].pin[0] > '9' ||
                                                    s1[loggedInAccount].pin[1] < '0' || s1[loggedInAccount].pin[1] > '9' ||
                                                    s1[loggedInAccount].pin[2] < '0' || s1[loggedInAccount].pin[2] > '9' ||
                                                    s1[loggedInAccount].pin[3] < '0' || s1[loggedInAccount].pin[3] > '9')
                                                    {
                                                        printf("Invalid PIN! Please enter exactly 4 numbers.\n");
                                                    }
                                                        }while(strlen(s1[loggedInAccount].pin) != 4 ||
                                                            s1[loggedInAccount].pin[0] < '0' || s1[loggedInAccount].pin[0] > '9' ||
                                                            s1[loggedInAccount].pin[1] < '0' || s1[loggedInAccount].pin[1] > '9' ||
                                                            s1[loggedInAccount].pin[2] < '0' || s1[loggedInAccount].pin[2] > '9' ||
                                                            s1[loggedInAccount].pin[3] < '0' || s1[loggedInAccount].pin[3] > '9');

                                                

                                            printf("\n\nNew pin updated successfully.");
                                        }
                                        else
                                        {
                                            printf("wrong old pin .");
                                        }
                                break;
                                case 5 :
                                         

                                        printf("\n========== TRANSACTION HISTORY ==========\n");

                                        if (s1[loggedInAccount].transactionCount == 0)
                                        {
                                        printf("No transactions found.\n");
                                        }
                                        else
                                        {
                                            for (i = 0; i < s1[loggedInAccount].transactionCount; i++)
                                            {
                                                if (s1[loggedInAccount].arr[i].type == 1)
                                                {
                                                    printf("\nDeposit");
                                                }
                                                else if (s1[loggedInAccount].arr[i].type == 2)
                                                {
                                                    printf("\nWithdrawal");
                                                }

                                                printf("\nAmount : %d", s1[loggedInAccount].arr[i].amount);
                                                printf("\nDate & Time : %s", s1[loggedInAccount].arr[i].datetime);
                                                printf("\n----------------------------------------");
                                            }
                                        }

                                        printf("\n========================================\n");
                                 break;
                                 default :
                                            printf("\n\n wrong input : \n please select an valid input :");
                                    break;

                            }
                        }while(menu!=6);
                    }
                    else
                    {
                        printf("Wrong pin ");
                    }
                }
                else
                {
                    printf("invalid account number :\n %ld ",accountno);
                }
                



        break ;
        case 3 :
                printf("\n\nThank you for using our bank .");
        break ;
        default :
                printf("\n\nwrong input ");
        break;
    }
}while(choise!=3);

}