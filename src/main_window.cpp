#include <memory>
#include <adwaita.h>

#include <interface/application.h>
#include <main_window.h>

namespace aegis {
    MainWindow::MainWindow() {
        interface::app = std::make_unique<interface::Application>();

        set_title("Aegis");
        set_default_size(640, 480);

        const auto styleManager{adw_style_manager_get_default()};
        if (adw_style_manager_get_system_supports_color_schemes(styleManager)) {
            adw_style_manager_set_color_scheme(styleManager, ADW_COLOR_SCHEME_PREFER_DARK);
        }
        const fs::path current{"."};
        interface::app->checkAndTouchDirectories(current, dirIsValid);
    }
    MainWindow::~MainWindow() = default;
}
