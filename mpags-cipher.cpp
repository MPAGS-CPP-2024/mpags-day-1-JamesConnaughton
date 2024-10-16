#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]){

    // Convert command line arguments into an easier to use form
    const std::vector<std::string> cmdLineArgs{argv, argv+argc};
    const std::size_t nCmdLineArgs(cmdLineArgs.size());

    // Help requested boolean and message
    bool helpRequested{false};
    std::string help_message{
        """Usage: ./mpags-cipher [options]\n"""
        """Options:\n"""
        """ -h, --help: Display this message\n"""
        """ --version: Display version\n"""
        """ -i FILE  ,  --input-file FILE: Specify the input file\n"""
        """ -o FILE  ,  --output-file FILE: Specify the output file"""
        };

    // Versioning
    bool versionRequested{false};
    const std::string version_number{"0.1.0"};

    // Input file
    std::string input_file{""};
    bool input_file_given{false};

    // Output file
    std::string output_file{""};
    bool output_file_given{false};

    for (size_t i{1}; i < nCmdLineArgs; i++){
        if (cmdLineArgs[i] == "--help" || cmdLineArgs[i] == "-h"){
            helpRequested = true;
        }
        else if (cmdLineArgs[i] == "--version"){
            versionRequested = true;
        }
        else if (cmdLineArgs[i] == "--input-file" || cmdLineArgs[i] == "-i"){
            // Check if the list is long enough
            if (i < nCmdLineArgs - 1){
                input_file = cmdLineArgs[i+1];
                input_file_given = true;
                i++; // Increment so that the argument isn't reparsed
            }
            else{
                std::cout << "Error: No input file specified" << std::endl;
                return 1;
            }
        }
        else if (cmdLineArgs[i] == "--output-file" || cmdLineArgs[i] == "-o"){
            // Check if the list is long enough
            if (i < nCmdLineArgs - 1){
                output_file = cmdLineArgs[i+1];
                output_file_given = true;
                i++; // Increment so that the argument isn't reparsed
            }
            else{
                std::cout << "Error: No output file specified" << std::endl;
                return 1;
            }
        }
        else{
            std::cout << "Argument " << cmdLineArgs[i] << " is unknown. Use ./mpags-cipher --help to list configurations" << std::endl;
            return 1;
        }
    }


    if (helpRequested){
        std::cout << help_message << std::endl;
        return 0;
    }

    if (versionRequested){
        std::cout << "Version: " << version_number << std::endl;
        return 0;
    }

    if (input_file_given){
        std::cout << "Input file: " << input_file << std::endl;
    }

    if (output_file_given){
        std::cout << "Output file: " << output_file << std::endl;
    }

    char in_char{'x'};
    std::string out_str{""};

    // Take each letter from user input
    while(std::cin >> in_char){
        
        // Convert to upper case
        if (std::isalpha(in_char)){
            out_str += std::toupper(in_char);
            continue;
        }

        // Change numbers to words
        switch (in_char){
            case '1':
                out_str += "ONE";
                break;
            case '2':
                out_str += "TWO";
                break;
            case '3':
                out_str += "THREE";
                break;
            case '4':
                out_str += "FOUR";
                break;
            case '5':
                out_str += "FIVE";
                break;
            case '6':
                out_str += "SIX";
                break;
            case '7':
                out_str += "SEVEN";
                break;
            case '8':
                out_str += "EIGHT";
                break;
            case '9':
                out_str += "NINE";
                break;
            case '0':
                out_str += "ZERO";
                break;
            default:
                // Do nothing
                break;
        }
        // None alphanumeric characters left
        // Don't add them to the string (removed)
    }
    std::cout << out_str << std::endl;
}