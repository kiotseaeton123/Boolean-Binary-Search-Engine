//
// Created by kiots on 11/22/2021.
//

#include "IndexHandler.h"

void IndexHandler::parse_corpus(string &path) {
    doc_parser.parse_filesystem(path);
}

void IndexHandler::find_word(string &word) {
    doc_parser.find_word(word);
}
