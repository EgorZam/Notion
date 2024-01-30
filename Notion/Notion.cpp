#include <iostream>
#include <vector>
#include <string>

// Структура для представления заметки
struct Note {
    std::string title;
    std::string content;
};

// Класс для управления заметками
class NoteManager {
private:
    std::vector<Note> notes;

public:
    // Добавить новую заметку
    void addNote() {
        Note newNote;
        std::cout << "Введите заголовок заметки: ";
        std::getline(std::cin, newNote.title);
        std::cout << "Введите текст заметки: ";
        std::getline(std::cin, newNote.content);
        notes.push_back(newNote);
        std::cout << "Заметка успешно добавлена!\n";
    }

    // Вывести все заметки
    void displayNotes() const {
        if (notes.empty()) {
            std::cout << "Заметок нет.\n";
        }
        else {
            std::cout << "Список заметок:\n";
            for (const auto& note : notes) {
                std::cout << "---------------------\n";
                std::cout << "Заголовок: " << note.title << '\n';
                std::cout << "Текст: " << note.content << '\n';
            }
            std::cout << "---------------------\n";
        }
    }

    // Удалить заметку по заголовку
    void deleteNote() {
        std::string titleToDelete;
        std::cout << "Введите заголовок заметки для удаления: ";
        std::getline(std::cin, titleToDelete);

        auto it = std::remove_if(notes.begin(), notes.end(), [titleToDelete](const Note& note) {
            return note.title == titleToDelete;
            });

        if (it != notes.end()) {
            notes.erase(it, notes.end());
            std::cout << "Заметка успешно удалена!\n";
        }
        else {
            std::cout << "Заметка с указанным заголовком не найдена.\n";
        }
    }
};

int main() {
    NoteManager noteManager;
    int choice;

    do {
        // Меню
        std::cout << "Выберите действие:\n";
        std::cout << "1. Добавить заметку\n";
        std::cout << "2. Вывести все заметки\n";
        std::cout << "3. Удалить заметку\n";
        std::cout << "0. Выйти\n";
        std::cout << "Ваш выбор: ";

        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера после ввода числа

        switch (choice) {
        case 1:
            noteManager.addNote();
            break;
        case 2:
            noteManager.displayNotes();
            break;
        case 3:
            noteManager.deleteNote();
            break;
        case 0:
            std::cout << "Программа завершена.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте еще раз.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}
