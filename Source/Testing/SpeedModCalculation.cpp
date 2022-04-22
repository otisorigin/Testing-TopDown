#include "SpeedModCalculation.h"
#include "TestingAttributeSet.h"
#include "TopDownPlayerCharacter.h"
#include "Kismet/GameplayStatics.h"


USpeedModCalculation::USpeedModCalculation()
{
	MaxSpeedDef.AttributeToCapture = UTestingAttributeSet::GetMaxSpeedAttribute();
	MaxSpeedDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	MaxSpeedDef.bSnapshot = false;


	RelevantAttributesToCapture.Add(MaxSpeedDef);
}

float USpeedModCalculation::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluationParameters;
    const UAbilitySystemComponent* AbilitySystemComponent = Spec.GetContext().GetOriginalInstigatorAbilitySystemComponent();

    ATopDownPlayerCharacter* Character = Cast<ATopDownPlayerCharacter>(AbilitySystemComponent->GetOwnerActor());

    float NewMaxSpeedValue = 0.0f;
    if (Character)
    {
        NewMaxSpeedValue = Character->GetSpeedFactor();
    }

	return NewMaxSpeedValue;
}