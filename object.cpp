#include <stdio.h>
#include <string.h>
#include "object.h"
Object::Object()
{
}
Object::~Object()
{
}
static int find_substr_index(const char * str, const char * substr)
{
    if (strlen(str) < strlen(substr))
        return -1;
    int idx = 0;
    int len = strlen(substr);
    bool start = true;
    const char * pos = str;
    while (*pos) {
        if (start && !strncmp(pos, substr, len) && pos[len]=='\n')
            return idx;
        start = false;
        if (*pos == '\n') {
            idx++;
            start = true;
        }
        pos++;
    }
    return -1;
}
void Object::connect(Object* sender, const char* sig, Object* receiver, const char* slt)
{
    int sig_idx = find_substr_index(sender->meta.sig_names, sig);
    int slt_idx = find_substr_index(receiver->meta.slts_names, slt);
    if (sig_idx == -1 || slt_idx == -1) {
        perror("signal or slot not found!");
    } else {
        Connection c = {receiver, slt_idx};
        sender->connections.insert(std::pair<int, Connection>(sig_idx, c));
    }
}
void Object::onClick()
{
    printf("Hello Qt!");
}
void MetaObject::active(Object* sender, int idx)
{
    auto ret = sender->connections.equal_range(idx);
    for (auto it = ret.first; it != ret.second; ++it) {
        Connection c = (*it).second;
        c.receiver->metacall(c.method);
    }
}
void Object::testSignal()
{
    emit click();
}
