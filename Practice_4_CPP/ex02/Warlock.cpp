#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : name(name), title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
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
    _spellbook.learnSpell(spell);
}

void    Warlock::forgetSpell(std::string name)
{
   _spellbook.forgetSpell(name);
}

void    Warlock::launchSpell(std::string spellname, ATarget &target)
{
    ASpell *temp = _spellbook.createSpell(spellname);

    if (temp)
        temp->launch(target);
}
