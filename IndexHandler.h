//
// Created by kiots on 11/22/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_INDEXHANDLER_H
#define INC_21F_FINAL_PROJ_TEMPLATE_INDEXHANDLER_H
/*
 * handles persistance file
 * handles inverted file index
 * handles queries from search-engine
 */
#include "DocumentParser.h"
#include "Document.h"

class IndexHandler {
private:
    DocumentParser doc_parser;

public:
    void parse_corpus(std::string &path);
    void find_word(std::string &word);


};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_INDEXHANDLER_H
