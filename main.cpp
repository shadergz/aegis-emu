#include <memory>
#include <interface/application.h>

namespace aegis {
    class MainWindow {
    public:
        MainWindow() {
            interface::app = std::make_unique<interface::Application>();

            const fs::path current{"."};
            interface::app->checkAndTouchDirectories(current, dirIsValid);
        }
    private:
        bool dirIsValid{};
    };
}

int main() {
    [[maybe_unused]] aegis::MainWindow window{};

    return {};
}
