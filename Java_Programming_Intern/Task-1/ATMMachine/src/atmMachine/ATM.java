package atmMachine;

public class ATM {
    private double balance = 10000; // Initial balance

    public double getBalance() {
        return balance;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Successfully deposited: " + amount);
        } else {
            System.out.println("Invalid deposit amount. Please enter a positive value.");
        }
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Invalid withdrawal amount. Please enter a positive value.");
        } else if (amount > balance) {
            System.out.println("Insufficient balance. You cannot withdraw more than " + balance);
        } else {
            balance -= amount;
            System.out.println("Successfully withdrew: " + amount);
        }
    }
}