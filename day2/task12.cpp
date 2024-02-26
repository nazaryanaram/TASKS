#include <iostream>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;

public:
    Book() {}

    Book(const std::string& title, const std::string& author, const std::string& ISBN) {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
    }

    // methods setter for title, author and ISBN

    void setTitle(const std::string& title) {
        this->title = title;
    }

    void setAuthor(const std::string& author) {
        this->author = author;
    }

    void setISBN(const std::string& ISBN) {
        this->ISBN = ISBN;
    }

    // methods getter for title, author and ISBN

    std::string getTitle() {
        return title;
    }

    std::string getAuthor() {
        return author;
    }

    std::string getISBN() {
        return ISBN;
    }
};

int main()
{
    Book book;

    // initalizing book object
    book.setTitle("Code");
    book.setAuthor("Charlez Petzold");
    book.setISBN("324354645700345435");

    // print book atributes
    std::cout << book.getTitle() << std::endl;
    std::cout << book.getAuthor() << std::endl;
    std::cout << book.getISBN() << std::endl;

    return 0;
}