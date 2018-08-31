/*UVa 230
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

struct Book {
    std::string author;
    std::string title;
    bool borrowed{false};
    Book(const std::string& item)
    {
        auto end_pos = item.find('\"', 1) - 1;
        title        = item.substr(1, end_pos);
        author       = item.substr(end_pos + 6);
    }
    bool operator<(const Book& rhs) const
    {
        return (this->author < rhs.author) || ((this->author == rhs.author) && (this->title < rhs.title));
    }
};

std::vector<Book> books;
std::set<Book> borrowed;
std::set<Book> returned;

void print(void)
{
    for (auto& book : books) {
        std::cout << "\"" << book.title << "\""
                  << " by " << book.author << " is borrowed:" << book.borrowed << std::endl;
    }
    std::cout << std::endl;
    for (auto& book : returned) { std::cout << book.title << std::endl; }
}

void borrow(const std::string& item)
{
    const auto op_length = 8;
    auto bor_title       = item.substr(op_length, static_cast<int>(item.size()) - 1 - op_length);
    for (auto& book : books) {
        if (book.title == bor_title) {
            // borrowed.insert(book); break;
            book.borrowed = true;
            break;
        }
    }
}

void ret(const std::string& item)
{
    const auto op_length = 8;
    auto ret_title       = item.substr(op_length, static_cast<int>(item.size()) - 1 - op_length);
    for (auto& book : books) {
        if (book.title == ret_title) {
            returned.insert(book);
            break;
        }
    }
}

void shelve(void)
{
    auto itr = books.begin();
    for (const auto& ret_book : returned) {
        while (itr->title != ret_book.title) { itr = std::next(itr); }
        itr->borrowed = false;
        if (itr == books.begin()) {
            std::cout << "Put \"" << ret_book.title << "\" first" << std::endl;
            itr = std::next(itr);
            continue;
        }
        auto find_itr = std::prev(itr);
        itr = std::next(itr);
        while (find_itr != books.begin()) {
            if (!find_itr->borrowed) {
                std::cout << "Put \"" << ret_book.title << "\" after \"" << find_itr->title << "\"" << std::endl;
                break;
            }
            find_itr = std::prev(find_itr);
        }
        if (find_itr != books.begin()) {
            continue;
        } else {
            if (!find_itr->borrowed) {
                std::cout << "Put \"" << ret_book.title << "\" after \"" << find_itr->title << "\"" << std::endl;
            } else {
                std::cout << "Put \"" << ret_book.title << "\" first" << std::endl;
            }
        }
    }
    std::cout << "END" << std::endl;
    returned.clear();
    return;
}

int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("chapter05\\borrower_input.txt", "r", stdin);
    freopen("chapter05\\borrower_output.txt", "w", stdout);
#endif
    std::string item;
    std::getline(std::cin, item);
    while (item.front() != 'E') {
        Book tmp{item};
        books.push_back(tmp);
        std::getline(std::cin, item);
    }
    std::sort(books.begin(), books.end());
    //print();
    std::getline(std::cin, item);
    while (item.front() != 'E') {
        switch (item.front()) {
            case 'B': borrow(item); break;
            case 'R': ret(item); break;
            case 'S': shelve(); break;
            default: assert(false); break;
        }
        std::getline(std::cin, item);
    }
    //print();
    return 0;
}
