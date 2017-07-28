package.cpath=package.cpath..';./?.so;'
function dump(o)
   if type(o) == 'table' then
      local s = '{ '
      for k,v in pairs(o) do
         if type(k) ~= 'number' then k = '"'..k..'"' end
         s = s .. '['..k..'] = ' .. dump(v) .. ','
      end
      return s .. '} '
   else
      return tostring(o)
   end
end
lib = require "mylib"
print(dump(lib))
local ave,sum = lib.average(1,2,3,4,5)
print(ave,sum)
lib.sayHello()

