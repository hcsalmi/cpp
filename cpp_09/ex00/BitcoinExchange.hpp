#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <regex>
#include <fstream>

class BitcoinExchange
{
    private:
        std::map<std::string, long double>  _database;
        std::string                         _minDate;

        void        handleExchange(std::string filename);
        void        readDatabase();
        void        handleInputOutput(filename);
        bool        validateDate(std::string date);
        long double findMatchInDatabase(std::string date);
        void        calculateAndPrint()

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);

        ~BitcoinExchange();

        
    class DatabaseErrorException : public std::exception {
			public:
				const char *what(void) const throw() { return "Datafile error: failed to read data, file empty or invalid format"; }
		};

    class InputFileErrorException : public std::exception {
			public:
				const char *what(void) const throw() { return "Input file error: failed to read data, file empty or invalid format"; }
		};
};



#endif