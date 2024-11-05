#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
    std::string name;
    std::string title;
    Warlock();
    Warlock &operator=(Warlock const &other);
    Warlock(Warlock const &other);
    SpellBook spellBook;

public:
    std::string const &getName() const;
    std::string const &getTitle() const;
    void setTitle(std::string const &str);
    Warlock(std::string const &name, std::string const &title);
    ~Warlock();
    void introduce() const;
    void learnSpell(ASpell *spell);
    void forgetSpell(std::string const & spellName);
    void launchSpell(std::string const & spellName, ATarget const &target);
};
