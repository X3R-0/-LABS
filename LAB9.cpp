#include <iostream>
#include <cassert>
#include <string>

enum class Portrait { Lenin, Washington, Hitler };
enum class LightBulbColor { Blue, White, Red };
enum class Wire { Red, Yellow, Green };
enum class BombWireColor { Red, Yellow, Green };

struct Bomb {
    Portrait portrait;
    LightBulbColor lightBulbColor;
    bool switchState;
    int dialValue;
};

struct BombDefusionDecision {
    bool shouldDefuse;
    BombWireColor wireColor;
};

int getColorValue(LightBulbColor color, Portrait portrait) {
    int totalColors = 3;
    if (portrait == Portrait::Hitler) {
        color = static_cast<LightBulbColor>((static_cast<int>(color) + 1 + totalColors) % totalColors);
    }

    switch (color) {
    case LightBulbColor::Blue:  return 11;
    case LightBulbColor::White: return 15;
    case LightBulbColor::Red:   return 35;
    }

    return -1;
}

Wire shiftWire(Wire wire, int shift) {
    int totalWires = 3;
    return static_cast<Wire>((static_cast<int>(wire) + shift + totalWires) % totalWires);
}

std::string wireToString(Wire wire) {
    switch (wire) {
    case Wire::Red:    return "Red";
    case Wire::Yellow: return "Yellow";
    case Wire::Green:  return "Green";
    }
    return "";
}

BombDefusionDecision decideBombDefusion(Bomb bomb) {
    BombDefusionDecision decision{};

    if (bomb.portrait == Portrait::Lenin) {
        decision.shouldDefuse = false;
        return decision;
    }

    int colorValue = getColorValue(bomb.lightBulbColor, bomb.portrait);
    Wire wireToCut;

    if (bomb.dialValue < colorValue) {
        wireToCut = Wire::Red;
    } else if (bomb.dialValue == colorValue) {
        wireToCut = Wire::Green;
    } else {
        wireToCut = Wire::Yellow;
    }

    if (bomb.switchState) {
        wireToCut = shiftWire(wireToCut, -1);
    }

    if (bomb.dialValue % 4 == 0) {
        wireToCut = shiftWire(wireToCut, bomb.dialValue / 4);
    }

    decision.shouldDefuse = true;
    switch (wireToCut) {
    case Wire::Red:    decision.wireColor = BombWireColor::Red; break;
    case Wire::Yellow: decision.wireColor = BombWireColor::Yellow; break;
    case Wire::Green:  decision.wireColor = BombWireColor::Green; break;
    }

    return decision;
}

std::string getWireColorString(BombWireColor color) {
    switch (color) {
    case BombWireColor::Red:    return "Red";
    case BombWireColor::Yellow: return "Yellow";
    case BombWireColor::Green:  return "Green";
    }
    return "";
}

int main() {
    assert(decideBombDefusion(Bomb{ Portrait::Lenin, LightBulbColor::Blue, false, 10 }).shouldDefuse == false);
    assert(decideBombDefusion(Bomb{ Portrait::Washington, LightBulbColor::Blue, false, 10 }).shouldDefuse == true);
    assert(decideBombDefusion(Bomb{ Portrait::Hitler, LightBulbColor::White, false, 35 }).shouldDefuse == true);
    assert(decideBombDefusion(Bomb{ Portrait::Hitler, LightBulbColor::Red, true, 28 }).shouldDefuse == true);
    assert(decideBombDefusion(Bomb{ Portrait::Washington, LightBulbColor::Blue, false, 8 }).shouldDefuse == true);

    std::cout << "All test cases passed!" << std::endl;

    int portraitInput, bulbColorInput, switchInput, dialInput;
    std::cout << "Enter portrait (0: Lenin, 1: Washington, 2: Hitler): ";
    std::cin >> portraitInput;
    std::cout << "Enter light bulb color (0: Blue, 1: White, 2: Red): ";
    std::cin >> bulbColorInput;
    std::cout << "Enter switch state (0: Off, 1: On): ";
    std::cin >> switchInput;
    std::cout << "Enter dial value (1-100): ";
    std::cin >> dialInput;

    BombDefusionDecision decision = decideBombDefusion({ static_cast<Portrait>(portraitInput), static_cast<LightBulbColor>(bulbColorInput), static_cast<bool>(switchInput), dialInput });

    if (decision.shouldDefuse) {
        std::cout << "Cutting the " << getWireColorString(decision.wireColor) << " wire" << std::endl;
    } else {
        std::cout << "Do not cut any wire" << std::endl;
    }

    return 0;
}