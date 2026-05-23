#include <string>
#include <iostream>
#include "include/Reservation.hpp"


Reservation::Reservation()
    : reservationId(0),
      passengerId(0),
      flightId(0),
      status("Pending"),
      paymentId(0) {}

Reservation::Reservation(int reservationId,
                         int passengerId,
                         int flightId,
                         const std::string& seatNumber,
                         const std::string& seatClass,
                         int paymentId,
                         const std::string& bookingDate)
    : reservationId(reservationId),
      passengerId(passengerId),
      flightId(flightId),
      seatNumber(seatNumber),
      seatClass(seatClass),
      status("Pending"),
      paymentId(paymentId),
      bookingDate(bookingDate) {}

int Reservation::getReservationId() const {
    return reservationId;
}
int Reservation::getPassengerId() const {
    return passengerId;
}
int Reservation::getFlightId() const {  
    return flightId;
}
std::string Reservation::getSeatNumber() const {
    return seatNumber;
}
std::string Reservation::getSeatClass() const {
    return seatClass;
}
std::string Reservation::getStatus() const {
    return status;
}
int Reservation::getPaymentId() const {
    return paymentId;
}
std::string Reservation::getBookingDate() const {
    return bookingDate;
}

void Reservation::setSeatNumber(const std::string& seatNumber) {
    this->seatNumber = seatNumber;
}
void Reservation::setSeatClass(const std::string& seatClass) {
    this->seatClass = seatClass;
}
void Reservation::setStatus(const std::string& status) {
    this->status = status;
}
void Reservation::setPaymentId(int paymentId) {
    this->paymentId = paymentId;
}

void Reservation::confirm() {
    status = "Confirmed";
}
void Reservation::cancel() {
    status = "Cancelled";
}
void Reservation::markWaitlisted() {
    status = "Waitlisted";
}
void Reservation::markCheckedIn() {
    status = "Checked-In";
}

bool Reservation::isConfirmed() const{
    return status == "Confirmed";  
}
bool Reservation::isCancelled() const {
    return status == "Cancelled";
}
bool Reservation::isCheckedIn() const {
    return status == "Checked-In";
}

void Reservation::displayInfo() const {
    std::cout << "Reservation ID: " << reservationId << std::endl;
    std::cout << "Passenger ID: " << passengerId << std::endl;
    std::cout << "Flight ID: " << flightId << std::endl;
    std::cout << "Seat Number: " << seatNumber << std::endl;
    std::cout << "Seat Class: " << seatClass << std::endl;
    std::cout << "Status: " << status << std::endl;
    std::cout << "Payment ID: " << paymentId << std::endl;
    std::cout << "Booking Date: " << bookingDate << std::endl;
}