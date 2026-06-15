public interface PaymentProcessor {
    void processPayment(double amount);
}

public class PayPalService {

    public void sendPayment(double amount) {
        System.out.println("Paid " + amount + " using PayPal");
    }
}

public class PayPalAdapter implements PaymentProcessor {

    private PayPalService payPalService;

    public PayPalAdapter(PayPalService payPalService) {
        this.payPalService = payPalService;
    }

    @Override
    public void processPayment(double amount) {
        payPalService.sendPayment(amount);
    }
}
