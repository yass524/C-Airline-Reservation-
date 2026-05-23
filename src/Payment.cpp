#include <string>
#include <iostream>
#include "include/Payment.hpp"


Payment::Payment()
    : paymentId(0),
      reservationId(0),
      amount(0.0),
      status("Pending") {}

Payment::Payment(int paymentId,
                 int reservationId,
                 double amount,
                 const std::string& paymentMethod,
                 const std::string& transactionDate)
    : paymentId(paymentId),
      reservationId(reservationId),
      amount(amount),
      paymentMethod(paymentMethod),
      status("Pending"),
      transactionDate(transactionDate) {}

int Payment::getPaymentId() const {
    return paymentId;
}
int Payment::getReservationId() const {
    return reservationId;
}
double Payment::getAmount() const {
    return amount;
}
std::string Payment::getPaymentMethod() const {
    return paymentMethod;
}
std::string Payment::getStatus() const {
    return status;
}
std::string Payment::getTransactionDate() const {
    return transactionDate;
}

void Payment::setAmount(double amount){
    this->amount = amount;
}
void Payment::setPaymentMethod(const std::string& paymentMethod) {
    this->paymentMethod = paymentMethod;
}
void Payment::setStatus(const std::string& status) {
    this->status = status;
}
bool Payment::processPayment() {
    // Simulate payment processing logic
    setStatus("Completed");
    return true; 
}
bool Payment::processRefund() {
    
    setStatus("Refunded");
    return true; 
}
bool Payment::isCompleted() const {
    return status == "Completed";
}
bool Payment::isRefunded() const {
    return status == "Refunded";
}

void Payment::displayInfo() const {
    std::cout << "Payment ID: " << paymentId << std::endl;
    std::cout << "Reservation ID: " << reservationId << std::endl;
    std::cout << "Amount: $" << amount << std::endl;
    std::cout << "Payment Method: " << paymentMethod << std::endl;
    std::cout << "Status: " << status << std::endl;
    std::cout << "Transaction Date: " << transactionDate << std::endl;
}