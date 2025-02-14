#include <string>
#include <vector>

#include "core/templatetui.hpp"

/**
 * @brief Parse all options listed behind an argument
 *
 * @param args argument list
 * @param find argument (as vector for multiple arg version support, like -h & --help)
 * @return vector of options
 */
std::vector<std::string> getArgOptions(const std::vector<std::string>& args,
                                       const std::vector<std::string>& find) {
    std::vector<std::string> out;
    for (const auto& arg : find) {
        auto argIndex = std::find(args.begin(), args.end(), arg);
        if (argIndex == args.end()) {
            continue;
        }
        while (++argIndex != args.end()) {
            if ((*argIndex).at(0) == '-') {
                // arrived at next argument -> stop
                break;
            }
            out.push_back(*argIndex);
        }
    }
    return out;
}

/**
 * @brief Check if argument exists in argument list
 *
 * @param args argument list
 * @param arg argument to search for
 * @return true, if argument exists
 */
bool argExists(const std::vector<std::string>& args, std::string arg) {
    return std::find(args.begin(), args.end(), arg) != args.end();
}

/**
 * @brief Main: For argument parsing and calling the TUI.
 *
 * @param argc argument count
 * @param argv arguments
 * @return Exit Code
 */
int main(int argc, const char** argv) {
    // too few amount of arguments
    if (argc <= 0) {
        return TemplateTUI::showHelp(argc <= 0 ? "" : argv[0], "wrong amount of arguments");
    }

    std::vector<std::string> args(argv + 1, argv + argc);
    // -h, --help
    if (argExists(args, "-h") || argExists(args, "--help")) {
        return TemplateTUI::showHelp(argv[0]);
    }
    // -v, --version
    if (argExists(args, "-v") || argExists(args, "--version")) {
        return TemplateTUI::showVersion();
    }
    
    // TODO: insert more arguments for your application here
    
    // Template TUI
    TemplateTUI templatetui;
    return templatetui.Run();
}
