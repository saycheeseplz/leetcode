class Book
{
private:
    char *title;
    char *authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
        this->title = nullptr;
        this->authors = nullptr;
        this->publishingYear = 0;
    }

    Book(const char *title, const char *authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->publishingYear = publishingYear;
        this->title = new char(strlen(title) + 1);
        strcpy(this->title, title);
        this->authors = new char(strlen(authors));
        strcpy(this->authors, authors);
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
        int n = strlen(book.title) + 1;
        int m = strlen(book.authors) + 1;
        char *title = new char[n];
        char *authors = new char[m];
        this->publishingYear = book.publishingYear;
        for (int i = 0; i < n; i++)
        {
            title[i] = book.title[i];
        }
        for (int j = 0; j < m; j++)
        {
            authors[j] = book.authors[j];
        }
        this->authors = authors;
        this->title = title;
        delete[] authors;
        delete[] title;
    }

    void setTitle(const char *title)
    {
        /*
         * STUDENT ANSWER
         */
        char *dummy = new char[strlen(title) + 1];
        strcpy(dummy, title);
        this->title = dummy;
        delete[] dummy;
    }

    void setAuthors(const char *authors)
    {
        /*
         * STUDENT ANSWER
         */
        char *dummy = new char[strlen(authors) + 1];
        strcpy(dummy, authors);
        this->authors = dummy;
        delete[] dummy;
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->publishingYear = publishingYear;
    }

    char *getTitle() const
    {
        /*
         * STUDENT ANSWER

         */
        return this->title;
    }

    char *getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        delete[] title;
        delete[] authors;
    }

    void printBook()
    {
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};