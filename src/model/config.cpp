#include "src/model/config.h"

Config::Config()
{
    source = Config::OFFLINE;
    sourceInfo = "";
    updateTime = 0;
}

Config::Config(Source _source, std::string _sourceInfo, long _updateTime)
{
    source = _source;
    sourceInfo = _sourceInfo;
    updateTime = _updateTime;
}
