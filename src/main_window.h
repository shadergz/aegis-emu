#pragma once

#include <gtkmm/window.h>

namespace aegis {
    class MainWindow final : public Gtk::Window {
    public:
        MainWindow();
        ~MainWindow() override;
    private:
        bool dirIsValid{};
    };
}
