#ifndef RWFUNC_H
#define RWFUNC_H

#include <string>
#include "component.h"

int readFile(LinkedList *lst, std::string file);
int writeFile(LinkedList *lst, int companiesCount, std::string file);

#endif // RWFUNC_H
