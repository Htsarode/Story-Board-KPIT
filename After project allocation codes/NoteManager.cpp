#include "NoteManager.h"

// Validation functions
void validateTitle(const std::string &title)
{
    // Allow only alphanumeric characters and spaces
    for (char c : title)
    {
        if (!std::isalnum(c) && !std::isspace(c))
        {
            throw std::invalid_argument("Invalid title");
        }
    }
}

void validateText(const std::string &text)
{
    // Allow only alphanumeric characters, spaces, and special characters (!, @, #, $, etc.)
    for (char c : text)
    {
        if (!std::isalnum(c) && !std::isspace(c) && !std::ispunct(c))
        {
            throw std::invalid_argument("Invalid text");
        }
    }
}
void NoteManager::addNote()
{
    Note newNote;
    std::cin.ignore();
    std::cout << "Enter title: " << std::endl;
    std::getline(std::cin, newNote.title);
    validateTitle(newNote.title);

    std::cout << "Enter text: " << std::endl;
    std::getline(std::cin, newNote.text);
    validateText(newNote.text);

    // Store note in file
    std::ofstream file("notes.txt", std::ios_base::app);
    file << newNote.title << std::endl;
    file << newNote.text << std::endl;
    file.close();
}

void NoteManager::searchNoteByTitle()
{
    std::string title;
    std::cin.ignore();
    std::cout << "Enter title to search: ";
    std::getline(std::cin, title);
    validateTitle(title);

    std::ifstream file("notes.txt");
    std::string line;
    bool found = false;
    while (std::getline(file, line))
    {
        if (line == title)
        {
            found = true;
            std::cout << "Note found:" << std::endl;
            std::cout << line << std::endl;
            std::getline(file, line);
            std::cout << line << std::endl;
        }
    }
    file.close();
    if (!found)
    {
        std::cout << "Note not found." << std::endl;
    }
}

void NoteManager::searchNoteByText()
{
    std::string text;
    std::cin.ignore();
    std::cout << "Enter text to search: ";
    std::getline(std::cin, text);
    validateText(text);

    std::ifstream file("notes.txt");
    std::string line;
    bool found = false;
    while (std::getline(file, line))
    {
        if (line.find(text) != std::string::npos)
        {
            found = true;
            std::cout << "Note found:" << std::endl;
            std::cout << line << std::endl;
            std::getline(file, line);
            std::cout << line << std::endl;
        }
    }
    file.close();
    if (!found)
    {
        std::cout << "Note not found." << std::endl;
    }
}

void NoteManager::deleteNote()
{
    std::string title;
    std::cin.ignore();
    std::cout << "Enter title of note to delete: ";
    std::getline(std::cin, title);
    validateTitle(title);

    std::ifstream file("notes.txt");
    std::vector<Note> notes;
    Note note;
    bool found = false;
    while (std::getline(file, note.title))
    {
        std::getline(file, note.text);
        if (note.title != title)
        {
            notes.push_back(note);
        }
        else
        {
            found = true;
        }
    }
    file.close();
    if (found)
    {
        std::ofstream newFile("notes.txt");
        for (const auto &note : notes)
        {
            newFile << note.title << std::endl;
            newFile << note.text << std::endl;
        }
        newFile.close();
        std::cout << "Note deleted." << std::endl;
    }
    else
    {
        std::cout << "Note not found." << std::endl;
    }
}

void NoteManager::modifyNote()
{
    std::string title;
    std::cin.ignore();
    std::cout << "Enter title of note to modify: ";
    std::getline(std::cin, title);
    validateTitle(title);

    std::ifstream file("notes.txt");
    std::vector<Note> notes;
    Note note;
    bool found = false;
    while (std::getline(file, note.title))
    {
        std::getline(file, note.text);
        if (note.title == title)
        {
            found = true;
            std::cout << "Enter new title: ";
            std::getline(std::cin, note.title);
            validateTitle(note.title);

            std::cout << "Enter new text: ";
            std::getline(std::cin, note.text);
            validateText(note.text);
        }
        notes.push_back(note);
    }
    file.close();
    if (found)
    {
        std::ofstream newFile("notes.txt");
        for (const auto &note : notes)
        {
            newFile << note.title << std::endl;
            newFile << note.text << std::endl;
        }
        newFile.close();
        std::cout << "Note modified." << std::endl;
    }
    else
    {
        std::cout << "Note not found." << std::endl;
    }
}

void NoteManager::displayNotes()
{
    std::ifstream file("notes.txt");
    if (!file.is_open())
    {
        std::cout << "No notes available." << std::endl;
        return;
    }

    std::string line;
    int noteNumber = 1;
    while (std::getline(file, line))
    {
        std::cout << "Note " << noteNumber << ":" << std::endl;
        std::cout << "Title: " << line << std::endl;
        std::getline(file, line);
        std::cout << "Text: " << line << std::endl;
        std::cout << std::endl;
        noteNumber++;
    }
    file.close();
}
