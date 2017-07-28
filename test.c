#include <stdio.h>  
#include "lualib.h"  
#include "lauxlib.h"
static int averageFunc(lua_State *L)  
{  
    int n = lua_gettop(L);  
    double sum = 0;  
    int i;  

    /* 循环求参数之和 */  
    for (i = 1; i <= n; i++)  
        sum += lua_tonumber(L, i);  

    lua_pushnumber(L, sum / n);     //压入平均值  
    lua_pushnumber(L, sum);         //压入和  

    return 2;                       //返回两个结果  
}  

static int sayHelloFunc(lua_State* L)  
{  
    printf("hello world!");  
    return 0;  
}  

static const struct luaL_Reg regs[] =
{  
    {"average", averageFunc},  
    {"sayHello", sayHelloFunc},  
    {NULL, NULL}       //数组中最后一对必须是{NULL, NULL}，用来表示结束      
};  
//这里luaopen_xxx必须和生成的so库名字一样
int luaopen_mylib(lua_State *L)
{
    //lua5.1 之中有一个luaL_register,用于把luaL_Reg 数组中的所有函数注册到lua中。
    //但在lua5.2中已经不支持这一函数了，下面是最新的api
    lua_newtable(L);
    luaL_setfuncs(L, regs, 0);
    return 1;       // 把myLib表压入了栈中，所以就需要返回1  
}
