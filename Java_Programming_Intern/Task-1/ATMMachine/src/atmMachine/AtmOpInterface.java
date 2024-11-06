package atmMachine;

public interface AtmOpInterface {
    void viewBalance();
    void withdrawAmount(double withdrawAmount);
    void depositAmount(double depositAmount);
    void viewMiniStatement();
}
