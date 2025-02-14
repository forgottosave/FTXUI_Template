#include "templatetui.hpp"

#include <iostream>
#include <string>

#include <ftxui/component/event.hpp>
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

#include "../util/util.hpp"

TemplateTUI::TemplateTUI() : screen(ftxui::ScreenInteractive::Fullscreen()) {
    using namespace ftxui;

    // TODO: set up your elements & TUI in this constructor :)

    // Example: Clicker
    mainContainer = Container::Vertical({
        Renderer([&] { return text("Clicked: " + std::to_string(counter)); }),
        Button(" Click me. ", [&] { ++counter; }) | color(Color::Green)
    });

}

int TemplateTUI::Run() {
    using namespace ftxui;
    
    screen.Loop(mainContainer);
    return EXIT_SUCCESS;
}

const ftxui::ScreenInteractive& TemplateTUI::GetScreen() const {
    return screen;
}

// STATIC
int TemplateTUI::showHelp(const std::string& caller, const std::string& errorMessage) {
    using namespace ftxui;

    // define command line options
    std::vector<std::vector<std::string>> commandOptions{
        // option,        args, description
        {"-h, --help",    "",   "Show help options."},
        {"-v, --version", "",   "Show application version."},
    };

    Elements options{text("Options: ")};
    Elements arguments{text("Arguments: ")};
    Elements meanings{text("Description: ")};
    for (const auto& command : commandOptions) {
        options.push_back(text(command.at(0) + "  ") | color(Color::GrayLight));
        arguments.push_back(text(command.at(1) + "  ") | color(Color::GrayLight));
        meanings.push_back(text(command.at(2) + "  "));
    }

    auto helpPage = vbox(
        {errorMessage.empty() ? filler() : (text(errorMessage) | bold | color(Color::Red) | flex),
         hbox({text("Usage: "), text(caller) | color(Color::GrayLight),
               // TODO: add argument structure :)
               text(" [OPTION...]") | color(Color::Yellow)}),
         text(""),
         hbox({
             vbox(options),
             vbox(arguments),
             vbox(meanings),
         }),
         text(""),
         // TODO: change repository name and link :)
         hbox({text("Report bugs at "), text("Github.com/forgottosave/FTXUI_Template") |
                                            hyperlink("https://github.com/forgottosave/FTXUI_Template")}),
         text("")});

    auto screen = Screen::Create(Dimension::Fit(helpPage));
    Render(screen, helpPage);
    screen.Print();
    std::cout << "\n";

    return errorMessage.empty();
}

int TemplateTUI::showVersion() {
    using namespace ftxui;

    // TODO: change version :)
    auto versionText = text("template-tui 1.0.0");

    auto screen = Screen::Create(Dimension::Fit(versionText));
    Render(screen, versionText);
    screen.Print();
    std::cout << "\n";

    return 0;
}
