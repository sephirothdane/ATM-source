#include <iostream>
#include <string>
#include <Windows.h>
#include <windows.h>
using namespace std;
void printErrorCodes(int errorCode) {
	switch (errorCode) {
	case 1: // Invalid passpassword code
		std::cout << "Invalid password" << std::endl;
		break;
	case 2://inclvalid username
		std::cout << "Invalid username" << std::endl;
		break;
	case 3:
		std::cout << "Account Locked" << std::endl;
		break;
	}
}

class Program {
private:
	int accountAccessed;
	int accountBalance;
	int transactions;
	int totalWithdrawls;
	int totalDeposits;
	std::string secretPinNumber;
	bool lockedAccount;
	bool newAcount;
	bool login_completed;
	bool UserPinSet;
	bool usernameSetCompleted;
	bool passwordSetCompleted;
	std::string password;
	std::string username;
	bool userLoggedin;
public:
	Program() {
		usernameSetCompleted = false;
		passwordSetCompleted = false;
		accountAccessed = 0;
		transactions = 0;
		accountBalance = 0;
		totalWithdrawls = 0;
		totalDeposits = 0;
		lockedAccount = false;
		UserPinSet = false;
		newAcount = false;
		login_completed = false;
		userLoggedin = false;
	}
	~Program();

	void setupUsername(std::string);
	void setupPassword(std::string);
	string getUsername();
	string getPassword();
	int getAccountBalance();
	void setAccountBalance();
	int getTotalWithdrawls();
	int getTotalAccountLogins();
	void getNumberTransactions();
	void helpMenu();
	void withdrawScreen();
	void depositScreen();
	bool getUserPinSet();
	void loginAccount();
	void setPinNumber();
	void mainMenu();
	void printAccountBalance();
	void exitSystem();

};