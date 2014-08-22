#ifndef CONFIGREPOSITORY_H
#define CONFIGREPOSITORY_H

#include "src/model/config.h"

class ConfigRepository
{
public:
    virtual ~ConfigRepository() {}
    virtual void writeConfig(Config config) = 0;
    virtual Config readConfig() = 0;
};

#endif // CONFIGREPOSITORY_H
