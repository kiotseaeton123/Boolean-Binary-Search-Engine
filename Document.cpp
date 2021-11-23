//
// Created by kiots on 11/22/2021.
//

#include "Document.h"

void Document::set_uuid(std::string uuid) {
    this->uuid = uuid;

}

void Document::set_title(std::string title) {
    this->title = title;

}

void Document::set_url(std::string url) {
    this->url = url;

}

void Document::set_published(std::string published) {
    this->published = published;

}

std::string Document::get_uuid() {
    return uuid;
}

std::string Document::get_title() {
    return title;
}

std::string Document::get_url() {
    return url;
}

std::string Document::get_published() {
    return published;
}
