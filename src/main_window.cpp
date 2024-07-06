#include <memory>
#include <adwaita.h>

#include <base/exception.h>
#include <interface/application.h>
#include <main_window.h>

namespace aegis {
    using namespace interface;

    MainWindow::MainWindow() {
        app = std::make_unique<Application>();

        set_title("Aegis");
        set_default_size(640, 480);

        const auto styleManager{adw_style_manager_get_default()};
        if (adw_style_manager_get_system_supports_color_schemes(styleManager)) {
            adw_style_manager_set_color_scheme(styleManager, ADW_COLOR_SCHEME_PREFER_DARK);
        }
        const virtfs::path current{"."};
        app->checkAndTouchDirectories(current, dirIsValid);
        app->placeUserRequest("keys_prod", &askUserKeys);

        app->initialize();
    }
    MainWindow::~MainWindow() = default;

    bool MainWindow::askUserKeys() {
        return {};
    }
}
