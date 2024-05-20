#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : name(name), title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
    for (std::map<std::string, ASpell *>::iterator it = _spellbook.begin(); it != _spellbook.end(); it++)
    {
        delete it->second;
    }
    _spellbook.clear();
}

const std::string &Warlock::getName() const
{
    return (name);
}

const std::string &Warlock::getTitle() const
{
    return(title);
}

void    Warlock::setTitle(const std::string &title)
{
    this->title = title;
}

void Warlock::introduce() const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void    Warlock::learnSpell(ASpell *spell)
{
    if (spell)
        if (_spellbook.find(spell->getName()) == _spellbook.end())
            _spellbook.insert(std::make_pair(spell->getName() ,spell->clone()));
}

void    Warlock::forgetSpell(std::string name)
{
    std::map<std::string, ASpell *>::iterator it = _spellbook.find(name);

    if (it != _spellbook.end())
    {
        delete (it->second);
        _spellbook.erase(name);
    }
}

void    Warlock::launchSpell(std::string spellname, ATarget &target)
{
    ASpell *temp = _spellbook[spellname];

    if (temp)
        temp->launch(target);
}
