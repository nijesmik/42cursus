#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
private:
    std::string name;
    std::string effects;

public:
    std::string getName() const;
    std::string getEffects() const;
    virtual ASpell *clone() const = 0;
    ASpell(std::string const &name, std::string const &effects);
    virtual ~ASpell();
    void launch(ATarget const &target) const;
};
