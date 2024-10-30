#include <iostream>
#include <string>
#include <cmath>

/**
 * A struct for holding information about a car.
 */
struct Car {
    /**
     * The make (brand) of the car.
     */
    std::string make;
    
    /**
     * The model of the car.
     */
    std::string model;

    /**
     * The year the car was made.
     */
    int year;

    /**
     * The current value of the car in dollars.
     */
    float price_dollars;

    /**
     * Whether the car is used.
     */
    bool used = false;
};

/**
 * Calculate the value of the car at some point in the future.
 * @param  car The car to calculate the value of.
 * @param  years_from_now The number of years out to estimate the value.
 * @return  The estimated value.
 * 
 * Calculate the value using value = price_now * e^(-r * t) where r is the depreciation
 * rate and t is the years_from_now. Let's say Mercedes cars have a depreciation of 15%
 * or 0.15, and Teslas have a depreciation of 25% or 0.25. All other cars have a rate of
 * 20% or 0.20.
 */
float calculateCarValue(Car car, float years_from_now) {
    float depreciation;
    float x = 2.718281828459045;
    // *** Task: Implement this function *** //
    if (car.make == "Mercedes") {
        depreciation = 0.15;
        return car.price_dollars * pow(x,(-depreciation*years_from_now));
    }
    else if (car.make == "Tesla") {
        depreciation = 0.25;
        return car.price_dollars * pow(x,(-depreciation*years_from_now));
    }
    else {
        depreciation = 0.20;
        return car.price_dollars * pow(x,(-depreciation*years_from_now));
    }

    
   
    

    // *** End Student Code *** //
}

int main() {

    // *** Task: Collect information about the car then calculate its value with calculate_car_value() *** //
    Car car;
    float years_from_now;
    std::cout << "Enter the car make: ";
    std::cin >> car.make ;
    std::cout << "Enter the car model: ";
    std::cin >> car.model;
    std::cout << "Enter the car year: ";
    std::cin >> car.year;
    std::cout << "Enter the car price: ";
    std::cin >> car.price_dollars;
    std::string myString = "";
    std::cout<< "Is the car used? (True/False) ";
    std::cin >> myString;
    if (myString=="True") {
        car.used = true;
    }
    else {
        car.used = false;
    }
    
    std::cout << "How many years from now do you want to estimate the value? ";
    std::cin >> years_from_now;

    float value = calculateCarValue (car, years_from_now);

    std::cout << "The estimated value of the car is $" << value << std::endl;

    // *** End Student Code *** //

    return 0;
}