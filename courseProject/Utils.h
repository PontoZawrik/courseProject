#pragma once
#include <string>


using System::String;

inline std::string ToStdString(String^ str) {
    using System::IntPtr;
    using System::Runtime::InteropServices::Marshal;

    IntPtr ptr = Marshal::StringToHGlobalAnsi(str);
    std::string result = static_cast<char*>(ptr.ToPointer());
    Marshal::FreeHGlobal(ptr);

    return result;
}


inline String^ ToSysString(const std::string& str) {
    return gcnew String(str.c_str());
}
