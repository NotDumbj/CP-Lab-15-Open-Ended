#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<limits>

using namespace std;

struct Book
{
    string title;
    string author;
    int publication_year;
    string genre;
};

void oldestbookfinder(Book books[6], Book& oldBook, const string& genre);
void mainmenu();
void getbookdetail();
void categorizebooks();
void displaybooks();
void start();



Book book[6];
Book ficbook[6];
Book nonficbook[6];
Book ficoldbook;
Book nonficoldbook;

int main()
{
    mainmenu();
    return 0;
}


void oldestbookfinder(Book books[6], Book& oldBook, const string& genre)
{
    oldBook = books[0];


    for (int i = 1; i < 6; i++)
    {
        if (books[i].genre == genre && books[i].publication_year < oldBook.publication_year)
        {
            oldBook = books[i];
        }
    }
}


void getbookdetail()
{
    ofstream outFile("Books.txt");
    for (int i = 0; i < 6; i++)
    {
        int j = i + 1;
        cout << "Enter details of Book " << j << endl;
        cout << "Enter Book Title : ";
        while (true)
        {
            getline(cin, book[i].title);
            if (book[i].title.empty() || book[i].title.size() <= 2)
            {
                cout << "I can't thought of a book with this entries.\n";
                cout << "Please Enter Valid Title Name : ";
                cin.clear();
            }
            else if (isspace(book[i].title[0]) || isspace(book[i].title[1]))
            {
                cout << "What book name has spaces as there starting characters...!?\n";
                cout << "Please Enter Valid Title Name : ";
                cin.clear();
            }
            else
            {
                break;
            }
            cin.ignore();
        }
        cout << "Enter Book Author's Name : ";
        while (true)
        {
            getline(cin, book[i].author);

            bool check = false;

            for (char c : book[i].author) {
                if (!isalpha(c)) {
                    cout << "Human Names do not have symbols or numbers in them.\n";
                    cout << "Please Enter a Valid Author Name : ";
                    cin.clear();
                    break;
                }
                else
                {
                    check = true;
                }
            }
            if (check == true)
            {
                if ((book[i].author.empty() || book[i].author.size() <= 2)) {
                    cout << "I can't think of a human name with this entry.\n";
                    cout << "Please Enter a Valid Author Name : ";
                    cin.clear();
                }

                else if ((isspace(book[i].author[0]) || isspace(book[i].author[1]))) {
                    cout << "What human name has spaces as their starting characters.\n";
                    cout << "Please Enter a Valid Author Name : ";
                    cin.clear();
                }

                else
                {
                    break;
                }
            }
            
            cin.clear();

        }
        cout << "Enter Book Publication Year : ";
        while (true)
        {
            if (cin >> book[i].publication_year)
            {
                if (book[i].publication_year > 2024 || book[i].publication_year < 1000)
                {
                    cout << "A book of that year cannot be existing.\n";
                    cout << "Enter Valid Year : ";
                }
                else
                {
                    break;
                }
            }
            else
            {
                cout << "Enter Valid Year : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cout << "What's Book Genre ; \n";
        cout << " > Fiction     ( 1 )\n";
        cout << " > Non-Fiction ( 2 )\n\n";
        while (true)
        {
            char book_genre = _getch();
            if (book_genre == '1')
            {
                book[i].genre = "Fiction";
                break;
            }
            else if (book_genre == '2')
            {
                book[i].genre = "Non-Fiction";
                break;
            }
            else
            {
                cin.clear();
                if (_kbhit)
                {
                    _getch();
                }
            }
        }
        cin.ignore();

        if (outFile.is_open())
        {
            outFile << book[i].title << "\n";
            outFile << book[i].author << "\n";
            outFile << book[i].publication_year << "\n";
            outFile << book[i].genre << "\n";
        }
    }
    outFile.close();
}

void mainmenu()
{
    system("cls");
    cout << "Welcome to Book Categorizing Program :)\n\n";
    cout << "We only categorize in two genre ;\n * Fiction\n * Non-Fiction\n\n";
    cout << " >  Start ( 1 )\n";
    cout << " >  Quit  ( 2 )\n";
    while (true)
    {
        char choice = _getch();
        if (choice == '1')
        {
            system("cls");
            start();
            break;
        }
        else if (choice == '2')
        {
            exit(0);
        }
        else
        {
            cin.clear();
            if (_kbhit)
            {
                _getch();
            }
        }
    }

}

void start()
{
    if (!book->title.empty())
    {
        cout << "Books Data Found... Displaying Books\n\n";
        displaybooks();
    }
    cout << "The array of books is empty..  :( \n";
    cout << "You Need to Input Details for Books...\n\n";
    getbookdetail();
    categorizebooks();

    oldestbookfinder(ficbook, ficoldbook, "Fiction");
    oldestbookfinder(nonficbook, nonficoldbook, "Non-Fiction");
    system("cls");
    displaybooks();
}

void categorizebooks()
{
    int fb = 0, nfb = 0;
    for (int i = 0; i < 6; i++)
    {
        if (book[i].genre == "Fiction")
        {
            ficbook[fb] = book[i];
            fb++;
        }
        else if (book[i].genre == "Non-Fiction")
        {
            nonficbook[nfb] = book[i];
            nfb++;
        }
    }
}


void displaybooks()
{
    cout << "|||          FICTION BOOKS           |||" << endl << endl;
    if (ficbook[0].title.empty()) {
        cout << "No Fiction books available." << endl;
    }
    else {
        for (int i = 0; i < 6; i++)
        {
            if (!ficbook[i].title.empty()) {
                cout << "    Book " << i+1 << endl;
                cout << "    Title  : " << ficbook[i].title << endl;
                cout << "    Author : " << ficbook[i].author << endl;
                cout << "    Publication Date : " << ficbook[i].publication_year << endl << endl;
            }
        }
        cout << "\n    Earliest Published Fiction Book :" << endl;
        cout << "    Title  : " << ficoldbook.title << endl;
        cout << "    Author : " << ficoldbook.author << endl;
        cout << "    Publication Date : " << ficoldbook.publication_year << endl << endl << endl;
    }
    cout << "|||        NON-FICTION BOOKS        |||" << endl << endl;
    if (nonficbook[0].title.empty()) {
        cout << "No Non-Fiction books available." << endl;
    }
    else {
        for (int i = 0; i < 6; i++)
        {
            if (!nonficbook[i].title.empty()) {
                cout << "    Book " << i+1 << endl;
                cout << "    Title  : " << nonficbook[i].title << endl;
                cout << "    Author : " << nonficbook[i].author << endl;
                cout << "    Publication Date : " << nonficbook[i].publication_year << endl << endl;
            }
        }
        cout << "\n    Earliest Published Non-Fiction Book :" << endl;
        cout << "    Title  : " << nonficoldbook.title << endl;
        cout << "    Author : " << nonficoldbook.author << endl;
        cout << "    Publication Date : " << nonficoldbook.publication_year << endl << endl << endl;
    }

    cout << "\n\nBooks has been displayed, Check them out. (i.e Scroll Up)\n\n";
    system("pause");
    mainmenu();
}
