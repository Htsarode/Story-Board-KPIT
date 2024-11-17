#include "NoteManager.h"

int main() {
    NoteManager noteManager;
    int choice;
    do {
        std::cout << "1. Add Note" << std::endl;
        std::cout << "2. Search Note by Title" << std::endl;
        std::cout << "3. Search Note by Text" << std::endl;
        std::cout << "4. Delete Note" << std::endl;
        std::cout << "5. Modify Note" << std::endl;
        std::cout << "6. Display Notes" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                noteManager.addNote();
                break;
            case 2:
                noteManager.searchNoteByTitle();
                break;
            case 3:
                noteManager.searchNoteByText();
                break;
            case 4:
                noteManager.deleteNote();
                break;
            case 5:
                noteManager.modifyNote();
                break;
            case 6:
                noteManager.displayNotes();
                break;
            case 7:
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != 7);

    return 0;
}