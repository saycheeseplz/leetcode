// ❌ Trước
void processOrder() {
    validate();
    calculateTotal();
    printInvoice();
}

// ✅ Sau (tách rõ)
void processOrder() {
    validateOrder();
    calculateOrderTotal();
    printInvoice();
}