#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ql/quantlib.hpp> // Include the QuantLib library
#include "csv.h" //including csv parser header
#include <cmath>

//csv parser 
//Quant Lib is a library used for modeling, trading
using namespace QuantLib;
using namespace std;

int main() {
    io::CSVReader<1> in("Mastercard data.numbers");
//creating a vector to store the adj close, so we can access it    
    std::vector<double> adj_prices;  
    in.read_header(io::ignore_extra_column, "Close","Open",Volume","Date");
    double adj_close;
    while (in.read_row(adj_price)) {
        close_prices.push_back(adj_price);
    }

//to find the logarithmic returns
std::vector<double> log_returns;
    for (size_t i = 1; i < adj_prices.size(); ++i) {
        double log_return = std::log(adj_prices[i]) - std::log(adj_prices[i - 1]);
        log_returns.push_back(log_return);
    }


// Function to calculate the logarithmic returns of a price series
vector<double> calculateLogReturns(const vector<double>& prices) {
    // ... (Same as before)
}

// Function to perform the Augmented Dickey-Fuller (ADF) test for stationarity
bool adfTest(const vector<double>& series) {
    // Perform the ADF test to check for stationarity
    // You can implement the ADF test using statistical libraries or custom code
    // Return true if the series is stationary, false otherwise
}

// Function to test for cointegration using Augmented dick Fuller method
bool testForCointegration(const vector<double>& series1, const vector<double>& series2) {
    // ... (Same as before)
}

vector<double> readDataFromFile(const string& filename) {
    vector<double> prices;
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        return prices;
    }

    string line;
    getline(inputFile, line); // Skip header line (assuming CSV has a header)

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string dateStr, closeStr;
        getline(ss, dateStr, ',');
        getline(ss, closeStr, ',');
        double price = stod(closeStr);
        prices.push_back(price);
    }

    return prices;
}

int main() {
    // Load historical price data for Mastercard and Visa stocks from Yahoo Finance CSV file
    vector<double> mastercardPrices = readDataFromFile("yahoo_finance_data.csv");

    // Check if data was loaded successfully
    if (mastercardPrices.empty()) {
        cerr << "Error: Could not load data from the CSV file." << endl;
        return 1;
    }

    // Since we are using a single CSV file, let's assume the "Visa" data is in the same file.
    // You can repeat the same process for reading Visa data from a different CSV file.

    // Check for cointegration with Visa stock data
    if (testForCointegration(mastercardPrices, visaPrices)) {
        cout << "Cointegration exists between Mastercard and Visa stocks." << endl;
    } else {
        cout << "Cointegration does not exist between Mastercard and Visa stocks." << endl;
    }

    return 0;
}
