#ifndef OBJECT_H
#define OBJECT_H
#include <map>
# define slots
# define signals protected
# define emit
class Object;

struct MetaObject
{
    const char * sig_names;
    const char * slts_names;
    static void active(Object * sender, int idx);
};

struct Connection
{
    Object *receiver;
    int method;
};

typedef std::multimap<int, Connection> ConnectionMap;
class Object
{
    static MetaObject meta;

    void metacall(int idx);

public:
    Object();

    virtual ~Object();

    static void connect(Object*, const char*, Object*, const char*);

    void testSignal();
signals:
    void click();
public slots:
    void onClick();
friend class MetaObject;
private:
     ConnectionMap connections;
};
#endif
