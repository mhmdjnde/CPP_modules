#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }
    std::map<std::string, double> db = read_db();
    if (db.empty()) {
        std::cerr << "Error: database is empty.\n";
        return 1;
    }
    
    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }
    
    std::string line;
    while (std::getline(input_file, line)) {
        process_line(db, line);
    }
    return 0;
}
