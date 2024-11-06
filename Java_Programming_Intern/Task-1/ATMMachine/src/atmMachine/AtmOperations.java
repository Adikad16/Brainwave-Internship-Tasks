package atmMachine;

import java.util.HashMap;
import java.util.Map;

public class AtmOperations implements AtmOpInterface {
    private ATM atm = new ATM();
    private Map<String, Double> miniStatement = new HashMap<>();

    @Override
    public void viewBalance() {
        System.out.println("Current Balance: " + atm.getBalance());
    }

    @Override
    public void withdrawAmount(double withdrawAmount) {
        if (withdrawAmount <= 0) {
            System.out.println("Invalid withdrawal amount. Please enter a positive value.");
        } else {
            atm.withdraw(withdrawAmount);
            miniStatement.put("Withdrawn", withdrawAmount);
            // Display updated balance after withdrawal
            System.out.println("Updated Balance: " + atm.getBalance());
        }
    }

    @Override
    public void depositAmount(double depositAmount) {
        atm.deposit(depositAmount);
        if (depositAmount > 0) { // Only add to mini statement if the deposit was valid
            miniStatement.put("Deposited", depositAmount);
            // Display updated balance after deposit
            System.out.println("Updated Balance: " + atm.getBalance());
        }
    }

    public void viewMiniStatement() {
        System.out.println("Mini Statement:");
        for (Map.Entry<String, Double> entry : miniStatement.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}