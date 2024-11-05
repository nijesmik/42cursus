#include <iostream>

class Warlock
{
private:
    std::string name;
    std::string title;
    Warlock();
    Warlock &operator=(Warlock const &other);
    Warlock(Warlock const &other);

public:
    std::string const &getName() const;
    std::string const &getTitle() const;
    void setTitle(std::string const &str);
    Warlock(std::string const &name, std::string const &title);
    ~Warlock();
    void introduce() const;
};
