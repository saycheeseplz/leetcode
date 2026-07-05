public abstract class Employee implements IEmployee {
    private String name;
    private int paymentPerHour;

    public Employee(String name, int paymentPerHour) {
        this.name = name;
        this.paymentPerHour = paymentPerHour;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String getName() {
        return name;
    }

    public void setPaymentPerHour(int pay) {
        this.paymentPerHour = pay;
    }

    public int getPaymentPerHour() {
        return paymentPerHour;
    }

    @Override
    public abstract int calculateSalary();

}
