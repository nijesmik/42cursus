#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
private:
    std::string type;

public:
    std::string const &getType() const;
    ATarget(std::string const &type);
    virtual ATarget *clone() const = 0;
    virtual ~ATarget();
    void getHitBySpell(ASpell const &spell) const;
};