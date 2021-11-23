//
// Created by kiots on 11/22/2021.
//

#include "SearchEngine.h"

SearchEngine::SearchEngine() {
    index_handler = new IndexHandler();
}

void SearchEngine::parse_corpus(std::string &path) {
    index_handler->parse_corpus(path);
}

void SearchEngine::find_word(std::string &word) {
    index_handler->find_word(word);
}

void SearchEngine::clear_index() {

}
