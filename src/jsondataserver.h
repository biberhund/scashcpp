// Copyright (c) 2018 Scash developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef JSONDATA_SERVER_H
#define JSONDATA_SERVER_H

#include <string>

namespace JsonDataServer
{
    extern bool fJsonDataServerEnabled;
    extern int fJsonDataServerPort;

    void ThreadJsonDataServer(void* parg);
}

#endif // JSONDATA_SERVER_H

