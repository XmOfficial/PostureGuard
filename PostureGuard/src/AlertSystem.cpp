#include "AlertSystem.h"
#include <stdlib.h>

void AlertSystem::showAlert(const std::string &message) 
{
    // --timeout=2 参数控制显示时间，& 实现后台执行
    system(("zenity --warning --title='PostureGuard' --text='" + message + 
            "' --timeout=1 --width=300 &").c_str()); 
}