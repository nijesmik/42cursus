#include "TargetGenerator.hpp"

void TargetGenerator::learnTargetType(ATarget *target)
{
    map[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const &target)
{
    if (map.find(target) != map.end())
    {
        map.erase(target);
    }
}

ATarget *TargetGenerator::createTarget(std::string const &target)
{
    if (map.find(target) != map.end())
    {
        return map[target];
    }
    return NULL;
}

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}