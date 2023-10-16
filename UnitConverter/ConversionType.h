// Filename: ConversionType.h
// Purpose: This header file defines an enumeration class for different types of unit conversions.
// Author: Philip Lee

#pragma once  // Ensures that this header file is included only once during compilation

// Defines an enumeration class for types of unit conversions.
// The enum class ensures better type safety and encapsulation compared to a regular enum.
enum class ConversionType
{
    InchesToCm,  // Represents a conversion from inches to centimeters
    CmToInches,  // Represents a conversion from centimeters to inches
    KgToLbs,     // Represents a conversion from kilograms to pounds
    LbsToKg,     // Represents a conversion from pounds to kilograms
    Invalid,     // Represents an invalid or unrecognized conversion type
};