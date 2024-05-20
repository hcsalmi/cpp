#include "ASpell.hpp"

ASpell::ASpell()
{

}

ASpell::ASpell(const std::string &name, const std::string effects) : name(name), effects(effects)
{

}

ASpell::ASpell(const ASpell &src) : name(src.name), effects(src.effects)
{

}

ASpell &ASpell::operator=(const ASpell &src)
{
    if (this != &src)
    {
        this->name = src.name;
        this->effects = src.effects;
    }
    return (*this);
}

ASpell::~ASpell()
{

}

std::string ASpell::getName() const
{
    return (name);
}

std::string ASpell::getEffects() const
{
    return (effects);
}

void    ASpell::launch(const ATarget &target) const
{
    target.getHitBySpell(*this);
}
