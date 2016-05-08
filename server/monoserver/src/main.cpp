/*
 * =====================================================================================
 *
 *       Filename: main.cpp
 *        Created: 08/31/2015 08:52:57 PM
 *  Last Modified: 05/07/2016 17:06:47
 *
 *    Description: 
 *
 *        Version: 1.0
 *       Revision: none
 *       Compiler: gcc
 *
 *         Author: ANHONG
 *          Email: anhonghe@gmail.com
 *   Organization: USTC
 *
 * =====================================================================================
 */
#include <ctime>
#include <asio.hpp>

#include "log.hpp"
#include "taskhub.hpp"
#include "threadpn.hpp"
#include "mainwindow.hpp"
#include "eventtaskhub.hpp"
#include "addmonsterwindow.hpp"
#include "serverconfigurewindow.hpp"
#include "databaseconfigurewindow.hpp"

Log                      *g_Log;
TaskHub                  *g_TaskHub;
EventTaskHub             *g_EventTaskHub;
Theron::EndPoint         *g_EndPoint;
Theron::Framework        *g_Framework;
ThreadPN                 *g_ThreadPN;

MainWindow               *g_MainWindow;
MonoServer               *g_MonoServer;
AddMonsterWindow         *g_AddMonsterWindow;
ServerConfigureWindow    *g_ServerConfigureWindow;
DatabaseConfigureWindow  *g_DatabaseConfigureWindow;

int main()
{
    std::srand(std::time(nullptr));

    g_Log                     = new Log("mir2x-monoserver-v0.1");
    g_TaskHub                 = new TaskHub();
    g_MainWindow              = new MainWindow();
    g_MonoServer              = new MonoServer();
    g_ServerConfigureWindow   = new ServerConfigureWindow();
    g_DatabaseConfigureWindow = new DatabaseConfigureWindow();
    g_EventTaskHub            = new EventTaskHub();
    g_EndPoint                = new Theron::EndPoint("monoserver", "tcp://127.0.0.1:5556");
    g_Framework               = new Theron::Framework(*g_EndPoint);
    g_ThreadPN                = new ThreadPN(4);

    g_MainWindow->ShowAll();

    return Fl::run();
}
