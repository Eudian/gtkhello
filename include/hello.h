#ifndef __HELLO_H

#define __HELLO_H
struct uiref;

struct uiref *hello_new();
void hello_run(struct uiref *ui);
void hello_close(struct uiref **ui);

#endif
