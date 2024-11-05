#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
    : name(name), title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}


Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
    for (std::map<std::string, ASpell *>::iterator it = spellBook.begin(); it != spellBook.end(); ++it)
    {
        delete it->second;
    }
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
    if (spellBook.find(spell->getName()) == spellBook.end())
    {
        spellBook[spell->getName()] = spell->clone();
    }
}

void Warlock::forgetSpell(std::string const &spellName)
{
    if (spellBook.find(spellName) != spellBook.end())
    {
        delete spellBook[spellName];
        spellBook.erase(spellName);
    }
}

void Warlock::launchSpell(std::string const &spellName, ATarget const &target)
{
    if (spellBook.find(spellName) != spellBook.end())
    {
        spellBook[spellName]->launch(target);
    }
}