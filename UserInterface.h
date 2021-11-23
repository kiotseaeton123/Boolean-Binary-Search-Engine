//
// Created by kiots on 11/22/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_USERINTERFACE_H
#define INC_21F_FINAL_PROJ_TEMPLATE_USERINTERFACE_H

/*
 * receives queries from user
 * communicates with search engine
 * formats and displays results
 */

/*
 * functionality:
 * 1. clear index
 * 2. manage persistent index
 * 3. parse document dataset to populate index OR read from persistence file
 * 4. enter boolean query
 *      -results display: article title, publication, date published
 *      -result returns 15 articles, in order of relevancy
 *      -user can choose a result and print text
 * 5. output statistics
 *      -total number of articles indexed
 *      -avg words/article(w/o stop words)
 *      -number of words indexed(nodes in AVLTree)
 *      -number of unique Orgs, Persons
 *      -50 most frequent words(w/o stop words)
 *      -other interesting stats...://
 */
#include <iostream>
#include "SearchEngine.h"

class UserInterface {
private:
    SearchEngine* search_engine;

public:
    UserInterface(const char* directory_path);
    void parse_query(char* query);
    void search_word(std::string word);

    int prompt_user();
    void read_persistence_file();
};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_USERINTERFACE_H
