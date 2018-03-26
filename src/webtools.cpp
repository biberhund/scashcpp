#include "webtools.h"

#include "util.h"

#include <map>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/convenience.hpp>
#include <boost/algorithm/string/replace.hpp>

namespace StrTools
{
    std::string replaceTemplate(const std::string& where, const std::string& what, const std::string& to)
    {
        std::string result = where;
        boost::replace_all(result, what, to);
        return result;
    }

    std::string safeEncodeFileNameWithoutExtension(const std::string& name)
    {
        std::string result = "";

        for (size_t u = 0; u < name.length(); u++)
        {
            if (isalnum(name[u]))
                result += name[u];
            else
                result += "_";
        }

        return result;
    }


    std::string filterURLRequest(const std::string& name)
    {
        std::string result = "";

        for (size_t u = 0; u < name.length(); u++)
        {
            if (isalnum(name[u]) || name[u] == '?' || name[u] == '.' || name[u] == '/')
                result += name[u];
        }

        return result;
    }

}
namespace  TimeTools
{
    unsigned int getNowTime()
    {
        return time(NULL);
    }

    std::string unixTimeToString(unsigned int ts)
    {
        struct tm epoch_time;
        time_t tsLI = ts;
        memcpy(&epoch_time, gmtime(&tsLI), sizeof (struct tm));
        char res[64];
        strftime(res, sizeof(res), "%Y-%m-%d %H:%M:%S UTC", &epoch_time);
        return res;
    }

    std::string unixTimeToAgeFromNow(unsigned int ts, unsigned int from)
    {
        if (from <= ts) return "now";
        unsigned int diff = from - ts;
        if (diff < 60) return std::to_string(diff) + "s";
        if (diff < 60*60) return std::to_string(diff/60) + "m";
        return std::to_string(diff/60/60) + "h";
    }
}

namespace WebTools
{
    void writeAccessLog(const std::string& data)
    {
        try
        {
            boost::filesystem::path pathBe = GetDataDir() / "webdb";
            boost::filesystem::create_directory(pathBe);

            std::string addressFileName = "access_log.txt";
            boost::filesystem::path pathAddressFile = pathBe / addressFileName;

            std::fstream fileOut(pathAddressFile.c_str(), std::ofstream::out | std::ofstream::app);

            fileOut << data << "\n";

            fileOut.close();
        }
        catch (std::exception& ex)
        {
            printf("Write access log failed: %s for message [%s]\n", ex.what(), data.c_str());
        }
    }

    std::string readWebTemplateData(const std::string& dir, const std::string& filename)
    {
        try
        {
            boost::filesystem::path pathBe = GetDataDir() / dir;
            boost::filesystem::create_directory(pathBe);

            boost::filesystem::path pathTarget = pathBe / filename;

            std::ifstream fileStream(pathTarget.string());
            std::string strData;

            fileStream.seekg(0, std::ios::end);
            strData.reserve(fileStream.tellg());
            fileStream.seekg(0, std::ios::beg);

            strData.assign((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());

            return strData;
        }
        catch (std::exception& ex)
        {
            printf("Read web template data failed: %s for file [%s]\n", ex.what(), filename.c_str());
        }
        return "";
    }


    int ReadCounterFile(const std::string& file)
    {
        try
        {
            boost::filesystem::path pathBe = GetDataDir() / "webdb";
            boost::filesystem::create_directory(pathBe);

            std::string addressFileName = file;
            boost::filesystem::path pathSupplyFile = pathBe / addressFileName;

            std::fstream fileIn(pathSupplyFile.c_str(), std::ifstream::in);

            int supply;
            fileIn >> supply;

            fileIn.close();
            return supply;
        }
        catch (std::exception& ex)
        {
            printf("Read int file failed [%s]\n", ex.what());
        }
        return 0;
    }

    int AddToCounterFile(const std::string &file, int amount)
    {
        int newSupply = ReadCounterFile(file);
        newSupply += amount;

        try
        {
            boost::filesystem::path pathBe = GetDataDir() / "webdb";
            boost::filesystem::create_directory(pathBe);

            std::string addressFileName = file;
            boost::filesystem::path pathSupplyFile = pathBe / addressFileName;

            std::fstream fileOut(pathSupplyFile.c_str(), std::ofstream::out);

            fileOut << newSupply;

            fileOut.close();
        }
        catch (std::exception& ex)
        {
            printf("Write int file failed [%s]\n", ex.what());
            return false;
        }
        return true;
    }

}
