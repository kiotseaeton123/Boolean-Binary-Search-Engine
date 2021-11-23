//
// Created by kiots on 11/22/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_SEARCHENGINE_H
#define INC_21F_FINAL_PROJ_TEMPLATE_SEARCHENGINE_H
/*
 *process single-word searches, prefixed boolean queries
 * opens persistence files: organizations, persons, communicates with IndexHandler
 */

#include <iostream>
#include "IndexHandler.h"

class SearchEngine {
private:
    IndexHandler* index_handler;

public:
    SearchEngine();
    void parse_corpus(std::string &path);
    void find_word(std::string &word);

    void clear_index();

};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_SEARCHENGINE_H
