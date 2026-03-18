#include <stdio.h>


void checkBalance(float balance);
float deposit();
float withdraw(float balance);


int main()
{
    int choise = 0;
    float balance = 0.0f;

    printf("WELCOME TO THE BANK!\n");

    do
    {
        printf("\nSelect an option: \n");
        printf("1. Check balance\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Exit\n");

        printf("\nEnter your choise: ");
        scanf("%d", &choise);

        switch (choise)
        {
        case 1:
            checkBalance(balance);
            break;

        case 2:
            balance += deposit();
            checkBalance(balance);
            break;

        case 3:
            balance -= withdraw(balance);
            checkBalance(balance);
            break;
        
        case 4:
            printf("\nThank you for using the bank!\n");
            break;
        
        default:
            printf("\nInvalid choise! Please select 1 - 4\n");
            break;
        }




    } while (choise != 4);
    

    return 0;
}


void checkBalance(float balance)
{
    printf("\nYour current balance is: $%.2f\n", balance);

}

float deposit()
{
    float amount = 0.0f;
    
    printf("\nEnter amount to deposit: $");
    scanf("%f", &amount);

    if(amount < 0)
    {
        printf("\nInvalid amount!\n");
        return 0;
    }
    else
    {
        printf("\nSuccessfully deposited $%.2f\n", amount);
        return amount;
    }

}

float withdraw(float balance)
{
    float amount = 0.0f;

    printf("\nEnter amount to withdraw: $");
    scanf("%f", &amount);
    
    if(amount < 0)
    {
        printf("\nInvalid amount!\n");
        return 0;  
    }
    else if(amount > balance)
    {
        printf("\nInsufficient funds! Your balance is $%.2f\n", balance);
        return 0;  
    }
    else
    {
        printf("\nSuccessfully withdrew $%.2f\n", amount);
        return amount;
    }

}
