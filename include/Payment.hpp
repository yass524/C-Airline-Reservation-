#pragma once

#include <string>

class Payment {
private:
    int paymentId;
    int reservationId;
    double amount;
    std::string paymentMethod;
    std::string status;
    std::string transactionDate;

public:
    Payment();

    Payment(int paymentId,
            int reservationId,
            double amount,
            const std::string& paymentMethod,
            const std::string& transactionDate);

    int getPaymentId() const;
    int getReservationId() const;
    double getAmount() const;
    std::string getPaymentMethod() const;
    std::string getStatus() const;
    std::string getTransactionDate() const;

    void setAmount(double amount);
    void setPaymentMethod(const std::string& paymentMethod);
    void setStatus(const std::string& status);

    bool processPayment();
    bool processRefund();

    bool isCompleted() const;
    bool isRefunded() const;

    void displayInfo() const;
};