#include "ATM.h";



void Program::mainMenu() {
	int menuOption;
	std::cout << "\n1.Log into account.\n2.Help\n3.Deposit\n4.Withdraw.\n5.Account Balance.\n6.Exit." << std::endl;
	std::cin >> menuOption;
	if (menuOption == 1) {
		loginAccount();
	}
	else if (menuOption == 2) {
		helpMenu();
	}
	else if (menuOption == 3) {
		depositScreen();
	}
	else if (menuOption == 4) {
		withdrawScreen();
	}
	else if (menuOption == 5) {
		setAccountBalance();
	}
	else if (menuOption == 6) {
		exitSystem();
	}
}

void Program::exitSystem() {
	int counter = 10;
	Sleep(1000);
	while (counter >= 1) {
		std::cout << "\r Closing system in " << counter << flush;
		Sleep(1000);
		counter--;
	}

}
void Program::setupUsername(std::string Username) {
	if (Username.size() > 6 && Username.size() < 15) {
		username = Username;
		usernameSetCompleted = true;
	}
}
void Program::setupPassword(std::string Password) {
	password = Password;
	passwordSetCompleted = true;
}

std::string Program::getUsername() {
	return username;
}
std::string Program::getPassword() {
	return password;
}

int Program::getAccountBalance() {
	return accountBalance;
}
void Program::setAccountBalance() {
	std::string enter;
	std::cout << "Your account balance is " << accountBalance << std::endl;
	std::cout << "Press enter to return to the main menu" << std::endl;
	std::cin >> enter;
	mainMenu();
}
void Program::printAccountBalance() {
	std::string enter;
	std::cout << "Your current balance is: " << accountBalance << std::endl;
	std::cout << "Press any key to return to the main menu" << std::endl;
	std::cin >> enter;
	mainMenu();
}
int Program::getTotalWithdrawls() {
	return totalWithdrawls;
}
int Program::getTotalAccountLogins() {
	return accountAccessed;
}
void Program::getNumberTransactions() {
	std::string enter;
	std::cout << "Your account has a total of " << transactions << "transactions " << std::endl;
	std::cout << "Press 'enter' to return to the main menu" << std::endl;
	std::cin >> enter;
	mainMenu();
}
void Program::helpMenu() {
	std::string enter;
	std::cout << "THIS IS THE HELP MENU" << std::endl;
	std::cout << "If you need live assistance, please call 800-555-2142 between 9AM - 5PM " << std::endl;
	std::cout << "Please press 'enter' to return to the main menu" << std::endl;
	std::cin >> enter;
	mainMenu();

}

void Program::withdrawScreen() {
	int funds;
	int choice;

	std::cout << "Welcone to the withdraw screen " << std::endl;
	std::cout << "How much would you like to withdraw? :" << std::endl;
	std::cin >> funds;
	if (funds < accountBalance) {
		accountBalance -= funds;
		std::cout << "\nYou have withdrawn " << funds << "\n Your new balance is " << accountBalance << std::endl;
	}
	else if (funds > accountBalance || accountBalance == 0) {
		std::cout << "Insufficient funds" << std::endl;
		std::cout << "Please try a lesser amount." << std::endl;
		std::cout << "\n1.Main Menu\n2.Change Amount.\n3.Deposit Funds." << std::endl;
		std::cin >> choice;
		if (choice == 1) { mainMenu(); }
		else if (choice == 2)
		{
			std::cout << "Ok. Let's try again.";
			Sleep(2);
			withdrawScreen();
		}
		else if (choice == 3) {
			depositScreen();
		}
	}
}


void Program::depositScreen() {
	int choice;
	int funds;
	int second_choice;
	std::cout << "Welcome to the deposit screen" << std::endl;
	std::cout << "Please enter your deposit method" << std::endl;
	std::cout << "\n1.Deposit Check.\n2.Deposit Cash" << std::endl;
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "Please enter the amount.." << std::endl;
		std::cin >> funds;
		std::cout << "The amount you are depositing into your account is " << funds << std::endl;
		std::cout << "Please keep in mind it can take up to 3 days to verify your check" << std::endl;
		if (funds >= 25) {
			std::cout << "We will release 25 dollars into your account until your check clears" << std::endl;
		}
		else {

		}
		std::cout << "Thank you for using ABC's atm." << std::endl;
		std::cout << "1.Main Menu." << std::endl;
		std::cout << "2.Exit System." << std::endl;
		std::cin >> second_choice;
		if (second_choice == 1) {
			mainMenu();
		}
		else {
			std::cout << "Terminating program" << std::endl;
			std::cout << "Please don't forget your atm card" << std::endl;
		}
	}
	else if (choice == 2) {
		std::cout << "Your are depositing cash into your account" << std::endl;
		std::cout << "Please place the cash into the cash deposit slot" << std::endl;
		std::cout << "Please enter the amount.." << std::endl;
		std::cin >> funds;
		accountBalance += funds;
		std::cout << "You have deposited" << funds << "into your account" << std::endl;
		std::cout << "Your new account balance is: " << accountBalance << std::endl;
		std::cout << endl;
		std::cout << "Thank you for using ABC's atm." << std::endl;
		std::cout << "1.Main Menu." << std::endl;
		std::cout << "2.Exit System." << std::endl;
		std::cin >> second_choice;
		if (second_choice == 1) {
			mainMenu();
		}
		else {
			std::cout << "Terminating program" << std::endl;
			std::cout << "Please don't forget your atm card" << std::endl;
		}
	}
}
bool Program::getUserPinSet()
{
	return UserPinSet;
}



void Program::setPinNumber() {
	std::string pin;
	int Menuchoice;
	//int PinLength = pin.size();
	std::string newPin;
	std::string enter;
	if (UserPinSet == true) {
		std::cout << "Your pin has already been set" << std::endl;
		std::cout << "Would you like to change your PIN" << std::endl;
		std::cout << "\n1.YES\n2.NO" << std::endl;
		std::cin >> newPin;
		if (newPin.size() == 4) {
			std::cout << "Invalid size" << std::endl;
		}
		else {
			std::cout << "Your PIN has been set" << std::endl;
			secretPinNumber = newPin;
			UserPinSet = true;
		}
	}
	else if (UserPinSet == false) {
		std::cout << "Enter a new pin" << std::endl;
		std::cin >> newPin;
		if (newPin.size() == 4) {
			std::cout << "Your PIN has been set" << std::endl;
			std::cout << "Your new PIN number is: " << newPin << std::endl;
			secretPinNumber = newPin;
			UserPinSet = true;
			std::cout << "Returning back to the main menu" << std::endl;
			Sleep(1);
			mainMenu();
		}
	}
}

void Program::loginAccount() {
	std::string un, pw;
	if (userLoggedin == true|| lockedAccount == false && newAcount == false && usernameSetCompleted == true && passwordSetCompleted == true) {
		int passwordTries = 0;
		int usernameTries = 0;
		std::string SecretPin;
		std::cout << "Please enter your username: ";
		std::cin >> un;
		if (un == username) {
			std::cout << "Username found." << std::endl;
			std::cout << "Now enter your account password: ";
			std::cin >> pw;
			if (pw == password) {
				std::cout << "Finally, enter your secret code" << std::endl;
				std::cin >> SecretPin;
				if (SecretPin == secretPinNumber) {
					std::cout << "You have successfully logged in" << std::endl;
					userLoggedin = true;
					mainMenu();
				}
			}
			else {
				std::cout << "Invalid password" << std::endl;
				passwordTries++;
				if (passwordTries == 3)
				{
					lockedAccount = true;
				}

			}

		}
		else {
			std::cout << "Invalid Username" << std::endl;
			usernameTries++;
			if (usernameTries == 3) {
				lockedAccount = true;
			}
		}
	}

}


int main() {
	Program p;
	p.setupUsername("arichmond00");
	p.setupPassword("1baseball");
	//std::cout <<" \n Username: "<< p.getUsername() << "\n Password: "<<p.getPassword();
	//p.loginAccount();
	//std::cout << p.getAccountBalance();
	//p.withdrawScreen();
	p.getUserPinSet();
	p.setPinNumber();

}
