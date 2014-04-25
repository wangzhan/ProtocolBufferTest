// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#ifdef _DEBUG
#pragma comment(lib, "../lib/debug/libprotobuf.lib")
#else
#pragma comment(lib, "../lib/release/libprotobuf.lib")
#endif

#pragma warning(disable:4996)

// TODO: reference additional headers your program requires here
