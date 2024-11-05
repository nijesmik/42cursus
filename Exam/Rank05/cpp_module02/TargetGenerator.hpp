#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
private:
    std::map<std::string, ATarget *> map;

public:
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget *);
    void forgetTargetType(std::string const &);
    ATarget *createTarget(std::string const &);
};