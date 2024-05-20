#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{
    for (std::map<std::string, ASpell *>::iterator it = _spells.begin(); it != _spells.end(); it++)
    {
       delete it->second;
    }
    _spells.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
    {
        if (_spells.find(spell->getName()) == _spells.end())
            _spells.insert(std::make_pair(spell->getName(), spell->clone()));
    }
}

void SpellBook::forgetSpell(std::string const &spell)
{
    std::map<std::string, ASpell *>::iterator it = _spells.find(spell);

    if (it != _spells.end())
    {
        delete it->second;
        _spells.erase(spell);
    }
}

ASpell* SpellBook::createSpell(std::string const &spell)
{
  std::map<std::string, ASpell *>::iterator it = _spells.find(spell);

    if (it != _spells.end())
        return _spells[spell];

    return (NULL);
}
