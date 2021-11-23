
/*
 *
 */
#include "UserInterface.h"

int main(int argc, char *argv[]) {

    if(argv[1] && argv[2]){

        UserInterface ui (argv[1]);
        ui.parse_query(argv[2]);

    }else{
        throw::invalid_argument("invalid command line argument:/");
    }
//
//    string directory_path = "/mnt/c/Users/kiots/CLionProjects/2018_01";
//    UserInterface ui(directory_path.c_str());
//    ui.parse_query("help");


    return 0;
}
