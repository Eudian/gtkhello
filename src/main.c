#include <gtk/gtk.h>
#include <hello.h>

int main(int argc, char**argv)
{
    gtk_init(&argc, &argv);
    struct uiref *ui;
    ui = hello_new();
    if (!ui)
        return -1;
    hello_run(ui);
    hello_close(&ui);
    return 0;
} 
