#pragma once

#include <string>

class Reservation {
private:
    int reservationId;
    int passengerId;
    int flightId;
    std::string seatNumber;
    std::string seatClass;
    std::string status;
    int paymentId;
    std::string bookingDate;

public:
    Reservation();

    Reservation(int reservationId,
                int passengerId,
                int flightId,
                const std::string& seatNumber,
                const std::string& seatClass,
                int paymentId,
                const std::string& bookingDate);

    int getReservationId() const;
    int getPassengerId() const;
    int getFlightId() const;
    std::string getSeatNumber() const;
    std::string getSeatClass() const;
    std::string getStatus() const;
    int getPaymentId() const;
    std::string getBookingDate() const;

    void setSeatNumber(const std::string& seatNumber);
    void setSeatClass(const std::string& seatClass);
    void setStatus(const std::string& status);
    void setPaymentId(int paymentId);

    void confirm();
    void cancel();
    void markWaitlisted();
    void markCheckedIn();

    bool isConfirmed() const;
    bool isCancelled() const;
    bool isCheckedIn() const;

    void displayInfo() const;
};