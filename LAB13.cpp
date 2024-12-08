#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

struct Payload {
    int number;
    std::string text;
};

using EventHandler = std::function<void(Payload)>;

struct Event {
    std::string id;
    std::vector<std::pair<EventHandler, std::string>> handlers;
};

std::map<std::string, Event> events;

void printPayload(Payload payload) {
    std::cout << "Payload: " << payload.number << ", " << payload.text << std::endl;
}

void addNumberToPayload(Payload payload) {
    int n;
    std::cout << "Введите число, которое нужно добавить к payload: ";
    std::cin >> n;
    payload.number += n;
    std::cout << "Результат: " << payload.number << std::endl;
}

void printText(Payload payload) {
    std::cout << "Text in payload: " << payload.text << std::endl;
}

void appendTextToPayload(Payload payload) {
    std::string additionalText;
    std::cout << "Введите текст, который нужно добавить: ";
    std::cin.ignore();
    std::getline(std::cin, additionalText);
    payload.text += additionalText;
    std::cout << "Результат: " << payload.text << std::endl;
}

void createEvent() {
    std::string eventId;
    std::cout << "Введите идентификатор нового события: ";
    std::cin >> eventId;

    if (events.find(eventId) != events.end()) {
        std::cout << "Событие с таким идентификатором уже существует." << std::endl;
        return;
    }

    events[eventId] = {eventId, {}};
    std::cout << "Событие " << eventId << " создано." << std::endl;
}

void addHandlerToEvent() {
    std::string eventId;
    std::cout << "Введите идентификатор события для подписки: ";
    std::cin >> eventId;

    if (events.find(eventId) == events.end()) {
        std::cout << "Событие не найдено." << std::endl;
        return;
    }

    std::cout << "Выберите функцию для подписки:\n1. Print Payload\n2. Add Number to Payload\n3. Print Text\n4. Append Text to Payload\n";
    int choice;
    std::cin >> choice;

    EventHandler handler;
    switch (choice) {
        case 1:
            handler = printPayload;
            break;
        case 2:
            handler = addNumberToPayload;
            break;
        case 3:
            handler = printText;
            break;
        case 4:
            handler = appendTextToPayload;
            break;
        default:
            std::cout << "Некорректный выбор." << std::endl;
            return;
    }

    events[eventId].handlers.emplace_back(handler, "");
    std::cout << "Функция подписана на событие " << eventId << "." << std::endl;
}

void removeHandlerFromEvent() {
    std::string eventId;
    std::cout << "Введите идентификатор события для отписки: ";
    std::cin >> eventId;

    if (events.find(eventId) == events.end()) {
        std::cout << "Событие не найдено." << std::endl;
        return;
    }

    std::cout << "Введите идентификатор обработчика для отписки: ";
    std::string handlerId;
    std::cin >> handlerId;

    auto& handlers = events[eventId].handlers;
    handlers.erase(std::remove_if(handlers.begin(), handlers.end(), [&](const std::pair<EventHandler, std::string>& handler) {
        return handler.second == handlerId;
    }), handlers.end());

    std::cout << "Обработчик отписан от события " << eventId << "." << std::endl;
}

void listEventsAndHandlers() {
    for (const auto& [eventId, event] : events) {
        std::cout << "Событие " << eventId << ":\n";
        for (const auto& handler : event.handlers) {
            std::cout << " - Обработчик (с контекстом): " << handler.second << std::endl;
        }
    }
}

void triggerEvent() {
    std::string eventId;
    std::cout << "Введите идентификатор события для вызова: ";
    std::cin >> eventId;

    if (events.find(eventId) == events.end()) {
        std::cout << "Событие не найдено." << std::endl;
        return;
    }

    Payload payload;
    std::cout << "Введите значение для числа (0 для пропуска): ";
    std::cin >> payload.number;
    std::cout << "Введите текст для payload: ";
    std::cin.ignore();
    std::getline(std::cin, payload.text);

    for (const auto& handler : events[eventId].handlers) {
        handler.first(payload);
    }
}

int main() {
    while (true) {
        std::cout << "\nМеню:\n1. Создать событие\n2. Подписать обработчик\n3. Отписать обработчик\n4. Печать событий и обработчиков\n5. Вызвать событие\n6. Выход\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                createEvent();
                break;
            case 2:
                addHandlerToEvent();
                break;
            case 3:
                removeHandlerFromEvent();
                break;
            case 4:
                listEventsAndHandlers();
                break;
            case 5:
                triggerEvent();
                break;
            case 6:
                return 0;
            default:
                std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
        }
    }
}
