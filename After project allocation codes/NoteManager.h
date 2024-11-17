#ifndef NOTE_MANAGER_H
#define NOTE_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Note.h"

class NoteManager {
public:
    void addNote();
    void searchNoteByTitle();
    void searchNoteByText();
    void deleteNote();
    void modifyNote();
    void displayNotes();
};

#endif  // NOTE_MANAGER_H
