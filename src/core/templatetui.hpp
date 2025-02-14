#pragma once

#include <memory>
#include <string>
#include <vector>

#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

#include "../util/util.hpp"

/**
 * @brief The Template TUI. Call Run() to execute :)
 */
class TemplateTUI {
   public:
    /**
     * @brief Constructs, builds and assembles all components of the TemplateTUI.
     */
    explicit TemplateTUI();

    /**
     * @brief Runs the TemplateTUI.
     *
     * @return Exit Code
     */
    int Run();

   public:
    // TODO: add your methods here :)
    [[nodiscard]] const ftxui::ScreenInteractive& GetScreen() const;

   private:
    // TODO: add state variables here :)
    int counter = 0;

    // components
    ftxui::ScreenInteractive screen;
    ftxui::Component mainContainer;

   public:
    /**
     * @brief Print help page
     *
     * @param caller argv[0]
     * @param errorMessage Optional error message to include.
     * @return Exit Code
     */
    static int showHelp(const std::string& caller, const std::string& errorMessage = "");

    /**
     * @brief Print the application version
     *
     * @return Exit Code
     */
    static int showVersion();
};
