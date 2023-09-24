#include <iostream>
#include <iomanip>
#include <limits>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
    double balance = 0;
    int choice = 0;

    do
    {
        std::cout << "*******************" << '\n';
        std::cout << "Enter your choice: " << '\n';
        std::cout << "*******************" << '\n';
        std::cout << "1. Show Balance" << '\n';
        std::cout << "2. Deposit Money" << '\n';
        std::cout << "3. Withdraw Money" << '\n';
        std::cout << "4. Exit" << '\n';

        std::cin >> choice;

        std::cin.clear(); // This function will reset any error flags, when the standart input fails to interpret the input.
        fflush(stdin); // This will clear the input buffer. Basically speaking, once we hit enter, we have a new line character within our input buffer, so we just need to flush that and get rid of it.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice)
        {
            case 1:
                    showBalance(balance);
                    break;
            case 2:
                    balance += deposit();
                    showBalance(balance);
                    break;
            case 3:
                    balance -= withdraw(balance);
                    showBalance(balance);
                    break;
            case 4:
                    std::cout << "Thank you for visiting!" << '\n';
                    break;
            default:
                    std::cout << "Invalid choice. Please enter any option from 1 to 4." << '\n';
        }
    } while (choice != 4);
    
    return 0;
}

void showBalance(double balance)
{
    std::cout << "Your balance is: " << balance << " $" << std::setprecision(2) << std::fixed << '\n';
}

double deposit()
{
    double amount = 0;

    std::cout << "Enter amount to be deposited: ";

    std::cin >> amount;

    if (amount > 0)
    {
        return amount;
    }
    else
    {
        std::cout << "That is not a valid amount." << '\n';
        return 0;
    }
}

double withdraw(double balance)
{
    double amount = 0;

    std::cout << "Enter amount to be withdrawn: ";

    std::cin >> amount;

    if (amount > balance)
    {
        std::cout << "Insufficient funds!" << '\n';
        return 0;
    }
    else if (amount < 0)
    {
        std::cout << "That is not a valid amount." << '\n';
        return 0;
    }
    else
    {
        return amount;
    }
}