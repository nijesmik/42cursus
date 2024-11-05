#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
    for (std::map<std::string, ASpell *>::iterator it = spellBook.begin(); it != spellBook.end(); ++it)
    {
        delete it->second;
    }
}

void SpellBook::learnSpell(ASpell *spell)
{
    if (spellBook.find(spell->getName()) == spellBook.end())
    {
        spellBook[spell->getName()] = spell->clone();
    }
}

void SpellBook::forgetSpell(std::string const &spellName)
{
    if (spellBook.find(spellName) != spellBook.end())
    {
        delete spellBook[spellName];
        spellBook.erase(spellName);
    }
}

ASpell *SpellBook::createSpell(std::string const &spellName)
{
    if (spellBook.find(spellName) != spellBook.end())
    {
        return spellBook[spellName];
    }
    return NULL;
}