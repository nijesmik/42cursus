#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
    : name(name), title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

std::string const &Warlock::getName() const
{
    return name;
}

std::string const &Warlock::getTitle() const
{
    return title;
}

void Warlock::setTitle(std::string const &str)
{
    title = str;
}

void Warlock::learnSpell(ASpell *spell)
{
    spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string const &spellName)
{
    spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string const &spellName, ATarget const &target)
{
    ASpell *spell = spellBook.createSpell(spellName);
    if (spell)
    {
        spell->launch(target);
    }
}