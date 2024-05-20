#include "ATarget.hpp"

ATarget::ATarget()
{

}

ATarget::ATarget(const std::string &type) : type(type)
{

}

ATarget::ATarget(const ATarget &src) : type(src.type)
{

}

ATarget &ATarget::operator=(const ATarget &src)
{
    if (this != &src)
        this->type = src.type;
    return (*this);
}

ATarget::~ATarget()
{

}

std::string ATarget::getType() const
{
    return type;
}

void    ATarget::getHitBySpell(const ASpell &spell) const
{
    std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}

