//
// Created by kiots on 11/22/2021.
//

#include "DocumentParser.h"

DocumentParser::DocumentParser() {
    //parse stop_words into set stop_words
    ifstream file;
    file.open("stop_words.txt");
    string word;

    if(!file.is_open())
        cout << "couldn't open file:(" << endl;

    while (getline(file, word)){
        stop_words.insert(word);
    }
    file.close();

}

void DocumentParser::parse_filesystem(string &directory_path) {
    //print status bar
    int i = 0;
    for (auto &file_name : filesystem::directory_iterator(directory_path)) {
        //status bar
        ++i;
        if (i % 100 == 0)
            cout << ".";
        if (i % 5000 == 0)
            cout << endl;
        cout.flush();

        if (file_name.is_directory()) {
            for (auto &file : filesystem::directory_iterator(file_name.path())) {
                ifstream _file(file.path());
                string whole_article;
                string temp;
                while (getline(_file, temp)) { whole_article += temp; }
                parse_json(whole_article);

                _file.close();
            }
        }
        ifstream file(file_name.path());
        string whole_article;
        string temp;
        while (getline(file, temp)) { whole_article += temp; }
        parse_json(whole_article);

        file.close();
    }
}

void DocumentParser::parse_json(string whole_article) {
    rapidjson::Document article;
    article.Parse(whole_article.c_str());

    string article_id = article["uuid"].GetString();
    string article_title = article["title"].GetString();

    string article_published = article["published"].GetString();
    string article_publication = article["url"].GetString();

    vector<string> article_persons;
    for (auto &a : article["entities"]["persons"].GetArray())
        article_persons.push_back(a["name"].GetString());

    vector<string> article_organizations;
    for (auto &a : article["entities"]["organizations"].GetArray())
        article_organizations.push_back(a["name"].GetString());

    string article_text = article["text"].GetString();
    stringstream s(article_text);
    string temp_word;
    while (getline(s, temp_word, ' ')) {
        Porter2Stemmer::stem(temp_word);
        bool _not_stop_word = not_stop_word(temp_word);

        if (_not_stop_word) {
            vector<string> documents;
            word_map.insert(temp_word, documents).push_back(article_title);
        }
    }
}

bool DocumentParser::not_stop_word(string word) {
    //if not stop word, return true
    if (stop_words.find(word) == stop_words.end() ? true : false);
}

void DocumentParser::find_word(string word) {
    for (auto &documents : word_map.find(word))
        cout << "Title: " << documents << endl;
}


