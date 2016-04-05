#pragma once

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

// Defines for logging and testing.
#define OML_LOG

// STL
#ifdef OML_LOG
#include <iostream>
#include <iomanip>
#endif

#include <string>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
