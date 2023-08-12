#include <gtk/gtk.h>

static void on_clicked(gpointer data) {
  g_print("msg: %s\n", (char *) data);
}

static void on_activate(GtkApplication *app, gpointer data __attribute__((unused))) {
  GtkBuilder *builder;
  GObject *window, *obj;

  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "window.ui", NULL);

  window = gtk_builder_get_object(builder, "window");
  gtk_window_set_application(GTK_WINDOW(window), app);

  obj = gtk_builder_get_object(builder, "quit-btn");
  g_signal_connect_swapped(obj, "clicked", G_CALLBACK(gtk_window_destroy), window);

  obj = gtk_builder_get_object(builder, "home-btn");
  g_signal_connect_swapped(obj, "clicked", G_CALLBACK(on_clicked), "Home Button");

  obj = gtk_builder_get_object(builder, "settings-btn");
  g_signal_connect_swapped(obj, "clicked", G_CALLBACK(on_clicked), "Settings Button");

  obj = gtk_builder_get_object(builder, "about-btn");
  g_signal_connect_swapped(obj, "clicked", G_CALLBACK(on_clicked), "About Button");

  obj = gtk_builder_get_object(builder, "help-btn");
  g_signal_connect_swapped(obj, "clicked", G_CALLBACK(on_clicked), "Help Button");

  gtk_window_present(GTK_WINDOW(window));

  g_object_unref(builder);
}

int main(int argc, char *argv[]) {
  GtkApplication *app = NULL;
  int status = 0;

  app = gtk_application_new("dev.davenchy.hello_world", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
