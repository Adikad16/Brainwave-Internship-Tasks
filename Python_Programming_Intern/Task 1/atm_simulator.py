class ATM:
    def __init__(self):
        self.balance = 10000  # Initial balance

    def get_balance(self):
        return self.balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Successfully deposited: {amount}")
        else:
            print("Invalid deposit amount. Please enter a positive value.")

    def withdraw(self, amount):
        if amount <= 0:
            print("Invalid withdrawal amount. Please enter a positive value.")
        elif amount > self.balance:
            print(f"Insufficient balance. You cannot withdraw more than {self.balance}")
        else:
            self.balance -= amount
            print(f"Successfully withdrew: {amount}")


class AtmOperations:
    def __init__(self):
        self.atm = ATM()
        self.mini_statement = []

    def view_balance(self):
        print(f"Current Balance: {self.atm.get_balance()}")

    def withdraw_amount(self, withdraw_amount):
        if withdraw_amount <= 0:
            print("Invalid withdrawal amount. Please enter a positive value.")
        else:
            self.atm.withdraw(withdraw_amount)
            self.mini_statement.append(f"Withdrawn: {withdraw_amount}")
            print(f"Updated Balance: {self.atm.get_balance()}")

    def deposit_amount(self, deposit_amount):
        self.atm.deposit(deposit_amount)
        if deposit_amount > 0:
            self.mini_statement.append(f"Deposited: {deposit_amount}")
            print(f"Updated Balance: {self.atm.get_balance()}")

    def view_mini_statement(self):
        print("Mini Statement:")
        for entry in self.mini_statement:
            print(entry)


def main():
    atm_operations = AtmOperations()

    while True:
        print("\nATM Menu:")
        print("1. View Balance")
        print("2. Withdraw Amount")
        print("3. Deposit Amount")
        print("4. View Mini Statement")
        print("5. Exit")
        
        choice = input("Enter your choice: ")

        if choice == '1':
            atm_operations.view_balance()
        elif choice == '2':
            withdraw_amount = float(input("Enter amount to withdraw: "))
            atm_operations.withdraw_amount(withdraw_amount)
        elif choice == '3':
            deposit_amount = float(input("Enter amount to deposit: "))
            atm_operations.deposit_amount(deposit_amount)
        elif choice == '4':
            atm_operations.view_mini_statement()
        elif choice == '5':
            print("Thank you for using the ATM.")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()