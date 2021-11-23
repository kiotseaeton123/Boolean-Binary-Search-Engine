//
// Created by kiots on 11/22/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_DOCUMENTPARSER_H
#define INC_21F_FINAL_PROJ_TEMPLATE_DOCUMENTPARSER_H
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include "AVLTree.h"
#include "Document.h"
#include "porter2_stemmer.h"

#include "include/rapidjson/document.h"
#include "include/rapidjson/istreamwrapper.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/Writer.h"

class DocumentParser {
private:
    set<string> stop_words;
    AVLTree<string, vector<string>> word_map; //<word, vector<articles>>

public:
    DocumentParser();
    void parse_filesystem(string &directory_path);
    void parse_json(string whole_article);
    bool not_stop_word(string);

    void find_word(string word);



};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_DOCUMENTPARSER_H
