#include <iostream>
#include <gtest/gtest.h>


#include <string>

// Abstract Vehicle class
class Vehicle {
public:
    virtual void drive() = 0;  // Pure virtual method
};

// Concrete Vehicle classes
class Car : public Vehicle {
public:
    void drive() override {
        std::cout << "Driving a Car!" << std::endl;
    }
};

class Bike : public Vehicle {
public:
    void drive() override {
        std::cout << "Riding a Bike!" << std::endl;
    }
};

class Truck : public Vehicle {
public:
    void drive() override {
        std::cout << "Driving a Truck!" << std::endl;
    }
};

// VehicleFactory class
class VehicleFactory {
public:
    Vehicle* createVehicle(const std::string& vehicleType) {
        if (vehicleType == "Car") {
            return new Car();
        } else if (vehicleType == "Bike") {
            return new Bike();
        } else if (vehicleType == "Truck") {
            return new Truck();
        }
        return nullptr;  // Unknown vehicle type
    }
};


// Test to check that Car is created and behaves correctly
TEST(VehicleFactoryTest, CreateCar) {
    VehicleFactory factory;
    Vehicle* vehicle = factory.createVehicle("Car");
    testing::internal::CaptureStdout();
    vehicle->drive();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Driving a Car!\n");
    delete vehicle; // Don't forget to delete the dynamically allocated vehicle
}

// Test to check that Bike is created and behaves correctly
TEST(VehicleFactoryTest, CreateBike) {
    VehicleFactory factory;
    Vehicle* vehicle = factory.createVehicle("Bike");
    testing::internal::CaptureStdout();
    vehicle->drive();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Riding a Bike!\n");
    delete vehicle;
}

// Test to check that Truck is created and behaves correctly
TEST(VehicleFactoryTest, CreateTruck) {
    VehicleFactory factory;
    Vehicle* vehicle = factory.createVehicle("Truck");
    testing::internal::CaptureStdout();
    vehicle->drive();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Driving a Truck!\n");
    delete vehicle;
}


