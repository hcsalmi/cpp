#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{

}

BitcoinExchange::~BitcoinExchange()
{

}

void    BitcoinExchange::calculateAndPrint(long double inputValue, long double dbPrice)
{
    //yks kertaa toinen
    //pyorista
    //printtaa stardard outille
}

long double BitcoinExchange::findMatchInDatabase(std::string date)
{
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    int minYear = std::stoi(_minDate.substr(0, 4)); // tulee vasta kun etsitaan input filen perusteella vastaavuutta
    int minMonth = std::stoi(_minDate.substr(5, 2));
    int minDay = std::stoi(_minDate.substr(8, 2));
    
//    if (year <= minYear && month <= minMonth && )
    //katso ensin onko exact match
    //funktio joka etsii mapista onko sita keyta -> palauttaa npos jos ei ole?
    //jos ei, niin etsi edellinen (vrt. vuosi, kuukausi, paiva). Juoksuta alaspain kk, pva, vuosi kunnes loytyy?
    //Paitsi jos ei olemassa vanhempaa (vrt. _minDate), palauta -1 tms.
    //muuten palauta arvo
}

void    BitcoinExchange::handleInputOutput(filename)
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

    std::regex format([0-9]{4}-[0-9]{2}-[0-9]{2} \\| ([0-9]+)(\\.[0-9]+)?);
    while (getline(file, line))
    {
        std::smatch match;
		if (std::regex_match(line, match, format))
		{
            std::string date = match[1].str();
            long double inputValue = stold(match[2].str());
            if (!validateDate(date))
                throw InputFileErrorException();
            if (inputValue > 1000)
                throw InputFileErrorException();
            long double dbPrice = findMatchInDatabase(date);
            calculateAndPrint(inputValue, dbPrice);
        }
        else
            throw InputFileErrorException();
    }
}

bool checkForLeapYear(int year)
{
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return (true);
	return (false);
}

bool    BitcoinExchange::validateDate(std::string date)
{
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 0 || month > 12)
        return (false);
    if (checkForLeapYear(year) == true)
		months[1] = 29;
    if (daysInMonth[month - 1] > day)
        return (false);
    return (true);
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
    std::regex format([0-9]{4}-[0-9]{2}-[0-9]{2},([0-9]+)(\\.[0-9]+)?)
    while (getline(file, line))
    {
        std::smatch match;
		if (std::regex_match(line, match, format))
		{
            std::string date = match[1].str();
            long double value = stold(match[2].str());
            if (!validateDate(date))
                 throw DatabaseErrorException();
            if (minDateFlag == false)
            {
                _minDate = date;
                minDateFlag = true;
            }
            _database[date] = value;
        }
        else
            throw DatabaseErrorException();
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
