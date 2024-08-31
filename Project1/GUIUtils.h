#pragma once
#include <cstring> 
#include <string> 
#include <iostream> 
#include <string.h>
#include <msclr/marshal.h>

using namespace msclr::interop;

using namespace System::Windows::Forms;
using namespace System;

extern void charToString(char in[20], String^ out);

extern void StringToChar(char out[20], String^ in);
