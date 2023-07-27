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
    in.read_header(io::ignore_extra_column, "Close","Open","Volume","Date");
    double adj_close;
    while (in.read_row(adj_price)) {
        adj_prices.push_back(adj_price);
    }

//Logarithmic returns
std::vector<double> log_returns;
    for (size_t i = 1; i < adj_prices.size(); ++i) {
        double log_return = std::log(adj_prices[i]) - std::log(adj_prices[i - 1]);
        log_returns.push_back(log_return);
    }

// Calculate the mean of the vector made previously
double mean(const vector<double>& adj_close) {
    double total = 0.0;
    for (double value : adj_close) {
        total += value;
    }
    return total / static_cast<double>(data.size()); //converting the adj_close to double using static_cast
}

// Calculate the standard deviation of the vector 
double standardDeviation(const vector<double>& data) {
    double meanValue = mean(data);
    double total = 0.0;
    //value refers to the adj_close
    for (double value : data) {
        double diff = value - meanValue;
        total += diff * diff;
    }
    return sqrt(total / static_cast<double>(data.size() - 1));
}




// Function to test for cointegration using Augmented dick Fuller method
bool testForCointegration(const vector<double>& "Mastercard data.numbers", const vector<double>& "Visa data.numbers") {
    // ... (Same as before)
}

bool adfTest(const vector<double>& series) {
    // Calculate the first differences of the series
    vector<double> differences = calculateFirstDifferences(series);

    // Calculate the ADF test statistic
    double n = static_cast<double>(differences.size());
    double sumDifferences = 0.0;
    for (double diff : differences) {
        sumDifferences += diff;
    }
    double meanDifferences = sumDifferences / n;
    double varianceDifferences = variance(differences);
    double adfStat = (meanDifferences - 0.0) / sqrt(varianceDifferences / n);


    // Compare the ADF test statistic with the critical value
    return adfStat < criticalValue;
}

int main() {
    // Sample data for demonstration (replace with your own data)
    vector<double> stockPrices = {100.0, 102.0, 105.0, 108.0, 110.0, 112.0};

    // Check for stationarity using ADF test
    if (adfTest(stockPrices)) {
        cout << "The stock prices are likely stationary." << endl;
    } else {
        cout << "The stock prices are likely non-stationary." << endl;
    }

    return 0;
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
    vector<double> mastercardPrices = readDataFromFile("Mastercard data.numbers");

    // Check if data was loaded successfully
    if (mastercardPrices.empty()) {
        cerr << "Error: Could not load data from the CSV file." << endl;
        return 1;
    }

int main() {
    vector<double> visaPrices = readDataFromFile("Visa data.numbers");

    // Checking if data was loaded successfully
    if (VisaPrices.empty()) {
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
