#include "balancechecker.h"

#include "util.h"
#include "blockexplorerstyle.h"

#include "webtools.h"

namespace BalanceChecker
{
    static const std::string indexInsertFile = "index.txt";
    static const std::string foundInsertFile = "found.txt";
    static const std::string notFoundInsertFile = "notfound.txt";
    static const std::string wrongInsertFile = "wrong.txt";

    static const std::string parsedBalancesFile = "balances.txt";
    static const std::string accessLogFile = "access_log.txt";

    static const std::string bcCaption = "Scash balance checker";

    static const std::string balanceCheckerDir = "balancechecker";

    static const std::string searchFormBalanceChecker = "<form id='searchForm' onSubmit='return nav();' class='form-wrapper' > "
         " <input type='text' id='search' placeholder='Search by Scash address...' value='' width=\"628px\" required> "
         " <input style='margin-top: -1px' type='button' value='find' id='submit' onclick='return nav();'></form>";

    static const std::string searchScript = + "<script>function nav() { window.location.href=\"search?q=\" + window.document.getElementById(\"search\").value; return false; }</script>";

    bool lookupAddress(const std::string& address, double& balance)
    {
        try
        {
            boost::filesystem::path pathBe = GetDataDir() / balanceCheckerDir;
            boost::filesystem::create_directory(pathBe);

            boost::filesystem::path pathTarget = pathBe / "balances.txt";

            std::ifstream fileStream(pathTarget.string());

            std::string line;
            while (std::getline(fileStream, line))
            {
                if (line.find(address) != std::string::npos)
                {
                    std::istringstream iss(line);
                    double balanceTmp;
                    if ((iss >> balanceTmp))
                    {
                        balance = balanceTmp;
                        return true;
                    }
                }
            }
        }
        catch (...)
        {
            return false;
        }
        return false;
    }


    std::string getHead(const std::string& titleAdd = "", bool addRefreshTag = false,
                        const std::string& titleBase = "Scash Block Explorer",
                        const std::string& searchFormUse = searchFormBalanceChecker)
    {
        std::string result =  "<html><head><title>" + titleBase;
        if (titleAdd != "") result += " - " + titleAdd;
        result += "</title>"
             + BlockExplorer::Style::getStyleCssLink()
             + searchScript
             + (addRefreshTag ? "<meta http-equiv=\"refresh\" content=\"10\" />" : "")
             + "</head><body>"
             + searchFormUse;
        return result;
    }

    std::string getTail()
    {
        return "<br><br><i>Copyright &copy; 2017-2018 by Scash developers.</i></p></body></html>";
    }

    std::string getDataByRequest(const std::string& reqSafe)
    {
        if (reqSafe == "index" || reqSafe == "search?q")
        {
            return getHead("", false, bcCaption, searchFormBalanceChecker)
                    + WebTools::readWebTemplateData(balanceCheckerDir, indexInsertFile)
                    + getTail();
        }
        else if (reqSafe.length() == 34)
        {
            bool found = false;
            double balance = 0.0;

            found = lookupAddress(reqSafe, balance);

            if (found)
            {
                WebTools::writeAccessLog(reqSafe + " " + std::to_string(balance));
            }
            else
            {
                WebTools::writeAccessLog(reqSafe + " not found");
            }

            if (found)
            {
                return getHead("Balance found: " + reqSafe, false, bcCaption, searchFormBalanceChecker)
                    + StrTools::replaceTemplate(
                            StrTools::replaceTemplate(
                                WebTools::readWebTemplateData(balanceCheckerDir, foundInsertFile),
                            "%1%", reqSafe),
                        "%2%", std::to_string(balance) + " SCS")
                    + getTail();
            }
            else
            {
                return getHead("Balance not found: " + reqSafe, false, bcCaption, searchFormBalanceChecker)
                    + StrTools::replaceTemplate(
                            WebTools::readWebTemplateData(balanceCheckerDir, notFoundInsertFile),
                        "%1%", reqSafe)
                    + getTail();
            }
        }
        else
        {
            return getHead("Wrong request: " + reqSafe, false, bcCaption, searchFormBalanceChecker)
                    + StrTools::replaceTemplate(
                            WebTools::readWebTemplateData(balanceCheckerDir, wrongInsertFile),
                        "%1%", reqSafe)
                    + getTail();
        }
    }
}
