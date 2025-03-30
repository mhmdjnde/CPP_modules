#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>

std::map<std::string, double> read_db();
void process_line(const std::map<std::string, double>& db, const std::string& line);
#endif
