#include "lauxlib.h"
#include "lua.h"
#include "luaconfig/core/autocmds.h"
#include "luaconfig/core/commands.h"
#include "luaconfig/core/highlights.h"
#include "luaconfig/core/maps.h"
#include "luaconfig/core/options.h"
#include "luaconfig/utils/printstack.h"
#include "nvim.h"
#include <stdio.h>

int add (int a, int b);

int
lua_setup (lua_State *L)
{
    // stack = [nvlx]
    l_options_load (L);
    l_maps_load (L);
    l_highlights_load (L);
    l_autocmds_load (L);
    l_commands_load (L);
    return 0;
}

LUA_API int
luaopen_nvelox_init (lua_State *L)
{
    printf ("%d\n", add (5, 10));
    luaL_Reg fns[] = { { "setup", lua_setup }, { NULL, NULL } };
    luaL_newlib (L, fns);
    return 1;
}
