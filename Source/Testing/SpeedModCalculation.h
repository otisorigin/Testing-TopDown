#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "SpeedModCalculation.generated.h"

/**
 * 
 */
UCLASS()
class USpeedModCalculation : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
public:
	USpeedModCalculation();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const;

private:
	FGameplayEffectAttributeCaptureDefinition MaxSpeedDef;
};