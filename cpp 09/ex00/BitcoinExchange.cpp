#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <cstring>

#include <string>
#include <cstdlib>
#include <cstring>

int is_valid_date(const std::string& date)
{
    char yearStr[5] = {0};
    char monthStr[3] = {0};
    char dayStr[3] = {0};

    if (date.length() != 10)
        return 0;
    if (date[4] != '-' || date[7] != '-')
        return 0;

    std::strncpy(yearStr, date.c_str(), 4);
    int year = std::atoi(yearStr);
    if (year < 1)
        return 0;

    std::strncpy(monthStr, date.c_str() + 5, 2);
    int month = std::atoi(monthStr);
    if (month < 1 || month > 12)
        return 0;

    std::strncpy(dayStr, date.c_str() + 8, 2);
    int day = std::atoi(dayStr);
    if (day < 1 || day > 31)
        return 0;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return 0;

    if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 29 || (day == 29 && !isLeapYear))
            return 0;
    }
    return 1;
}


std::map<std::string, double> read_db() {
    std::map<std::string, double> db;
    std::ifstream file("data.csv");
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file 'data.csv'.\n";
        return db;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            if (!is_valid_date(date))
                continue;
            
            std::string priceStr = line.substr(commaPos + 1);
            double price = std::atof(priceStr.c_str());
            if (price < 0)
                continue;
            db[date] = price;
        }
    }
    return db;
}

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, last - first + 1);
}

void process_line(const std::map<std::string, double>& db, const std::string& line)
{
    if (line.empty() || line == "date | value")
        return;

    size_t pipePos = line.find("|");
    if (pipePos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date = trim(line.substr(0, pipePos));
    if (!is_valid_date(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    std::string valueStr = trim(line.substr(pipePos + 1));
    if (valueStr.empty())
    {
        std::cerr << "Error: invalid value\n";
        return;
    }

    for (size_t i = 0; i < valueStr.length(); i++)
    {
        if (!isdigit(valueStr[i]) && valueStr[i] != '.' && valueStr[i] != '-') {
            std::cerr << "Error: invalid value\n";
            return;
        }
    }

    double value = std::atof(valueStr.c_str());
    if (value < 0) {
        std::cerr << "Error: not a positive number.\n";
        return;
    }
    if (value > 1000) {
        std::cerr << "Error: too large a number.\n";
        return;
    }

    std::map<std::string, double>::const_iterator it = db.lower_bound(date);
    if (it == db.begin() && it->first != date)
    {
        std::cerr << "Error: no data available for this date.\n";
        return;
    }
    if (it == db.end() || it->first != date)
        --it;
    
    double result = value * it->second;
    std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
}
