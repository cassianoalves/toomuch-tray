#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "configdatdao.h"

using namespace boost::property_tree;

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
    ptree p;
    p.put("updateTime", config.updateTime);
    p.put("sourceInfo", config.sourceInfo);
    ptree pp;
    pp.put("x", config.widgetPosition.x());
    pp.put("y", config.widgetPosition.y());
    p.put_child("widgetPosition", pp);
    p.put("source", config.source);

    json_parser::write_json(buildConfigPath(), p);
}

Config * ConfigDatDAO::readConfig() {
    Config * c = new Config();
    ptree p;
    json_parser::read_json(buildConfigPath().c_str(), p);
    c->updateTime = p.get<long>("updateTime");
    c->sourceInfo = p.get<std::string>("sourceInfo");
    c->widgetPosition.setX(p.get<int>(path("widgetPosition.x")));
    c->widgetPosition.setY(p.get<int>(path("widgetPosition.y")));
    c->setSource(p.get<int>("source"));
    return c;
}

std::string ConfigDatDAO::buildConfigPath() {
    return homePath + "/" + CONFIG_FILENAME;
}
