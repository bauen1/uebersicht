#include <stdlib.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <webkit2gtk/webkit2gtk.h>

static void die(const char *err) {
	fputs(err, stderr);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);

	GtKWidget *main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GdkScreen *screen = gtk_window_get_screen(GTK_WINDOW(main_window));
	GdkVisual *visual = gdk_screen_get_rgba_visual(screen);
	if (visual && gdk_screen_is_composited(screen)) {
		gtk_widget_set_visual(GTK_WIDGET(main_window), visual);
	} else {
		die("screen is not composited, check your configuration");
	}
	gtk_window_set_title(GTK_WINDOW(main_window), "uebersicht overlay");
	gtk_window_set_decorated(GTK_WINDOW(main_window), FALSE);

	g_signal_connect(G_OBJECT(main_window), "destroy", G_CALLBACK(destroy_cb), NULL);

	// TODO: webview

	gtk_widget_show_all(main_window);
	gtk_window_fullscreen(GTK_WINDOW(main_window)); // works for xfce, kinda
	gtk_main();

	return 0;
}
