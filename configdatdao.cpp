#include "configdatdao.h"

ConfigDatDAO::ConfigDatDAO()
{
}
ConfigDatDAO::ConfigDatDAO(std::string _homePath) {
    homePath = _homePath;
}

void ConfigDatDAO::setHomePath(std::string _homePath) {
    homePath = _homePath;
}


void ConfigDatDAO::writeConfig(Config config) {

}

Config ConfigDatDAO::readConfig() {
    Config c;
    return c;
}
