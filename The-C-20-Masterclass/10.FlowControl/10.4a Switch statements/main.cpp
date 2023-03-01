#include <iostream>
//https://mariusbancila.ro/blog/2021/03/23/initializing-statement-for-if-switch-foreach/

//Before C++17.
//-----------------------
auto option = get_option();
switch (option)
{
case 'a': /* add */   break;
case 'd': /* del */   break;
case 'l': /* list */  break;
case 'q': /* quit */  break;
default:  /* error */ break;
}

//In C++17, this statement can be refactored to the following form:
//-----------------------
switch (auto option = get_option(); option)
{
   case 'a': /* add */   break;
   case 'd': /* del */   break;
   case 'l': /* list */  break;
   case 'q': /* quit */  break;
   default:  /* error */ break;
}