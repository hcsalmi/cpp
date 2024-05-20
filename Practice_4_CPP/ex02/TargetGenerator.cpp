#include "TargetGenerator.hpp"


TargetGenerator::TargetGenerator()
{

}

TargetGenerator::~TargetGenerator()
{
    for (std::map<std::string, ATarget *>::iterator it = _targets.begin(); it != _targets.end(); it++)
    {
        delete it->second;
    }
    _targets.clear();
}

void  TargetGenerator::learnTargetType(ATarget *target)
{
    if (target)
    {
        if (_targets.find(target->getType()) == _targets.end())
            _targets.insert(std::make_pair(target->getType(), target->clone()));
    }
}

void  TargetGenerator::forgetTargetType(std::string const &target)
{
    std::map<std::string, ATarget *>::iterator it = _targets.find(target);

    if (it != _targets.end())
    {
        delete it->second;
        _targets.erase(target);
    }
}

ATarget*  TargetGenerator::createTarget(std::string const &target)
{
    std::map<std::string, ATarget *>::iterator it = _targets.find(target);

    if (it != _targets.end())
        return _targets[target];

    return (NULL);
}
