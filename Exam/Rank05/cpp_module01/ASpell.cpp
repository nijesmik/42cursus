#include "ASpell.hpp"

std::string ASpell::getName() const
{
    return name;
}

std::string ASpell::getEffects() const
{
    return effects;
}

ASpell::~ASpell() {}

ASpell::ASpell(std::string const &name, std::string const &effects)
    : name(name), effects(effects)
{
}

void ASpell::launch(ATarget const &target) const
{
    target.getHitBySpell(*this);
}
