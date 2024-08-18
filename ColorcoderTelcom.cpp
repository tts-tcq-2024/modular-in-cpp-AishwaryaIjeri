#include "ColorcoderTelcom.h"

namespace TelCoColorCoder {
    // Define the color names
    const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    const int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    // ColorPair implementation
    ColorPair::ColorPair(MajorColor major, MinorColor minor) : majorColor(major), minorColor(minor) {}

    MajorColor ColorPair::getMajor() {
        return majorColor;
    }

    MinorColor ColorPair::getMinor() {
        return minorColor;
    }

    std::string ColorPair::ToString() {
        return std::string(MajorColorNames[majorColor]) + " " + MinorColorNames[minorColor];
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        if (pairNumber < 1 || pairNumber > numberOfMajorColors * numberOfMinorColors) {
            throw std::out_of_range("Pair number is out of range");
        }
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor = static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        if (major >= numberOfMajorColors || minor >= numberOfMinorColors) {
            throw std::out_of_range("Invalid color");
        }
        return major * numberOfMinorColors + minor + 1;
    }

    void PrintColorCodingReference() {
        int pairNumber = 1;
        for (int major = 0; major < numberOfMajorColors; ++major) {
            for (int minor = 0; minor < numberOfMinorColors; ++minor) {
                ColorPair colorPair(static_cast<MajorColor>(major), static_cast<MinorColor>(minor));
                std::cout << "Pair " << pairNumber++ << ": " << colorPair.ToString() << std::endl;
            }
        }
    }
}
