#ifndef _TYPEDEFINE_H_
#define _TYPEDEFINE_H_

#include "stdafx.h"


#include <string>
using namespace std;

typedef int                 BOOL;
#define FALSE 0
#define TRUE 1

#ifdef _LINUX_
    #define BOOL int
#endif
#endif


#ifdef _LINUX_
#else
#ifdef _DEBUG



#else
#endif
#endif
//宏定义不然会奔溃
//BUILDING_LIBCURL;HTTP_ONLY;TIXML_USE_STL
//全部用MTD模式
//附加头文件 ".\jsoncpp-src-0.5.0\include";".\curl-7.32.0\include" ".\tinyxmlSTLvc6-UTF8"


//#include <json/json.h>
#include <curl/curl.h>
//#include <tinyxml.h>
//#include <tinystr.h>

//#pragma comment(lib,"./jsoncpp-src-0.5.0/build/vs71/debug/lib_json/json_vc71_libmtd.lib")

#if  X64_UPDATE
#pragma comment(lib,"./curl-7.32.0/vs/vc8/lib/x64/Debug/vc8libcurl.lib")
#else
#pragma comment(lib,"./curl-7.32.0/vs/vc8/lib/Debug/vc8libcurl.lib")
#endif


//#pragma comment(lib,"./tinyxmlSTLvc6-UTF8/Debug/tinyxmlSTLvc6.lib")


#define	WIN_PLATFORM
#include <windows.h>

#include <string>
#include <vector>
using namespace std;

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"wldap32.lib")
#pragma comment(lib,"Advapi32.lib")
