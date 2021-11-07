#include "object.h"
int main()
{
   Object obj1, obj2;
   Object::connect(&obj1, "click", &obj2, "onClick");
   obj1.testSignal();
   return 0;;
}
