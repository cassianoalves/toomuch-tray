#ifndef CONFIGDATDAO_H
#define CONFIGDATDAO_H

#include <string>

#include "src/repository/configrepository.h"

class ConfigDatDAO : public ConfigRepository
{
public:
    ConfigDatDAO(std::string homePath);
    ConfigDatDAO();
    void setHomePath(std::string homePath);
    void writeConfig(Config config);
    Config readConfig();

private:
    std::string homePath;

};

#endif // CONFIGDATDAO_H
