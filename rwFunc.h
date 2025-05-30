#ifndef RWFUNC_H
#define RWFUNC_H

#include <string>
#include "component.h"

int readFile(LinkedList *lst, const std::string file);
int writeFile(LinkedList *lst, const int elementCount, const std::string file);

#endif // RWFUNC_H
