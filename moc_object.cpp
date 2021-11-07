#include "object.h"
static const char sig_names[] = "click\n";
static const char slts_names[] = "onClick\n";
MetaObject Object::meta = {sig_names, slts_names};
void Object::click()
{
    MetaObject::active(this, 0);
}

void Object::metacall(int idx)
{
    switch (idx) {
        case 0:
            onClick();
            break;
        default:
            break;
    };
}
