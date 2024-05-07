#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    this->_database = src._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        this->_database = src._database;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

void    BitcoinExchange::calculateAndPrint(long double inputValue, long double dbPrice)
{
    std::cout << inputValue << " = " << inputValue * dbPrice << std::endl;
}

bool checkForLeapYear(int year)
{
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return (true);
	return (false);
}

std::tm BitcoinExchange::stringToTm(const std::string &date)
{
    std::tm tm = {};
    std::istringstream iss(date);
    iss >> std::get_time(&tm, "%Y-%m-%d");
    return (tm);
}

bool    BitcoinExchange::isInTheFuture(const std::string &date)
{
    std::tm dateAsTm = stringToTm(date);
    std::time_t currentTime = std::time(nullptr);

    std::tm *currentTm = std::localtime(&currentTime);

    if (std::mktime(currentTm) - std::mktime(&dateAsTm) < 0)
    {
        return (true);
    }
    return (false);
}

bool    BitcoinExchange::validateDate(const std::string &date)
{
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 0 || month > 12)
        return (false);
    if (checkForLeapYear(year) == true)
		daysInMonth[1] = 29;
    if (day > daysInMonth[month - 1])
        return (false);
    return (true);
}

long double BitcoinExchange::findMatchInDatabase(const std::string &date)
{
    std::tm dateAsTm = stringToTm(date);
    std::tm firstEntry = stringToTm(this->_minDate);
    if (std::mktime(&dateAsTm) < std::mktime(&firstEntry))
    {
        std::cout << "Error: no earlier entry in database" << std::endl;
        return (-1);
    }
    
    std::string match;
    long double value;
    for (auto it = this->_database.begin(); it != this->_database.end(); ++it)
    {
        std::tm databaseDate = stringToTm(it->first);
        if (std::mktime(&databaseDate) <= std::mktime(&dateAsTm))
        {
            match = it->first;
            value = it->second;
        }
        else
            break ;
    }
    std::cout << match << " => ";
    return (value);
}

void    BitcoinExchange::handleInputOutput(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.bad() || file.fail())
       throw InputFileErrorException();

    std::string line;
    if (!std::getline(file, line))
    {
        file.close();
        throw InputFileErrorException();
    }
    if (line != "date | value")
    {
        file.close();
        throw InputFileErrorException();
    }

    std::regex format("([0-9]{4}-[0-9]{2}-[0-9]{2}) \\| ([0-9]+(?:\\.[0-9]+)?)");
    while (getline(file, line))
    {
        std::smatch match;
		if (std::regex_match(line, match, format))
		{
            std::string date = match[1].str();
            long double inputValue = stold(match[2].str());

            if (!validateDate(date))
            {
                std::cout << "Error: invalid date" << std::endl;
                continue ;
            }
            if (inputValue > 1000)
            {
                std::cout << "Error: value exceeds maximum" << std::endl;
                continue ;
            }
            long double dbPrice = findMatchInDatabase(date);
            if (dbPrice < 0)
                continue ;
            calculateAndPrint(inputValue, dbPrice);
        }
        else
            std::cout << "Error: value negative or line invalid format" << std::endl;;
    }

}

void    BitcoinExchange::readDatabase()
{
    std::ifstream file("./data.csv");
    if (file.bad() || file.fail())
       throw DatabaseErrorException();
    
    std::string line;
    if (!std::getline(file, line))
    {
        file.close();
        throw DatabaseErrorException();
    }
    if (line != "date,exchange_rate")
    {
        file.close();
        throw DatabaseErrorException();
    }
    
    bool minDateFlag = false;
    std::regex format("([0-9]{4}-[0-9]{2}-[0-9]{2}),([0-9]+(?:\\.[0-9]+)?)");

    while (getline(file, line))
    {
        std::smatch match;
		if (std::regex_match(line, match, format))
		{
            std::string date = match[1].str();
            long double value = stold(match[2].str());
            if (!validateDate(date))
                 throw InvalidContentException();
            if (isInTheFuture(date) == true)
                throw InvalidContentException();
            if (minDateFlag == false)
            {
                _minDate = date;
                minDateFlag = true;
            }
            _database[date] = value;
        }
        else
            throw InvalidContentException();
    }
}

void BitcoinExchange::handleExchange(std::string filename)
{
	try
	{
		readDatabase();
		handleInputOutput(filename);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
