#ifndef TAPPLICATION_H
#define TAPPLICATION_H

class TApplication
{
public:
    TApplication();
    int exec();
private:
   int startMenu();
   int getInt();
   int listMenu();
   int arrListMenu();
   int stackMenu();
};

#endif // TAPPLICATION_H
