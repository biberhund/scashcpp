#ifndef WEBTOOLS_H
#define WEBTOOLS_H

#include <string>

namespace StrTools
{
    std::string replaceTemplate(const std::string& where, const std::string& what, const std::string& to);
    std::string safeEncodeFileNameWithoutExtension(const std::string& name);
    std::string filterURLRequest(const std::string& name);
}

namespace TimeTools
{
    unsigned int getNowTime();
    std::string unixTimeToString(unsigned int ts);
    std::string unixTimeToAgeFromNow(unsigned int ts, unsigned int from);
}

namespace WebTools
{
    void writeAccessLog(const std::string& data);

    std::string readWebTemplateData(const std::string& dir, const std::string& filename);

    int ReadCounterFile(const std::string &file);
    int AddToCounterFile(const std::string &file, int amount);
}

#endif // WEBTOOLS_H
