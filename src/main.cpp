#include <gtkmm/application.h>

#include <main_window.h>

int main(const int argc, char** argv) {
    const auto gtkApp{Gtk::Application::create("emu.aegis")};

    return gtkApp->make_window_and_run<aegis::MainWindow>(argc, argv);
}
