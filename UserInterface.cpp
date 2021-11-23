//
// Created by kiots on 11/22/2021.
//

#include "UserInterface.h"

UserInterface::UserInterface(const char *directory_path) {
    std::string path = directory_path;
    search_engine = new SearchEngine();
    search_engine->parse_corpus(path);
//
//    bool start = true;
//    while (start) {
//        switch (prompt_user()) {
//            case 1:
//                search_engine->clear_index();
//                break;
//            case 2:
//                search_engine->parse_corpus(path);
//                break;
//            case 3:
//                read_persistence_file();
//                break;
//            default:
//                start = false;
//                break;
//        }
//    }
}

int UserInterface::prompt_user() {
    cout << "\n---------Welcome:)---------\n Pick an Option: \n" << endl;
    cout << "\t1. Clear Index" << endl << "\t2. Parse Data to Populate Index" << endl;
    cout << "\t3. Read from Persistence File(Not Available)" << endl << "\t4. Quit " << endl;

    int user_input;
    cin >> user_input;

    switch (user_input) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 4:
            return 4;
            break;
        default:
            cout << "Invalid response...:/\n" << endl;
            return prompt_user();
    }
}

void UserInterface::read_persistence_file() {
    int user_input;
    cout << "Pick an Option: \n" << endl;
    cout << "\t1. Query" << endl << "\t2. Get Statistics" << endl;
    cin >> user_input;

    switch(user_input){
        case 1:
            cout << "type query: ";
            string query;
            cin >> query;

    }
}

void UserInterface::parse_query(char *query) {
    //parse user query; may contain AND, OR, NOT, ORG, PEOPLE, *word
    std::string word = query;
    search_word(word);
}

void UserInterface::search_word(std::string word) {
    search_engine->find_word(word);
}




