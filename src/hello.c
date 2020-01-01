#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <memory.h>

struct uiref{
        GtkWidget *window;
        GtkWidget *image;
        GtkWidget *button_close;
        GCallback on_window_destroy;
        GCallback on_button_close_clicked;
        };

void on_window_destroy(GtkWidget *widget, gpointer data)
{
        gtk_main_quit();
}

void on_button_close_clicked(GtkWidget *widget, gpointer data)
{
        struct uiref *ui = (struct uiref*) data;
        gchar *impath;
        impath = g_build_filename(HELLO_IMAGEDIR, "goodbye.png", NULL);
        if (0 == access(impath, 0))
                gtk_image_set_from_file(GTK_IMAGE(ui->image), impath);
        g_free(impath);
        gtk_widget_set_sensitive(ui->window, 0);
        g_timeout_add(2000, (GSourceFunc)gtk_widget_destroy, (gpointer)ui->window);
}

struct uiref *hello_new()
{
        int res;
        gchar *impath;
        struct uiref *ui;
        ui = (struct uiref*) malloc(sizeof(struct uiref));
        GtkBuilder *builder = gtk_builder_new();
        GdkPixbuf *pixbuf;
        
        res = gtk_builder_add_from_resource(builder, "/org/hello/ui/hello.ui", NULL);
        if (!res) {
                printf("Failed to load ui file.\n");
                return NULL;
        }
        
        ui->window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
        ui->image = GTK_WIDGET(gtk_builder_get_object(builder, "image"));
        ui->button_close = GTK_WIDGET(gtk_builder_get_object(builder, "button_close"));
        ui->on_window_destroy = (GCallback)on_window_destroy;
        ui->on_button_close_clicked = (GCallback)on_button_close_clicked;
        
        gtk_builder_connect_signals(builder, (gpointer)ui);
        //g_signal_connect(ui.window, "destroy", ui.on_window_destroy, NULL);
        //g_signal_connect(ui.button_close, "clicked", ui.on_button_close_clicked, (gpointer)&ui);
        
        pixbuf = gdk_pixbuf_new_from_resource("/org/hello/icons/hello.png", NULL);
        if (pixbuf)
                gtk_window_set_icon(GTK_WINDOW(ui->window), pixbuf);
        
        impath = g_build_filename(HELLO_IMAGEDIR, "hello-world.png", NULL);
        if (0 == access(impath, 0))
                gtk_image_set_from_file(GTK_IMAGE(ui->image), impath);
        g_free(impath);
        g_object_unref(builder);
        
        return ui;
}

void hello_run(struct uiref *ui)
{
        gtk_widget_show(ui->window);
        gtk_main();
}

void hello_close(struct uiref **ui)
{
        if (*ui)
                free(*ui);
                *ui = NULL; 
}
