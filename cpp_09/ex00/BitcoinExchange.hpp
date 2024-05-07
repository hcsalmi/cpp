#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <regex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ctime>

class BitcoinExchange
{
    private:
        std::map<std::string, long double>  _database;
        std::string                         _minDate;

        void        readDatabase();
        void        handleInputOutput(const std::string &filename);
        bool        validateDate (const std::string &date);
        std::tm     stringToTm(const std::string &date);
        bool        isInTheFuture(const std::string &date);
        long double findMatchInDatabase(const std::string &date);
        void        calculateAndPrint(long double inputValue, long double dbPrice);


    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();

        void        handleExchange(std::string filename);

        
    class DatabaseErrorException : public std::exception {
			public:
				const char *what(void) const throw() { return "Datafile error: failed to read data, file empty or invalid header"; }
		};
    
    class InputFileErrorException : public std::exception {
			public:
				const char *what(void) const throw() { return "Input file error: failed to read data, file empty or invalid header"; }
		};

    class InvalidContentException : public std::exception {
			public:
				const char *what(void) const throw() { return "Datafile error: data format incorrect or date in the future"; }
		};

};

#endif