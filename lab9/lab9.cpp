#include <iostream>
using namespace std;

class TemperatureConverter {
    private:
        double kelvin_;
    public:
        TemperatureConverter() {
            kelvin_ = 0;
        }
        TemperatureConverter(double kelvin) {
            kelvin_ = kelvin;
        }
        void SetTempFromKelvin(double kelvin) {
            kelvin_ = kelvin;
        }
        double GetTempFromKelvin() {
            return kelvin_;
        }
        void SetTempFromCelsius(double celsius) {
            kelvin_ = celsius + 273.15;
        }
        void SetTempFromFahrenheit(double fahrenheit) {
            kelvin_ = (fahrenheit - 32) * 5 / 9 + 273.15;
        }
        double GetTempAsCelsius() {
            return kelvin_ - 273.15;
        }
        double GetTempAsFahrenheit() {
            return (kelvin_ - 273.15) * 9 / 5 + 32;
        }
        void PrintTemperatures() {
            cout << "Kelvin: " << GetTempFromKelvin() << endl << "Celsius: " << GetTempAsCelsius() << endl << "Fahrenheit: " << GetTempAsFahrenheit() << endl;
        }
};