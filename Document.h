//
// Created by kiots on 11/22/2021.
//

#ifndef INC_21F_FINAL_PROJ_TEMPLATE_DOCUMENT_H
#define INC_21F_FINAL_PROJ_TEMPLATE_DOCUMENT_H
/*
 * getters and setters for key info in document
 */
#include <iostream>

class Document {

private:
    std::string uuid;
    std::string title;
    std::string url;//for publication
    std::string published;//publish date

public:
    void set_uuid(std::string uuid);
    void set_title(std::string title);
    void set_url(std::string url);
    void set_published(std::string published);

    std::string get_uuid();
    std::string get_title();
    std::string get_url();
    std::string get_published();
};


#endif //INC_21F_FINAL_PROJ_TEMPLATE_DOCUMENT_H
