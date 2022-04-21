#include "TestingAttributeSet.h"

#define MAX_SPEED 50000.0f

void UTestingAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    if (Attribute == GetMaxSpeedAttribute())
    {
        NewValue = FMath::Clamp<float>(NewValue, 0, MAX_SPEED);
    }
}